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
/* Author name:      Caio Villela /Hebert Wandick                    */
/* Creation date:    21/apr/2020                                     */
/* Revision date:    21/apr/2020                                     */
/* ***************************************************************** */
#include "lptmr.h"
#include "display7seg.h"

/*system include*/
#include "fsl_device_registers.h"

int iFlag = 0;     /* interruption flag */


/* ************************************************  */
/* Method name:        main_cyclicExecuteIsr         */
/* Method description: lets program continue running */
/*                     upon timer reaching its limit */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************  */
void main_cyclicExecuteIsr(void){
    iFlag = 1;
}



int main(void){
    unsigned char iIterator;   /*auxliary varieble to chose the correc display, with star at 1 not on 0*/
    unsigned char ucDisplays[4] = {1, 2, 3, 4};  /*display values, hardcoded for testing*/
    int iDC = 0;       /* display counter, tells which display is to be shown */
    display7seg_init();
    tc_installLptmr0(4000,main_cyclicExecuteIsr);

    while(1){
        iIterator = iDC + 1;
        display7seg_writeSymbol(iIterator, ucDisplays[iDC]);

       /*stuck here until timer finishes*/
        while(iFlag == 0);

        /*reset flag*/
        iFlag = 0;

        /*increment counter*/
        iDC= (iDC == 3) ? 0 : iDC + 1;
    };
    return 0;
}
