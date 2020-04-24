/* ************************************************ */
/* Method name:        PWM_init	                    */
/* Method description: Initialize PWM				*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */

#include "board.h"

#include "fsl_clock_manager.h"

void PWM_init(void){
	/*un-gateport C clock*/
	SIM_SCGC5 |= 0x0800;

	/*un-gateport C clock*/
	TURN_ON_BITS(SIM_SCGC6, 0b01U, 25);

	/*Prescale Factor Selection, 110 Divide by 64*/
	TURN_OFF_BITS(TPM1_SC,0b111U, 0);
	TURN_ON_BITS(TPM1_SC, 0b110U, 0);

	/*TPM clock source select, 11 MCGIRCLK clock (32KHz)*/
	TURN_ON_BITS(SIM_SOPT2, 0b011U, 24);

	/*Clock Mode Selection *,01 LPTPM counter increments on every LPTPM counter clock */
	TURN_OFF_BITS(TPM1_SC,0b11U, 3);
	TURN_ON_BITS(TPM1_SC, 0b01U, 3);
	/*Center-aligned PWM Select,0 LPTPM counter operates in up counting mode.*/
	TURN_OFF_BITS(TPM1_SC,0b01U, 5);

	TURN_OFF_BITS(TPM1_MOD,0xFFFFU, 0);
	TURN_ON_BITS(TPM1_MOD, 49U, 0);

	TURN_OFF_BITS(TPM1_MOD,0xFFFFU, 0);
	TURN_ON_BITS(TPM1_MOD, 49U, 0);
}

/* ************************************************ */
/* Method name:        coolerfan_init               */
/* Method description: Initialize coolerfan			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void coolerfan_init(void){
	TURN_OFF_BITS(COLLOERFAN_TPMx_CnSC,0b11U, 4);
	TURN_ON_BITS(COLLOERFAN_TPMx_CnSC, 0b10u, 4);

	TURN_ON_BITS(COLLOERFAN_PORTx_PCRn, 0b11U, 8);
}

/* ************************************************ */
/* Method name:        heater_init		            */
/* Method description: Initialize heater			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void heater_init(void){
	TURN_OFF_BITS(COLLOERFAN_TPMx_CnSC,0xFFFFFFFFU, 4);
	TURN_ON_BITS(COLLOERFAN_TPMx_CnSC, 0b10u, 4);

	TURN_ON_BITS(	HEADER_PORTx_PCRn, 0b11U, 8);
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
	TURN_OFF_BITS(COLLOERFAN_TPMx_CnV, 0xFFFFFFFFU, 0);
	TURN_ON_BITS(COLLOERFAN_TPMx_CnV, (unsigned int)fCoolerDuty*50, 0);
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
	TURN_OFF_BITS(HEADER_TPMx_CnV, 0xFFFFFFFFU, 0);
	TURN_ON_BITS(HEADER_TPMx_CnV, (unsigned int)fHeaterDuty*50, 0);
}
