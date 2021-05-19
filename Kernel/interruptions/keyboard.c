#include <keyboard.h>
#include <naiveConsole.h>

#define BREAK_CODE(num) num>0x80


static int keyDetected = 0;
static int idx;

static const char keyTable[] = {
	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', '¿',0, 0,
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '´', '+',0, 0, 
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'ñ', '{', '|',0, '}',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', 
    0, '*', 0, ' ',0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '7','↑', '9', '-', '←', '5', '→', '+', '1', '↓', '3', 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0
};

void keyboard_handler(){
    idx = _keyHandler();
    if(BREAK_CODE(idx)) //es break code 
        keyDetected=0;
    else if(idx == 0x1C)    //code del enter
        ncNewline();
    else if(idx == 0x0E)
        ncBackspace();
    else if(idx == 0xF)
        ncSwitchShell();
    else{
        keyDetected=1;
        ncPrintChar(keyTable[idx]);
        }
}


int keyDetect(){
    return keyDetected;
}

char readChar(){
    keyDetected = 0;
    return keyTable[idx];
}