#include <naiveConsole.h>

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