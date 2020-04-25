/* ************************************************ */
/* Method name:        PWM_init	                    */
/* Method description: Initialize PWM				*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

#include "board.h"
#include "aquecedorECooler.h"
#include "fsl_clock_manager.h"

void PWM_init(void){
	/*un-gateport A clock*/
	SET_BITS(SIM_SCGC5, CGC_CLOCK_ENABLED, 1, PORT_A_TO_SHIFT);

	/*un-gateport C clock*/
	SET_BITS(SIM_SCGC6, CGC_CLOCK_ENABLED, 1, 25);

	/*Prescale Factor Selection, 110 Divide by 64*/
	SET_BITS(TPM1_SC, PRESCALER, 3, 0);

	/*TPM clock source select, 11 MCGIRCLK clock (32KHz)*/
	SET_BITS(SIM_SOPT2, TPM_CLOCK, 2, 24);

	/*Clock Mode Selection *,01 LPTPM counter increments on every LPTPM counter clock */
	SET_BITS(TPM1_SC, TPM_CMOD, 2, 3);

	/*Center-aligned PWM Select,0 LPTPM counter operates in up counting mode.*/
	SET_BITS(TPM1_SC, TPM_CPWMS, 1, 5);

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
	SET_BITS(COLLOERFAN_TPMx_CnSC, TPM_MSnx, 2, 4);
	SET_BITS(COLLOERFAN_TPMx_CnSC, TPM_ELSnx, 2, 2);

	SET_BITS(COLLOERFAN_PORTx_PCRn, CONFIG_PORT_AS_PWM, 3, 8);
	coolerfan_PWMDuty(0);
}

/* ************************************************ */
/* Method name:        heater_init		            */
/* Method description: Initialize heater			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void heater_init(void){
	SET_BITS(HEADER_TPMx_CnSC, TPM_MSnx, 2, 4);
	SET_BITS(HEADER_TPMx_CnSC, TPM_ELSnx, 2, 2);

	SET_BITS(	HEADER_PORTx_PCRn, CONFIG_PORT_AS_PWM, 3, 8);
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
	SET_BITS(COLLOERFAN_TPMx_CnV, (unsigned int)fCoolerDuty*50, 16, 0);
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
	SET_BITS(HEADER_TPMx_CnV, (unsigned int)fHeaterDuty*50, 16, 0);
}
