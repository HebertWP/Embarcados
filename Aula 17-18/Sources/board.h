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

/*state machine constants*/
#define IDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define FLOAT_VALUE '5'
#define BUTTON_VALUE '6'
#define SET_VALUE '7'

#define MAX_VALUE_LENGTH 3

#endif /* SOURCES_BOARD_H_ */
