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

#include "fsl_device_registers.h"
#include "lptmr.h"
#include "display7seg.h"
#include "util.h"

int iDC = 0;   /* display counter, tells which display is to be shown */
int iMode = 0; /* which mode are */
int iNum = 0;  /* which number to be displayed */

/* ************************************************  */
/* Method name:        main_cyclicExecuteIsr         */
/* Method description: lets program continue running */
/*                     upon timer reaching its limit */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************  */
void main_cyclicExecuteIsr(void)
{
    /*select which infomation will be show*/
    switch (iMode)
    {
    case 0:
        display7seg_writeNumber(-1);
        break;
    case 1:
        display7seg_writeNumber(iNum);
        break;
    case 2:
        display7seg_writeSymbol(iDC, 22);
    };
};

int main(void)
{
    display7seg_init();
    tc_installLptmr0(16, main_cyclicExecuteIsr);
    while (1)
    {
        /* update the global variables that will be printed*/
        iMode = 0;
        util_genDelay100ms();
        iMode = 1;
        iNum++;
        util_genDelay100ms();
        iMode = 2;
        /*limit off iDC is 4*/
        iDC = iDC >= 4 ? iDC++ : 0;
        util_genDelay100ms();
    };
    return 0;
}
