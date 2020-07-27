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
#include "lptmr.h"

bool bFlag = false;
/* ************************************************  */
/* Method name:        main_cyclicExecuteIsr         */
/* Method description: lets program continue running */
/*                     upon timer reaching its limit */
/* Input params:       n/a                           */
/* Output params:      n/a                           */
/* ************************************************  */
void main_cyclicExecuteIsr(void)
{
	bFlag = true;
}

int main(void)
{

	/*init GPIOS*/
	int *iLeds = (int *)NULL; /* no leds*/
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
	coolerfan_PWMDuty(0); /*turn off fan*/
	heater_PWMDuty(0); /*turn off heater*/

	/*init Temperature sensor*/
	initTempSensor();

	/*init lcd*/
	void lcd_initLcd(void);

	/*init PID with interruptions*/
	pid_init();
	tc_installLptmr0(100000, main_cyclicExecuteIsr);

	/*Updade Screen*/
	setScreen();

	while (true)
	{
		/*read buttons and put on staemachine*/
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
		if (bFlag)
		{
			coolerfan_PWMDuty(pidUpdateData(getTemp())/100);
			bFlag = false;
			/*Updade Screen*/
			setScreen();
		}
	}
	/* Never leave main */
	return 0;
}
