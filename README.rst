LWEncryptionMachine
===================

LWEncryptionMachine is a simple encryption machine that can encrypt a user-entered cryptographic key
and message using a Caesar cipher.


Installation
--------------

.. code-block::

    git clone https://github.com/leeway64/LWEncryptionMachine.git
    cd LWEncryptionMachine
    make build


An introduction to ciphers
---------------------------

This project uses a Caesar cipher; more information on Caesar ciphers can be found
`here <https://en.wikipedia.org/wiki/Caesar_cipher>`_.

In general, ciphers work by transforming plaintext into ciphertext through a cipher.

.. image:: images/Cipher_encryption_process.png

The previous diagram was drawn with `PlantUML <https://plantuml.com/>`_. To render the diagram, run
the following commands:

.. code-block::

    plantuml


Examples
----------

.. code-block::

    bin/LWEncryptionMachine

    bin/LWEncryptionMachine abcdefghijklmnopqrstuvwxyz0123456789 3

    bin/LWEncryptionMachine 0123456789 7


.. image:: images/Example_letters_numbers.jpg

.. image:: images/Example_numbers.jpg


Running unit tests
-------------------

Tests were run with ``ALPHABET`` equal to "abcdefghijklmnopqrstuvwxyz"; if you would like to run the
unit tests, you will have to make sure, in ``main.c``, ``ALPHABET = "abcdefghijklmnopqrstuvwxyz"`` is
uncommented, and all other ALPHABETs are commented.

.. code-block::

    make run-tests


Acknowledgements
------------------

This project is based on `Assessment 3 <https://courses.cs.washington.edu/courses/cse142/21su/assessments/a3/>`_
for `UW Seattle CSE 142 (summer 2020) <https://courses.cs.washington.edu/courses/cse142/21su/>`_.
The assignment was originally meant to be completed in Java, but I completed it in C.


Third-party software
----------------------

- `CMake <https://cmake.org/>`_ (BSD 3-clause License): C/C++ build system
- `CuTest <http://cutest.sourceforge.net/>`_ (zlib License): C unit testing framework.
