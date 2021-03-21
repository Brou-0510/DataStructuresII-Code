/*
 -------------------------------------
 File:    marks_bst.c
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
#include "marks_bst.h"

void add_data(MARKS *dsp, char *name, float score) {
// your implementation
	if (search(dsp->bst, name) == NULL) {
		insert(&dsp->bst, name, score);
		int count = dsp->count;
		float mean = dsp->mean;
		float stddev = dsp->stddev;
		dsp->count = count + 1;
		dsp->mean = (mean * count + score) / (count + 1);
		dsp->stddev = sqrt(
				score * score / (count + 1.0)
						+ (stddev * stddev + mean * mean)
								* (count / (count + 1.0))
						- dsp->mean * dsp->mean);
	} else {
		printf("record exit");
	}
}

void remove_data(MARKS *dsp, char *name) {
// your implementation
	TNODE *np = NULL;
	if ((np = search(dsp->bst, name)) != NULL) {
		float score = np->data.score;
		delete(&dsp->bst, name);

		//recompute statistics summary by removing an old one
		int count = dsp->count;
		float mean = dsp->mean;
		float stddev = dsp->stddev;
		dsp->count = count - 1;
		dsp->mean = (mean * count - score) / (count - 1.0);
		dsp->stddev = sqrt(
				(stddev * stddev + mean * mean) * (count / (count - 1.0))
						- score * score / (count - 1.0)
						- dsp->mean * dsp->mean);
	}
}

// the following are adopted and modified from previous assignments
char letter_grade(float s) {
	char r = 'F';
	if (s >= 90)
		r = 'S';
	else if (s >= 80)
		r = 'A';
	else if (s >= 70)
		r = 'B';
	else if (s >= 60)
		r = 'C';
	else if (s >= 50)
		r = 'D';
	else
		r = 'F';
	return r;
}

void display_marks(MARKS *dsp) {
	printf("%-15s%d\n", "count", dsp->count);
	printf("%-15s%3.1f\n", "mean", dsp->mean);
	printf("%-15s%3.1f\n", "stddev", dsp->stddev);
	display_inorder(dsp->bst);
}

void clean_marks(MARKS *dsp) {
	clean_tree(&dsp->bst);
	dsp->count = 0;
	dsp->mean = 0;
	dsp->stddev = 0;
}

void import_data(MARKS *ds, char *filename) {
	char line[40], name[20];
	FILE *fp = fopen(filename, "r");
	char *result = NULL;
	float score = 0;
	char delimiters[] = ",\n";

	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		result = strtok(line, delimiters);
		if (result) {
			strcpy(name, result);
			result = strtok(NULL, delimiters);
			score = atof(result);
			add_data(ds, name, score);
		}
	}
	fclose(fp);
}

void print_to_file_inorder(TNODE *root, FILE *fp) {
	if (root) {
		if (root->left)
			print_to_file_inorder(root->left, fp);
		fprintf(fp, "%s,%3.1f,%c\n", root->data.name, root->data.score,
				letter_grade(root->data.score));
		if (root->right)
			print_to_file_inorder(root->right, fp);
	}
}

void report_data(MARKS *dsp, char *filename) {
	FILE *fp = fopen(filename, "w");
	fprintf(fp, "%s:%d\n", "count", dsp->count);
	fprintf(fp, "%s:%.0f\n", "mean", dsp->mean);
	fprintf(fp, "%s:%.0f\n", "stddev", dsp->stddev);
	print_to_file_inorder(dsp->bst, fp);
	fclose(fp);
}
