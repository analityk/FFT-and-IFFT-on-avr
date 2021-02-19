#ifndef fft_h__
#define fft_h__

#include <avr/io.h>
#include <complex.h>
#include <math.h>

void fft(uint8_t n, uint8_t m, float* x, float* y);
void ifft(uint8_t n, uint8_t m, float* x, float* y);

#endif // fft_h__
