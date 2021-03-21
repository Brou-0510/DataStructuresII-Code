/*
 -------------------------------------
 File:    main.c
 Project: brou2520_lab01
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-17
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL); // turns standard output buffering off
	int number = 0;
	printf("Enter a number: ");
	scanf("%d", &number);
	printf("The number you entered is %d\n", number);
	return (0);
}

