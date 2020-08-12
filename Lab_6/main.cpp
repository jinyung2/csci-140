/*  Program: main.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/09/2018	     
    Description: A program that emulates a simple deposit withdrawal from a savings account.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

int main() {
    // BANK 1
    int initDollars = 0;
    int initCents = 0;
    cout << "Please input the initial dollars" << endl;
    cin >> initDollars;
    cout << endl << "Please input the initial cents" << endl;
    cin >> initCents;
    cout << endl;
    SavingsAccount bank1(initDollars,initCents);
    bool running = true;
    while(running){
        char choice = 'y';
        cout << "Would you like to make a deposit? Y or y for yes" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            int dol = 0;
            int cent = 0;
            cout  << "Please input the dollars to be deposited" << endl;
            cin >> dol;
            cout << "Please input the cents to be deposited" << endl;
            cin >> cent;
            bank1.deposit(dol, cent);
        }else{
            do{
                cout << "Would you like to make a withdrawal? Y or y for yes" << endl;
                cin >> choice;
                if (choice == 'y' || choice == 'Y'){
                    int dol = 0;
                    int cent = 0;
                    cout  << "Please input the dollars to be withdrawn" << endl;
                    cin >> dol;
                    cout << "Please input the cents to be withdrawn" << endl;
                    cin >> cent;
                    bank1.withdrawal(dol, cent);
                }
                else{
                    cout << endl;
                    bank1.balance();
                    running = false;
                    break;
                }
            }while(choice == 'y');
        }
    }


    //BANK 2
    cout << "Bank 2 initialized with 0 dollars and 0 cents." << endl;
    SavingsAccount bank2;
    running = true;
    while(running){
        char choice = 'y';
        cout << endl << "Would you like to make a deposit? Y or y for yes" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            int dol = 0;
            int cent = 0;
            cout  << "Please input the dollars to be deposited" << endl;
            cin >> dol;
            cout << "Please input the cents to be deposited" << endl;
            cin >> cent;
            bank2.deposit(dol, cent);
        }else{
            do{
                cout << "Would you like to make a withdrawal? Y or y for yes" << endl;
                cin >> choice;
                if (choice == 'y' || choice == 'Y'){
                    int dol = 0;
                    int cent = 0;
                    cout  << "Please input the dollars to be withdrawn" << endl;
                    cin >> dol;
                    cout << "Please input the cents to be withdrawn" << endl;
                    cin >> cent;
                    bank2.withdrawal(dol, cent);
                }
                else{
                    cout << endl;
                    bank2.balance();
                    running = false;
                    break;
                }
            }while(choice == 'y');
        }
    }

    return 0;
}


