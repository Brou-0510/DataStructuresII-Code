/*
 -------------------------------------
 File:    mysort.c
 Project: CP264-a4q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-11
 -------------------------------------
 */

#include "mysort.h"

/*
 Define an enumeration type named BOOLEAN with name false as 0 and true as 1. (in mysort.h)
 */

/*
 This function tests if array a[n] is sorted in increasing order between index left and right, and returns true if yes, otherwise false.
 */
BOOLEAN is_sorted(int *a, int left, int right) {
// your implementation
	for (int i = left; i <= right - 1; i++) {
		if (*(a + i) > *(a + i + 1))
			return false;
	}
	return true;
}
/*
 This function swaps the values at referenced locations. It is an auxiliary function for the sorting functions.
 */
void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}
/*
 This function sorts the elements of int array *a from index left to right in increasing order, using the selection sort algorithm.
 */
void select_sort(int *a, int left, int right) {
// your implementation
	int i, j, k;
	for (i = left; i <= right; i++) {
		k = i;
		for (j = i + 1; j <= right; ++j) {
			if (*(a + j) < *(a + k)) {
				k = j;
			}
		}
		if (i != k) {
			swap(a + k, a + i);
		}
	}
}

/*
 This function sorts the elements of int array *a from index left to right in increasing order, using the quick sort algorithm.
 */
void quick_sort(int *a, int left, int right) {
// your implementation
	int key, i, j;
	if (left < right) {
		key = left;
		i = left;
		j = right;

		while (i < j) {
			while (*(a + i) <= *(a + key))
				i++;
			while (*(a + j) > *(a + key))
				j--;
			if (i < j)
				swap(a + i, a + j);
		}
		swap(a + j, a + key);
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}

