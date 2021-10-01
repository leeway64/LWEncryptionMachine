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

void encryptKey() {
	char key[128];
	char encryptedKey[128];

	char* text = "";
	sprintf(text, "Encrypted messages use a shared keyword to decrypt.\n");
	sprintf(text + strlen(text), "  Enter key: ");
	printf("%s", text);
	fgets(key, 128, stdin);
	
	key[strlen(key) - 1] = '\0';  // Remove the newline character captured by fgets
	strcpy(encryptedKey, key);
	encryptWord(encryptedKey);
	printf("    \"%s\" has been encrypted to: %s\n", key, encryptedKey);
}

void encryptMessage() {
	printf("How many words is your message? ");
	printf("Message fully encrypted. Happy secret messaging!");
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
