#include <stdio.h>
#include <stdlib.h>
#include "EncryptionMachine.h"

const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
#define SHIFT 3


void printIntro() {
	char* intro = "";
	sprintf(intro, "Welcome to the CSE142 Encryption Machine\n");
	sprintf(intro + strlen(intro), "The program lets you encrypt a message\n");
	sprintf(intro + strlen(intro), "with a key for your recipient to decrypt!\n\n");
	puts(intro);
}

int indexOf(char letter) {
	for (int i = 0; i < stringLength(ALPHABET); ++i)
	{
		if (letter == ALPHABET[i])
		{
			return i;
		}
	}
	return -1;
}

int stringLength(char* string) {
	int i = 0;
	while (string[i] != '\n')
	{
		++i;
	}
	return i;
}

/* @param letter: the letter to encrypt
*/
char encryptLetter(char letter) {
	int alphabetLength = stringLength(ALPHABET);
	int oldLetterIndex = indexOf(letter);
	int newLetterIndex = oldLetterIndex % alphabetLength;

	char encryptedLetter = ALPHABET[newLetterIndex];
	return encryptedLetter;
}

/*@param */
void encryptWord(char word[]) {
}
