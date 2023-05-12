#include "LWEncryptionMachine.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Incorrect number of arguments. Enter the alphabet and the number of letters to be shifted by.\n");
        printf("For example: LWEncryptionMachine abcdefghijklmnopqrstuvwxyz0123456789 3\n");
        exit(1);
    }

    char *ALPHABET = argv[1];
    char *SHIFT_char = argv[2];

    int SHIFT = (int) SHIFT_char

    printIntro();
	encryptKey(ALPHABET, SHIFT);
	encryptMessage(ALPHABET, SHIFT);
	return 0;
}
