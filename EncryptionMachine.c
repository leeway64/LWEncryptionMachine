#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "EncryptionMachine.h"

const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
//const char* ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const char* ALPHABET = "0123456789";
//const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz0123456789";

#define SHIFT 3


void printIntro() {
    // The longest line is 43 characters long.
    char intro[43] = "Welcome to the CSE142 Encryption Machine";
    puts(intro);
    sprintf(intro, "The program lets you encrypt a message");
    puts(intro);
    sprintf(intro, "with a key for your recipient to decrypt!\n");
    puts(intro);
}

//// Encrypts a user-entered cryptographic key.
void encryptKey() {
	char key[128];
	char encryptedKey[128];

	printf("%s", "Encrypted messages use a shared keyword to decrypt.\n");
	printf("%s", "  Enter key: ");
	fgets(key, 128, stdin);
	
	key[strlen(key) - 1] = '\0';  // Remove the newline character captured by fgets
	strcpy(encryptedKey, key);
	encryptWord(encryptedKey);
	printf("    \"%s\" has been encrypted to: %s\n\n", key, encryptedKey);
}

/// Encrypts a certain message by using a cipher. The user enters the number of words to be encrypted,
/// and the program encrypts the following user-entered words.
void encryptMessage() {
	uint64_t numberOfWords;
	printf("How many words is your message? ");
	scanf("%d", &numberOfWords);

	// There is a remaining newline character left from stdin that isn't read by stdin. Read that,
	// but don't do anything with it.
	getchar();
	for (int i = numberOfWords; i > 0; --i) {
		char word[128];
		char encryptedWord[128];
		printf("  Next word: ");
		fgets(word, 128, stdin);

		word[strlen(word) - 1] = '\0';  // Remove the newline character captured by fgets
		strcpy(encryptedWord, word);
		encryptWord(encryptedWord);
		printf("    \"%s\" has been encrypted to: %s\n", word, encryptedWord);
	}

	printf("\nMessage fully encrypted. Happy secret messaging!\n");
}

/// Encrypts 1 letter using a Caesar cipher. The letter is encrypted by shifting the letter's position
/// in ALPHABET SHIFT spaces to the right. It basically replaces the letter with another letter further
/// down in the alphabet.
/// @param letter: The char to encrypt
/// @return The encrypted char
char encryptLetter(char letter) {
	int alphabetLength = strlen(ALPHABET);
	int oldLetterIndex = indexOf(letter);
	int newLetterIndex = (oldLetterIndex + SHIFT) % alphabetLength;

	char encryptedLetter = ALPHABET[newLetterIndex];
	return encryptedLetter;
}

/// Encrypt a word using a Ceasar cipher.
/// @param word is the string to be encrypted using the cipher. word is modified in-place.
void encryptWord(char word[]) {
	for (int i = 0; i < strlen(word); ++i)
	{
		word[i] = encryptLetter(word[i]);
	}
}

/// Finds the index of a letter in ALPHABET.
/// @param letter is the char whose index is to be found in ALPHABET.
/// @return The index of letter in ALPHABET, or -1 if the index is not found.
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
