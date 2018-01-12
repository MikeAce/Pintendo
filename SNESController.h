/*
 * File:   SNESController.h
 * Author: Andreas
 *
 * Created on 20. September 2015, 15:23
 */

#ifndef SNESCONTROLLER_H
#define	SNESCONTROLLER_H

#define gpioSnesClock 16
#define gpioSnesLatch 26
#define gpioSnesData0 14
#define gpioSnesData1 15


void snesInit(void);

void snesClose(void);

typedef enum
{
    snesButton_B = 0,
    snesButton_Y,
    snesButton_Select,
    snesButton_Start,
    snesButton_Ip,
    snesButton_Down,
    snesButton_Left,
    snesButton_Right,
    snesButton_A,
    snesButton_X,
    snesButton_L1,
    snesButton_R1
} SnesButton;

typedef enum
{
    snesEvent_Pressed = 0,
    snesEvent_Released
}SnesButtonEvent;

void snesRegisterCallback(SnesButton Button, SnesButtonEvent ButtonEvent, void (*callback)(void));

int snesIsButtonPressed(SnesButton Button);

int snesStartPollButtonsAsync(void);

void snesStopPollButtonsAsync(void);

#endif	/* SNESCONTROLLER_H */

