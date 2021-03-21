/*
 -------------------------------------
 File:    quadratic.c
 Project: CP264-a1q3
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-18
 -------------------------------------
 */

#include <stdio.h>
#include <math.h>  // need this library for maths functions fabs() and sqrt()

#define EPSILON 0.000001
// or #define EPSILON 1e-6

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float a, b, c, d, x1, x2;
	int inn;
	char temp;

	do {  // do-while for new input problem
		  // do-while loop to get correct input of three floating numbers,
		do {
			printf("Please enter the coefficients a,b,c\n");
			inn = scanf("%f,%f,%f", &a, &b, &c);

			if (inn != 3) {
				printf("input:Invalid input\n");
			} else
				break;

			do {  // flush the input buffer
				scanf("%c", &temp);
				if (temp == '\n')
					break;
			} while (1);

		} while (1);

		if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
			printf("input:quit\n");
			break;
		} else if (fabs(a) < EPSILON) {
			printf("input:not a quadratic equation\n");
		} else {

			d = b * b - 4 * a * c;  // compute the discriminant

			// your solution logic
			if (a == 0) {

				printf("not a quadratic equation\n");
			} else if (d == 0) { //Equal roots

				printf("the equation has two equal roots:\n");
				x1 = (-b + sqrt(d)) / (2 * a);
				printf("x:%f\n", x1);

			} else if (d < 0) { //Complex roots

				printf("the equation has complex roots:\n");
				float x1_q, x2_q;
				x1_q = (-b) / (2 * a);
				x1 = (sqrt(fabs(d)) / (2 * a));
				x2_q = (-b) / (2 * a);
				x2 = (sqrt(fabs(d)) / (2 * a));

				printf("real:%f+%fi\n", x1, x1_q);
				printf("imaginary:%f-%fi\n", x2, x1_q);

			} else if (d > 0) {

				printf("the equation has distinct real roots\n");
				x1 = (-b + sqrt(d)) / (2 * a);
				x2 = (-b - sqrt(d)) / (2 * a);
				printf("x1:%f\nx2:%f\n", x1, x2);

			}
		}
	} while (1);
	return 0;
}
