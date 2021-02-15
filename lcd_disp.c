#include "lcd_disp.h"

/* Configuraton for lcd */
static int lcd_h;

static const int RS = 3;
static const int EN = 14;
static const int D0 = 4;
static const int D1 = 12;
static const int D2 = 13;
static const int D3 = 6;

static char *states[] =
{
	"OK", // < threshold 
	"Reduce", // > threshold &&  < threshold + 1
	"Critical", //  > threshold &&  < threshold + 2
	"Fatal" //  >= threshold + 2
};

int lcd_initialization(void)
{
	if (wiringPiSetup() < 0)
    {
       	fprintf (stderr, "Greška pri inicijalizaciji: %s\n", strerror (errno));
   	 	return 1 ;
   	}
    
    lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);
 
    return 0;
}
 
void write_to_lcd(void)
{
	lcdClear(lcd_h);
    lcdPosition(lcd_h, 0,0);
    lcdPrintf(lcd_h,"Temp: %d.%d", integer, decimal);
	unsigned char state = 0;

	if((integer >= threshold)) //integer is current temperature value
	{
		if(integer < (threshold + 1))
			state = 1;
		else if(integer < (threshold + 2))
			state = 2;
		else
			state = 3;
	}
	else
		state = 0;

    lcdPosition(lcd_h, 0,1);
    lcdPrintf(lcd_h, "Stanje: %s", states[state]);
}
