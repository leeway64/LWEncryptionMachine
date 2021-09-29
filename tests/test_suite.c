#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"
#include "../EncryptionMachine.h"


void testIndexOf(CuTest* tc) {
    CuAssertIntEquals(tc, indexOf('a'), 0);
    CuAssertIntEquals(tc, indexOf('b'), 1);
    CuAssertIntEquals(tc, indexOf('c'), 2);
    CuAssertIntEquals(tc, indexOf('s'), 18);
    CuAssertIntEquals(tc, indexOf('x'), 23);
    CuAssertIntEquals(tc, indexOf('y'), 24);
    CuAssertIntEquals(tc, indexOf('z'), 25);
}

void testEncryptLetter(CuTest* tc) {
    CuAssertIntEquals(tc, encryptLetter('a'), 'd');
    CuAssertIntEquals(tc, encryptLetter('d'), 'g');
    CuAssertIntEquals(tc, encryptLetter('e'), 'h');
    CuAssertIntEquals(tc, encryptLetter('f'), 'i');
    CuAssertIntEquals(tc, encryptLetter('n'), 'q');
    CuAssertIntEquals(tc, encryptLetter('y'), 'b');
    CuAssertIntEquals(tc, encryptLetter('z'), 'c');

}

void testCopyString(CuTest* tc) {
    
}

void testEncryptWord(CuTest* tc) {
    /*CuAssertStrEquals(tc);
    CuAssertStrEquals(tc);
    CuAssertStrEquals(tc);
    CuAssertStrEquals(tc);
    CuAssertStrEquals(tc);
    CuAssertStrEquals(tc);*/

}

CuSuite* EncryptionMachineGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testIndexOf);
    SUITE_ADD_TEST(suite, testEncryptLetter);
    SUITE_ADD_TEST(suite, testEncryptWord);
    SUITE_ADD_TEST(suite, testCopyString);
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

int main(void) {
    RunAllTests();
}
