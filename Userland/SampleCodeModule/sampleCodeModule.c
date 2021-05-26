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
		printf("Char %c String %s int %d", '1', "2", 3);
	}
	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;
	
	return 0xDEADBEEF;
}