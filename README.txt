Due date: Sunday 1/24/2016 @ 11:59pm

Objective:
~~~~~~~~~~

- Become familiar with the project submission environment
- Introduction to C programming
- Help you think about test cases and ambiguities in specifications

Assignment:
~~~~~~~~~~~

(1) Write an interpreter for a simple programming language:

- The program is passed as a command line argument to the interpreter

- A program consists of a sequence of assignment statements

- Each statement is terminated with ';'

- The left hand side of an assignment is always a simple variable

- Variable names can only contain a single lower-case letter

- The right hand side of an assignment is always a positive integer literal

- All variables are initialized to 0

- The interpreter prints the values of all the non-zero variables in
  alphabetical order when it finishes interpreting the program

- Unexpected characters are ignored

(2) Donate a test case by adding two files:

    <csid>.test : the test
    <csid>.ok   : the expected output

    Where <csid> is you CS ID (not your UTEID)

(3) Answer the questions in REPORT.txt

Examples:
~~~~~~~~~

./p1 "x = 10;"
x:10

./p1 "x = 2_09 ; a = 17;"
a:17
x:209

Files you're allowed to change:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   p1.c
   <csid>.test
   <csid>.ok

Files you're supposed to leave alone:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   Everything else
   
To compile:
~~~~~~~~~~~

    make

To run tests:
~~~~~~~~~~~~~

    make clean test

To make the output less noisy:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    make -s clean test

To debug with gdb
~~~~~~~~~~~~~~~~~

    make
    gdb ./p1
    (gdb) run "x = 100; a = 30;"

