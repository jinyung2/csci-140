/*  Program: Tuition.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/04/2018	     
    Description: Computes cost of tuition based on residency status and housing requirements.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char residency;
    char housing;
    int bill = 0;

    cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
    cin >> residency;
    if (residency != 'I' && residency !='O'){
        cout << "Bad Input" << endl;
        return 1;
    }
    cout << "Please input \"Y\" if you require room and board and \"N\" if you do not:" << endl;
    cin >> housing;
    if (housing !='Y' && housing != 'N'){
        cout << "Bad Input" << endl;
        return 1;
    }
    if (residency == 'I'){
        bill += 3000;
        if (housing == 'Y'){
            bill += 2500;
        }
    }
    else{
        bill += 4500;
        if (housing == 'Y'){
            bill += 3500;
        }
    }

    cout << "Your total bill for this semester is $" << bill;

    return 0;
}