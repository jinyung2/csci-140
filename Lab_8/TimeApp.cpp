/*  Program: TimeApp.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/24/2018
    Description: An application to test our Time classes. Utilizes and array of Time objects and pointers.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    cout << "Creating new Time object with default time (0:00 AM / Midnight)" << endl;
    Time time;
    time.print();
    cout << "Going back 1 minute in time" << endl;
    time.back();
    time.print();
    cout << "Advancing 1 minute" << endl;
    time.advance();
    time.print();
    cout << "Advancing 15 minutes" << endl;
    time.advance(15);
    time.print();
    cout << "Advancing 150 minutes" << endl;
    time.advance(150);
    time.print();
    return 0;
}