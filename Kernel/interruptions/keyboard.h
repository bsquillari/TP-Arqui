#ifndef KEYBOARD_H
#define KEYBOARD_H


void keyboard_handler();
int _keyHandler();
void cleanBuffer();
int getEndBuffer();
char * getBuffer();

char * pruebaInt80();

#endif