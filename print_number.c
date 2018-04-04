#include "ezdsp5535.h"
#include "ezdsp5535_lcd.h"
#include "ascii_digits.h"
#include <stdio.h>

void initPrintNumber()
{

}

void clearLCD()
{
	printf("\n\nClear LCD\n\n\n");
}

void setWritePointerToFirstChar()
{
	printf("\n");
}


void printChar(char x)
{
	printf("%c", x);
}

