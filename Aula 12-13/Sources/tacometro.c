/* ***************************************************************** */
/* File name:        tacometro.c  		                             */
/* File description: File containing the implementation of functions */
/*                   used to control the tacometro			         */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    08/may/2020                                     */
/* Revision date:    08/may/2020                                     */
/* ***************************************************************** */

/*my  includes*/
#include "board.h"
#include "tacometro.h"

/*system include*/
#include "fsl_clock_manager.h"

/* ************************************************ */
/* Method name:        tachometer_init              */
/* Method description: Initialize coolerfan			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void tachometer_init(void)
{
    /* 1- un-gateport TPM1 clock*/
    SET_BITS(SIM_SCGC6, CGC_CLOCK_ENABLED, 1, CGC_TMP0_TO_SHIFT);

    /*2- Prescale Factor Select at TPM1_SC on bytes 2-0*/
    SET_BITS(TACHOMETER_TPMx_SC, PRESCALER_DIVEDE_BY_ONE, 3, 0);

    /*3- un-gateport A clock*/
    SET_BITS(SIM_SCGC5, CGC_CLOCK_ENABLED, 1, PORT_E_TO_SHIFT);

    /*4- Config port as PWM port */
    SET_BITS(TACHOMETER_PORTx_PCRn, CONFIG_PORT_AS_EXTERNAL_CLOCK, 3, 8);

    /*5- Select with pin external (TPM_CLKIN0) will be use as input */
    SET_BITS(SIM_SOPT4, TPM_CLKIN0, 1, TPM0CLKSEL_TO_SHIFT);

    /*6- config  the TPM's timer to increment in external clock rising edge */
    SET_BITS(TACHOMETER_TPMx_SC, CMDO_RISING_EDGE_CONT, 2, 3);
}

/* ************************************************ */
/* Method name:        tachometer_readSensor        */
/* Method description: read cooler speed 			*/
/* Input params:       uiPeriod the period of		*/
/*  				   measurement 					*/
/* Output params:      cooler speed in RPM          */
/* ************************************************ */
unsigned int tachometer_readSensor(unsigned int uiPeriod)
{
    return 0;
}
