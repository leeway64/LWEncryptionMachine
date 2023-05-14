// A program to encrypt a cryptographic key and a message using a Caesar cipher.

void printIntro(char *ALPHABET, char *SHIFT);

void encryptKey(char *ALPHABET, int SHIFT);

void encryptMessage(char *ALPHABET, int SHIFT);

char encryptLetter(char letter, char *ALPHABET, int SHIFT);

void encryptWord(char word[], char *ALPHABET, int SHIFT);

int indexOf(char letter, const char *ALPHABET);
