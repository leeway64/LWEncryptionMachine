LWEncryptionMachine
===================

This project created a simple encryption machine that can encrypt a user-entered cryptographic key
and message using a Caesar cipher; more information on Caesar ciphers can be found
`here <https://en.wikipedia.org/wiki/Caesar_cipher>`_.


Installation
--------------

.. code-block::

    git clone https://github.com/leeway64/LWEncryptionMachine.git
    cd LWEncryptionMachine


An introduction to ciphers
---------------------------

In general, ciphers work by transforming plaintext into ciphertext through a cipher.

.. image:: images/Cipher_encryption_process.png

The previous diagram was drawn with `PlantUML <https://plantuml.com/>`_ to render the diagram, run
the following commands:

.. code-block::

    plantuml


Examples
-----------

With an alphabet of "abcdefghijklmnopqrstuvwxyz0123456789", shift of 3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: images/Example_letters_numbers.jpg

With an alphabet of "0123456789", shift of 7
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: images/Example_numbers.jpg


Acknowledgements
------------------

This project is based on `Assessment 3 <https://courses.cs.washington.edu/courses/cse142/21su/assessments/a3/>`_
for `UW Seattle CSE 142 (summer 2020) <https://courses.cs.washington.edu/courses/cse142/21su/>`_.
The assignment was originally meant to be completed in Java, but I completed it in C.


Third-party software
----------------------

- `CuTest <http://cutest.sourceforge.net/>`_ (zlib License): C unit testing framework.
