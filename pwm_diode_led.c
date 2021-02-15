#include "pwm_diode_led.h"
#include "temp.h"

void diode_initialization(void)
{
	wiringPiSetup();
	if(softPwmCreate(28, 0, 100) != 0)
		printf("Doslo je do greske.");
}

void PWM_diode_func(void)
{
	
	int pwm;

	if((integer >= threshold)) //integer is current temperature value
	{
		if(integer < (threshold + 1))
			pwm = 20;
		else if(integer < (threshold + 2))
			pwm = 40;
		else if(integer < (threshold + 3))
			pwm = 60;
		else if(integer < (threshold + 4))
			pwm = 80;
		else
			pwm = 100;
	}
	else
	{
		pwm = 0;
	}

	softPwmWrite(28, pwm);
}
