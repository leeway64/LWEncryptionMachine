#include <stdio.h>
#include "CuTest.h"
#include "../src/LWEncryptionMachine.h"


void testIndexOf(CuTest* tc) {
    CuAssertIntEquals(tc, indexOf('a'), 0);
    CuAssertIntEquals(tc, indexOf('b'), 1);
    CuAssertIntEquals(tc, indexOf('c'), 2);
    CuAssertIntEquals(tc, indexOf('s'), 18);
    CuAssertIntEquals(tc, indexOf('x'), 23);
    CuAssertIntEquals(tc, indexOf('y'), 24);
    CuAssertIntEquals(tc, indexOf('z'), 25);
}

// encryptLetter and encryptWord were tested with a SHIFT of 3 and an alphabet composed of the 26
// lowercase English letters.
void testEncryptLetter(CuTest* tc) {
    CuAssertIntEquals(tc, encryptLetter('a', "abcdefghijklmnopqrstuvwxyz", 3), 'd');
    CuAssertIntEquals(tc, encryptLetter('d', "abcdefghijklmnopqrstuvwxyz", 3), 'g');
    CuAssertIntEquals(tc, encryptLetter('e', "abcdefghijklmnopqrstuvwxyz", 3), 'h');
    CuAssertIntEquals(tc, encryptLetter('f', "abcdefghijklmnopqrstuvwxyz", 3), 'i');
    CuAssertIntEquals(tc, encryptLetter('n', "abcdefghijklmnopqrstuvwxyz", 3), 'q');
    CuAssertIntEquals(tc, encryptLetter('y', "abcdefghijklmnopqrstuvwxyz", 3), 'b');
    CuAssertIntEquals(tc, encryptLetter('z', "abcdefghijklmnopqrstuvwxyz", 3), 'c');

}

void testEncryptWord(CuTest* tc) {
    char str1[] = "play";
    encryptWord(str1, "abcdefghijklmnopqrstuvwxyz", 3);
    CuAssertStrEquals(tc, str1, "sodb");

    char str2[] = "cseonefortytwo";
    encryptWord(str2, "abcdefghijklmnopqrstuvwxyz", 3);
    CuAssertStrEquals(tc, str2, "fvhrqhiruwbwzr");

    char str3[] = "the";
    encryptWord(str3, "abcdefghijklmnopqrstuvwxyz", 3);
    CuAssertStrEquals(tc, str3, "wkh");

    char str4[] = "jumps";
    encryptWord(str4, "abcdefghijklmnopqrstuvwxyz", 3);
    CuAssertStrEquals(tc, str4, "mxpsv");

    char str5[] = "a";
    encryptWord(str5, "abcdefghijklmnopqrstuvwxyz", 3);
    CuAssertStrEquals(tc, str5, "d");

    char str6[] = "science";
    encryptWord(str6, "abcdefghijklmnopqrstuvwxyz", 3);
    CuAssertStrEquals(tc, str6, "vflhqfh");
}

CuSuite* EncryptionMachineGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testIndexOf);
    SUITE_ADD_TEST(suite, testEncryptLetter);
    SUITE_ADD_TEST(suite, testEncryptWord);
    return suite;
}

void RunAllTests(void) {
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, EncryptionMachineGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main() {
    RunAllTests();
    return 0;
}
