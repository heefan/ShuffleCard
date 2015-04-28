# ShuffleCard

GENERAL DESCRIPTION:

This module solves a coding problem that involves shuffling a deck of cards.  The problem description is as follows:

You are given a deck containing n cards.  While holding the deck:

Take the top card off the deck and set it on the table.
Take the next card off the top and put it on the bottom of the deck in your hand.
Continue steps 1 and 2 until all cards are on the table.  This is a round.
Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.

Write a program to determine how many rounds it will take to put a deck back into the original order.  This will involve creating a data structure to represent the order of the cards. This program should be written in C, C++, Java or JavaScript/Node.js, and should be executable from the command line. It should take a number of cards in the deck as a command line argument and write the result to stdout.

Other than data structures you create yourself:

For a C/C++ solution, do not use STL.
For a Java solution, you may only use a primitive Java array in your implementation. This mean no java.utils classes. You may use System.arraycopy.
For a JavaScript solution, do not use any Array methods.
