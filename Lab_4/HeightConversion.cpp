/*  Program: HeightConversion.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/17/2018	     
    Description: height conversion program from Lab 3, utilizing functions.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const float INT_METER = 0.0254;

float inchToMeter(int, int);
int meterToInch(float);

int main() {
    int selection;
    double meter;
    int feet, inches;
    feet = inches = 0;
    meter = 0;
    while(true){
        cout << "Input 1 for Feet and Inches to Meter and 2 for Meter to Feet and Inches: ";
        cin >> selection;
        switch(selection){
            case 1: {
                cout << "Enter feet and inches separated by space: ";
                cin >> feet >> inches;
                float result = inchToMeter(feet, inches);
                cout << "\nMeter value: " << fixed << setprecision(2) << result << endl << endl;
            }
                break;
            case 2: {
                cout << "Enter meter: ";
                cin >> meter;
                int resultInch = meterToInch(meter);
                feet = resultInch / 12;
                inches = resultInch % 12;
                cout << "\nFeet and Inches value: " << feet << " feet " << inches << " inches" << endl << endl;
            }
                break;
            default: cout << "Invalid Input. Terminating Program."; break;
        }
        if (selection != 1 && selection != 2){
            break;
        }
    }
    return 0;
}

float inchToMeter(int feet, int inches){
    int totalInch = inches + feet * 12;
    return INT_METER * totalInch;
}

int meterToInch(float meter){
    return static_cast<int>(round(meter / INT_METER));
}