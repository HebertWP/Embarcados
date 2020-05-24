typedef union
{
  unsigned char ucBytes[4];
  float fReal;
}floatUCharType;

float uCharToFloat(unsigned char ucValue){
  floatUCharType varFloatUChar;
  static unsigned char ucCount;

  varFloatUChar.ucBytes[ucCount] = ucValue;

  if(++ucCount >= 4){
      ucCount = 0;
      return(varFloatUChar.fReal);
  }
}

unsigned char* floatToUChar(int flag, float fReceived){
  floatUCharType varFloatUChar;
  unsigned char ucSendChar[4];
  int iCount;

  varFloatUChar.fReal = fReceived;
  return(varFloatUChar.ucBytes);

}



void setParam(unsigned char ucParam, unsigned char ucValue){


  if('b' == ucParam){
    if('0' == ucByte){
      /*desliga botao*/
    } else {
      /*liga botao*/
    }
  }

  if('v' == ucParam){
    /*converte floats*/
  }
}

void answerParam(unsigned char ucParam, unsigned char ucValue){
  /*cria mensagem de answer*/
}
