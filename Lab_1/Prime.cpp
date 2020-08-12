/*  Program: Prime.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 8/29/2018
    Description: Determine if a number is a prime number.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

int main() {
    int number;
    bool prime = true;
    int i = 2;

    cout << "Enter a number: ";
    cin >> number;

    while (prime){
        if (i >= number) { break; }
        if (number % i == 0){
            prime = false;
        }
        i++;
    }
    if (prime){
        cout << number << " is a prime number";
    }
    else {
        cout << number << " is not a prime number";
    }

}