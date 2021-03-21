/*
 -------------------------------------
 File:    myrecord.c
 Project: CP264-a4q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-11
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_LINE 100

/*
 This function converts a float score to a letter grade according to ranges  S=[90, 100], A=[80, 90), B=[70, 80), C=[60, 70), D=[50,60), F=[0,50), and returns the letter grade.
 */
char letter_grade(float s) {
// your implementation
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

	/* alternate letter_grade i made before i figured out the binary search for increasing order
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

	 return r;
	 */
}
/*
 This function imports data from file of name passed by filename, and stores all record entries in an array of RECORD dataset[], and returns the number of records read.
 */
int import_data(RECORD dataset[], char *filename) {
// your implementation
	FILE *fp;
	char delimiters[] = ",\n\r";
	char line[100];
	int i = 0;  // record counter
	char *token = NULL;
	fp = fopen(filename, "r");
	while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char*) strtok(line, delimiters);
		strcpy(dataset[i].name, token); // copy string char array
		token = (char*) strtok(NULL, delimiters);
		dataset[i].score = atof(token); // convert string to float
		i++;
	}
	fclose(fp);
	return i; // # of records
}
/*
 This function computes the average score, and standard deviation of the score values of dataset[], and returns the results by the RECORD type. It also outputs name and letter grade to file of name passed by filename, using format "%s,%c\n"
 */
REPORT report_data(RECORD dataset[], int n, char *filename) {
	REPORT report = { };
	if (n < 1)
		return report;

// your implementation
	FILE *fp;
	fp = fopen(filename, "w");
	int i;
	int count = n;
	float mean = 0;
	float stddev = 0;

	for (i = 0; i < n; i++) {
		fprintf(fp, "%-10s%c\n", dataset[i].name,
				letter_grade(dataset[i].score));
	}
	for (i = 0; i < n; i++) {
		mean += dataset[i].score;
	}
	mean /= count;
	for (i = 0; i < n; i++) {
		stddev += (dataset[i].score - mean) * (dataset[i].score - mean);
	}
	stddev = sqrt(stddev / count);

	fprintf(fp, "\n%-10s%d\n", "count:", report.count = count);
	fprintf(fp, "%-10s%0.1f\n", "mean:", report.mean = mean);
	fprintf(fp, "%-10s%0.1f\n", "stddev:", report.stddev = stddev);
	fclose(fp);
	return report;
}
