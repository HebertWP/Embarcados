/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Hebert Wandick / Caio Villela                   */
/* Creation date:    24/abri/2020                                    */
/* Revision date:    26/jul/2020                                     */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/*                 General uC definitions                 */
/*first clear the with bits and them rite on then*/
#define SET_BITS(OUTPUT, INPUT, NUM_BITS, TO_SHIFT) (OUTPUT = ((OUTPUT & (~((0XFFFFFFFFU >> (32 - NUM_BITS)) << TO_SHIFT))) | (INPUT << TO_SHIFT)))

/* Clock gate control */
#define CGC_CLOCK_DISABLED 0x00U /*Disable clock*/
#define CGC_CLOCK_ENABLED 0x01U  /*Enable clock*/

#define CGC_TMP0_TO_SHIFT 24U /*To byte 24*/

#define PORT_E_TO_SHIFT 13U /*Select byte to be turn on*/

#define PRESCALER_DIVEDE_BY_ONE 0b000U   /*Prescale Factor Selection, 110 Divide by 1*/
#define TPM_CMOD_RISING_EDGE_CONT 0b010U /*Conting at rising edge */

#define CONFIG_PORT_AS_EXTERNAL_CLOCK 0b100U /*100 Alternative 4 (chip-specific).*/
#define TPM_CLKIN0 0b0000U                   /*Selec TPM_CLKIN0 */

#define TPM0CLKSEL_TO_SHIFT 24U

#define TACHOMETER_PORTx_PCRn PORTE_PCR29 /*Tachmeter connect at portA pin 12*/
#define TACHOMETER_TPMx_CnSC TPM0_C2SC    /*Tachmeter connect at TPM1 on CH 1*/
#define TACHOMETER_TPMx_CnV TPM0_C2V      /*Tachmeter connect at TPM1 on CH 1*/
#define TACHOMETER_TPMx_SC TPM0_SC
#define TACHOMETER_TPMx_CNT TPM0_CNT /*cont pulses at tachometer*/
#define TACHOMETER_TPMx_CNT_CLEAR 0x0000U

#endif /* SOURCES_BOARD_H_ */
