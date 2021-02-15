main: main.c lcd_disp.c temp.c pwm_diode_led.c
	gcc -o main main.c lcd_disp.c temp.c pwm_diode_led.c -lwiringPi -lwiringPiDev

.PHONY: clean
clean:
	rm main
