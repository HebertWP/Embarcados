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
/* Creation date:    08/may/2020                                     */
/* Revision date:    08/may/2020                                     */
/* ***************************************************************** */

/*my  includes*/
#include "lptmr.h"
#include "tacometro.h"

bool flag = false;

/* ************************************************  */
/* Method name:        main_cyclicExecuteIsr         */
/* Method description: lets program continue running */
/*                     upon timer reaching its limit */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************  */
void main_cyclicExecuteIsr()
{
    flag = true;
}

int main(void)
{
    unsigned int value = 0;
    /* initing the tachometer and interruptions */
    tachometer_init();
    tc_installLptmr0(2500, main_cyclicExecuteIsr);

    while (true)
    {
        /* if it is need to read tachometer */
        if (flag)
        {
            /*read with a windows of 100ms */
            value = tachometer_readSensor(100);
            flag = false;
        }
    }
    return 0;
}
