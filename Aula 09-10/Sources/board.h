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
#define DISPLAY_BASE_PNT                PORTC                                   /* peripheral port base pointer */
#define DISPLAY_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */

/*pins*/
#define DISPLAY_A_PIN                   0U
#define DISPLAY_B_PIN                   1U
#define DISPLAY_C_PIN                   2U
#define DISPLAY_D_PIN                   3U
#define DISPLAY_E_PIN                   4U
#define DISPLAY_F_PIN                   5U
#define DISPLAY_G_PIN                   6U
#define DISPLAY_DP_PIN                  7U

#define DISPLAY_D1_PIN                  13U
#define DISPLAY_D2_PIN                  12U
#define DISPLAY_D3_PIN                  11U
#define DISPLAY_D4_PIN                  10U

/*directories*/
#define DISPLAY_A_DIR                  (GPIO_OUTPUT << DISPLAY_A_PIN)
#define DISPLAY_B_DIR                  (GPIO_OUTPUT << DISPLAY_B_PIN)
#define DISPLAY_C_DIR                  (GPIO_OUTPUT << DISPLAY_C_PIN)
#define DISPLAY_D_DIR                  (GPIO_OUTPUT << DISPLAY_D_PIN)
#define DISPLAY_E_DIR                  (GPIO_OUTPUT << DISPLAY_E_PIN)
#define DISPLAY_F_DIR                  (GPIO_OUTPUT << DISPLAY_F_PIN)
#define DISPLAY_G_DIR                  (GPIO_OUTPUT << DISPLAY_G_PIN)
#define DISPLAY_DP_DIR                 (GPIO_OUTPUT << DISPLAY_DP_PIN)

#define DISPLAY_D1_DIR                 (GPIO_OUTPUT << DISPLAY_D1_PIN)
#define DISPLAY_D2_DIR                 (GPIO_OUTPUT << DISPLAY_D2_PIN)
#define DISPLAY_D3_DIR                 (GPIO_OUTPUT << DISPLAY_D3_PIN)
#define DISPLAY_D4_DIR                 (GPIO_OUTPUT << DISPLAY_D4_PIN)


#endif /* SOURCES_BOARD_H_ */
