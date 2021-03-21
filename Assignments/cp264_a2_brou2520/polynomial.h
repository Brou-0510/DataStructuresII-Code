/*
 -------------------------------------
 File:    polynomial.h
 Project: CP264-a2q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-27
 -------------------------------------
 */

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

void display_polynomial(float p[], int n, float x) {
// your implementation
	int g = n - 1;
	printf("P(%.2f)=", x);
	for (int i = 0; i < n; i++) {
		if (i != (n - 1)) {
			printf("%.2f*%.2f^%d + ", p[i], x, g);
			g--;
		} else
			printf("%.2f", p[i]);
	}
	return;
}

float horner(float p[], int n, float x) {
// your implementation
	float result = p[0];
	for (int i = 1; i < n; i++) {
		result = result * x + p[i];
	}

	return result;
}

float bisection(float p[], int n, float a, float b) {
// your implementation
	float c = (a + b) / 2;
	while ((fabs(horner(p, n, c)) > EPSILON) || (fabs(c - a) > EPSILON)) {
		if ((horner(p, n, c) >= 0 & horner(p, n, a) >= 0)
				|| (horner(p, n, c) < 0 & horner(p, n, a) < 0)) {
			a = c;
		} else {
			b = c;
		}
		c = (a + b) / 2;
	}
	return c;
}
