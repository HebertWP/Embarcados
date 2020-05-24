/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: implements UART configuration and interruption  */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    24/may/2020                                     */
/* Revision date:    24/may/2020                                     */
/* ***************************************************************** */

#include "fsl_device_registers.h"
#include "UART.h"
#include "print_scan.h"

int main(void){

    UART0_init();
    UART0_enableIRQ();

    /*Call the StateMachine*/
    UART0_IRQHandler();

};
