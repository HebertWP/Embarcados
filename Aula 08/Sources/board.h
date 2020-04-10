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

#define BUTTON1_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON1_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON1_PIN	         (uint32_t) 1u
#define BUTTON1_MASK            0x02

#define BUTTON2_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON2_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON2_PIN	         (uint32_t) 2u
#define BUTTON2_MASK            0x04

#define BUTTON3_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON3_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON3_PIN	         (uint32_t) 4u
#define BUTTON3_MASK            0x10

#define BUTTON4_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define BUTTON4_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define BUTTON4_PIN	         (uint32_t) 5u
#define BUTTON4_MASK            0x20

#define LED1_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED1_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED1_PIN	         (uint32_t) 1u
#define LED1_MASK            0x02

#define LED2_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED2_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED2_PIN	         (uint32_t) 2u
#define LED2_MASK            0x04

#define LED3_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED3_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED3_PIN	         (uint32_t) 4u
#define LED3_MASK            0x10

#define LED4_PORT_BASE_PNT   PORTA /* peripheral port base pointer */
#define LED4_GPIO_BASE_PNT   PTA   /* peripheral gpio base pointer */
#define LED4_PIN	         (uint32_t) 5u
#define LED4_MASK            0x20

#endif /* SOURCES_BOARD_H_ */
