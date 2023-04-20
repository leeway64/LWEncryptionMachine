cmake_minimum_required (VERSION 3.8)

project ("LWEncryptionMachine"
        LANGUAGES C
        VERSION "1.0.0")

set(CMAKE_C_STANDARD 23)

# Executable for the Encryption Machine
add_executable (LWEncryptionMachine "src/main.c" "src/LWEncryptionMachine.c" "src/LWEncryptionMachine.h")

# Executable for the test suite
add_executable (test_suite "tests/test_suite.c" "tests/CuTest.c" "src/LWEncryptionMachine.c" "src/LWEncryptionMachine.h")
