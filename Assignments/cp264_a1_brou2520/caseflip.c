/*
 -------------------------------------
 File:    caseflip.c
 Project: CP264-a1q1
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-01-18
 -------------------------------------
 */

#include <stdio.h>
int main() {
	//the following two lines are for Eclipse console none-buffered output, in case you use Eclipse to do your assignment
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char c = 0, temp;

	do {
		printf("Please enter a character\n");
		scanf("%c", &c); //this is to get  character input from keyboard

		do { // this loop is to get rid of additional characters in stdin buffer
			scanf("%c", &temp);
			if (temp == '\n')
				break;
		} while (1);

		// implement your program logic here
		if (c == '*') { //check if quit

			break;
		} else if (c >= 'a' && c <= 'z') { //check if lower case

			printf("%c:%d,%c\n", c, c, c - 32);
		} else if (c >= 'A' && c <= 'Z') { //check if upper case

			printf("%c:%d,%c\n", c, c, c + 32);
		} else {

			printf("%c:invalid\n", c);
		}

	} while (1);
	printf("%c:quit\n", c);
	return 0;
}

