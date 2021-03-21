/*
 -------------------------------------
 File:    myrecord_llist.c
 Project: CP264-a5
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-26
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_llist.h"

void display(NODE *start) {
	NODE *np = start;
	while (np != NULL) {
		printf("%s,%.1f\n", np->data.name, np->data.score);
		np = np->next;
	}
}

NODE* search(NODE *startp, char *name) {
// your implementation
	NODE *curr = startp;
	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void insert(NODE **startp, char *name, float score) {
// your implementation
	NODE *p = (NODE*) malloc(sizeof(NODE));
	strcpy(p->data.name, name);
	p->data.score = score;
	p->next = NULL;
	NODE *prev = NULL;
	NODE *ptr = *startp;
	while (ptr != NULL) {
		if (strcmp(ptr->data.name, name) >= 0)
			break;
		prev = ptr;
		ptr = ptr->next;
	}

	if (prev == NULL) {
		*startp = p;
		p->next = ptr;
	} else {
		prev->next = p;
		p->next = ptr;
	}
}

int delete(NODE **startp, char *name) {
// your implementation
	NODE *curr = *startp;
	NODE *prev = NULL;

	while (curr != NULL) {
		if (strcmp(curr->data.name, name) == 0)
			break;
		prev = curr;
		curr = curr->next;
	}

	if (curr != NULL) {
		prev->next = curr->next;
		free(curr);
		return 1;
	} else {
		return 0;
	}
}

void clean(NODE **startp) {
	// your implementation
	NODE *curr = *startp;
	NODE *prev = NULL;

	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	*startp = NULL;
}

// the following functions are adapted and modified from previous assignments.
char letter_grade(float s) {
	char g[] = { 'S', 'A', 'B', 'C', 'D', 'F' };
	float b[] = { 100, 90, 80, 70, 60, 50, 0 };
	int left = 0, right = sizeof(b) / sizeof(float) - 1;

	for (int i = left; i < right + 1; i++) {
		if (s <= b[i] && s >= b[i + 1])
			left = i;
	}
	if (right == left)
		return g[left - 1];
	else
		return g[left];

}

int import_data(NODE **startp, char *filename) {
	char line[40], name[20];
	char *result = NULL;
	char delimiters[] = ",";
	float score = 0;
	int count = 0;

	FILE *fp = fopen(filename, "r");

	while (fgets(line, sizeof(line), fp) != NULL) {
		result = strtok(line, delimiters);
		strcpy(name, result);
		result = strtok(NULL, delimiters);
		score = atof(result);
		insert(startp, name, score);
		count++;
	}
	fclose(fp);

	return count;
}

REPORT report_data(NODE *start, char *filename) {
	REPORT report = { };
	NODE *np = start;
	int count = 0;
	float mean = 0;
	float stddev = 0;

	FILE *fp = fopen(filename, "w");
	while (np != NULL) {
		count++;
		mean += np->data.score;
		stddev += np->data.score * np->data.score;
		fprintf(fp, "%s,%3.1f,%c\n", np->data.name, np->data.score,
				letter_grade(np->data.score));
		np = np->next;
	}
	fclose(fp);

	mean /= count;
	stddev = sqrt(stddev / count - mean * mean);
	report.count = count;
	report.mean = mean;
	report.stddev = stddev;
	return report;
}

