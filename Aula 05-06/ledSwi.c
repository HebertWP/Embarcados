/* ***************************************************************** */
/* File name:        ledSwi.c                                        */
/* File description: This file implements the functions needed to    */
/*                   initialize, switch in between and operate red   */
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


int readButton(int iPin);

void ligaLed(int iPin);

void desligaLed(int iPin);

void toggleLed(int iPin);

void writeLed(int iPin, int iNivel);




#define
