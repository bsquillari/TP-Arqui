/* sampleCodeModule.c */
#include "lib.h"
#include "commandDispatcher.h"
char * v = (char*)0xB8000 + 79 * 2;
	static char c;
	static char buffer1[MAX_BUFFER]={0};
	static int idx1 = 0;
	static int idx0 = 0;
	static char buffer0[MAX_BUFFER]={0};
	static char * buffer = buffer1;
	static int bufferID = 1;
	static int * idx=&idx1;
	
	
// void resetShell(){
// 	for (int i = 0; i < 12; i++)
// 	{
// 		putChar('\n');
// 	}
// 	if(!bufferID){
// 			*buffer0 = 0;
// 			idx0 = 0;
// 		}else{
// 			*buffer1 = 0;
// 			idx1 = 0;
// 		}
// }
int main() {

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
	printf("Bienvenido! Que comando desea correr?\n");
	while(1){
		while((c=getChar())!='\n'){
			putChar(c);
			if(c=='\b'){
			if((*idx)!=0)
			(*idx)--;
			}
			else if(c=='\t'){
				bufferID = (bufferID+1)%2;
				if(bufferID){
					buffer = buffer1;
					idx = &idx1;
				}else{
					buffer = buffer0;
					idx = &idx0;
				}
			}else{
			buffer[*idx]=c;
			(*idx)++;
			}
		}
		putChar('\n');
		buffer[(*idx)++]='\n';
		buffer[(*idx)++]=0;
		*idx=0;
		commandSelector(buffer);
		buffer[0] = 0; // "Borro" el buffer
	}

	// **		Prueba básica de las exceptions			** //
		// #include "exceptionTests.h"
		// divTest();
	// *************************************************** //

	return 0;
}


