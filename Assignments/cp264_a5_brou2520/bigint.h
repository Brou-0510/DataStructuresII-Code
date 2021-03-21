/*
 -------------------------------------
 File:    bigint.h
 Project: CP264-a5
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-26
 -------------------------------------
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#include "dllist.h"

// your code
typedef struct bigint {
	NODE *start;
	NODE *end;
} BIGINT;

BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

BIGINT bigint(char *digitstr);
void display_bigint(BIGINT bignumber);
void clean_bigint(BIGINT *bignumberp);

#endif

