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

/* General uC definitions */

/* Clock gate control */
#define CGC_CLOCK_DISABLED 0x00U
#define CGC_CLOCK_ENABLED 0x01U

/* GPIO input / output */
#define GPIO_INPUT 0x00U
#define GPIO_OUTPUT 0x01U

/* LCD definitions */

/* LCD Register Selector
* Used as register selector input
* When (LCD_RS = LCD_RS_HIGH) =&gt; DATA register is selected
* When (LCD_RS = LCD_RS_LOW) =&gt; INSTRUCTION register is selected
*/
#define LCD_PORT_BASE_PNT PORTC
/* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT PTC
/* peripheral gpio base pointer */

#define LCD_RS_PIN 8U
/* register selector */
#define LCD_RS_DIR (GPIO_OUTPUT &lt;&lt; LCD_RS_PIN)
#define LCD_RS_ALT kPortMuxAsGpio
#define LCD_ENABLE_PIN 9U
/* enable pin */
//#define LCD_ENABLE_DIR (GPIO_OUTPUT &lt;&lt; LCD_ENABLE_PIN)
#define LCD_ENABLE_ALT kPortMuxAsGpio
#define LCD_RS_HIGH 1U
#define LCD_RS_DATA LCD_RS_HIGH
#define LCD_RS_LOW 0U
#define LCD_RS_CMD LCD_RS_LOW
#define LCD_ENABLED 1U
#define LCD_DISABLED 0U
#define LCD_DATA_DIR kGpioDigitalOutput
/* LCD data pins */
#define LCD_DATA_ALT kPortMuxAsGpio
#define LCD_DATA_DB0_PIN 0u
#define LCD_DATA_DB1_PIN 1u
#define LCD_DATA_DB2_PIN 2u
#define LCD_DATA_DB3_PIN 3U
#define LCD_DATA_DB4_PIN 4U
#define LCD_DATA_DB5_PIN 5U
#define LCD_DATA_DB6_PIN 6U
#define LCD_DATA_DB7_PIN 7U
#define LCD_DATA_DB0_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB0_PIN)
#define LCD_DATA_DB1_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB1_PIN)
#define LCD_DATA_DB2_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB2_PIN)
#define LCD_DATA_DB3_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB3_PIN)
#define LCD_DATA_DB4_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB4_PIN)
#define LCD_DATA_DB5_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB5_PIN)
#define LCD_DATA_DB6_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB6_PIN)
#define LCD_DATA_DB7_DIR (GPIO_OUTPUT &lt;&lt; LCD_DATA_DB7_PIN)
/* END OF LCD definitions */

#endif /* SOURCES_BOARD_H_ */
