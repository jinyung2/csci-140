/*  Program: KiloAndMiles.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/17/2018	     
    Description: A program that converts between miles to km and km to miles.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

const float KILO = 0.621;
const float MILE = 1.61;

float kmToMile(float);
float mileToKm(float);

int main() {
    int selection = 0;
    do{
        cout << "Please input\n1 Convert mile to kilometers\n2 Convert kilometers to miles\n3 Quit\n";
        cin >> selection;
        if (selection == 1){
            cout << "Please input the miles to be converted" << endl;
            float value;
            cin >> value;
            cout << value << " miles = " << mileToKm(value) << " kilometers\n\n";
        }
        else if (selection == 2){
            cout << "Please input the kilometers to be converted" << endl;
            float value;
            cin >> value;
            cout << value << " kilometers = " << kmToMile(value) << " miles\n\n";
        }
    }while(selection != 3);
    return 0;
}

float kmToMile(float kilometer){
    return kilometer * KILO;
}

float mileToKm(float mile){
    return mile * MILE;
}