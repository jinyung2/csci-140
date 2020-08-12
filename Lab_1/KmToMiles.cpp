/*  Program: KmToMiles.cpp
    Author: Jin Choi
    Class: CSCI140
    Date: 8/29/2018
    Description: A program to convert kilometers to miles.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

int main() {
    float kilometer;
    float convertedResult;

    cout << "Enter a kilometer number to be converted into miles: ";
    cin >> kilometer;
    convertedResult = kilometer/1.609344;

    cout << "Kilometer converted: " << convertedResult << " miles";

    return 0;

}