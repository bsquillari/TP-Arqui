/* sampleCodeModule.c */
#include "lib.h"
char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	//All the following code may be removed 
	*v = 'X';
	*(v+1) = 0x74;

	while(1){
		char* buffer = scanf();
		printf(buffer);
	}
	// char a = getChar();
	// putChar(a);
	// char* buf = scanf();
	// printf(buf);
	// printf("bue");
	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	
	return 0xDEADBEEF;
}