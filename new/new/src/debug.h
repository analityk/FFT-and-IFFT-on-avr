#ifndef debug_h__
#define debug_h__

#include <avr/io.h>
#include <stdio.h>
#include <serial.h>
#include <stdlib.h>
#include <string.h>

class Debug{
public:
	void Print(uint16_t di, const char* text);
	void Print(int16_t di, const char* text);
	void Print(uint16_t a, uint16_t b, const char* text);
	void Print(uint16_t a, int16_t b, const char* text);
};

extern Debug debug;

#endif // debug_h__
