/*  Program: WaterBill.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/04/2018	     
    Description: Calculates monthly water cost using quarterly data. Conditional computes if user is conservative with water or not.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float firstQuarter;
    float secondQuarter;
    float thirdQuarter;
    float fourthQuarter;
    float monthAvg;
    string usage;

    cout << "Please input your water bill for quarter 1:" << endl;
    cin >> firstQuarter;
    cout << "Please input your water bill for quarter 2:" << endl;
    cin >> secondQuarter;
    cout << "Please input your water bill for quarter 3:" << endl;
    cin >> thirdQuarter;
    cout << "Please input your water bill for quarter 4:" << endl;
    cin >> fourthQuarter;

    monthAvg = (firstQuarter + secondQuarter + thirdQuarter + fourthQuarter)/12;
    cout << "Your average monthly bill is $" << fixed << setprecision(2) << monthAvg << ". ";
    if (monthAvg > 75){
        cout << "You are using an excessive amount of water";
    }
    else if (monthAvg > 25){
        cout << "You are using a typical amount of water";
    }
    else {
        cout << "How are you using so little water?";
    }
}