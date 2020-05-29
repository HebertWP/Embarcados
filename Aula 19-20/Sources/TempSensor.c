#include "adc.h"
#include "lut_adc_3v3.h"

void initTempSensor(void){
	adc_initADCModule();
};

unsigned int getTemp(){
	adc_initConvertion();
	while(!adc_isAdcDone());
	int iAux=adc_getConvertionValue();
	return tabela_temp[iAux];
};
