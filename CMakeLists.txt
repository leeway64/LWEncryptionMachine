cmake_minimum_required (VERSION 3.8)

project ("Encryption_Machine")

# Executable for the Encryption Machine
add_executable (EncryptionMachine "main.c" "EncryptionMachine.c" "EncryptionMachine.h")

target_include_directories(EncryptionMachine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests/)

# Executable for the test suite
add_executable (test_suite "tests/test_suite.c" "tests/CuTest.c" "EncryptionMachine.c" "EncryptionMachine.h")
