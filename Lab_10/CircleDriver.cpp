/*  Program: CircleDriver.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/10/2018	     
    Description: Driver file for Circle class. Tests the distance function.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;

int main() {
    Circle c1(3,2);
    Circle c2(4,4);
    cout << "Circle c1 is centered at (" << c1.getX() << ", " << c1.getY() << ")" << endl;
    cout << "Circle c2 is centered at (" << c2.getX() << ", " << c2.getY() << ")" << endl;
    cout << "The distance between Circles c1 and c2: " << fixed << setprecision(3) <<  c1 - c2 << endl;
    return 0;
}