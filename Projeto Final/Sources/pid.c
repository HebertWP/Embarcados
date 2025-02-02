/* ***************************************************************** */
/* File name:        pid.c                                           */
/* File description: This file has a couple of useful functions to   */
/*                   control the implemented PID controller          */
/* Author name:      julioalvesMS, IagoAF, rBacurau, Hebert Wandick  */
/*					 Caio Villela					                 */
/* Creation date:    21jun2018                                       */
/* Revision date:    01ago2020                                       */
/* ***************************************************************** */

#include "pid.h"

pid_data_type pidConfig;
float fSetValue=0;

/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void)
{
	pidConfig.fKp = 0.0;
	pidConfig.fKd = 0.0;
	pidConfig.fKi = 0.0;
	pidConfig.fError_previous = 0;
	pidConfig.fError_sum = 0.0;
}


/* ************************************************** */
/* Method name:        pid_setKp                      */
/* Method description: Set a new value for the PID    */
/*                     proportional constant          */
/* Input params:       fKp: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKp(float fKp)
{
	pidConfig.fKp = fKp;
}


/* ************************************************** */
/* Method name:        pid_getKp                      */
/* Method description: Get the value from the PID     */
/*                     proportional constant          */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float pid_getKp(void)
{
	return pidConfig.fKp;
}


/* ************************************************** */
/* Method name:        pid_setKi                      */
/* Method description: Set a new value for the PID    */
/*                     integrative constant           */
/* Input params:       fKi: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKi(float fKi)
{
	pidConfig.fKi = fKi;
}


/* ************************************************** */
/* Method name:        pid_getKi                      */
/* Method description: Get the value from the PID     */
/*                     integrative constant           */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float pid_getKi(void)
{
	return pidConfig.fKi;
}


/* ************************************************** */
/* Method name:        pid_setKd                      */
/* Method description: Set a new value for the PID    */
/*                     derivative constant            */
/* Input params:       fKd: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKd(float fKd)
{
	pidConfig.fKd = fKd;
}


/* ************************************************** */
/* Method name:        pid_getKd                      */
/* Method description: Get the value from the PID     */
/*                     derivative constant            */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float pid_getKd(void)
{
	return pidConfig.fKd;
}

/* ************************************************** */
/* Method name:        pid_setSetValue                */
/* Method description: set temperature target in PID  */
/* Input params:       fValue: the temperature        */
/* Output params:      n/a			                  */
/* ************************************************** */
void  pid_setSetValue(float fValue){
	fSetValue=(fValue > 77 ) ? 77: fValue;/*limit temperature in 77*/
}

/* ************************************************** */
/* Method name:        pid_getSetValue                */
/* Method description: get temperature target in PID  */
/* Input params:       n/a					          */
/* Output params:      float: temperature             */
/* ************************************************** */
float pid_getSetValue(){
	return fSetValue;
};

/* ************************************************** */
/* Method name:        pid_updateData                 */
/* Method description: Update the control output      */
/*                     using the reference and sensor */
/*                     value                          */
/* Input params:       fSensorValue: Value read from  */
/*                     the sensor                     */
/* Output params:      float: New Control effort     */
/* ************************************************** */
float pidUpdateData(float fSensorValue)
{
	float fError, fDifference, fOut;
	static int iStaturationFlag;

	fError = fSetValue - fSensorValue;
	
	/* if there is no saturation */
	if( iStaturationFlag == 0)
		pidConfig.fError_sum += fError;
	
	fDifference = pidConfig.fError_previous - fError;

	fOut = pidConfig.fKp*fError
		 + pidConfig.fKi*pidConfig.fError_sum
		 + pidConfig.fKd*fDifference;

	pidConfig.fError_previous = fError;

	if (fOut>100.0){
		fOut = 100.0;
		iStaturationFlag = 1;
	}
	
	else if (fOut<0.0){
		fOut = 0.0;
		iStaturationFlag = 1;
	}

	else
		iStaturationFlag = 0;
	

	return fOut;
}
