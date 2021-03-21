/*
 -------------------------------------
 File:    bst.c
 Project: CP264-a7q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-03-11
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bst.h"

TNODE* search(TNODE *root, char *name) {
// your implementation
	while (root) {
		if (strcmp(root->data.name, name) == 0)
			return root;
		else if (strcmp(root->data.name, name) > 0)
			root = root->left;
		else if (strcmp(root->data.name, name) < 0)
			root = root->right;

	}
	return NULL;
}

void insert(TNODE **rootp, char *name, float score) {
// your implementation
	if (*rootp == NULL) {
		RECORD data = { { 0 } };
		TNODE *newnp = (TNODE*) malloc(sizeof(TNODE));
		strncpy(data.name, name, 39);

		data.score = score;
		newnp->data = data;
		newnp->right = NULL;
		newnp->left = NULL;

		*rootp = newnp;
		return;
	} else {
		if (strcmp(name, (*rootp)->data.name) > 0)
			insert(&(*rootp)->right, name, score);
		else if (strcmp(name, (*rootp)->data.name) < 0)
			insert(&(*rootp)->left, name, score);
		else
			return;
	}
}
void delete(TNODE **rootp, char *name) {
// your implementation
	TNODE *root = *rootp, *tnp;
	if (root == NULL)
		return;
	else if (0 == strcmp(name, (*rootp)->data.name)) {
		if (root->left == NULL && root->right == NULL) {
			free(rootp);
			*rootp = NULL;
		} else if (root->left != NULL && root->right == NULL) {
			tnp = (*rootp)->left;
			free(rootp);
			*rootp = tnp;
		} else if (root->left == NULL & root->right != NULL) {
			tnp = (*rootp)->right;
			free(rootp);
			*rootp = tnp;
		} else if (root->left != NULL && root->right != NULL) {
			tnp = extract_smallest_node(&root->right);
			tnp->left = (*rootp)->left;
			tnp->right = (*rootp)->right;
			free(rootp);
			*rootp = tnp;
		}
	} else {
		if (0 < strcmp(name, (*rootp)->data.name))
			delete(&(*rootp)->left, name);
		else
			delete(&(*rootp)->left, name);
	}
}

TNODE* extract_smallest_node(TNODE **rootp) {
// your implementation
	if (*rootp == NULL || (*rootp)->left == NULL)
		return *rootp;
	else
		return extract_smallest_node(&(*rootp)->left);
}

void display_inorder(TNODE *root) {
	if (root) {
		if (root->left)
			display_inorder(root->left);
		printf("%-15s%3.1f\n", root->data.name, root->data.score);
		if (root->right)
			display_inorder(root->right);
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
