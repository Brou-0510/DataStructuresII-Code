/*
 -------------------------------------
 File:    expression.h
 Project: CP264-a6q3
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-05
 -------------------------------------
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "common.h"
#include "queue.h"

/*
 * convert infix expression in string to postfix expression represented by QUEUE and return the postfix expression queue.
 */
QUEUE infix_to_postfix(char *infixstr);

/*
 * evaluate and returns the value postfix expression passed by queue.
 */
int evaluate_postfix(QUEUE queue);

/*
 * evaluate and return the value of prefix expression passed by string infixstr, using infix_to_postfix() and evaluate_postfix() functions.
 */
int evaluate_prefix(char *infixstr);

#endif
