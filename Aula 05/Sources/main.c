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
#include "ledSwit.h"

/* globals */
int iLeds[3] = {1, 2, 4};
int iNumLeds = 3;
int iButtons[2] = {1, 3, 4};
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
	initLedButton(ILeds, iNumLeds, iButtons, iNumButtons);

	/* main loop */
	while (1)
	{
		/* sets the RGB led color */
		if (readButton(1))
		{
			ligaLed(1);
		};
		if (readButton(3))
		{
			ligaLed(2);
		};
		if (readButton(3) && readButton(1))
		{
			ligaLed(4);
		};

		if (!readButton(3) && !readButton(1))
		{
			desligaLed(1);
			desligaLed(2);
			desligaLed(4);
		};

		if (readButton(4))
		{
			toggleLed(1);
			toggleLed(2);
			toggleLed(4);
		};
		/* wait 1000ms doing anything! */
		util_genDelay1000ms();
	}
}
