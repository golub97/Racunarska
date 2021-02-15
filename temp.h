#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include <lcd.h>
#include <errno.h>
#include <sys/fcntl.h>

/* Functions */
extern void read_temperature(void);

/* Globals */
extern char arg[];
extern int integer, decimal;
