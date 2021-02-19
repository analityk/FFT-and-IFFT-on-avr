/*
 * new.cpp
 *
 * Created: 2021-02-15 11:46:29
 * Author : Szymon
 */

#include <avr/io.h>
#include <stdlib.h>
#include <serial.h>
#include <array.h>
#include <complex.h>
#include <math.h>
#include <fft.h>
#include <stdio.h>
#include <string.h>
#include <debug.h>

void delay(uint32_t volatile t){
	while(t--){};
};

float x[64];
float y[64];

int main(void)
{
	Serial.Enable();
	Serial.SetUbrr(103); // 9600

	for(uint8_t i=0; i<64; i++){
		x[i] = 50.0 * sin(4.0 * i / M_PI) + 50.0 * sin(8.0 * i / M_PI);
		debug.Print( (int16_t)(x[i]), " raw data : %s\r\n");
	};

	// fft(n, p, x, y):
	// n - rozmiar wektora próbek
	// p - n = 2^p
	// x, y - czêœæ rzeczywista i urojona
	fft(64, 6, x, y);

	for(uint8_t i=0; i<32; i++){
		//float ht = hypot(x[i], y[i]);
		//uint16_t ff = (uint16_t)ht;
		//debug.Print(i, ff, "x[%s] = %s\r\n");
	};

	ifft(64, 6, x, y);

	for(uint8_t i=0; i<64; i++){
		int16_t ff = (int16_t)x[i];
		debug.Print(i, ff, "x[%s] = %s\r\n");
	};













    /* Replace with your application code */
    while (1)
    {
		//for(uint8_t i=0; i<64; i++){
			//x[i] = sin(8 * i / 3.14159);
			//y[i] = 0.0;
		//};
		//
		//fft(64, 5, x, y);
		//for(uint8_t i=0; i<32; i++){
			//float mc = hypot(x[i], y[i]);
			//uint8_t t = (uint8_t)(mc);
			//Serial.write(t);
		//};

    }
}

