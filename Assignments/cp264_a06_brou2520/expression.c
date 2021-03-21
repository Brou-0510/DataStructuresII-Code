/*
 -------------------------------------
 File:    expression.c
 Project: CP264-a6q3
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
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function
 */
int get_priority(char op) {
	if (op == '/' || op == '*' || op == '%')
		return 1;
	else if (op == '+' || op == '-')
		return 0;
	else
		return -1;
}

/*
 * auxiliary function
 */
int type(char c) {
	if (c >= '0' && c <= '9')
		return 0;
	else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
		return 1;
	else if (c == '(')
		return 2;
	else if (c == ')')
		return 3;
	else
		return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
	int index = 0;
	char *p = infixstr;
	QUEUE queue = { 0 };
	STACK stack = { 0 };
	int sign = 1, num = 0;
	NODE *temp = { 0 }; // stores popped
	while (*p) {
		int curr = type(*p); // store current
		if (*p == '-' && (p == infixstr || *(p - 1) == '(')) // get sign of operand
			sign = -1;
		else if (curr == 0) { // operand
			// use horners algo to get operand
			num = *p - '0';
			while (type(*(p + 1)) == 0) {
				num = num * 10 + *(p + 1) - '0';
				p++;
			}
			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;
		} else if (curr == 1) { // operator
			while (stack.top
					&& get_priority(*p)
							< get_priority((temp = pop(&stack))->data)) {
				if (temp->type != 2 && temp->type != 3)
					enqueue(&queue, temp);
			}
			if (temp && get_priority(*p) >= get_priority(temp->data)) {
				push(&stack, temp);
			}
			push(&stack, new_node(*p, type(*p)));
		} else if (curr == 2) { // (
			push(&stack, new_node(*p, type(*p)));
		} else if (curr == 3) { // )
			while (stack.top && (temp = pop(&stack))->type != 2) {
				enqueue(&queue, temp);
			}
		}
		p++;
		index++;
	}
	while (stack.top)
		enqueue(&queue, pop(&stack));
	clean_stack(&stack);
	return queue;
}

int evaluate_postfix(QUEUE queue) {
	NODE *p = queue.front;
	STACK stack = { 0 };  // auxiliary stack for postfix eval
	int type = 0;
	int temp;
	while (p) {
		type = p->type;
		if (type == 0) { // operand
			push(&stack, new_node(p->data, 0));
		} else if (type == 1) { // operator
			int p1 = pop(&stack)->data;
			int p2 = pop(&stack)->data;
			temp = 0;
			if (p->data == '+')
				temp = p2 + p1;
			else if (p->data == '-')
				temp = p2 - p1;
			else if (p->data == '*')
				temp = p2 * p1;
			else if (p->data == '/')
				temp = p2 / p1;
			push(&stack, new_node(temp, 0));
		}
		p = p->next;
	}
	int result = stack.top->data;
	return result;
}

int evaluate_prefix(char *infixstr) {
// your implementation$
	//1. call infix_to_postfix() compute the postfix expression queue
	//2. call evaluate_postfix() to evaluate the postfix expression to get a value
	//3. clean the postfix expression queue to avoid memory leaking
	//4. return the value
	QUEUE eq = infix_to_postfix(infixstr);
	int pre = evaluate_postfix(eq);
	clean_queue(&eq);
	return pre;
}

