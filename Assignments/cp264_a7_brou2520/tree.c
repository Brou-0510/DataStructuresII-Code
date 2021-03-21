/*
 -------------------------------------
 File:    tree.c
 Project: CP264-a7q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-10
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TPROPS get_props(TNODE *root) {
	// your implementation;
	TPROPS r = { 0 };
	int right;

	int left;
	if (root == NULL)
		return r;
	else {
		r.count = 1 + get_props(root->left).count
				+ get_props(root->right).count;
		right = 1 + get_props(root->right).height;
		left = 1 + get_props(root->left).height;

		r.height = right > left ? right : left;

		return r;
	}
}

void display_preorder(TNODE *root) {
// your implementation
	if (root) {
		printf("%c ", root->data);
		display_preorder(root->left);
		display_preorder(root->right);
	}
}

void display_inorder(TNODE *root) {
// your implementation
	if (root) {
		display_inorder(root->left);
		printf("%c ", root->data);
		display_inorder(root->right);
	}
}

void display_postorder(TNODE *root) {
// your implementation
	if (root) {
		display_postorder(root->left);
		display_postorder(root->right);
		printf("%c ", root->data);
	}
}

TNODE* iterative_bf_search(TNODE *root, int val) {
// your implementation
	QUEUE queue = { 0 }; // aux queue
	TNODE *r = NULL, *p = NULL;
	if (root == NULL)
		return r;
	else {
		enqueue(&queue, root);
		while (queue.front) {
			p = dequeue(&queue);
			if (p->data == val) {
				clean_queue(&queue);
				return p;
			}
			if (p->left)
				enqueue(&queue, p->left);
			if (p->right)
				enqueue(&queue, p->right);
		}
	}

	clean_queue(&queue);

	return r;
}

TNODE* iterative_df_search(TNODE *root, int val) {
// your implementation
	STACK stack = { 0 };
	TNODE *r = NULL, *p = NULL;

	if (root == NULL)
		return r;

	else {
		push(&stack, root);

		while (stack.top) {
			p = peek(&stack);
			pop(&stack);
			if (p->data == val) {
				clean_stack(&stack);
				return p;
			}
			if (p->right)
				push(&stack, p->right);
			if (p->left)
				push(&stack, p->left);
		}

	}
	clean_stack(&stack);

	return r;
}

/* basic functions */
TNODE* new_node(int value) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np == NULL)
		return NULL;
	np->data = value;
	np->left = NULL;
	np->right = NULL;
	return np;
}

void display_tree(TNODE *root, int prelen) {
	if (root) {
		int i;
		for (i = 0; i < prelen; i++)
			printf("%c", ' ');
		printf("%s", "|___");
		printf("%c\n", root->data);
		display_tree(root->right, prelen + 4);
		display_tree(root->left, prelen + 4);
	}
}

void clean_tree(TNODE **rootp) {
	TNODE *root = *rootp;
	if (root) {
		if (root->left)
			clean_tree(&root->left);
		if (root->right)
			clean_tree(&root->right);
		free(root);
	}
	*rootp = NULL;
}

// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data) {
	QNODE *p = (QNODE*) malloc(sizeof(QNODE));
	if (p == NULL)
		return;
	else {
		p->data = data;
		p->next = NULL;

		if (qp->front == NULL) {
			qp->front = p;
			qp->rear = p;
		} else {
			(qp->rear)->next = p;
			qp->rear = p;
		}
	}
}
void* dequeue(QUEUE *qp) {
	void *temp = NULL;
	if (qp->front) {
		QNODE *p = qp->front;
		temp = p->data;
		if (qp->front == qp->rear) {
			qp->front = NULL;
			qp->rear = NULL;
		} else {
			qp->front = p->next;
		}
		free(p);
		return temp;
	}
	return NULL;
}
void clean_queue(QUEUE *qp) {
	QNODE *temp, *p = qp->front;
	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
	}
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data) {
	SNODE *p = (SNODE*) malloc(sizeof(SNODE));
	p->data = data;
	p->next = NULL;
	if (sp->top == NULL) {
		sp->top = p;
	} else {
		p->next = sp->top;
		sp->top = p;
	}
}
void pop(STACK *sp) {
	if (sp->top != NULL) {
		SNODE *p = sp->top;
		sp->top = p->next;
		free(p);
	}
}
void* peek(STACK *sp) {
	if (sp->top != NULL) {
		return sp->top->data;
	}
	return NULL;
}
void clean_stack(STACK *sp) {
	SNODE *temp, *p = sp->top;
	while (p) {
		temp = p;
		p = p->next;
		free(temp);
	}
	sp->top = NULL;
}
