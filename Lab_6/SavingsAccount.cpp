/*  Program: SavingsAccount.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/09/2018	     
    Description: The main implementation for class and functions for savings account.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(){
    this->dollars = 0;
    this->cents = 0;
}

SavingsAccount::SavingsAccount(int dollars, int cents){
    this->dollars = dollars;
    this->cents = cents;
    normalize();
}

void SavingsAccount::deposit(int dollars, int cents){
    this->dollars += dollars;
    this->cents += cents;
    normalize();
}

void SavingsAccount::withdrawal(int dollars, int cents) {
    if (dollars > this->dollars){
        cout << "Not enough money." << endl;
    }
    if (cents > this->cents){
        if (this->dollars > 0){
            if (dollars > this->dollars-1){
                cout << "Not enough money." << endl;
            }else{
                this->dollars -= 1;
                this->cents += 100;
                this-> cents -= cents;
                this->dollars -= dollars;
            }
        }
    }
    else{
        this->dollars -= dollars;
        this->cents -= cents;
    }
}

void SavingsAccount::balance() {
    cout << "Dollars = " << dollars << " cents = " << cents << "." << endl;
}

void SavingsAccount::normalize() {
    if (cents >= 100){
        int temp = cents / 100;
        cents %= 100;
        dollars += temp;
    }
}