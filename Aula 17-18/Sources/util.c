#include "stdint.h"
uint8_t toUint8_t(unsigned char ucValue){
	return (uint8_t)ucValue - 48; /*using asci table*/
}
void setParam(unsigned char ucParam, unsigned char *ucByte){
  if('b' == ucParam){
    if('0' == ucByte[0]){
      /*desliga botao*/
    	/*test was supossed to use the debug mode with a break poin in here*/
    } else {
    	/*test was supossed to use the debug mode with a break poin in here*/
      /*liga botao*/
    }
  }

  if('v' == ucParam){
    /*converte floats*/
	float fTemp=10*toUint8_t(ucByte[0])+toUint8_t(ucByte[1])+0.1*toUint8_t(ucByte[0])+0.01*toUint8_t(ucByte[0]);
  }
}

void answerParam(unsigned char ucParam){
	float fTemp;
	float fCy;
	switch ( ucParam) {
		case 't':
			/* retorna a temperatura*/
			fTemp=23.37;
			for(int iI=0; iI< sizeof(float);iI++)
				debug_putchar(((int*)(&fTemp))[iI]);
			break;
		case 'c':
			/*Retorno o duty cycle do cooler*/
			fCy=0.1;
			for(int iI=0; iI< sizeof(float);iI++)
				debug_putchar(((int*)(&fCy))[iI]);
			break;
		case 'a':
			/*Retorno o aquecedor cycle do cooler*/
			fCy=1;
			for(int iI=0; iI< sizeof(float);iI++)
				debug_putchar(((int*)(&fCy))[iI]);
			break;
	};
}
