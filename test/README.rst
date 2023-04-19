Unit Tests
===========

Windows
---------



To run the unit tests, enter ``cl test_suite.c CuTest.c /link /out:test_suite.exe`` into the developer
command prompt for Visual Studio in the current directory to compile tests. Then, run ``test_suite.exe`` to run tests.

Alternatively, ``select test_suite`` as the target in the IDE and run that executable.

Tests were run with ``ALPHABET`` equal to "abcdefghijklmnopqrstuvwxyz"; if you would like to run the
unit tests, you will have to make sure, in ``main.c``, ``ALPHABET = "abcdefghijklmnopqrstuvwxyz"`` is
uncommented, and all other ALPHABETs are commented.

Linux
-------
