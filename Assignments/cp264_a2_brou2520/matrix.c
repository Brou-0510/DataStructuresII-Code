/*
 -------------------------------------
 File:    matrix.c
 Project: CP264-a2q3
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-29
 -------------------------------------
 */

#include<stdio.h>
#include "matrix.h"

void display_matrix(int *m, int n) {
	int *p = m, i, j;
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%4d", *p++);
	}
	printf("\n");
}

int sum(int *m, int n) {
// your implementation
	int *p = m, i, j, sum = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			sum += *p++;
	}
	return sum;
}

int is_magic_square(int *m, int n) {
	int s = 0, x;
	int *p = m, i, j;
	for (i = 0; i < n; i++) // step 1: we get sum of first row
		s += *p++;

	for (i = 1; i < n; i++) { // step 2: compare sum of remaining rows with first row
		x = 0;
		for (j = 0; j < n; j++)
			x += *p++;
		if (s != x)
			return 0;
	}

	p = m;

	for (i = 0; i < n; i++) { // step 3: check if sum of first column matches sum of remaining columns
		x = 0;
		for (j = 0; j < n; j++)
			x += *(p + j * n + i);
		if (s != x)
			return 0;
	}

	x = 0;
	for (i = 0; i < n; i++) // step 4: check the sum of right diagonal
		x += *(p + i * n + (n - i - 1));
	if (s != x)
		return 0;

	x = 0;
	for (i = 0; i < n; i++) // step 5: check the sum of left diagonal
		x += *(p + i * n + i);
	if (s != x)
		return 0;
	return 1;
}

void transpose_matrix(int *m1, int *m2, int n) {
// your implementation
	int *p1 = m1, *p2 = m2, i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			*p2++ = *(p1 + n * j + i);
		}
	}
}

void multiply_matrix(int *m1, int *m2, int *m3, int n) {
// your implementation
	int *p1 = m1, *p2 = m2, *p3 = m3, x = 0, i, j, l;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			x = 0;
			for (l = 0; l < n; l++) {
				x += *(p1 + n * i + l) * *(p2 + n * l + j);
			}
			*p3++ = x;
		}
	}
}
