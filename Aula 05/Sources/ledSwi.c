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

void initLedButton(int *iPinsLed, int iTamLed,int *iPinsButton, int iTamButton){
    int iI = 0; /*integer iterator*/
    uint32_t uiLedPins; /*selected led pins are 1*/
    uint32_t uiButtonPins; /*selected button pins are 1*/

    /*un-gateport A clock*/
    SIM_SCGC5|=0x200;

    /*initialize selected Leds as GPIO and set them as digital output*/
    if(iTamLed != 0){
        for(iI = 0; iI < iTamLed; iI ++;){
            if(1 == iPinsLed[i]){
                PORTA_PCR1 |= 0x100
                GPIOA_PDDR |= LED1_PIN
            }else if(2 == iPinsLed[i]){
                PORTA_PCR2 |= 0x100
                GPIOA_PDDR |= LED2_PIN
            }else if(3 == iPinsLed[i]){
                PORTA_PCR4 |= 0x100
                GPIOA_PDDR |= LED3_PIN
            }else if(4 == iPinsLed[i]){
                PORTA_PCR5 |= 0x100
                GPIOA_PDDR |= LED4_PIN
            }
        }


    }


    /*initialize selected buttons as GPIO and set them as digital input*/
    if(iTamButton != 0){
        for(iI = 0; iI < iTamButton; iI ++;){
            if(1 == iPinsButton[i]){
                PORTA_PCR1 |= 0x100
                GPIOA_PDDR |= (uint32_t) 0u
            }else if(2 == iPinsButton[i]){
                PORTA_PCR2 |= 0x100
                GPIOA_PDDR |= (uint32_t) 0u
            }else if(3 == iPinsButton[i]){
                PORTA_PCR4 |= 0x100
                GPIOA_PDDR |= (uint32_t) 0u
            }else if(4 == iPinsButton[i]){
                PORTA_PCR5 |= 0x100
                GPIOA_PDDR |= (uint32_t) 0u
            }
        }
    }
}

void toggleLed(int iPin)
{
    switch (iPin)
    {
    case 1:
        GPIOA_PTOR |= LED1_PIN;
        break;
    case 2:
        GPIOA_PTOR |= LED2_PIN;
        break;
    case 3:
        GPIOA_PTOR |= LED3_PIN;
        break;
    case 4:
        GPIOA_PTOR |= LED4_PIN;
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
            GPIOA_PSOR|=LED1_PIN;
            break;
        case 2:
            GPIOA_PSOR|=LED2_PIN;
            break;
        case 3:
            GPIOA_PSOR|=LED3_PIN;
            break;
        case 4:
            GPIOA_PSOR|=LED4_PIN;
            break;
        };
    }
    else
    {
        case 1:
            GPIOA_PCOR|=LED1_PIN;
            break;
        case 2:
            GPIOA_PCOR|=LED2_PIN;
            break;
        case 3:
            GPIOA_PCOR|=LED3_PIN;
            break;
        case 4:
            GPIOA_PCOR|=LED4_PIN;
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
        GPIOA_PDIR |= BUTTON1_PIN;
        break;
    case 2:
        GPIOA_PDIR |= BUTTON2_PIN;
        break;
    case 3:
        GPIOA_PDIR |= BUTTON3_PIN;
        break;
    case 4:
        GPIOA_PDIR |= BUTTON4_PIN;
        break;
}
