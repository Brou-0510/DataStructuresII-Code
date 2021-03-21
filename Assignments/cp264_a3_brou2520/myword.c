/*
 -------------------------------------
 File:    mystring.c
 Project: CP264-a3q2
 file description
 -------------------------------------
 Author:  Paige Broussard
 ID:      190832520
 Email:   brou2520@mylaurier.ca
 Version  2021-02-03
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "myword.h"
#include "mystring.h"

void set_stopword(char *filename, char *stopwords[]) {
// your implementation, refer to class code example 22 -- csv file read with string value

	FILE *fp = fopen(filename, "r");
	char line[1000];
	char delimiters[] = ".,\n\t\r";
	char *token;
	int i;

	if (fp == NULL) {
		printf("file opening error?!?!!!!!");
		return;
	} else {
		printf("file is opened alright\n");
		while (fgets(line, 1000, fp) != NULL) {
			token = (char*) strtok(line, delimiters);
			while (token != NULL) {
				i = (int) (*token - 'a');
				strcat(stopwords[i], token);
				strcat(stopwords[i], ",");
				token = (char*) strtok(NULL, delimiters);
			}
		}
	}
	fclose(fp);
	return;
}

// this function check if word is a word in string str,
// returns 1 if yes, 0 otherwise
int contain_word(char *str, char *word) {
	if (str == NULL || word == NULL)
		return 0;
	// your code

	char temp[20] = { 0 };
	strcat(temp, ","); // using , as word separator
	strcat(temp, word);
	strcat(temp, ",");

	if (strstr(str, temp))
		return 1;
	else
		return 0;
	return 0;
}

// this function check if the word is contained in directory stopwords[]
// returns 1 if yes, 0 otherwise. It use function contain_word()
int is_stopword(char *stopwords[], char *word) {
// your code
	if (word == NULL || *word == '\0')
		return 0;
	else {
		return contain_word(stopwords[*word - 'a'], word);
	}
}

int process_word(char *filename, WORDSUMMARY *ws, char *stopwords[]) {
	const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
	// your implementation

	FILE *fp = fopen(filename, "r");
	char line[1000];
	char *token;
	int i;
	int found = 0;

	while (fgets(line, MAX_LINE_LEN, fp) != NULL) { // all lines
		ws->line_count++;
		lower_case(line);
		trim(line);
		token = (char*) strtok(line, delimiters);

		while (token != NULL) { // all words in line
			ws->word_count++;
			if (is_stopword(stopwords, token) == 0) {
				for (i = 0; i < ws->keyword_count - 1; i++) {
					if (strcmp(token, ws->word_array[i].word) == 0) {
						ws->word_array[i].frequency++;
						found = 1;
						break;  // enough
					}
				}
				if (found == 0) {
					i = ws->keyword_count;
					strcpy(ws->word_array[i].word, token);
					ws->word_array[i].frequency = 1;
					ws->keyword_count++;
				}
			}
			token = (char*) strtok(NULL, delimiters);
			found = 0;
		}
	}
	fclose(fp);
	return 0;
}

int save_to_file(char *filename, WORDSUMMARY *ws) {
// your implementation
	FILE *fp = fopen(filename, "w");
	fprintf(fp, "%s:%d\n", "line count", ws->line_count);
	fprintf(fp, "%s:%d\n", "word count", ws->word_count);

	fprintf(fp, "%s:%d\n", "non-common word count", ws->keyword_count);

	int i;
	for (i = 0; i < ws->keyword_count; i++) {
		WORD word = ws->word_array[i];
		fprintf(fp, "%s:%d\n", word.word, word.frequency);
	}
	fclose(fp); // display_word_summary displays rest
	return 1;
}
