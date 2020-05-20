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

#endif /* SOURCES_BOARD_H_ */
