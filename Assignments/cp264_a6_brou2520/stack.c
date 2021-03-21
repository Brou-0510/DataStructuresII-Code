/*
 -------------------------------------
 File:    stack.c
 Project: CP264-a6q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-05
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
	if (sp->top == NULL) {
		sp->top = np;
	} else {
		np->next = sp->top;

		sp->top = np;
	}
}
NODE* pop(STACK *sp) {
	if (sp->top == NULL)
		return NULL;
	NODE *np = sp->top;
	sp->top = sp->top->next;
	np->next = NULL;
	return np;
}
void clean_stack(STACK *sp) {
	NODE *curr = sp->top;
	NODE *prev = NULL;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	sp = NULL;
}

