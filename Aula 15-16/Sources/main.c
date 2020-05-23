/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: implements UART configuration and interruption  */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    20/may/2020                                     */
/* Revision date:    20/may/2020                                     */
/* ***************************************************************** */

#include "fsl_device_registers.h"
#include "UART.h"
#include "print_scan.h"
#include "util.h"

int main(void){

    UART0_init();
    UART0_enableIRQ();

    /*echo*/
    UART0_IRQHandler();

};
