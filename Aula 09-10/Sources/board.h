/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Hebert Wandick / Caio Villela                   */
/* Creation date:    09abri2020                                      */
/* Revision date:    09abri2020                                      */
/* ***************************************************************** */
#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U

/* 7 seg display definitions */
#define 7_SEG_BASE_PNT                PORTC                                   /* peripheral port base pointer */
#define 7_SEG_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */


#define 7_SEG_A_PIN                  (GPIO_OUTPUT << LCD_RS_PIN)
#define 7_SEG_B_PIN
#define 7_SEG_C_PIN
#define 7_SEG_D_PIN
#define 7_SEG_E_PIN
#define 7_SEG_F_PIN
#define 7_SEG_G_PIN
#define 7_SEG_DP_PIN





#endif /* SOURCES_BOARD_H_ */
