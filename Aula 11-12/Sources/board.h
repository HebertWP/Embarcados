/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Hebert Wandick / Caio Villela                   */
/* Creation date:    24bri2020                                      */
/* Revision date:    25abri2020                                      */
/* ***************************************************************** */
#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/*                 General uC definitions                 */

#define SET_BITS(OUTPUT, INPUT, NUM_BITS, TO_SHIFT)               (OUTPUT = ((OUTPUT & ( ~( (0XFFFFFFFFU  >> (32 - NUM_BITS)) << TO_SHIFT) ) ) | (INPUT << TO_SHIFT)) )

/* Clock gate control */
#define  CGC_CLOCK_DISABLED     0x00U       /*Disable clock*/
#define  CGC_CLOCK_ENABLED		0x01U       /*Enable clock*/
#define PORT_A_TO_SHIFT			0x09U       /*Select byte to be turn on*/

#define PRESCALER				0b110U		/*Prescale Factor Selection, 110 Divide by 64*/
#define TPM_CLOCK				0b11U		/*TPM clock source select, 11 MCGIRCLK clock (32KHz)*/
#define TPM_CMOD				0b01U		/*Clock Mode Selection *,01 LPTPM counter increments on every LPTPM counter clock */
#define TPM_CPWMS				0b0U		/*Center-aligned PWM Select,0 LPTPM counter operates in up counting mode.*/
#define TPM_MOD					49U			/*Counting 50 pulses*/
#define TPM_MSnx				0b10U		/*Edge-aligned PWM*/
#define TPM_ELSnx				0b10U		/*High-true pulses (clear Output on match, set Output on reload)*/
#define CONFIG_PORT_AS_PWM		0b011U		/*011 Alternative 3 (chip-specific).*/

#define COOLERFAN_PORTx_PCRn	PORTA_PCR13 /*Cooler connect at portA pin 13*/
#define COOLERFAN_TPMx_CnSC 	TPM1_C0SC   /*Cooler connect at TPM1 on CH 0*/
#define COOLERFAN_TPMx_CnV 	TPM1_C0V    /*Cooler connect at TPM1 on CH 0*/

#define HEADER_PORTx_PCRn		PORTA_PCR12 /*Header connect at portA pin 12*/
#define HEADER_TPMx_CnSC 		TPM1_C1SC   /*Header connect at TPM1 on CH 1*/
#define HEADER_TPMx_CnV 		TPM1_C1V    /*Header connect at TPM1 on CH 1*/

#endif /* SOURCES_BOARD_H_ */
