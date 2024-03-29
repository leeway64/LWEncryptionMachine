#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "LWEncryptionMachine.h"


void printIntro(char *ALPHABET, char *SHIFT)
{
    // The longest line is 43 characters long.
    char intro[43] = "Welcome to LWEncryptionMachine";
    puts(intro);
    sprintf(intro, "The program lets you encrypt a message");
    puts(intro);
    sprintf(intro, "with a key for your recipient to decrypt!\n");
    puts(intro);
    
    printf("Alphabet entered: %s\n", ALPHABET);
    printf("Shift value entered: %s\n\n", SHIFT);
}

/// Encrypts a user-entered cryptographic key.
void encryptKey(char *ALPHABET, int SHIFT)
{
    char key[128];
    char encryptedKey[128];

    printf("%s", "Encrypted messages use a shared keyword to decrypt.\n");
    printf("%s", "  Enter key: ");
    fgets(key, 128, stdin);
    
    key[strlen(key) - 1] = '\0';  // Remove the newline character captured by fgets
    strcpy(encryptedKey, key);
    encryptWord(encryptedKey, ALPHABET, SHIFT);
    printf("    \"%s\" has been encrypted to: %s\n\n", key, encryptedKey);
}

/// Encrypts a certain message by using a cipher. The user enters the number of words to be encrypted,
/// and the program encrypts the following user-entered words.
void encryptMessage(char *ALPHABET, int SHIFT)
{
    uint64_t numberOfWords;
    printf("How many words is your message? ");
    scanf("%ld", &numberOfWords);

    // There is a remaining newline character left from stdin that isn't read by stdin. Read that,
    // but don't do anything with it.
    getchar();
    for (int i = numberOfWords; i > 0; --i)
    {
        char word[128];
        char encryptedWord[128];
        printf("  Next word: ");
        fgets(word, 128, stdin);

        word[strlen(word) - 1] = '\0';  // Remove the newline character captured by fgets
        strcpy(encryptedWord, word);
        encryptWord(encryptedWord, ALPHABET, SHIFT);
        printf("    \"%s\" has been encrypted to: %s\n", word, encryptedWord);
    }

    printf("\nMessage fully encrypted. Happy secret messaging!\n");
}

/// Encrypts 1 letter using a Caesar cipher. The letter is encrypted by shifting the letter's position
/// in ALPHABET SHIFT spaces to the right. It basically replaces the letter with another letter further
/// down in the alphabet.
/// @param letter: The char to encrypt
/// @return The encrypted char
char encryptLetter(char letter, char *ALPHABET, int SHIFT)
{
    const int alphabetLength = strlen(ALPHABET);
    const int oldLetterIndex = indexOf(letter, ALPHABET);
    const int newLetterIndex = (oldLetterIndex + SHIFT) % alphabetLength;

    char encryptedLetter = ALPHABET[newLetterIndex];
    return encryptedLetter;
}

/// Encrypt a word using a Caesar cipher.
/// @param word is the string to be encrypted using the cipher. word is modified in-place.
void encryptWord(char word[], char *ALPHABET, int SHIFT)
{
    for (int i = 0; i < strlen(word); ++i)
    {
        word[i] = encryptLetter(word[i], ALPHABET, SHIFT);
    }
}

/// Finds the index of a letter in ALPHABET.
/// @param letter is the char whose index is to be found in ALPHABET.
/// @return The index of letter in ALPHABET, or -1 if the index is not found.
int indexOf(char letter, const char *ALPHABET)
{
    for (int i = 0; i < strlen(ALPHABET); ++i)
    {
        if (letter == ALPHABET[i])
        {
            return i;
        }
    }
    return -1;
}
