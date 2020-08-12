/*  Program: TimeApp.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/31/2018
    Description: An application to test our Time classes. Tests the overloaded operators
    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    Time t1(23,59);
    Time t2;
    cout << t1 << t2;
    cout << "Equivalence Test: " << endl;
    if (t1==t2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << endl;
    cout << "Advancing first time by 1 minute." << endl;
    t1.advance();
    cout << t1 << t2;
    cout << "\nEquivalence Test: " << endl;
    if (t1==t2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << "\nTesting less than, greater than equal to and not equal: " << endl;
    cout << "setting second time to 12:00PM" << endl;
    t2.setHour(12);
    t2.setMinute(0);
    cout << t1 << t2;
    cout << "\nFirst time less than second time: " << endl;
    if (t1 < t2){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    cout << "\nFirst time greater than or equal to second time: " << endl;
    if (t1 >= t2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << "\nNot equal test: " << endl;
    if (t1 != t2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << "\nChanging first time to 12:00PM and using greater than equal to: " << endl;
    t1.setHour(12);
    t1.setMinute(0);
    cout << t1 << t2;
    if (t1 >= t2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }


    return 0;
}