#include "lib.h"
#include "sysCall.h"
#include <stdarg.h>
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

void printf(char* string, ...){
	int i=0, argumentCount=0;
	while(string[i]){
		if(string[i] == '%') argumentCount++;
		i++;
	}
	va_list list;
	va_start(list, argumentCount);
	while(*string){
		if(*string=='\''){
			string++;
			sysWrite(STDOUT,string, 1);
			string++;
		}
		else if(*string!='%'){
			sysWrite(STDOUT,string, 1);
			string++;
		}
		else{
			string++;
			switch (*string){
			case 'd': printNum(va_arg(list, int));
				break;
			case 'c': putChar(va_arg(list, int));
				break;
			case 's': printf(va_arg(list, int));
				break;
			default:
				break;
			}
			string++;
		}
	}
	va_end(list);
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
