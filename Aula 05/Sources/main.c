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
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

/* our includes */
#include "ledSwi.h"

/* globals */
/* using the 1º,2º,4º led*/
int iLeds[3] = {1, 2, 4};
int iNumLeds = 3;
/*using the 1º,3º,4º buttons*/
int iButtons[3] = {1, 3, 4};
int iNumButtons = 3;

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
            | Buttons|  led   |
            |1 |3 |4 |1 |2 |4 |
            |0 |0 |0 |l |d |d |
            |0 |0 |1 |t |t |t |
            |0 |1 |0 |d |l |d |
            |0 |1 |1 |t |t |t |
            |1 |0 |0 |d |d |l |
            |1 |0 |1 |t |t |t |
            |1 |1 |0 |l |l |l |
            |1 |1 |1 |d |d |d |
        */
        /*case |0 |0 |0 |l |d |d |  */   
        if (!readButton(1) && !readButton(3) && !readButton(3))
        {
            ligaLed(1);
            desligaLed(2);
            desligaLed(4);
        };
        /*case |0 |0 |1 |t |t |t |  */   
        if (!readButton(1) && !readButton(3) && readButton(4))
        {
            toggleLed(1);
            toggleLed(2);
            toggleLed(4);
        };
        /*case |0 |1 |0 |d |l |d |  */   
        if (!readButton(1) && readButton(3) && !readButton(3))
        {
            desligaLed(1);
            ligaLed(2);
            desligaLed(4);
        };
        /*case |0 |1 |1 |t |t |t |  */   
        if (!readButton(1) && readButton(3) && readButton(4))
        {
            toggleLed(1);
            toggleLed(2);
            toggleLed(4);
        };
        /*case |1 |0 |0 |d |d |l |  */   
        if (readButton(1) && !readButton(3) && !readButton(3))
        {
            desligaLed(1);
            desligaLed(2);
            ligaLed(4);
        };
        /*case |1 |0 |1 |t |t |t |  */   
        if (readButton(1) && !readButton(3) && readButton(4))
        {
            toggleLed(1);
            toggleLed(2);
            toggleLed(4);
        };
        /*case |1 |1 |0 |l |l |l |  */   
        if (readButton(1) && readButton(3) && !readButton(3))
        {
            ligaLed(1);
            ligaLed(2);
            ligaLed(4);
        };
        /*case |1 |1 |1 |d |d |d |  */   
        if (readButton(1) && readButton(3) && readButton(3))
        {
            desligaLed(1);
            desligaLed(2);
            desligaLed(4);
        };

        /* wait unknown time to next cicle off operation */
        for(int iI=0; iI <500000; iI++);
    }
}
