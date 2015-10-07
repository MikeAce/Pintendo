/* 
 * File:   main.c
 * Author: Andreas
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

#define RED       1
#define GREEN     2
#define BLUE      3

int colVertical, colHorizontal;

void exitProgram(void)
{
    snesClose();
    rgbMatrixClose();
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

}

void snesCb_B_released(void)
{
    
}

void snesCb_A_pressed(void)
{
    if(snesIsButtonPressed(snesButton_L1))
        colVertical = RED;
    if(snesIsButtonPressed(snesButton_R1))
        colHorizontal = RED;
    draw();
}

void snesCb_A_released(void)
{

}

void snesCb_Y_pressed(void)
{
    if(snesIsButtonPressed(snesButton_L1))
        colVertical = GREEN;
    if(snesIsButtonPressed(snesButton_R1))
        colHorizontal = GREEN;
    draw();
}

void snesCb_Y_released(void)
{

}

void snesCb_X_pressed(void)
{
    if(snesIsButtonPressed(snesButton_L1))
        colVertical = BLUE;
    if(snesIsButtonPressed(snesButton_R1))
        colHorizontal = BLUE;
    draw();
}

void snesCb_X_released(void)
{

}

void snesCb_Start(void)
{
    if(snesIsButtonPressed(snesButton_Select))
        exitProgram();
}

void snesCb_Select(void)
{
    if(snesIsButtonPressed(snesButton_Start))
        exitProgram();
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
    
  
    if(!rgbMatrixInit(32,1,1))
    {
        fprintf(stderr, "Unable to setup RGB Matrix:%s\n",strerror(errno));
        return 1;
    }    
    
    snesInit();
    snesRegisterCallback(snesButton_B, snesEvent_Pressed, &snesCb_B_pressed);
    snesRegisterCallback(snesButton_A, snesEvent_Pressed, &snesCb_A_pressed);
    snesRegisterCallback(snesButton_X, snesEvent_Pressed, &snesCb_X_pressed);
    snesRegisterCallback(snesButton_Y, snesEvent_Pressed, &snesCb_Y_pressed);
    snesRegisterCallback(snesButton_B, snesEvent_Released, &snesCb_B_released);
    snesRegisterCallback(snesButton_A, snesEvent_Released, &snesCb_A_released);
    snesRegisterCallback(snesButton_X, snesEvent_Released, &snesCb_X_released);
    snesRegisterCallback(snesButton_Y, snesEvent_Released, &snesCb_Y_released);
    snesRegisterCallback(snesButton_Start, snesEvent_Pressed, &snesCb_Start);
    snesRegisterCallback(snesButton_Select, snesEvent_Pressed, &snesCb_Select);
    snesStartPollButtonsAsync();
    
    rgbMatrixFill(RGBMAX, RGBMAX, RGBMAX);
    
    srand (time(NULL));
    int i, j;
    while(1)
    {
        bcm2835_delay(100);  
        
        for(i=0; i<rgbMatrixHeight (); i++)
            for(j=0; j<rgbMatrixWidth (); j++)
              {
                rgbMatrixSetPixel (i, j, rand(), rand(), rand());
                bcm2835_delay(1);  
              } 
             
    }
    

    exitProgram();

    return (EXIT_SUCCESS);
}

