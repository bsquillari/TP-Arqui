#include "commands.h"
#include "lib.h"
#include "sysCall.h"
#include "exceptionTests.h"

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

#define commandsQuantity 5
void helpCommand(){
    static char * strings[][2] = {
        {"help: display every command available\n","&> help\n"},
        {"inforeg: print every register with its value\n","&> inforeg\n"},
        {"printmem: 32bytes from the direction passed by argument\n","&> printmem [DIRECTION](hexa)\n"},
        {"date: show real time live\n","&> date\n"},
        {"exceptionTest: Test exception routines. 0: Division by 0. 6: Invalid operation code.\n","&> exceptionTest [Exception ID]\n"}
    };
    for (int i = 0; i < commandsQuantity; i++)
    {
        printf("@ ");
        printf(strings[i][0]);
        printf("Syntax: ");
        printf(strings[i][1]);
        if(i!=commandsQuantity-1){
        printf("Press enter to see next command.");
        scanf();
        }
    }
}


static char * registersNames[] = {"RAX", "RBX", "RCX", "RDX", "RBP", "RSI", "RDI", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15"};
void printRegName(int index){
	putChar(' ');
	printf(registersNames[index]);
	printf(":");
    cleanBuffer();
}

void inforegCommand(){
    
    printf("RAX: %s    ",numToStr(readRAX(),16));

    printf("RBX: %s    ",numToStr(readRBX(),16));

    printf("RCX: %s    ",numToStr(readRCX(),16));

    printf("RDX: %s    ",numToStr(readRDX(),16));

    printf("RBP: %s    ",numToStr(readRBP(),16));

    printf("RSI: %s    ",numToStr(readRSI(),16));

    printf("RDI: %s    ",numToStr(readRDI(),16));

    printf("R8: %s    ",numToStr(readR8(),16));

    printf("R9: %s    ",numToStr(readR9(),16));

    printf("R10: %s    ",numToStr(readR10(),16));

    printf("R11: %s    ",numToStr(readR11(),16));

    printf("R12: %s    ",numToStr(readR12(),16));

    printf("R13: %s    ",numToStr(readR13(),16));

    printf("R14: %s    ",numToStr(readR14(),16));

    printf("R15: %s    ",numToStr(readR15(),16));

    //printRegs();
    printf("\n");
}


void printmemCommand(char* buffer){
    char arg[MAX_BUFFER];
    
    getArguments(buffer,arg);
    int direction=hexToDec(arg);
    if(direction>=0){ //&& direction <= DIREC_MAX-32){
        for(int i=0;i<=32;i+=4){
            //imprimo 4 bloques de 4bytes al ser una arquitectura de 64 bits
            int value=readDirection(direction+i);
            int low=value>>16;
            value=value<<16;
            value+=low;

            printf("%s:",numToStr(direction+i,16));

            printf("%s     ",numToStr(value,16));
        }
        printf("\n");
    }else{
        printer("Direccion invalida");
        printf("\n");
    }   
    
   

}


void dateCommand(){
    printTime(sysTime(HOURS));
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

void exceptionTestCommando(char * buffer){
    char arg[MAX_BUFFER];
    
    getArguments(buffer,arg);
    int num=strToNum(arg);
    if(num<0){
        printf("ID de excepcion invalido.\n");
    }else{
        switch (num)
        {
        case 0:
            divTest();
            break;
        case 6:
            opCodeTest();
            break;
        default:
            break;
        }
    }
}
