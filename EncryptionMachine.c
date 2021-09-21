//

#include <stdio.h>
#include <stdlib.h>

const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
#define SHIFT 3


void printIntro() {
	char* intro = "";
	sprintf(intro, "Welcome to the CSE142 Encryption Machine\n");
	sprintf(intro + strlen(intro), "The program lets you encrypt a message\n");
	sprintf(intro + strlen(intro), "with a key for your recipient to decrypt!\n\n");
	puts(intro);
}

/*@param */
void encryptLetter(char letter) {

}

/*@param */
void encryptWord(char word[]) {
}

int main() {
	printIntro();
	return 0;
}
