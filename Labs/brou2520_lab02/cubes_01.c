/*
 -------------------------------------
 File:    cubes_01.c
 Project: brou2520_lab02_t01
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-24
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 12

int main(int argc, char *argv[]) {
//==============================
	setbuf(stdout, NULL);           // turns standard output buffering off

	int i;                          // Loop counter/index.

	int values[ARR_SIZE];     // Integer Array of size 10
	long int cubes[ARR_SIZE];     // Integer Array of size 10.

	// Populate the "values" array with consecutive integers
	// [1,2,3, ..., 10]
	for (i = 0; i < ARR_SIZE; i++) {
		values[i] = i + 1;
	}
	// Populate each element of the "squares" array with the
	// square value of its corresponding integer value stored in
	// the "values" array.
	for (i = 0; i < ARR_SIZE; i++) {
		cubes[i] = values[i] * values[i] * values[i];
	}
	// Print the table of values
	printf("\n");
	printf("Array traversal by \"ARRAY INDEXING\"\n");
	printf("===================================\n");
	printf("\n");
	printf("Value       Cube  \n");
	printf("=====     ==========\n");

	for (i = 0; i < ARR_SIZE; i++) {
		printf("%3d     %8ld\n", values[i], cubes[i]);
	}

	printf(":::\n");
	printf("::: Program Terminated.\n");
	printf(":::\n");

	return 0;
}
