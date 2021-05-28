#include <keyboard.h>
#include <naiveConsole.h>

#define BREAK_CODE(num) num>0x80


//static int keyDetected = 0;
static int idx;

static const char keyTable[] = {
	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', '¿',0, 0,
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '´', '+',0, 0, 
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'ñ', '{', '|',0, '}',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', 
    0, '*', 0, ' ',0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '7','↑', '9', '-', '←', '5', '→', '+', '1', '↓', '3', 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0
};
static char buffer1[64] = {0};
static char buffer2[64] = {0};
static char* currentBuffer=buffer1;
static int idx1=0, idx2=0;
static int* bufferIdx=&idx1;
static int endBuffer = 0;
void keyboard_handler(){
    idx = _keyHandler();
    
    if(endBuffer){
        currentBuffer[*bufferIdx]=0;
        *bufferIdx=0;
        endBuffer = 0;
    }
    if(BREAK_CODE(idx)) //es break code 
        return;
    else if(idx == 0x1C) {   //code del enter
        ncNewline();
        currentBuffer[(*bufferIdx)++]='\n';
        currentBuffer[(*bufferIdx)++]=0;
        endBuffer = 1;
    }
    else if(idx == 0x0E){   //code del delete
        ncBackspace();
        (*bufferIdx)--;
    }
    else if(idx == 0xF){    //code del TAB
        ncSwitchShell();
        if(currentBuffer==buffer1){
            bufferIdx=&idx2;
            currentBuffer=buffer2;
        }
        else {
            currentBuffer=buffer1;
            bufferIdx=&idx1;
        }
    }
    else{
        currentBuffer[(*bufferIdx)++]=keyTable[idx];
        ncPrintChar(keyTable[idx]);
        }
}

void cleanBuffer(){
    //ncNewline();
    endBuffer=0;
    for(int i = 0; i<64; i++){
        currentBuffer[i]=0;
    }
    (*bufferIdx)=0;
}

int getEndBuffer(){
    return endBuffer;
}

char * getBuffer(){
    return currentBuffer;
}