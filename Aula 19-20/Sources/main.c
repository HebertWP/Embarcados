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
#include "ledSwi.h"
#include "communicationStateMachine.h"

int main(void)
{

	/*init GPIOS*/
	/* no leds*/
	int *iLeds = (int*) NULL;
	int iNumLeds = 0;
	/*using the 1º,2º,3º buttons*/
	int iButtons[3] = {1, 2, 3};
	int iNumButtons = 3;
	initLedButton(iLeds, iNumLeds, iButtons, iNumButtons);
	bool press = false;
	
	/*init UART0*/
	UART0_init();
	UART0_enableIRQ();

	/*cooler and fan control*/
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
	while (1)
	{
		if (!press)
		{
			if (readButton(1))
			{
				processByteCommunication('@');
				press = true;
			}
			else if (readButton(2))
			{
				processByteCommunication('<');
				press = true;
			}
			else if (readButton(3))
			{
				processByteCommunication('>');
				press = true;
			}
		}
		else
		{
			if (!readButton(1) && !readButton(2) && readButton(3))
				press = false;
		}

		/*PID LOOP*/
		fTemp = getTemp();
		fSetPoint = getSetPoint();
		fActuatorValue = pidUpdateData(fTemp, fSetPoint);
		actuatorSetValue(fActuatorValue);

		setScreen();
		/*print Temperature*/
		ucAux[0] = fTemp % 10 + 48;
		fTemp = fTemp / 10 ;
		ucAux[1] = fTemp % 10 + 48;
		ucAux[2] = '\0';
		lcd_writeText(0, ucAux);
		util_genDelay100ms();
	}
	/* Never leave main */
	return 0;
}
