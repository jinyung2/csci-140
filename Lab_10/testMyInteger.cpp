// A driver to test MyInteger class
// Created by T. Vo for CSCI 140 Fall 2018

// Modified by: your name

#include <iostream>
#include "MyInteger.h"

using namespace std;

int main()
{
	MyInteger i1;		// 0
	MyInteger i2(5);	// 5
	MyInteger i3 = i2;	// 5

	cout << "i1: " << i1 << endl;
	cout << "i2: " << i2.getValue() << endl;
	cout << "i3: " << i3 << endl;

	i1.setValue(-4);
	i3 = i1 + i2;
	cout << "i3: " << i3 << endl;			// 1

	cout << "i2 - i1: " << i2 - i1 << endl;	// 9

	cout << "Enter an integer: ";
	cin >> i1;							// enter 123

	if (i1 == i2)							// different
		cout << "same" << endl;
	else
		cout << "different" << endl;

	i1 = i2;
	if (i1 == i2)							// same
		cout << "same" << endl;
	else
		cout << "different" << endl;

	// feel free to add more test cases below

	return 0;
}