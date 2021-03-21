/*
 -------------------------------------
 File:    dllist.h
 Project: CP264-a5
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-26
 -------------------------------------
 */
#ifndef DLLIST_H_
#define DLLIST_H_

#include <stdio.h>
#include <stdlib.h>

// your code
typedef struct node {
	char data;
	struct node *prev;
	struct node *next;
} NODE;

NODE* new_node(char data);
void display_forward(NODE *start);
void display_backward(NODE *end);
void insert_start(NODE **startp, NODE **endp, NODE *new_np);
void insert_end(NODE **startp, NODE **endp, NODE *new_np);
void delete_start(NODE **startp, NODE **endp);
void delete_end(NODE **startp, NODE **endp);
void clean(NODE **startp, NODE **endp);

#endif
