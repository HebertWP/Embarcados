typedef union
{
  unsigned char ucBytes[4];
  float fReal;
}floatUCharType;

float uChatToFloat(unsigned char ucValue){
  floatUCharType varFloatUChar;
  static unsigned char ucCount;

  varFloatUChar.ucBytes[ucCount] = ucValue;

  if(++ucCount >= 4){
      ucCount = 0;
      return(varFloatUChar.fReal);
  }
}

unsigned char floatToUChar(int flag, float fReceived){
  floatUCharType varFloatUChar;
  unsigned char ucSendChar;
  static unsigned char ucCount;

  varFloatUChar.fReal = fReceived;

  if(flag == 0){
    ucCount = 0;
    return(varFloatUChar.ucBytes[0]);
  }
  if(ucCount < 4){
    ucCount++ ;
    return(varFloatUChar.ucBytes[ucCount]);
  }
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
