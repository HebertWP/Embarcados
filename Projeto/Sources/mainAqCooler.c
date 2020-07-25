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
/* Creation date:    24/apr/2020                                     */
/* Revision date:    24/apr/2020                                     */
/* ***************************************************************** */

/*my  includes*/
#include "aquecedorECooler.h"

int main(void)
{
    /*initing the cooler and header control */
    PWM_init();
    coolerfan_init();
    heater_init();

    /*make both work in 50% of power*/
    coolerfan_PWMDuty(0.5);
    heater_PWMDuty(0.5);

    while (1) {

    }
    return 0;
}
