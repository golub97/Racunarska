#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

/* Functions */
extern void PWM_diode_func(void);
extern void diode_initialization(void);

/* Globals */
extern int threshold;
