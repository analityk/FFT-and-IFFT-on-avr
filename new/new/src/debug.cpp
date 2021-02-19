#include <debug.h>

void Debug::Print(uint16_t di, const char* text)
{
	char r[30];
	char s[30];

	memset(r, 0, 30);
	memset(s, 0, 30);

	itoa(di, r, 10);
	sprintf(s, text, r);
	Serial.write(s);
}

void Debug::Print(int16_t di, const char* text)
{
	char r[30];
	char s[30];

	memset(r, 0, 30);
	memset(s, 0, 30);

	itoa(di, r, 10);
	sprintf(s, text, r);
	Serial.write(s);
}

void Debug::Print(uint16_t a, uint16_t b, const char* text)
{
	char r1[10];
	char r2[10];
	char s[40];

	memset(r1, 0, 10);
	memset(r2, 0, 10);
	memset(s, 0, 30);

	itoa(a, r1, 10);
	itoa(b, r2, 10);
	sprintf(s, text, r1, r2);
	Serial.write(s);
}

void Debug::Print(uint16_t a, int16_t b, const char* text)
{
	char r1[10];
	char r2[10];
	char s[40];

	memset(r1, 0, 10);
	memset(r2, 0, 10);
	memset(s, 0, 30);

	itoa(a, r1, 10);
	itoa(b, r2, 10);
	sprintf(s, text, r1, r2);
	Serial.write(s);
};


Debug debug;