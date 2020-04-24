/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Hebert Wandick / Caio Villela                   */
/* Creation date:    24bri2020                                      */
/* Revision date:    24abri2020                                      */
/* ***************************************************************** */
#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/*                 General uC definitions                 */
/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

#define TURN_ON_BITS(OUTPUT, INPUT, TO_SHIFT)               (OUTPUT |= INPUT << TO_SHIFT)
#define TURN_OFF_BITS(OUTPUT, INPUT,TO_SHIFT)               (OUTPUT &= 0XFFFFFFFFU  ^ ( INPUT<< TO_SHIFT))

#define COLLOERFAN_BASE_PNT                PORTA                                   /* peripheral port base pointer */
#define COLLOERFAN_GPIO_BASE_PNT           PTA                                     /* peripheral gpio base pointer */
#define COLLOERFAN_PORTx_PCRn			PORTA_PCR13

#define HEADER_BASE_PNT                PORTA                                   /* peripheral port base pointer */
#define HEADER_GPIO_BASE_PNT           PTA                                     /* peripheral gpio base pointer */
#define HEADER_PORTx_PCRn			PORTA_PCR12

#define COLLOERFAN_TPMx_CnSC TPM1_C0SC
#define HEADER_TPMx_CnSC TPM1_C1SC

#define COLLOERFAN_TPMx_CnV TPM1_C0V
#define HEADER_TPMx_CnV TPM1_C1V

#endif /* SOURCES_BOARD_H_ */
