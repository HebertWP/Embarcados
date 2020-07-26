/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: implements UART configuration and interruption  */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    30/may/2020                                     */
/* Revision date:    30/may/2020                                     */
/* ***************************************************************** */

/*My includes*/
#include "TempSensor.h"
#include "lcd.h"
#include "util.h"
#include "UART.h"
#include "print_scan.h"
#include "aquecedorECooler.h"

int main(void)
{

	/*init UART0*/
    UART0_init();
    UART0_enableIRQ();
	
	PWM_init();
    coolerfan_init();
    heater_init();

    /*init Temperature sensor*/
    unsigned int uiTemp;
	unsigned char ucAux[3];
 	initTempSensor();

 	/*init lcd*/
 	void lcd_initLcd(void);
    while(1){
    	/*get and show temperature at lcd*/
    	util_genDelay100ms();
    	uiTemp=getTemp();
    	ucAux[0]=uiTemp%10 + 48; /*add 48 to match ascii table*/
    	uiTemp=uiTemp/10;
    	ucAux[1]=uiTemp%10 + 48; /*add 48 to match ascii table*/
    	ucAux[2]='\0';
    	lcd_writeText(0,ucAux);
    }
    /* Never leave main */
    return 0;
}
