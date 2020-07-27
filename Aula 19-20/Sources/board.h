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


/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

#define SET_BITS(OUTPUT, INPUT, NUM_BITS, TO_SHIFT)               (OUTPUT = ((OUTPUT & ( ~( (0XFFFFFFFFU  >> (32 - NUM_BITS)) << TO_SHIFT) ) ) | (INPUT << TO_SHIFT)) )

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

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U

/*                 LCD definitions                 */

/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define LCD_PORT_BASE_PNT           PORTC                                   /* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */

#define LCD_RS_PIN                  8U                                      /* register selector */
#define LCD_RS_DIR                  (GPIO_OUTPUT << LCD_RS_PIN)
#define LCD_RS_ALT                  kPortMuxAsGpio

#define LCD_ENABLE_PIN              9U                                      /* enable pin */
#define LCD_ENABLE_DIR              (GPIO_OUTPUT << LCD_ENABLE_PIN)
#define LCD_ENABLE_ALT              kPortMuxAsGpio

#define LCD_RS_HIGH                 1U
#define LCD_RS_DATA                 LCD_RS_HIGH

#define LCD_RS_LOW                  0U
#define LCD_RS_CMD                  LCD_RS_LOW

#define LCD_ENABLED                 1U
#define LCD_DISABLED                0U

#define LCD_DATA_DIR                kGpioDigitalOutput                      /* LCD data pins */
#define LCD_DATA_ALT                kPortMuxAsGpio

#define LCD_DATA_DB0_PIN            0u
#define LCD_DATA_DB1_PIN            1u
#define LCD_DATA_DB2_PIN            2u
#define LCD_DATA_DB3_PIN            3U
#define LCD_DATA_DB4_PIN            4U
#define LCD_DATA_DB5_PIN            5U
#define LCD_DATA_DB6_PIN            6U
#define LCD_DATA_DB7_PIN            7U

#define LCD_DATA_DB0_DIR            (GPIO_OUTPUT << LCD_DATA_DB0_PIN)
#define LCD_DATA_DB1_DIR            (GPIO_OUTPUT << LCD_DATA_DB1_PIN)
#define LCD_DATA_DB2_DIR            (GPIO_OUTPUT << LCD_DATA_DB2_PIN)
#define LCD_DATA_DB3_DIR            (GPIO_OUTPUT << LCD_DATA_DB3_PIN)
#define LCD_DATA_DB4_DIR            (GPIO_OUTPUT << LCD_DATA_DB4_PIN)
#define LCD_DATA_DB5_DIR            (GPIO_OUTPUT << LCD_DATA_DB5_PIN)
#define LCD_DATA_DB6_DIR            (GPIO_OUTPUT << LCD_DATA_DB6_PIN)
#define LCD_DATA_DB7_DIR            (GPIO_OUTPUT << LCD_DATA_DB7_PIN)
/*                 END OF LCD definitions                 */

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*	TEMPERATURE SENSOR DIEODE DEFINITONS */
#define THERMOMETER_PORT_BASE_PNT 	PORTE		/*peripheral port base pointer */
#define THERMOMETER_GPIO_BASE_PNT 	PTE		/*peripheral gpio base pointer */
#define THERMOMETER_PIN				21U		/*THERMOMETER PIN */
#define THERMOMETER_DIR				(GPIO_INPUT << TERMOMETER_PIN)
#define THERMOMETER_ALT				0X00u

/*		END OF TERMPERATURE SENSOR DIODE DEFINITONS */

#endif /* SOURCES_BOARD_H_ */
