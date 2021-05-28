#include "commands.h"
#include "lib.h"
#include "sysCall.h"

#define SECONDS 0
#define MINUTES 2
#define HOURS 4
#define DAY 7
#define MONTH 8
#define YEAR 9

int isCommand(char* command, char* buffer){ //1 si son iguales, 0 si no
	int comLen=strlen(command);

    if(comLen > strlen(buffer))
		return 0;

    int i;
	for(i=0; i < comLen ; i++){
		if(buffer[i]== '\n' || command[i]!=buffer[i]) 
			return 0;
	}
	if (buffer[i] == '\n')
		return 1;
	return 0;
}

int isCommandWithArg(char* command, char* buffer){ //1 si son iguales, 0 si no
	int comLen=strlen(command);

	if(comLen > strlen(buffer))
		return 0;

	int i;
	for(i=0; i < comLen ; i++){
		if(buffer[i]== ' ' || command[i]!=buffer[i]) //si es el espacio, no coincide con el comando
			return 0;
	}
	if (buffer[i] == ' ') //si cuando termino de leer el comando y viene el espacio en buffer -> son iguales
		return 1;
	return 0;
}

void getArguments(char* buffer, char* arg){
    int buffLen=strlen(buffer);
    int i;
    for(i=0;buffer[i]!= ' ';i++);

    while(buffer[i]==' ')
        i++;
    int flag=1;

    for(int j=0; j < MAX_BUFFER && i < buffLen && flag; j++, i++ ){
        if(buffer[i]=='\n'){
            arg[j]=0; //final del string
            flag=0;
        }else
            arg[j]=buffer[i]; //copio el string
    }
}


void helpCommand(){
    printf("help: display every command available\n");
    printf("Syntaxis: &> help\n\n");
    printf("inforeg: print every register with its value\n");
    printf("Syntaxis: &> inforeg\n\n");
    printf("printmem: 32bytes from the direction passed by argument\n");
    printf("Syntaxis: &> printmem [DIRECTION](decimal)\n\n");
    printf("date: show real time live\n");
    printf("Syntaxis: &> date\n");

}


static char * registersNames[] = {"RAX", "RBX", "RCX", "RDX", "RBP", "RSI", "RDI", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"};
void printRegName(int index){
	putChar(' ');
	printf(registersNames[index]);
	printf(":");
}

void inforegCommand(){
    printRegs();
    printf("\n");
}


void printmemCommand(char* buffer){
    char arg[MAX_BUFFER];
    
    getArguments(buffer,arg);
    int direction=strToNum(arg);
    if(direction>=0){ //&& direction <= DIREC_MAX-32){
        for(int i=0;i!=32;i+=8){
            //imprimo 4 bloques de 8bytes al ser una arquitectura de 64 bits
            int value=readDirection(direction+i);
            cleanBuffer();
            printf("%s:",numToStr(direction+i,16));
            cleanBuffer();
            printf("%s     ",numToStr(value,16));
        }
        printf("\n");
    }else{
        printer("Direccion invalida");
        printf("\n");
    }   
    
   

}


void dateCommand(){
    printTime(sysTime(HOURS)-3);
    printf(":");
    printTime(sysTime(MINUTES));
    printf(":");
    printTime(sysTime(SECONDS));
    printf(" of ");
    printTime(sysTime(DAY));
    printf("/");
    printTime(sysTime(MONTH));
    printf("/");
    printTime(sysTime(YEAR));
    printf("\n");
    
}