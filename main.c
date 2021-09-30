// 

#include <stdio.h>
#include <stdlib.h>
#include "EncryptionMachine.h"


int main() {
	char key[128];
	printIntro();
	getKey(key);
	return 0;
}
