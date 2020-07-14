/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: File dedicated to the ES670 prototype projects  */
/*                   involving the FRDM-KL25Z board together with is */
/*                   daughter board containing more peripherals      */
/*                                                                   */
/*                   Processor MKL25Z128VLK4 characteristics         */
/*                   48 MHz ARM Cortex-M0+ core                      */
/*                   128 KB program flash memory                     */
/*                   16 KB SRAM                                      */
/*                   Voltage range: 1.71 to 3.6 V                    */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    10/apr/2020                                     */
/* Revision date:    10/apr/2020                                     */
/* ***************************************************************** */
#include "fsl_device_registers.h"
#include "lcd.h"
#include "util.h"

int main(void)
{

    /* Write your code here */
    /*Initing LCD*/
    lcd_initLcd();
    /* This for loop should be replaced. By default this loop allows a single stepping. */
    while(1){
        /* Teacher's text function */
        lcd_dummyText();

        /* wait 100ms without doing anything! */
        util_genDelay100ms();

        /*Test our function */
        lcd_writeText(0,"Na primeira linha");
        util_genDelay100ms();
        lcd_writeText(1,"Na segunda linha");
        util_genDelay100ms();
    }
    /* Never leave main */
    return 0;
}