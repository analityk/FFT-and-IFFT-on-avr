#include <fft.h>

/**********************************************************/
/* fft.c                                                  */
/* (c) Douglas L. Jones                                   */
/* University of Illinois at Urbana-Champaign             */
/* January 19, 1992                                       */
/*                                                        */
/*   fft: in-place radix-2 DIT DFT of a complex input     */
/*                                                        */
/*   input:                                               */
/* n: length of FFT: must be a power of two               */
/* m: n = 2**m                                            */
/*   input/output                                         */
/* x: double array of length n with real part of data     */
/* y: double array of length n with imag part of data     */
/*                                                        */
/*   Permission to copy and use this program is granted   */
/*   under a Creative Commons "Attribution" license       */
/*   http://creativecommons.org/licenses/by/1.0/          */
/**********************************************************/

void fft(uint8_t n, uint8_t m, float* x, float* y){
	uint8_t i, j, k, n1, n2;
	float c, s, e, a, t1, t2;

	char str[20];
	char u2s[20];

	j = 0; /* bit-reverse */
	n2 = n/2;
	for(i=1; i<n - 1; i++){
		n1 = n2;
		while(j >= n1){
			j = j - n1;
			n1 = n1/2;
		};
		j = j + n1;

		if(i < j){
			t1 = x[i];
			x[i] = x[j];
			x[j] = t1;
			t1 = y[i];
			y[i] = y[j];
			y[j] = t1;
		};
	};


	n1 = 0; /* FFT */
	n2 = 1;

	for(i=0; i < m; i++){
		n1 = n2;
		n2 = n2 + n2;
		e = -6.283185307179586/n2;
		a = 0.0;

		for(j = 0; j < n1; j++){
			c = cos(a);
			s = sin(a);
			a = a + e;

			for(k=j; k < n; k = k + n2){
				t1 = c * x[k + n1] - s * y[k + n1];
				t2 = s * x[k + n1] + c * y[k + n1];
				x[k + n1] = x[k] - t1;
				y[k + n1] = y[k] - t2;
				x[k] = x[k] + t1;
				y[k] = y[k] + t2;
			};
		};
	};
};

void ifft(uint8_t n, uint8_t m, float* x, float* y)
{
	fft(n, m, y, x);
	for(uint8_t i=0; i<n; i++){
		x[i] = (1.0/n)*x[i];
		y[i] = (1.0/n)*y[i];
	};
};

