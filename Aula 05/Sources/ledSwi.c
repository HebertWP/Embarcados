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

void initLedButton(int *iPinsLed, int iTamLed,int *iPinsButton, int iTamButton){
    int iI = 0; /*integer iterator*/
    uint32_t uiLedPins; /*selected led pins are 1*/
    uint32_t uiButtonPins; /*selected button pins are 1*/

    /*un-gateport A clock*/
    SIM_SCGC5|=0x200;

    /*initialize selected Leds as GPIO and set them as digital output*/
    if(iTamLed != 0){
        for(iI = 0; iI < iTamLed; iI ++){
            if(1 == iPinsLed[iI]){
                PORTA_PCR1 |= 0x100;
                GPIOA_PDDR |= LED1_MASK;
            }else if(2 == iPinsLed[iI]){
                PORTA_PCR2 |= 0x100;
                GPIOA_PDDR |= LED2_MASK;
            }else if(3 == iPinsLed[iI]){
                PORTA_PCR4 |= 0x100;
                GPIOA_PDDR |= LED3_MASK;
            }else if(4 == iPinsLed[iI]){
                PORTA_PCR5 |= 0x100;
                GPIOA_PDDR |= LED4_MASK;
            }
        }
    }

    /*initialize selected buttons as GPIO and set them as digital input*/
    if(iTamButton != 0){
        for(iI = 0; iI < iTamButton; iI ++){
            if(1 == iPinsButton[iI]){
                PORTA_PCR1 |= 0x100;
            }else if(2 == iPinsButton[iI]){
                PORTA_PCR2 |= 0x100;
            }else if(3 == iPinsButton[iI]){
                PORTA_PCR4 |= 0x100;
            }else if(4 == iPinsButton[iI]){
                PORTA_PCR5 |= 0x100;
            }
        }
    }
}

void toggleLed(int iPin)
{
    switch (iPin)
    {
    case 1:
        GPIOA_PTOR |= LED1_MASK;
        break;
    case 2:
        GPIOA_PTOR |= LED2_MASK;
        break;
    case 3:
        GPIOA_PTOR |= LED3_MASK;
        break;
    case 4:
        GPIOA_PTOR |= LED4_MASK;
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
            GPIOA_PSOR|= LED1_MASK;
            break;
        case 2:
            GPIOA_PSOR|= LED2_MASK;
            break;
        case 3:
            GPIOA_PSOR|= LED3_MASK;
            break;
        case 4:
            GPIOA_PSOR|= LED4_MASK;
            break;
        };
    }
    else
    {
      switch(iPin)
      {
        case 1:
            GPIOA_PCOR|= LED1_MASK;
            break;
        case 2:
            GPIOA_PCOR|= LED2_MASK;
            break;
        case 3:
            GPIOA_PCOR|= LED3_MASK;
            break;
        case 4:
            GPIOA_PCOR|= LED4_MASK;
            break;
        };
    }
}

void ligaLed(int iPin){
    writeLed(iPin,1);
};

void desligaLed(int iPin){ 
    writeLed(iPin,0);
}

int readButton(int iPin){
    int iInput; /*32 bit number showing the inputs*/

    iInput = GPIOA_PDIR;

    /*configures iPin as 32 bit pinnage regarding it's button*/
    switch(iPin){
        case 1:
            iPin = BUTTON1_MASK;
        case 2:
            iPin = BUTTON2_MASK;
        case 3:
            iPin = BUTTON3_MASK;
        case 4:
            iPin = BUTTON4_MASK;
      }

    /*bit mask, returns 1 if bit is turned on, returns 0 otherwise*/
    switch(iInput & iPin){
      case 1:
        return(0);
      case 0:
        return(1);
    }
}
