/*  Program: LogicError.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 8/29/2018
    Description: Lab 1.4 Logic Error, creating a temp variable to perform a swap.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

int main() {
    float firstNumber;
    float secondNumber;
    float temp;
// Prompt user to enter the first number.
    cout << "Enter the first number" << endl;
    cout << "Then hit enter" << endl;
    cin >> firstNumber;
// Prompt user to enter the second number.
    cout << "Enter the second number" << endl;
    cout << "Then hit enter" << endl;
    cin >> secondNumber;
// Echo print the input.
    cout << endl << "You input the numbers as " << firstNumber
         << " and " << secondNumber << endl;
// Now we will swap the values.
    temp = firstNumber;
    firstNumber = secondNumber;
    secondNumber = temp;
// Output the values.
    cout
            << "After swapping, the values of the two numbers are "
            << firstNumber << " and " << secondNumber << endl;
    return 0;
}
