/*  Program: VendingMachine.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 09/19/2018
    Description: A vending machine simulation for Project 1. Extra Credit 1A completed.

    I certify that the code below is my own work.

	Exception(s): N/A

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

const float DOLLAR = 1.00;
const float QUARTER = 0.25;
const float DIME = 0.10;
const float NICKEL = 0.05;

bool compute(int change, int &numQuarters, int &numDimes, int &numNickels, int insertedQuarters, int insertedDimes, int insertedNickels);
bool validate(int val);
void changeUpdate(int &Q1, int Q2, int &D1, int D2, int &N1, int N2);
void balanceUpdate(float &balance, int numDollars, int numQuarters, int numDimes, int numNickels);

int main() {
    int numTransaction, numDollars, numQuarters, numDimes, numNickels;
    numTransaction = numDollars = numQuarters = numDimes = numNickels = 0;
    float balance = 0;

    cout << "Vending Machine Version 1 by Jin Choi\n\n"
    << "Fill up machine with changes. Please wait ...\n";

    while(true){
        cout << "Enter number of Quarters, Dimes, and Nickels --> ";
        cin >> numQuarters >> numDimes >> numNickels;
        if (cin.fail() || numQuarters < 0 || numDimes < 0 || numNickels < 0){
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        else { break;}
    }
    cout << "There are " << numQuarters << " quarters, " << numDimes
        << " dimes, and " << numNickels << " nickels.\n";
    balanceUpdate(balance,numDollars, numQuarters, numDimes, numNickels);
    cout << "Initial machine balance is $" << fixed << setprecision(2) << balance << "." << endl
        << "One-dollar bill or coins will be accepted." << endl
        << "Only amount between 0 to 100 and multiple of 5 is accepted." << endl
        << "Enter 0 to stop the program.\nMachine is now ready.\n\n";
    do {
        int purchaseAmount = 0;
        cout << "Enter purchase amount [0 - 100] --> ";
        cin >> purchaseAmount;
        if (cin.fail()){
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        else{
            if (purchaseAmount == 0){
                balanceUpdate(balance,numDollars, numQuarters, numDimes, numNickels);
                cout << "Final report is being generated ...\nThere are " << numTransaction << " valid transactions.\n";
                cout << setw(19) << left << "Number of dollars" << right << ": " << numDollars << endl;
                cout << setw(19) << left << "Number of quarters" << right << ": " << numQuarters << endl;
                cout << setw(19) << left << "Number of dimes" << right << ": " << numDimes << endl;
                cout << setw(19) << left << "Number of nickels" << right  << ": " <<  numNickels << endl;
                cout << setw(19) << left << "Machine balanced" << right << ": $" << balance << endl
                     << "Machine is shutting down. Good bye.";
                break;
            }
            cout << "You entered a purchase amount of " << purchaseAmount << " cents." << endl;
            if (validate(purchaseAmount)){
                int coinOrBill = 0;
                int insertedAmount = 0;
                int changeAmount = 0;
                do{
                    int insertedQuarters, insertedDimes, insertedNickels;
                    insertedQuarters = insertedDimes = insertedNickels = 0;
                    cout << "Select an option (1 - dollar bill and 2 - coins) --> ";
                    cin >> coinOrBill;
                    if ((coinOrBill != 1 && coinOrBill != 2)){
                        cout << "Invalid input, try again.\n";
                    }
                    else {
                        if (coinOrBill == 1) {
                            insertedAmount = 100;
                            numDollars += 1;
                        }
                        else {
                            cout << "Please insert your coins --> ";
                            int coin = 0;
                            while (cin >> coin) {
                                if (coin == 0) { break; }
                                if (coin == 25) {
                                    insertedAmount += 25;
                                    insertedQuarters++;
                                }
                                if (coin == 10) {
                                    insertedAmount += 10;
                                    insertedDimes++;
                                }
                                if (coin == 5) {
                                    insertedAmount += 5;
                                    insertedNickels++;
                                }
                            }
                        }
                        if (insertedAmount > 0) {
                            cout << "You inserted an amount of " << insertedAmount << " cents.\n";
                            if (purchaseAmount > insertedAmount) {
                                cout << "Insufficient amount.\nYour transaction cannot be processed.\nPlease take back your coins.\n\n";
                            } else {
                                cout << "Processing your purchase ...\n";
                                changeAmount = insertedAmount - purchaseAmount;
                                cout << "Your change of " << changeAmount << " cents is given as: \n";
                                if (compute(changeAmount, numQuarters, numDimes, numNickels, insertedQuarters, insertedDimes, insertedNickels)) {
                                    numTransaction++;
                                }
                            }
                        }
                        else {
                            cout << "Invalid input, try again.\n\n";
                        }
                    }
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }while(coinOrBill != 1 && coinOrBill != 2);
            }
            else {
                if (purchaseAmount < 0 || purchaseAmount > 100){
                    cout << "Invalid amount (outside valid range). Try again.\n";
                }
                else{
                    cout << "Invalid amount (not multiple of 5). Try again.\n";
                }
            }
        }
    }while(true);

    return 0;
}


//Functions//
bool validate(int val){
    if (val == 0){
        return false;
    }
    return val%5 == 0;
}

bool compute(int change, int &numQuarters, int &numDimes, int &numNickels, int insertedQuarters, int insertedDimes, int insertedNickels){
    numQuarters += insertedQuarters;
    numDimes += insertedDimes;
    numNickels += insertedNickels;
    int tempQ, tempD, tempN;
    tempQ = tempD = tempN = 0;
    bool available = true;
    while (change != 0 && available){

        if (numQuarters == 0 && numDimes == 0 && numNickels == 0){
            available = false;
        }
        if (change >= 25 && numQuarters > 0){
            change -= 25;
            numQuarters--;
            tempQ++;
        }
        else if (change >= 10 && numDimes > 0){
            change -= 10;
            numDimes--;
            tempD++;
        }
        else {
            if (numNickels > 0){
                change -= 5;
                numNickels--;
                tempN++;
            }
            else{
                available = false;
            }
        }
    }
    if (available){
        cout << setw(11) << left << "\tquarter(s)" << right << ": " << tempQ << endl;
        cout << setw(11) << left << "\tdimes(s)" << right << ": " << tempD << endl;
        cout << setw(11) << left << "\tnickels(s)" << right << ": " << tempN << endl << endl;
    }
    else {
        numQuarters += tempQ-insertedQuarters;
        numDimes += tempD-insertedDimes;
        numNickels += tempN-insertedNickels;
        cout << "Insufficient change!\nYour transaction cannot be processed.\nPlease take back your money.\n\n";
    }
    return available;
}

void balanceUpdate(float &balance, int numDollars, int numQuarters, int numDimes, int numNickels){
    balance = DOLLAR*numDollars + QUARTER*numQuarters + DIME * numDimes + NICKEL*numNickels;
}