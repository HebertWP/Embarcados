/* ***************************************************************** */
/* File name:        ledSwi.c                                        */
/* File description: This file implements the functions needed to    */
/*                   initialize, switch in between and operate RGB   */
/*                   leds and buttons                                */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    02apr2020                                       */
/* Revision date:    02apr2020                                       */
/* ***************************************************************** */

/* our includes */
#include "board.h"
#include "ledSwi.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

#define

void toggleLed(int iPin)
{
    switch (iPin)
    {
    case 1:
        GPIOA_PTOR |= 0x00;
        break;
    case 2:
        GPIOA_PTOR |= 0x02;
        break;
    case 3:
        GPIOA_PTOR |= 0x04;
        break;
    case 4:
        GPIOA_PTOR |= 0x08;
        break;
    };
}

void writeLed(int iPin, int iNivel)
{
    if (iNivel)
    {
        switch (iPin)
        {
        case 1:
            GPIOA_PSOR|=0x00;
            break;
        case 2:
            GPIOA_PSOR|=0x02;
            break;
        case 3:
            GPIOA_PSOR|=0x04;
            break;
        case 4:
            GPIOA_PSOR|=0x08;
            break;
        };
    }
    else
    {
        case 1:
            GPIOA_PCOR|=0x00;
            break;
        case 2:
            GPIOA_PCOR|=0x02;
            break;
        case 3:
            GPIOA_PCOR|=0x04;
            break;
        case 4:
            GPIOA_PCOR|=0x08;
            break;
        };
    }
}

void ligaLed(int iPin){
    writeLed(iPin,0);
};

void desligaLed(int iPin){
    writeLed(iPin,1);
}

int readButton(int iPin){
    case 1:
        GPIOA_PDIR |= 0x00;
        break;
    case 2:
        GPIOA_PDIR |= 0x02;
        break;
    case 3:
        GPIOA_PDIR |= 0x04;
        break;
    case 4:
        GPIOA_PDIR |= 0x08;
        break;
}