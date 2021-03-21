/*
 -------------------------------------
 File:    dllist.c
 Project: CP264-a5
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-26
 -------------------------------------
 */

#include "dllist.h"

NODE* new_node(char data) {
// your implementation
	NODE *p = (NODE*) malloc(sizeof(NODE));
	p->data = data;
	p->next = NULL;
	p->prev = NULL;

	return p;
}

void display_forward(NODE *np) {
// your implementation
	NODE *p = np;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next;
	}
}

void display_backward(NODE *np) {
// your implementation
	NODE *p = np;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->prev;
	}
}

void insert_start(NODE **startp, NODE **endp, NODE *new_np) {
// your implementation
	if (*startp == NULL && *endp == NULL) {
		*startp = new_np;
		*endp = new_np;
	} else {
		(*startp)->prev = new_np;
		new_np->next = *startp;
		*startp = new_np;
	}
}

void insert_end(NODE **startp, NODE **endp, NODE *new_np) {
// your implementation
	if (*startp == NULL && *endp == NULL) {
		*startp = new_np;
		*endp = new_np;
	} else {
		(*endp)->next = new_np;
		new_np->prev = *endp;
		*endp = new_np;
	}
}

void delete_start(NODE **startp, NODE **endp) {
// your implementation
	if (*startp != NULL && *endp != NULL) {
		NODE *temp = *startp;
		*startp = temp->next;
		(*startp)->prev = NULL;
	}
}

void delete_end(NODE **startp, NODE **endp) {
// your implementation
	if (*startp != NULL && *endp != NULL) {
		NODE *temp = *endp;
		*endp = temp->prev;
		(*endp)->next = NULL;
	}
}

void clean(NODE **startp, NODE **endp) {
// your implementation
	struct node *curr, *np = *startp;

	while (np != NULL) {
		curr = np;
		np = np->next;
		free(curr);
	}
	*startp = NULL;
	*endp = NULL;
}

