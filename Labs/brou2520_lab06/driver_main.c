/*
 -------------------------------------
 File:    driver_main.c
 Project: stack_queue
 file description
 -------------------------------------
 Author:  Heider Ali
 ID:      9999999999
 Email:   heali@wlu.ca
 Version  2020-10-29
 -------------------------------------
 */
/* This lab give you a practice on how to build and test stacks
 * and queues. You have to give or complete the given code to
 * get the required output
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "llstack.h"
#include "llqueue.h"
//----- TEST DRIVER -----
int main() {

	//ItemType v;
	// Node_t* tmp;

	Stack_t stack = stackCreate();
	//assert(stackIsEmpty(stack));
	//assert(stackSize(stack) == 0);

	ItemType cp264[] = { "C", "P", "2", "6", "4" };
	printf("Stack\n=====\n");
	//1
	for (int i = 0; i < 5; i++) {
		stackPush(&stack, cp264[i]);
	}
	printf("\nStack:     ");
	stackPrint(stack);

	//2
	stackPopAll(&stack);
	ItemType lab[] = { "L", "A", "B", "0", "6" };
	for (int j = 0; j < 5; j++) {
		stackPush(&stack, lab[j]);
	}
	for (int i = 0; i < 5; i++) {
		stackPush(&stack, cp264[i]);
	}
	printf("\nStack:     ");
	stackPrint(stack);

	//3
	stackPopAll(&stack);
	for (int i = 0; i < 5; i++) {
		stackPush(&stack, cp264[i]);
	}
	printf("\nStack:     ");
	stackPrint(stack);

	//4
	for (int k = 0; k < 5; k++)
		stackPop(&stack);
	printf("\nStack:     ");
	printf("\n\nis the stack empty? (1-yes 0-no) %d\n", stackIsEmpty(stack));

	printf("\nQueue\n======\n");
	Queue_t q = qCreate();
	//assert(qIsEmpty(q));
	//assert(qLength(q) == 0);
	ItemType halloween[] = { "-", "H", "a", "l", "l", "o", "w", "e", "e", "n" };
	//1
	for (int n = 0; n < 6; n++) {
		qEnqueue(&q, halloween[n]);
	}
	printf("\nQueue:     ");
	qPrint(q);

	//2
	for (int n = 0; n < 6; n++) {
		qDequeue(&q);
	}
	for (int n = 0; n < 5; n++) {
		qEnqueue(&q, halloween[n]);
	}
	printf("\nQueue:     ");
	qDequeue(&q);
	qPrint(q);

	//3
	for (int n = 0; n < 5; n++) {
		qDequeue(&q);
	}
	for (int n = 0; n < 10; n++) {
		qEnqueue(&q, halloween[n]);
	}
	printf("\nQueue:     ");
	qDequeue(&q);
	qPrint(q);
}
