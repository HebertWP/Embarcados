/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: File dedicated to the ES670 prototype projects  */
/*                   involving the FRDM-KL25Z board together with is */
/*                   daughter board containing more peripherals      */
/*                                                                   */
/*                   Processor MKL25Z128VLK4 characteristics         */
/*                   48 MHz ARM Cortex-M0+ core                      */
/*                   128 KB program flash memory                     */
/*                   16 KB SRAM                                      */
/*                   Voltage range: 1.71 to 3.6 V                    */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    02apr2020                                       */
/* Revision date:    03apr2020                                       */
/* ***************************************************************** */

/* our includes */
#include "ledSwi.h"

/* globals */
/* using the 1º,2º,4º led*/
int iLeds[2] = {1, 2};
int iNumLeds = 2;
/*using the 1º,3º,4º buttons*/
int iButtons[2] = {3 , 4};
int iNumButtons = 2;

/* ************************************************ */
/* Method name:        main                         */
/* Method description: system entry point           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int main(void)
{
    /* board initializations */
    /* initing GPIOS */
    initLedButton(iLeds, iNumLeds, iButtons, iNumButtons);

    /* main loop */
    while (1)
    {
        /* logic table on this example:
                t= toggle
                l= ligada
                d= desliga
            |Buttons|  led  |
            | 3 | 4 | 1 | 2 |
            | 0 | 0 | l | l |
            | 0 | 1 | t | t |
            | 1 | 0 | d | l |
            | 1 | 1 | l | d |
        */
        /*case | 0 | 0 | l | l |  */   
        if (!readButton(3) && !readButton(4))
        {
            ligaLed(1);
            ligaLed(2);
        };
        /*case | 0 | 1 | t | t |  */   
        if (!readButton(3) && readButton(4))
        {
            toggleLed(1);
            toggleLed(2);
        };
        /*case | 1 | 0 |d | l |  */   
        if (readButton(3) && !readButton(4))
        {
            desligaLed(1);
            ligaLed(2);
        };
        /*case | 1 | 0 | d | l |  */   
        if (readButton(3) && readButton(4))
        {
            ligaLed(1);
            desligaLed(2);
        };
        
        /* wait unknown time to next cicle off operation */
        for(int iI=0; iI <500000; iI++)
            for(int iY=0; iY <500000; iY++);
    }
}
