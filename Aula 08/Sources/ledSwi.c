/* ***************************************************************** */
/* File name:        ledSwi.c                                        */
/* File description: This file implements the functions needed to    */
/*                   initialize, switch in between and operate RGB   */
/*                   leds and buttons                                */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    02apr2020                                       */
/* Revision date:    03apr2020                                       */
/* ***************************************************************** */

/* our includes */
#include "board.h"
#include "ledSwi.h"


/* **************************************************** */
/* Method name:        initLedButton                    */
/* Method description: Initializes selected Leds        */
/*                     and Buttons as GPIO and sets     */
/*                     them as digital output/input     */
/* Input params:       int* iPinsLed - array containing */
/*                     numbers of leds to be initialized*/
/*                     int iTamLed - size of that array */
/*                     int* iPinsButton-same for buttons*/
/*                     int iTamButton - same for buttons*/
/* Output params:      n/a                              */
/* **************************************************** */
void initLedButton(int *iPinsLed, int iTamLed,int *iPinsButton, int iTamButton){
    int iI = 0; /*integer iterator*/

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

/* **************************************************** */
/* Method name:        toggleLed                        */
/* Method description: toggles digital output           */
/* Input params:       int iPin - tells what led is to  */
/*                     be initialized                   */
/* Output params:      n/a                              */
/* **************************************************** */
void toggleLed(int iPin)
{
    /* toggle PTAx*/
    /* PTOR : Port Toggle Output Register */
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

/* **************************************************** */
/* Method name:        writeLed                         */
/* Method description: writes 1 or 0 on digital output  */
/* Input params:       int iPin - tells what led is to  */
/*                     be written on                    */
/*                     int iNivel - what level is to be */
/*                     written                          */
/* Output params:      n/a                              */
/* **************************************************** */
void writeLed(int iPin, int iNivel)
{
    /* set PTAx*/
    /* PSOR : Port Set Output Register */
    /* GPIOA_PSOR |= turn HIGH the correponting output pin */
    /* GPIOA_PCOR |= turn LOW the correponting output pin */
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

/* **************************************************** */
/* Method name:        ligaLed                          */
/* Method description: turns on Led                     */
/* Input params:       int iPin - tells what led is to  */
/*                     be turned on                     */
/* Output params:      n/a                              */
/* **************************************************** */
void ligaLed(int iPin){
    /*call the function responsible by set set pin output level to HIGH*/
    writeLed(iPin,1);
};


/* **************************************************** */
/* Method name:        desligaLed                       */
/* Method description: turns Led off                    */
/* Input params:       int iPin - tells what led is to  */
/*                     be turned off                    */
/* Output params:      n/a                              */
/* **************************************************** */

void desligaLed(int iPin){
    /*call the function responsible by set set pin output level to LOW*/
    writeLed(iPin,0);
}


/* **************************************************** */
/* Method name:        readButton                       */
/* Method description: reads logical level on selected  */
/*                     button                           */
/* Input params:       int iPin - tells what button is  */
/*                     to be read                       */
/* Output params:      n/a                              */
/* **************************************************** */
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

    /*bit mask, returns 1 if bit is turned off, returns 0 otherwise*/
    switch(iInput & iPin){
      case 1:
        return(0);
      case 0:
        return(1);
    }
    return 0;
}
