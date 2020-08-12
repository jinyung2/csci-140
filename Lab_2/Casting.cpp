/*  Program: Casting.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 9/4/18
    Description: A logic error correction for type casting to fix decimal truncation.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

const int AT_BAT = 421;
const int HITS = 123;

int main() {
    float batAvg;

    batAvg = static_cast<float>(HITS) / AT_BAT;
    cout << "The batting average is " << batAvg << endl;

     return 0;

}
