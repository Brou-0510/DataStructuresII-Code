/*
 -------------------------------------
 File:    bst.h
 Project: CP264-a7q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-11
 -------------------------------------
 */

#ifndef BST_H
#define BST_H

typedef struct rec {
	char name[40];
	float score;
} RECORD;

typedef struct node {
	RECORD data;
	struct node *left;
	struct node *right;
} TNODE;

/* search bst by data.name */
TNODE* search(TNODE *root, char *name);

/* insert record (name, score) into bst using data.name as key */
void insert(TNODE **rootp, char *name, float score);

/* delete node of data.name from bst */
void delete(TNODE **rootp, char *name);

/* get and return and delete the node of the smallest data.name node from the bst */
TNODE* extract_smallest_node(TNODE **rootp);

/* display bst tree data by in-order */
void display_inorder(TNODE *root);

/* clean the tree */
void clean_tree(TNODE **rootp);
#endif
