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

static int i = 0;


void main_cyclicExecuteIsr(void)
{
  /*apagar o enable dos displays*/
  /*selecionar o primeiro display novamente*/
  /*ISR para tratamento da interrupção gerada pelo LPTMR0*/
};



int main(void)
{
    while(1){




      /*mudar dps*/
      tc_installLptmr0(4000,main_cyclicExecuteIsr);
    }

    return 0;
}
