#include "lib.h"
#include "sysCall.h"
char buffer[40] = {0};


int strlen(char* string){
	int i =0;
	while(*string){
		i++;
		string++;
	}
	return i;
}

char* numToStr(int num){
	char aux = num%10;
	int i = MAX_BUFFER;
	buffer[i]=0;
	while(i>=0 && num>0){
		aux = num%10;
		buffer[i]='0'+aux;
		i--;
		num/=10;
	}
	return buffer+i+1;
}

void printf(char* string){
	sysWrite(STDOUT,string, strlen(string));
}

void printNum(int num){
	printf(numToStr(num));
}

void printer(char* string){
	sysWrite(STDERR, string, strlen(string));
}

void putChar(char c){
	sysWrite( STDOUT, &c, 1);
}

char getChar(){
	char ret;
	sysRead(STDIN, &ret, 1);
	return ret;
}

char* scanf(){
	buffer[0]=0;
	sysRead(STDIN, buffer, MAX_BUFFER);
	return buffer;
}
