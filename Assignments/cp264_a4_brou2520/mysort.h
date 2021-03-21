/*
 -------------------------------------
 File:    mysort.h
 Project: CP264-a4q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-11
 -------------------------------------
 */

#ifndef MYSORT_H
#define MYSORT_H

// define enum type BOOLEAN
typedef enum {
	false, true
} BOOLEAN;
BOOLEAN is_sorted(int *a, int left, int right);
void select_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);

#endif
