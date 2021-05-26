/* sampleCodeModule.c */
#include "lib.h"
char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	
	

	// while(1){
	// 	char* buffer = scanf();
	// 	//printf(buffer);
	// }

	// **		Prueba básica de las sysTime			** //
	// #include "sysCall.h"
	// int time = sysTime(2);
	
	// printNum(time);
	// char a[1];
	// sysRead(0,a, 1);
	// time = sysTime(4);

	// printNum(time);
	// sysRead(0,a, 1);
	// time = sysTime(0);

	// printNum(time);
	// *************************************************** //

	while(1){
		char* buffer = scanf();
		printf("Char %c String %s int %d", '1', "2", 3);
	}

	// **		Prueba básica de las exceptions			** //
		// #include "exceptionTests.h"
		// divTest();
	// *************************************************** //

	// char a = getChar();
	// putChar(a);
	// char* buf = scanf();
	// printf(buf);
	// printf("bue");
	return 0;
}