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

#define BUTTON1_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON1_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON1_PIN	         (uint32_t) 1u

#define BUTTON2_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON2_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON2_PIN	         (uint32_t) 2u

#define BUTTON3_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON3_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON3_PIN	         (uint32_t) 4u

#define BUTTON4_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON4_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON4_PIN	         (uint32_t) 5u
<<<<<<< HEAD
=======

#define LED1_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED1_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED1_PIN	         (uint32_t) 1u

#define LED2_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED2_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED2_PIN	         (uint32_t) 2u

#define LED3_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED3_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED3_PIN	         (uint32_t) 4u

#define LED4_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED4_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED4_PIN	         (uint32_t) 5u

>>>>>>> d02c7548758c9d95d3025b069445600973431836
#endif /* SOURCES_BOARD_H_ */
