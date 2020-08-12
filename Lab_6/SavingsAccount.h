/*  Program: SavingsAccount.h
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/09/2018	     
    Description: Header file for the SavingsAccount class in Lab 13.5

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#ifndef LAB_6_SAVINGSACCOUNT_H
#define LAB_6_SAVINGSACCOUNT_H

using namespace std;

class SavingsAccount {
    private:
        int dollars;
        int cents;
        void normalize();

    public:
        SavingsAccount();
        SavingsAccount(int dollars, int cents);
        void deposit(int dollars, int cents);
        void withdrawal (int dollars, int cents);
        void balance();

};

#endif //LAB_6_SAVINGSACCOUNT_H
