/*
 -------------------------------------
 File:    myrecord.h
 Project: CP264-a4q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-11
 -------------------------------------
 */

#ifndef MYRECORD_H
#define MYRECORD_H

/*
 Define a structure named RECORD to hold a person's name of 20 characters and the score of float type.
 */
typedef struct record {
// your design
	char name[20];
	float score;
} RECORD;
/*
 Define a structure named REPORT containing fields int count, float mean, float stddev (standard deviation).
 */
typedef struct {
// your design
	int count;
	float mean;
	float stddev;
} REPORT;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);
REPORT report_data(RECORD dataset[], int n, char *filename);

#endif
