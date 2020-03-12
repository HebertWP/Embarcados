/* ***************************************************************** */
/* File name:        board.h                                         */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/*                                                                   */
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_BOARD_H_
#define SOURCES_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/* FDRMKL25Z RGB LED pins defintions */
#define RED_LED_PORT_BASE_PNT    PORTB /* peripheral port base pointer */
#define RED_LED_GPIO_BASE_PNT    PTB   /* peripheral gpio base pointer */
#define RED_LED_PIN		         (uint32_t) 18u
#define GREEN_LED_PORT_BASE_PNT  PORTB /* peripheral port base pointer */
#define GREEN_LED_GPIO_BASE_PNT  PTB   /* peripheral gpio base pointer */
#define GREEN_LED_PIN	         (uint32_t) 19u
#define BLUE_LED_PORT_BASE_PNT   PORTB /* peripheral port base pointer */
#define BLUE_LED_GPIO_BASE_PNT   PTB   /* peripheral gpio base pointer */
#define BLUE_LED_PIN	         (uint32_t) 1u

#define BUTTON_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON_PIN	         (uint32_t) 4u
#endif /* SOURCES_BOARD_H_ */
