/* 
 * File:   main.c
 * Author: Markus & Andreas
 *
 * Created on 20. September 2015, 10:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <bcm2835.h>
#include <errno.h>


#include "RGBMatrixInclude/led-matrix.h"
#include "SNESController.h"
#include "LCDDisplay.h"

#define RED       1
#define GREEN     2
#define BLUE      3

int colVertical, colHorizontal;

void exitProgram(void)
{
    snesClose();
    rgbMatrixClose();
    lcdClose ();
    bcm2835_close();
    exit(EXIT_SUCCESS);
}

void draw()
{
    int i, j;
    int colPerStep = (RGBMAX+1)/rgbMatrixWidth();

    if(colVertical == colHorizontal)
        colPerStep /= 2;

    for(i=0; i<rgbMatrixWidth(); i++)
        for(j=0; j<rgbMatrixHeight(); j++)
        {
                rgbMatrixSetPixel(i,j, (colVertical==RED?i*colPerStep:0) + (colHorizontal==RED?j*colPerStep:0),
                                       (colVertical==GREEN?i*colPerStep:0) + (colHorizontal==GREEN?j*colPerStep:0),
                                       (colVertical==BLUE?i*colPerStep:0) + (colHorizontal==BLUE?j*colPerStep:0));
        }

}

void snesCb_B_pressed(void)
{
    printf("+B");
}

void snesCb_B_released(void)
{
    printf("-B");
}

void snesCb_A_pressed(void)
{
    printf("+A");
    if(snesIsButtonPressed(snesButton_L1))
        colVertical = RED;
    if(snesIsButtonPressed(snesButton_R1))
        colHorizontal = RED;
    draw();
}

void snesCb_A_released(void)
{
    printf("-A");
}

void snesCb_Y_pressed(void)
{
    printf("+Y");
    if(snesIsButtonPressed(snesButton_L1))
        colVertical = GREEN;
    if(snesIsButtonPressed(snesButton_R1))
        colHorizontal = GREEN;
    draw();
}

void snesCb_Y_released(void)
{
    printf("-Y");
}

void snesCb_X_pressed(void)
{
    printf("+X");
    if(snesIsButtonPressed(snesButton_L1))
        colVertical = BLUE;
    if(snesIsButtonPressed(snesButton_R1))
        colHorizontal = BLUE;
    draw();
}

void snesCb_X_released(void)
{
    printf("-X");
}

void snesCb_Start_pressed(void)
{
    printf("+Start");
    if(snesIsButtonPressed(snesButton_Select))
    {
        printf("BYEBYE\n");
        exitProgram();
    }
}

void snesCb_Start_released(void)
{
    printf("-Start");
}

void snesCb_Select_pressed(void)
{
    printf("+Select");
    if(snesIsButtonPressed(snesButton_Start))
    {
        printf("BYEBYE\n");
        exitProgram();
    }
}

void snesCb_Select_released(void)
{
    printf("-Select");
}


int main(int argc, char** argv) {

    printf("LOS GEHT'S\n");
    printf("press L1/R1 + Y/X/A to change color\n");
    printf("press Select + Start for exit!\n");

    signal(SIGINT, &exitProgram);
    if(!bcm2835_init()){
            fprintf(stderr, "Unable to setup bcm2835:%s\n",strerror(errno));
            return 1;
    }

    if(!rgbMatrixInit(32,1,2))
    {
        fprintf(stderr, "Unable to setup RGB Matrix:%s\n",strerror(errno));
        return 1;
    }


    snesInit();
    snesRegisterCallback(snesButton_B, snesEvent_Pressed, &snesCb_B_pressed);
    snesRegisterCallback(snesButton_A, snesEvent_Pressed, &snesCb_A_pressed);
    snesRegisterCallback(snesButton_X, snesEvent_Pressed, &snesCb_X_pressed);
    snesRegisterCallback(snesButton_Y, snesEvent_Pressed, &snesCb_Y_pressed);
    snesRegisterCallback(snesButton_Start, snesEvent_Pressed, &snesCb_Start_pressed);
    snesRegisterCallback(snesButton_Select, snesEvent_Pressed, &snesCb_Select_pressed);
    snesRegisterCallback(snesButton_B, snesEvent_Released, &snesCb_B_released);
    snesRegisterCallback(snesButton_A, snesEvent_Released, &snesCb_A_released);
    snesRegisterCallback(snesButton_X, snesEvent_Released, &snesCb_X_released);
    snesRegisterCallback(snesButton_Y, snesEvent_Released, &snesCb_Y_released);
    snesRegisterCallback(snesButton_Start, snesEvent_Released, &snesCb_Start_released);
    snesRegisterCallback(snesButton_Select, snesEvent_Released, &snesCb_Select_released);
    //snesStartPollButtonsAsync();

// die callbacks sind registriert, jetzt müssen die Funktionen nur noch was sinnvolles machen...
// je nach spiel, was gestartet wird (oder auch im Spiel: Menue, Game, ...), werden die callbacks
// umgemapped auf andere Funktionen wie bewegen, pause, schiessen, nächster Buchstabe, Lautstärke, ...

    //rgbMatrixFill(RGBMAX, RGBMAX, RGBMAX);

    srand(time(NULL));

    int i;
    double Pi = 3.141592653;
        for(i=0; i<32*32; i++)
        {
            rgbMatrixSetPixel(i%32, i/32, 100,100,100);
            bcm2835_delay(500);
            rgbMatrixSetPixel(i%32, i/32, 0,0,0);
        }

/* für LCD-Ansteuerung
    lcdInit (2, 16, 0, 1, 2, 3, 4, 5);
    lcdClear ();
    bcm2835_delay (3000);
    lcdPosition (0, 0) ; lcdPuts ("1: Paint") ;
    bcm2835_delay (3000);
    lcdPosition (0, 1) ; lcdPuts ("2: Snake") ;
*/
    while(1)
    {
        bcm2835_delay(1000);  
    }

    exitProgram();
    
    return (EXIT_SUCCESS);
}

