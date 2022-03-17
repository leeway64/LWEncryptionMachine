cmake_minimum_required (VERSION 3.8)

project ("Encryption_Machine"
        LANGUAGES C
        VERSION "1.0.0")

set(CMAKE_C_STANDARD 23)

# Executable for the Encryption Machine
add_executable (EncryptionMachine "src/main.c" "src/EncryptionMachine.c" "src/EncryptionMachine.h")

# Executable for the test suite
add_executable (test_suite "tests/test_suite.c" "tests/CuTest.c" "src/EncryptionMachine.c" "src/EncryptionMachine.h")
