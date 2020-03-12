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
#include "util.h"
#include "mcg.h"
#include "ledrgb.h"
#include "buttons.h"

/* globals */
static unsigned char cLedColor = 0;                 /* stores the current RGB led color */

/* ************************************************ */
/* Method name:        boardInit                    */
/* Method description: main board all needed        */
/*                     initializations              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void boardInit(void)
{
	/* fist of all, clock configuration and initialization */
	mcg_clockInit();

	/* RGB LED initialization */
	ledrgb_init();
	buttons_init();

}



/* ************************************************ */
/* Method name:        main                         */
/* Method description: system entry point           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
int main(void)
{
	/* board initializations */
	boardInit();

	/* main loop */
    while (1){
		/* sets the RGB led color */
        if(button_read()==1){
        	ledrgb_write(cLedColor);

        	/* increments the ledColor from 0 to 7 */
        	if(++cLedColor>7)
			cLedColor = 0;

        	/* wait 100ms doing anything! */
        	util_genDelay1000ms();
        }

    }
}
