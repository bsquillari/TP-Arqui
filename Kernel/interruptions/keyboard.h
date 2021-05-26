#ifndef KEYBOARD_H
#define KEYBOARD_H

void write(unsigned int fd, const char * buffer, unsigned int count);
void read(unsigned int fd, char * buffer, unsigned int count);

void keyboard_handler();
int _keyHandler();
void cleanBuffer();
int getEndBuffer();
char * getBuffer();


#endif