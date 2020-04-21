/* ***************************************************************** */
/* File name:        lcd.c                                           */
/* File description: file containing the implementation of functions */
/*                   used to control the LCD display                 */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    21/apr/2020                                     */
/* Revision date:    21/apr/2020                                     */
/* ***************************************************************** */

#include "display7seg.h"
#include "board.h"

/* system includes */
#include "fsl_lptmr_driver.h"
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

/* ************************************************ */
/* Method name:        display7seg_init             */
/* Method description: Initializes the 7 seg display*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void display7seg_init(void)
{
    /* pins configured as outputs */

    /*un-gateport C clock*/
    SIM_SCGC5 |= 0x0800;

    /*set pins as gpio*/
    PORTC_PCR0 |= 0x100;  /*A*/
    PORTC_PCR1 |= 0x100;  /*B*/
    PORTC_PCR2 |= 0x100;  /*C*/
    PORTC_PCR3 |= 0x100;  /*D*/
    PORTC_PCR4 |= 0x100;  /*E*/
    PORTC_PCR5 |= 0x100;  /*F*/
    PORTC_PCR6 |= 0x100;  /*G*/
    PORTC_PCR7 |= 0x100;  /*DP*/
    PORTC_PCR13 |= 0x100; /*D1*/
    PORTC_PCR12 |= 0x100; /*D2*/
    PORTC_PCR11 |= 0x100; /*D3*/
    PORTC_PCR10 |= 0x100; /*D4*/

    /* set pins as digital output */
    GPIOC_PDDR |= DISPLAY_A_DIR;
    GPIOC_PDDR |= DISPLAY_B_DIR;
    GPIOC_PDDR |= DISPLAY_C_DIR;
    GPIOC_PDDR |= DISPLAY_D_DIR;
    GPIOC_PDDR |= DISPLAY_E_DIR;
    GPIOC_PDDR |= DISPLAY_F_DIR;
    GPIOC_PDDR |= DISPLAY_G_DIR;
    GPIOC_PDDR |= DISPLAY_DP_DIR;
    GPIOC_PDDR |= DISPLAY_D1_DIR;
    GPIOC_PDDR |= DISPLAY_D2_DIR;
    GPIOC_PDDR |= DISPLAY_D3_DIR;
    GPIOC_PDDR |= DISPLAY_D4_DIR;
}

/* ******************************************************** */
/* Method name:        display7seg_writeSymbol              */
/* Method description: Writes a symbol on a 7seg display    */
/* Input params:       ucDisplay is a value ranging from    */
/*     1 to 4, relative to the display we are to write on   */
/*                     ucValue ranging from 0 to 22,        */
/*       indicates what symbol is to be shown on the display*/
/* Output params:      n/a                                  */
/* ******************************************************** */
void display7seg_writeSymbol(unsigned char ucDisplay, unsigned char ucValue)
{
    /*mask for 7seg display*/

    /*disable all displays*/
    GPIOC_PCOR |= DISPLAY_D1_DIR;
    GPIOC_PCOR |= DISPLAY_D2_DIR;
    GPIOC_PCOR |= DISPLAY_D3_DIR;
    GPIOC_PCOR |= DISPLAY_D4_DIR;

    /*turn off all data pins*/
    GPIOC_PCOR |= DISPLAY_A_DIR;
    GPIOC_PCOR |= DISPLAY_B_DIR;
    GPIOC_PCOR |= DISPLAY_C_DIR;
    GPIOC_PCOR |= DISPLAY_D_DIR;
    GPIOC_PCOR |= DISPLAY_E_DIR;
    GPIOC_PCOR |= DISPLAY_F_DIR;
    GPIOC_PCOR |= DISPLAY_G_DIR;
    GPIOC_PCOR |= DISPLAY_DP_DIR;

    /*write data on display BUS*/
    switch (ucValue)
    {
    case 0:
        GPIOC_PSOR |= 0x3F;
        break;
    case 1:
        GPIOC_PSOR |= 0x06;
        break;
    case 2:
        GPIOC_PSOR |= 0x5B;
        break;
    case 3:
        GPIOC_PSOR |= 0x4F;
        break;
    case 4:
        GPIOC_PSOR |= 0x66;
        break;
    case 5:
        GPIOC_PSOR |= 0x6D;
        break;
    case 6:
        GPIOC_PSOR |= 0x7D;
        break;
    case 7:
        GPIOC_PSOR |= 0X07;
        break;
    case 8:
        GPIOC_PSOR |= 0x7F;
        break;
    case 9:
        GPIOC_PSOR |= 0x6F;
        break;
    case 10:
        GPIOC_PSOR |= 0xBF;
        break;
    case 11:
        GPIOC_PSOR |= 0x86;
        break;
    case 12:
        GPIOC_PSOR |= 0xDB;
        break;
    case 13:
        GPIOC_PSOR |= 0xCF;
        break;
    case 14:
        GPIOC_PSOR |= 0xE6;
        break;
    case 15:
        GPIOC_PSOR |= 0xED;
        break;
    case 16:
        GPIOC_PSOR |= 0xFD;
        break;
    case 17:
        GPIOC_PSOR |= 0x87;
        break;
    case 18:
        GPIOC_PSOR |= 0xFF;
        break;
    case 19:
        GPIOC_PSOR |= 0xEF;
        break;
    case 20:
        GPIOC_PSOR |= 0x80;
        break;
    case 21:
        break;
    case 22:
        GPIOC_PSOR |= 0x80;
        break;
    };

    /*enable writing on a display*/
    switch (ucDisplay)
    {
    case 1:
        GPIOC_PSOR |= DISPLAY_D1_DIR;
        break;
    case 2:
        GPIOC_PSOR |= DISPLAY_D2_DIR;
        break;

    case 3:
        GPIOC_PSOR |= DISPLAY_D3_DIR;
        break;

    case 4:
        GPIOC_PSOR |= DISPLAY_D4_DIR;
        break;
    };
}

/* ******************************************************** */
/* Method name:        toChar					            */
/* Method description: Take a number and turn to Char 		*/
/* Input params:       iNum the number that will became char*/
/* Output params:      unsigned char with the 				*/
/* ******************************************************** */
unsigned char toChar(int iNum)
{
    switch (iNum)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    };
    return -1;
}

/* ******************************************************** */
/* Method name:        display7seg_writeNumber              */
/* Method description: write numbers on  7seg displays	    */
/* Input params:       iNum number to be print at displays  */
/* Output params:      n/a                                  */
/* ******************************************************** */
void display7seg_writeNumber(int iNum)
{
    if (iNum == -1 || iNum > 9999)
    {
        display7seg_writeSymbol(1, 22);
        display7seg_writeSymbol(2, 22);
        display7seg_writeSymbol(3, 22);
        display7seg_writeSymbol(4, 22);
    }
    int i = 1;
    do
    {
        /*write digit by digit, make "shift" of 10 per idaration*/
        display7seg_writeSymbol(i++, toChar(iNum % 10));
        iNum = iNum / 10;
    } while (iNum > 0);
}
