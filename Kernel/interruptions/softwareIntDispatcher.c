#include <naiveConsole.h>
#define RED 4
void write(unsigned int fd, const char * buffer, unsigned int count);
void read(unsigned int fd, char * buffer, unsigned int count);
int_80(unsigned int fd, const char * buffer, unsigned int count, int sysCall){
    switch (sysCall)
    {
    case 0:
        write(fd, buffer, count);
        break;
    case 1:
        read(fd, buffer, count);
        break;
    default:
        break;
    }
}

void write(unsigned int fd, const char * buffer, unsigned int count){
    if(fd==1){      // STDOUT
        for (int i = 0; i < count; i++)
        {
            ncPrintChar(buffer[i]);
        }
    }
    if(fd==2){      // STDERR
        for (int i = 0; i < count; i++)
        {
            ncPrintColorChar(buffer[i], RED);
        }
    }
}

void read(unsigned int fd, char * buffer, unsigned int count){
    if(fd==0){      // STDIN
        
    }
}