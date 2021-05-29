#ifndef COMMMANDS_H
#define COMMMANDS_H


int isCommand(char* command, char* buffer);
int isCommandWithArg(char* command, char* buffer);
void helpCommand();
void inforegCommand();
void printRegName(int index);
long readDirection(int direction);
void getArguments(char* buffer, char* arg);
void printRegs();
void printmemCommand(char* buffer);
void dateCommand();

int readRAX();
int readRBX();
int readRCX();
int readRDX();
int readRBP();
int readRSI();
int readRDI();
int readR8();
int readR9();
int readR10();
int readR11();
int readR12();
int readR13();
int readR14();
int readR15();


#endif