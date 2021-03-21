/*
 -------------------------------------
 File:    stack.h
 Project: CP264-a6q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-05
 -------------------------------------
 */

#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct stack {
	NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE* pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
