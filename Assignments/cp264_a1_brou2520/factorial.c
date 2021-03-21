/*
 -------------------------------------
 File:    factorial.c
 Project: CP264-a1q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-18
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
	int i, n = 0, f = 1, prev, is_overflow = 0;

	if (argc > 1) {
		n = atoi(args[1]);  // convert command line argument to an integer

		if (n >= 1) {         // the conversion is successful
			// your solution logic code
			int count = 0;
			printf("factorial %d\n", n);

			for (i = 1; i <= n; i++) {

				prev = f;
				f *= i;

				if (prev != f / i) {
					printf("\noverflow %d\n", i);
					break;
				}
				printf("%11d", f);
				count++;

				if (count == 4) {
					printf("\n");
					count = 0;
				}
				if (i == n) {
					printf("\n%d!:%d\n", n, f);
					break;
				}

			}

		} else {
			printf("%s:invalid argument\n", args[1]);
		}
	} else {
		printf("no argument");
	}
	return 0;
}

