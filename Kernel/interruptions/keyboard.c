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
static char buffer[64] = {0};
static int bufferIdx=0;
static int endBuffer = 0;
void keyboard_handler(){
    idx = _keyHandler();
    
    if(endBuffer){
        buffer[bufferIdx]=0;
        bufferIdx=0;
        endBuffer = 0;
    }
    if(BREAK_CODE(idx)) //es break code 
        return;
    else if(idx == 0x1C) {   //code del enter
        ncNewline();
        endBuffer = 1;
    }
    else if(idx == 0x0E){
        ncBackspace();
        bufferIdx--;
    }
    else if(idx == 0xF){
        ncSwitchShell();
        bufferIdx=0;
    }
    else{
        buffer[bufferIdx++]=keyTable[idx];
        ncPrintChar(keyTable[idx]);
        }
}

void cleanBuffer(){
    //ncNewline();
    endBuffer=0;
    for(int i = 0; i<64; i++){
        buffer[i]=0;
    }
    bufferIdx=0;
}

int getEndBuffer(){
    return endBuffer;
}

char * getBuffer(){
    return buffer;
}