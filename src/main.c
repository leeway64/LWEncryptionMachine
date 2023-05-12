#include "LWEncryptionMachine.h"

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Incorrect number of arguments. Enter the alphabet and the number of letters to be shifted.\n");
        printf("For example: LWEncryptionMachine abcdefghijklmnopqrstuvwxyz0123456789 3\n");
        exit(1);
    }
    
    printIntro();
	encryptKey();
	encryptMessage();
	return 0;
}
