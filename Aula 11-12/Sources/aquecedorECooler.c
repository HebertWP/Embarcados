/* ***************************************************************** */
/* File name:        aquecedorECooler.c                              */
/* File description: File containing the implementation of functions */
/*                   used to control the CoolerFan and Header        */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    21/apr/2020                                     */
/* Revision date:    24/apr/2020                                     */
/* ***************************************************************** */

/*my  includes*/
#include "board.h"

/*system include*/
#include "aquecedorECooler.h"
#include "fsl_clock_manager.h"

/* ************************************************ */
/* Method name:        PWM_init	                    */
/* Method description: Initialize PWM				*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void PWM_init(void){
    /*un-gateport A clock*/
    SET_BITS(SIM_SCGC5, CGC_CLOCK_ENABLED, 1, PORT_A_TO_SHIFT);

    /*un-gateport TPM1 clock*/
    SET_BITS(SIM_SCGC6, CGC_CLOCK_ENABLED, 1, 25);

    /*Prescale Factor Select at TPM1_SC on bytes 2-0*/
    SET_BITS(TPM1_SC, PRESCALER, 3, 0);

    /*TPM clock source select at SIM_SOPT2 on bytes 24-25*/
    SET_BITS(SIM_SOPT2, TPM_CLOCK, 2, 24);

    /*Clock Mode Selection at TPM1_SC on bytes 3-4*/
    SET_BITS(TPM1_SC, TPM_CMOD, 2, 3);

    /*Center-aligned PWM Select,0 LPTPM counter operates in up counting mode.*/
    SET_BITS(TPM1_SC, TPM_CPWMS, 1, 5);

    /**/
    /*Counting 50 pulses*/
    SET_BITS(TPM1_MOD, TPM_MOD, 16, 0);
}

/* ************************************************ */
/* Method name:        coolerfan_init               */
/* Method description: Initialize coolerfan			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void coolerfan_init(void){
    /*Set MSnA:MSnB and ELSnA:ELSnB*/
    SET_BITS(COOLERFAN_TPMx_CnSC, TPM_MSnx, 2, 4);
    SET_BITS(COOLERFAN_TPMx_CnSC, TPM_ELSnx, 2, 2);

    /*Config port as PWM port */
    SET_BITS(COOLERFAN_PORTx_PCRn, CONFIG_PORT_AS_PWM, 3, 8);
    coolerfan_PWMDuty(0);
}

/* ************************************************ */
/* Method name:        heater_init		            */
/* Method description: Initialize heater			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void heater_init(void){
    /*Set MSnA:MSnB and ELSnA:ELSnB*/
    SET_BITS(HEADER_TPMx_CnSC, TPM_MSnx, 2, 4);
    SET_BITS(HEADER_TPMx_CnSC, TPM_ELSnx, 2, 2);

    /*Config port as PWM port */
    SET_BITS(HEADER_PORTx_PCRn, CONFIG_PORT_AS_PWM, 3, 8);
    heater_PWMDuty(0);
}

/* ************************************************ */
/* Method name:        coolerfan_PWMDuty            */
/* Method description: set the coolerfan speed		*/
/* Input params:       fCoolerDuty how many 		*/
/* 					   percentage time the cooler 	*/
/* 					   will be in high				*/
/* Output params:      n/a                          */
/* ************************************************ */
void coolerfan_PWMDuty(float fCoolerDuty){
	/*reset the TPM1 */
	SET_BITS(TPM1_CNT,0x00,16,0);

	SET_BITS(COOLERFAN_TPMx_CnV, (unsigned int)(fCoolerDuty*49), 16, 0);
}

/* ************************************************ */
/* Method name:        heater_PWMDuty	            */
/* Method description: set the heater power			*/
/* Input params:       fHeaterDuty how many 		*/
/* 					   percentage time the cooler 	*/
/* 					   will be in high				*/
/* Output params:      n/a                          */
/* ************************************************ */
void heater_PWMDuty(float fHeaterDuty){
	/*reset the TPM1 */
	SET_BITS(TPM1_CNT,0x00,16,0);

	SET_BITS(HEADER_TPMx_CnV, (unsigned int)(fHeaterDuty*49), 16, 0);
}
