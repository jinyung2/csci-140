/*  Program: doubledPenny.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 09/24/2018
    Description: A program that loops to calculate the amount earned if a penny were doubled an inputted number of days.

    I certify that the code below is my own work.

	Exception(s): N/A

*/


#include <iostream>
#include <iomanip>

using namespace std;

void generate(int day, double amount, double total);

int main() {
    do{
        int days = 1;
        double amount;
        double total;
        amount = total = 0.01;
        cout << "Enter the number of days to double a penny (-1 to exit): ";
        cin >> days;
        if (days == -1){
            cout << "Terminating Program.";
            break;
        }
        if (days < 1){
            cout << "Invalid Input, Try Again." << endl;
        }
        else{
            cout << setw(3) << right << "Day" << setw(10) << "Amount" << setw(10) << "Total" << endl;
            for (int i = 1; i <= days; i++){
                generate(i, amount, total);
                amount *= 2;
                total += amount;
            }
            cout << endl;
        }
    }while(true);

    return 0;
}

void generate(int day, double amount, double total){
    cout << setw(3) << right << day << setw(10) << amount << setw(10) << total << endl;
}
