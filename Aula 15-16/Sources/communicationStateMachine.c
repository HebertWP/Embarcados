#include "communicationStateMachine.h"
#include "util.h"

#define IDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define FLOAT_VALUE '5'
#define BUTTON_VALUE '6'
#define SET_VALUE '7'
#define ANSWER '8'

#define MAX_VALUE_LENGTH 3

unsigned char ucUartState = IDLE;
unsigned char ucValueCount;

void processByteCommunication(unsigned char ucByte){

    static unsigned char ucParam;
    static unsigned char ucValue[MAX_VALUE_LENGTH + 1];
    if ('#' == ucByte)
      ucUartState = READY;
    else
        if(IDLE != ucUartState)
            switch (ucUartState){

              case READY:
                switch(ucByte){
                    case 'g':
                      ucUartState = GET;
                      break;

                    case 's':
                      ucUartState = SET;
                      break;

                    default:
                      ucUartState = IDLE;
                  }
                break;

                case GET:
                  if('t' == ucByte || 'c' == ucByte || 'a' == ucByte){
                    ucParam = ucByte;
                    ucUartState = PARAM;
                  }else
                    ucUartState = IDLE;
                  break;

                case SET:
                  if ('t' == ucByte){
                    ucParam = ucByte;
                    ucValueCount = 0;
                    ucUartState = FLOAT_VALUE;
                  }else if('b' == ucByte){
                    ucParam = ucByte;
                    ucUartState = BUTTON_VALUE;
                  }else
                    ucUartState = IDLE;
                  break;

                case PARAM:
                  if(';' == ucByte)
                    answerParam(ucParam, ucByte);
                  ucUartState = IDLE;
                  break;

                case FLOAT_VALUE:
                  if(ucByte >= '0' && ucByte <= '9'){
                    if(ucValueCount < MAX_VALUE_LENGTH)
                      ucValue[ucValueCount ++] = ucByte;
                  }else{
                    if(';' == ucByte){
                        ucValue[ucValueCount] = '\0';
                        setParam(ucParam, ucValue);
                    }
                    ucUartState = IDLE;
                  }
                  break;

                case BUTTON_VALUE:
                  if('0' == ucByte || '1' == ucByte){
                    ucValue[0] = ucByte;
                  }else{
                    if(';' == ucByte)
                      setParam(ucParam, ucValue);
                    ucUartState = IDLE;
                  }
                  break;

            }
}
