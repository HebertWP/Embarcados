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
#include "lptrm.h"

unsigned char ucDisplays[4];
int iDC = 0;      /*display counter, shows which display is to be shown*/


void main_cyclicExecuteIsr(void)
{
  /*acrescentar counter*/
  /*tratamento de flags*/
};



int main(void)
{
    tc_installLptmr0(4000,main_cyclicExecuteIsr);
    while(1){



        while(/*flag*/){

        }

    return 0;
}
