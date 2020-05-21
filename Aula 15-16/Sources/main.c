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

void main_cyclicExecuteIsr(void){
    iFlag = 1;
}


int main(void){

    UART0_init();
    UART0_enableIRQ();

    /*stuck on echo forever*/
    while(1)
        UART0_IRQHandler();

};
