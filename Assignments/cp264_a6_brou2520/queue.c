/*
 -------------------------------------
 File:    queue.c
 Project: CP264-a6q1
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
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
	if (qp->front == NULL || qp->rear == NULL) {
		qp->front = np;
		qp->rear = np;
	} else {    // Queue has elements, add to rear
		qp->rear->next = np;
		qp->rear = np;
	}
}

NODE* dequeue(QUEUE *qp) {
	if (qp->front == NULL || qp->rear == NULL)
		return NULL;
	NODE *np = qp->front;
	qp->front = qp->front->next;
	np->next = NULL;
	return np;
}

void clean_queue(QUEUE *qp) {
	NODE *curr = qp->front;
	NODE *prev = NULL;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	qp = NULL;
}

