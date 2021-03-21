/*
 -------------------------------------
 File:    queue.h
 Project: CP264-a6q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-05
 -------------------------------------
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

typedef struct queue {
	NODE *front;
	NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE* dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif
