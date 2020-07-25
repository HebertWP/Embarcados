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
#include "pid.h"


int main(void)
{

	/*init UART0*/
    UART0_init();
    UART0_enableIRQ();
	
	PWM_init();
    coolerfan_init();
    heater_init();

    /*init Temperature sensor*/
    unsigned int fTemp;
	unsigned char ucAux[3];
 	initTempSensor();

	float fSetPoint = 0, fActuatorValue = 0;


 	/*init lcd*/
 	void lcd_initLcd(void);
    while(1){

    	/*get and show temperature at lcd*/
    	
		/*get setPoint from UART*/

		/*PID LOOP*/
		fTemp = getTemp();
		fSetPoint = getSetPoint();
		fActuatorValue = pidUpdateData(fTemp, fSetPoint)
		actuatorSetValue(fActuatorValue)
		
		/*print Temperature*/
    	ucAux[0]=fTemp%10;
    	fTemp=fTemp/10;
    	ucAux[1]=fTemp%10;
    	ucAux[2]='\0';
    	lcd_writeText(0,ucAux);
		util_genDelay100ms();
    }
    /* Never leave main */
    return 0;
}
