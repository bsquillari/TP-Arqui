#include <naiveConsole.h>

#define GREY 7

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base);

static char buffer[64] = { '0' };
static uint8_t * const video = (uint8_t*)0xB8000;
static uint8_t * currentVideo = (uint8_t*)0xB8000;
static const uint32_t width = 80;
static const uint32_t height = 25 ;
static uint8_t shellSelector = 0;

void ncPrint(const char * string)
{
	int i;

	for (i = 0; string[i] != 0; i++)
		ncPrintChar(string[i]);
}

void ncPrintChar(char character)
{
	ncScroll();
	*currentVideo = character;
	currentVideo += 2;
}

void ncScroll(){
	if(shellSelector){
		if(currentVideo-video == (height/2)*width*2){
			ncNewline();
		}
	}else{
		if(currentVideo-video == height*width*2){
			ncNewline();
		}
	}
}

void ncSwitchShell(){
	shellSelector=1-shellSelector;
	currentVideo = (shellSelector)?video+(height-2)/2*width*2:video + (height-1)*width*2;
	for(uint8_t i = 0; i<width*2;i+=2){
		currentVideo[i]=' ';
	}
}

void ncNewline(){
	if(shellSelector){
		for(int i = 0; i<(height/2)-1; i++){
			for (int j=0; j<2*width-1; j++){
				video[width*2*i + j] = video[width*2*(i+1) + j];
			}
		}
		for(int i=0; i<2*width; i++){
			if(i%2==0)
				video[(height-2)/2*width*2+i] = ' ';
			else
				video[(height-2)/2*width*2+i]=GREY; //restauro el color de la celda
		}
		currentVideo = video+(height-2)/2*width*2;
		return;
	}

	for(int i = (height+1)/2; i<height; i++){
		for (int j=0; j<2*width; j++){
			video[width*2*i + j] = video[width*2*(i+1) + j];
		}
	}
	for(int i =0; i<=2*width; i+=2){
		video[height*2*width-i] = ' ';
	}
	currentVideo = video + (height-1)*width*2;
}

void ncPrintDec(uint64_t value)
{
	ncPrintBase(value, 10);
}

void ncPrintHex(uint64_t value)
{
	ncPrintBase(value, 16);
}

void ncPrintBin(uint64_t value)
{
	ncPrintBase(value, 2);
}

void ncPrintBase(uint64_t value, uint32_t base)
{
    uintToBase(value, buffer, base);
    ncPrint(buffer);
}

void ncBackspace(){
	currentVideo-=2;
	*currentVideo=' ';
}

void ncClear(){
	int i, mid = width;
	for (i = 0; i < height * width; i++)
		video[i * 2] = ' ';
	for(i=0; i<width*2; i+=2){
		video[24*width+i] = '-';
	}
	currentVideo = (shellSelector)?:video + (height-1)*width*2;
}

static uint32_t uintToBase(uint64_t value, char * buffer, uint32_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint32_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint32_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
