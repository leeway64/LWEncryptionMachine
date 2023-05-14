#include <stdio.h>
#include "CuTest.h"

#include "../src/LWEncryptionMachine.h"


void testIndexOf(CuTest* tc) {
    CuAssertIntEquals(tc, indexOf('a', "abcdefghijklmnopqrstuvwxyz"), 0);
    CuAssertIntEquals(tc, indexOf('b', "abcdefghijklmnopqrstuvwxyz"), 1);
    CuAssertIntEquals(tc, indexOf('c', "abcdefghijklmnopqrstuvwxyz"), 2);
    CuAssertIntEquals(tc, indexOf('s', "abcdefghijklmnopqrstuvwxyz"), 18);
    CuAssertIntEquals(tc, indexOf('x', "abcdefghijklmnopqrstuvwxyz"), 23);
    CuAssertIntEquals(tc, indexOf('y', "abcdefghijklmnopqrstuvwxyz"), 24);
    CuAssertIntEquals(tc, indexOf('z', "abcdefghijklmnopqrstuvwxyz"), 25);
    
    CuAssertIntEquals(tc, indexOf('0', "abcdefghijklmnopqrstuvwxyz0123456789"), 26);
    CuAssertIntEquals(tc, indexOf('2', "abcdefghijklmnopqrstuvwxyz0123456789"), 28);
    CuAssertIntEquals(tc, indexOf('4', "abcdefghijklmnopqrstuvwxyz0123456789"), 30);
    CuAssertIntEquals(tc, indexOf('8', "abcdefghijklmnopqrstuvwxyz0123456789"), 34);
                    
}

void testEncryptLetter(CuTest* tc) {
    CuAssertIntEquals(tc, encryptLetter('a', "abcdefghijklmnopqrstuvwxyz", 0), 'a');
    CuAssertIntEquals(tc, encryptLetter('d', "abcdefghijklmnopqrstuvwxyz", 1), 'e');
    CuAssertIntEquals(tc, encryptLetter('e', "abcdefghijklmnopqrstuvwxyz", 2), 'g');
    CuAssertIntEquals(tc, encryptLetter('f', "abcdefghijklmnopqrstuvwxyz", 3), 'i');
    
    CuAssertIntEquals(tc, encryptLetter('n', "abcdefghijklmnopqrstuvwxyz", 4), 'r');
    CuAssertIntEquals(tc, encryptLetter('y', "abcdefghijklmnopqrstuvwxyz", 5), 'd');
    CuAssertIntEquals(tc, encryptLetter('z', "abcdefghijklmnopqrstuvwxyz", 6), 'f');

    CuAssertIntEquals(tc, encryptLetter('0', "0123456789", 3), '3');
    CuAssertIntEquals(tc, encryptLetter('8', "0123456789", 4), '2');

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

    char str7[] = "cse142";
    encryptWord(str7, "abcdefghijklmnopqrstuvwxyz0123456789", 3);
    CuAssertStrEquals(tc, str7, "fvh475");
    
    char str8[] = "gucci";
    encryptWord(str8, "abcdefghijklmnopqrstuvwxyz0123456789", 3);
    CuAssertStrEquals(tc, str8, "jxffl");
    
    char str9[] = "gang";
    encryptWord(str9, "abcdefghijklmnopqrstuvwxyz0123456789", 3);
    CuAssertStrEquals(tc, str9, "jdqj");
    
    char str10[] = "2";
    encryptWord(str10, "abcdefghijklmnopqrstuvwxyz0123456789", 3);
    CuAssertStrEquals(tc, str10, "5");
    
    char str11[] = "QUICK";
    encryptWord(str11, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3);
    CuAssertStrEquals(tc, str11, "TXLFN");
    
    char str12[] = "JUMPS";
    encryptWord(str12, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3);
    CuAssertStrEquals(tc, str12, "MXPSV");
    
    char str13[] = "OVER";
    encryptWord(str13, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3);
    CuAssertStrEquals(tc, str13, "RYHU");
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
