#include "lcd.h"
#include <wiringPi.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "temp.h"
#include "pwm_diode_led.h"

/* Functions */
extern int lcd_initialization(void);
extern void write_to_lcd(void);

