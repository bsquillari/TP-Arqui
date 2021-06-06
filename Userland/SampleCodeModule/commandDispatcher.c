#include "lib.h"
#include "commands.h"


void commandSelector(char* buffer){
    if(isCommand("help", buffer)){
        helpCommand();
    }else if(isCommand("inforeg1", buffer)){
        inforegCommand(1);
    }else if(isCommand("inforeg", buffer)){
        inforegCommand(0);
    }else if(isCommandWithArg("printmem", buffer)){
        printmemCommand(buffer);
    }else if(isCommand("date", buffer)){
        dateCommand();
    }else if(isCommandWithArg("exceptiontest",buffer)){
        exceptionTestCommando(buffer);
    }else{
        printer("Command not found");
        printf("\n");
    }

}