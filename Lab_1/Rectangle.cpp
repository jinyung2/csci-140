/*  Program: Rectangle.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 8/29/2018
    Description: Lab 2.3, calculate area and perimeter of rectangle.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

int main() {
    float length;
    float width;
    float perimeter;
    float area;

    cout << "Enter Length: ";
    cin >> length;
    cout << endl << "Enter Width: ";
    cin >> width;
    perimeter = (2.0*length) + (2.0*width);
    area = length * width;

    cout << "Perimeter: " << perimeter << endl << "Area: " << area;
}