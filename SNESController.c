#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include "SNESController.h"

void (*callbacks_pressed[12])(void);
void (*callbacks_released[12])(void);

static volatile int buttonStatesAct[16];
static volatile int buttonStatesLast[16];

static pthread_t updateThread;
static volatile int updateState;

void snesInit(void)
{
    bcm2835_gpio_fsel(gpioSnesClock, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(gpioSnesLatch, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(gpioSnesData0, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(gpioSnesData1, BCM2835_GPIO_FSEL_INPT);

    bcm2835_gpio_write(gpioSnesClock, HIGH);

    int i;
    for(i=0; i<12; i++)
        buttonStatesLast[i] = 0;
}

void snesClose(void)
{
    snesStopPollButtonsAsync();
    bcm2835_gpio_write(gpioSnesClock, LOW);
    bcm2835_gpio_write(gpioSnesLatch, LOW);
    bcm2835_gpio_fsel(gpioSnesClock, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(gpioSnesLatch, BCM2835_GPIO_FSEL_INPT);
}

void snesRegisterCallback(SnesButton Button, SnesButtonEvent ButtonEvent, void (*callback)(void))
{
    if(ButtonEvent == snesEvent_Pressed)
        callbacks_pressed[Button] = callback;
    else if(ButtonEvent == snesEvent_Released)
        callbacks_released[Button] = callback;
}

int snesIsButtonPressed(SnesButton Button)
{
    return buttonStatesAct[Button];
}

void getButtons(void)
{
    int i;

    while(updateState == 1)
    {
        bcm2835_gpio_write(gpioSnesLatch, HIGH);
        bcm2835_delayMicroseconds(12);
        bcm2835_gpio_write(gpioSnesLatch, LOW);

        bcm2835_delayMicroseconds(6);
        buttonStatesAct[0] = !bcm2835_gpio_lev(gpioSnesData0);
        for(i=1; i<16; i++)
        {
            bcm2835_gpio_write(gpioSnesClock, LOW);
            bcm2835_delayMicroseconds(6);
            bcm2835_gpio_write(gpioSnesClock, HIGH);
            bcm2835_delayMicroseconds(6);
            buttonStatesAct[i] = !bcm2835_gpio_lev(gpioSnesData0);
        }

        for(i=0; i<12; i++)
        {
            if(buttonStatesAct[i] && (!buttonStatesLast[i]) && (callbacks_pressed[i] != NULL))
                (*(callbacks_pressed[i]))();
            else if((!buttonStatesAct[i]) && buttonStatesLast[i] && (callbacks_released[i] != NULL))
                (*(callbacks_released[i]))();
            buttonStatesLast[i] = buttonStatesAct[i];
        }

        bcm2835_delay(16);
    }

}

int snesStartPollButtonsAsync(void)
{
    updateState = 1;
    return pthread_create(&updateThread, NULL, &getButtons, NULL) ;
}

void snesStopPollButtonsAsync(void)
{
    updateState = 0;
}

