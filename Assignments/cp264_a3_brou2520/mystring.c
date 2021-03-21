/*
 -------------------------------------
 File:    mystring.c
 Project: CP264-a3q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-03
 -------------------------------------
 */

#include "mystring.h"
#define NULL 0

//use ascii bounds from a1 to simplify
#define lowercase_check(p) (*(p) >= 'a' && *(p) <= 'z') // returns if char at p is lowercase
#define uppercase_check(p) (*(p) >= 'A' && *(p) <= 'Z') // returns if char at p is uppercase
#define letter_check(p) lowercase_check(p) || uppercase_check(p) // returns if char at p is a letter

int str_length(char *s) {
// your implementation
	if (s == NULL)
		return -1;
	int counter = 0;
	char *p = s;
	while (*p) {
		if (letter_check(p) || *p == ' ')
			counter++;
		p++;
	}
	return counter;
}

int word_count(char *s) {
// your implementation
	if (s == NULL)
		return -1;
	int count = 0;
	char *p = s;
	while (*p) {
		if ((*(p - 1)) == ' ' && (letter_check(p))) {
			count++;
		}
		p++;
	}
	return count;
}

void lower_case(char *s) {
// your implementation
	if (s == NULL)
		return;
	char *p = s;
	while (*p) {
		if (uppercase_check(p))
			*p += 32;
		p++;
	}
}

void trim(char *s) {
// your implementation
	if (s == NULL || *s == '\0')
		return;
	char *p, *dp;
	for (p = s, dp = s; *p; p++) {
		if (*p != ' ' || (p > s && *(p - 1) != ' ')) {
			*dp = *p;
			dp++;
		}
	}
	if (*(p - 1) == ' ')
		*(dp - 1) = '\0';
	else
		*dp = '\0';
}
