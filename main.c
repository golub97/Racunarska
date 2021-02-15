#include "temp.h"
#include "lcd_disp.h"
#include "pwm_diode_led.h"

//Read README.txt file before testing project...

/* Globals*/
char arg[10];
char arg2[10];
int threshold; //keep in mind that treshold is an integer
 
/* Main program, application */
int main(int argc, char *argv[])
{ 
	//Protection, that everything works properly
	if(argc != 3)
	{
		printf("Number of arguments must be 3\n");
		return 1;
	}
	//Obtain arguments from the command line..
	strcpy(arg, argv[1]);
    threshold = atoi(argv[2]);

	printf("Threshold is: %d\n", threshold);

	//An array of pointers to functions
    void(*fptr[])(void) = {read_temperature, write_to_lcd, PWM_diode_func};

	
	unsigned int no_of_funct = sizeof(fptr)/sizeof(void(*)(void));
    unsigned int counter = 0;
 
    /* Initializations */
    if(1 == lcd_initialization()) return 1;
    diode_initialization();
    
    //Super loop
    while(1) fptr[(counter++) % no_of_funct](); //Cyclic functions call (read_temperature, write_to_lcd, PWM_diode_func)
 
    return 0;
}
 

