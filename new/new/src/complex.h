#ifndef complex_h__
#define complex_h__

#include <avr/io.h>
#include <stdlib.h>
#include <array.h>

template <class T>
class complex{
	public:
	T re;
	T im;

	complex(void): re(0.0), im(0.0){};
	complex(T re, T im): re(re), im(im){};
	complex(complex* c): re(c->re), im(c->im){};

	complex add(complex a, complex b){
		complex<T> t;
		t.re = a.re + b.re;
		t.im = a.im + b.im;
		return t;
	};

	complex sub(complex a, complex b){
		complex<T> t;
		t.re = a.re - b.re;
		t.im = a.im - b.im;
		return t;
	};

	complex mul(complex a, complex b){
		complex<T> t;
		t.re = a.re * b.re - a.im * b.im;
		t.im = a.im * b.re + a.re * b.im;
		return t;
	};

	complex div(complex a, complex b){
		if( (b.re == 0) && (b.im == 0) ){
			return complex<T>(0,0);
		};
		complex<T> t;

		t.re = ((a.re*b.re) + (a.im*b.im)) / (pow(b.re, 2.0) + pow(b.im, 2.0));
		t.im = ((a.im*b.re) - (a.re*b.im)) / (pow(b.re, 2.0) + pow(b.im, 2.0));
		return t;
	};

	T complex_abs(complex a){
		//return sqrt( pow(a.re, 2) + pow(a.im, 2));
		return hypot(a.re, a.im);
	};

};

#endif // complex_h__
