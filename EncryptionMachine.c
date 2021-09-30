#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	for (int i = 0; i < strlen(ALPHABET); ++i)
	{
		if (letter == ALPHABET[i])
		{
			return i;
		}
	}
	return -1;
}

void getKey(char* str) {
	char* text = "";
	sprintf(text, "Encrypted messages use a shared keyword to decrypt.\n");
	sprintf(text + strlen(text), "Enter key: ");
	puts(text);
}

/* @param letter: the letter to encrypt
*/
char encryptLetter(char letter) {
	int alphabetLength = strlen(ALPHABET);
	int oldLetterIndex = indexOf(letter);
	int newLetterIndex = (oldLetterIndex + SHIFT) % alphabetLength;

	char encryptedLetter = ALPHABET[newLetterIndex];
	return encryptedLetter;
}

/*@param */
void encryptWord(char word[]) {
	for (int i = 0; i < strlen(word); ++i)
	{
		word[i] = encryptLetter(word[i]);
	}

}
