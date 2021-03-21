/*
 -------------------------------------
 File:    avl.c
 Project: CP264-a8q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-19
 -------------------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl.h"

// A utility functions
int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(TNODE *np) {
// your implementation
	int height;

	height = 0;
	if (np)
		height = np->height;

	return height;
}

int balance_factor(TNODE *np) {
// your implementation
	int bf;
	if (np) {
		if (np->left && np->right)
			bf = np->left->height - np->right->height;
		else if (np->left && !np->right)
			bf = np->left->height;
		else if (!np->left && np->right)
			bf = 0 - np->right->height;
		else
			bf = -1;
	}
	return bf;
}

int is_avl(TNODE *root) {
// your implementation
	if (root == NULL) {
		return 1;
	} else {
		int bf = balance_factor(root);

		if (bf > 1 || bf < -1)
			return 0;
		if (is_avl(root->left) == 0)
			return 0;
		if (is_avl(root->right) == 0)
			return 0;

		return 1;
	}
}

TNODE* rotate_right(TNODE *y) {
// your implementation
	TNODE *temp1 = y->left;
	TNODE *temp2 = temp1->right;

	temp1->right = y;
	y->left = temp2;

	y->height = 1 + max(height(y->left), height(y->right));
	temp1->height = 1 + max(height(temp1->left), height(temp1->right));

	return temp1;
}

TNODE* rotate_left(TNODE *x) {
// your implementation
	TNODE *temp1 = x->right;
	TNODE *temp2 = temp1->left;

	temp1->left = x;
	x->right = temp2;

	x->height = 1 + max(height(x->left), height(x->right));
	temp1->height = 1 + max(height(temp1->left), height(temp1->right));

	return temp1;
}

void insert(TNODE **rootp, char *name, float score) {
	TNODE *np = (TNODE*) malloc(sizeof(TNODE));
	if (np == NULL)
		return;
	strcpy(np->data.name, name);
	np->data.score = score;
	np->height = 1;
	np->left = NULL;
	np->right = NULL;

	// 1. Perform the normal BST insertion
	if (*rootp == NULL) {
		*rootp = np;
		return;
	}

	TNODE *root = *rootp;
	if (strcmp(name, root->data.name) < 0)
		insert(&root->left, name, score);
	else if (strcmp(name, root->data.name) > 0)
		insert(&root->right, name, score);
	else
		return;

	// 2. update height of this root node

	// add your code here
	root->height = 1 + max(height(root->right), height(root->left));

	// 3. Get the balance factor of this ancestor node to check whether this node became unbalanced

	// add your code here
	int bf = balance_factor(root);

	// 4. re-balance if not balanced

	// add your code here
	//heavier on left
	if (bf > 1) {
		if (balance_factor(root->left) >= 0)
			*rootp = rotate_right(root);
		else {
			root->left = rotate_left(root->left);
			*rootp = rotate_right(root);
		}
	}

	//heavier on right
	else if (bf < -1) {
		if (balance_factor(root->left) <= 0)
			*rootp = rotate_left(root);
		else {
			root->right = rotate_right(root->right);
			*rootp = rotate_left(root);
		}
	}

}

void delete(TNODE **rootp, char *name) {
	TNODE *root = *rootp;
	TNODE *np;

	if (root == NULL)
		return;

	if (strcmp(name, root->data.name) == 0) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			*rootp = NULL;
		} else if (root->left != NULL && root->right == NULL) {
			np = root->left;
			free(root);
			*rootp = np;
		} else if (root->left == NULL && root->right != NULL) {
			np = root->right;
			free(root);
			*rootp = np;
		} else if (root->left != NULL && root->right != NULL) {
			np = extract_smallest_node(&root->right);
			np->left = root->left;
			np->right = root->right;
			free(root);
			*rootp = np;
		}
	} else {
		if (strcmp(name, root->data.name) < 0) {
			delete(&root->left, name);
		} else {
			delete(&root->right, name);
		}
	}

	// If the tree had only one node then return
	if (*rootp == NULL)
		return;

	root = *rootp;

	// STEP 2: update the this root node's height

	// add your code here
	root->height = 1 + max(height(root->right), height(root->left));

	// STEP 3: get the balance factor of this root node

	// add your code here
	int bf = balance_factor(root);

	// STEP 4: re-balance if not balanced

	// add your code here
	//heavier on left
	if (bf > 1) {
		if (balance_factor(root->left) >= 0)
			*rootp = rotate_right(root);
		else {
			root->left = rotate_left(root->left);
			*rootp = rotate_right(root);
		}
	}

	//heavier on right
	else if (bf < -1) {
		if (balance_factor(root->left) <= 0)
			*rootp = rotate_left(root);
		else {
			root->right = rotate_right(root->right);
			*rootp = rotate_left(root);
		}
	}
}

// following functions are from bst.c of a7
TNODE* extract_smallest_node(TNODE **rootp) {
	TNODE *tnp = *rootp;
	TNODE *parent = NULL;
	if (tnp == NULL) {
		return NULL;
	} else {
		while (tnp->left) {
			parent = tnp;
			tnp = tnp->left;
		}
		if (parent == NULL)
			*rootp = tnp->right;
		else
			parent->left = tnp->right;
		tnp->left = NULL;
		tnp->right = NULL;
		return tnp;
	}
}

TNODE* search(TNODE *root, char *name) {
	TNODE *tp = root;
	while (tp) {
		if (strcmp(name, tp->data.name) == 0) {
			return tp;
		} else if (strcmp(name, tp->data.name) < 0)
			tp = tp->left;
		else
			tp = tp->right;
	}
	return NULL;
}

void clean_tree(TNODE **rootp) {
	if (*rootp) {
		TNODE *np = *rootp;
		if (np->left)
			clean_tree(&np->left);
		if (np->right)
			clean_tree(&np->right);
		free(np);
	}
	*rootp = NULL;
}

void display_inorder(TNODE *root) {
	if (root) {
		if (root->left)
			display_inorder(root->left);
		printf("(%s %3.1f) ", root->data.name, root->data.score);
		if (root->right)
			display_inorder(root->right);
	}
}

void display_inorder_lines(TNODE *root) {
	if (root) {
		if (root->left)
			display_inorder_lines(root->left);
		printf("%-15s%.1f\n", root->data.name, root->data.score);
		if (root->right)
			display_inorder_lines(root->right);
	}
}

void display_tree(TNODE *root, int prelen) {
	if (root) {
		int i;
		for (i = 0; i < prelen; i++)
			printf("%c", ' ');
		printf("%s", "|___");
		printf("%s %.1f %d\n", root->data.name, root->data.score, root->height);
		display_tree(root->right, prelen + 4);
		display_tree(root->left, prelen + 4);
	}
}
