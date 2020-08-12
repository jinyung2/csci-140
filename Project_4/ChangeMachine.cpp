/*  Program: ChangeMachine.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/12/2018	     
    Description: This class is instantiated with each instance of VendingMachine, handles change.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

/*const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKEL = 0.05;*/

class ChangeMachine {
private:
    int Dollars;
    int Quarters;
    int Dimes;
    int Nickels;
    void addDollars(int n){Dollars += n; }
    void addQuarters(int n){ Quarters += n; }
    void addDimes(int n){ Dimes += n; }
    void addNickels(int n) { Nickels += n; }
    int removeQuarters(int n){
        int result = Quarters;
        if (Quarters >= n){
            Quarters -= n;
            result = n;
        }
        else{
            Quarters = 0;
        }
        return result;
    }
    int removeDimes(int n){
        int result = Dimes;
        if (Dimes >= n){
            Dimes -= n;
            result = n;
        }
        else{
            Dimes = 0;
        }
        return result;
    }
    int removeNickels(int n){
        int result = Nickels;
        if (Nickels >= n){
            Nickels -= n;
            result = n;
        }
        else{
            Nickels = 0;
        }
        return result;
    }
    int removeDollars(int n){
        int result = Dollars;
        if (Dollars >= n){
            Dollars -= n;
            result = n;
        }
        else{
            Dollars = 0;
        }
        return result;
    }

public:
    ChangeMachine(){
        Dollars = 0;
        Quarters = 0;
        Dimes = 0;
        Nickels = 0;
    }
    void insertChange(int Q, int D, int N){
        Quarters = Q;
        Dimes = D;
        Nickels = N;
    }
    int totalBal(){return 100*Dollars + 25*Quarters + 10*Dimes + 5*Nickels;}
    int getDollars() const{return Dollars; }
    int getQuarters() const{ return Quarters; }
    int getDimes() const{ return Dimes; }
    int getNickels() const {return Nickels; }
    bool giveChange(int changeRemoved[], int purchaseAmount, int Dollar, int Q = 0, int D = 0, int N = 0){
        bool success = false;
        int tempDollar = Dollars + Dollar;
        int tempQ = Quarters + Q;
        int tempD = Dimes + D;
        int tempN = Nickels + N;
        int total = tempDollar *100 + tempQ*25 + tempD*10 + tempN*5;
        int inserted = Dollar * 100 + Q*25 + D*10 + N*5;
        int change = inserted - purchaseAmount;
        if (total >= change){
            int removeTempDollar = 0; change/100 < tempDollar ? change/100 : tempDollar;
            if (change > 100 && removeTempDollar>0){
                change -= removeTempDollar*100;
            }
            if (tempN == 0 && tempQ > 0 && tempD > 0 && change > 25) { // Exception Handling Q D
                int smaller = change/25 < tempQ ? change/25 : tempQ;
                if (change%2 == 0){ //change is even
                    if (smaller%2 == 1){
                        smaller -= 1;
                    }
                }
                else{ // change is odd
                     if (smaller%2 == 0){
                         smaller -= 1;
                     }
                }
                if ((change - smaller*25)/10 <= tempD){ // you got enough dimes
                    addDollars(Dollar);
                    addQuarters(Q);
                    addDimes(D);
                    addNickels(N);
                    removeDollars(removeTempDollar);
                    changeRemoved[0] = removeQuarters(smaller);
                    changeRemoved[1] = removeDimes((change - smaller*25)/10);
                    success = true;
                }
            }
            else{ // GREEDY METHOD
                int rmvQ, rmvD, rmvN;
                rmvQ = rmvD = rmvN = 0;
                if ((change/25) > 0 && tempQ > 0){
                    rmvQ = change/25 < tempQ ? change/25 : tempQ;
                    change -= rmvQ * 25;
                }
                if ((change/10) > 0 && tempD > 0){
                    rmvD = change/10 < tempD ? change/10 : tempD;
                    change -= rmvD * 10;
                }
                if ((change/5) > 0 && tempN > 0){
                    rmvN = change/5 < tempN ? change/5 : tempN;
                    change -= rmvN * 5;
                }
                if (change == 0){
                    addDollars(Dollar);
                    addQuarters(Q);
                    addDimes(D);
                    addNickels(N);
                    removeDollars(removeTempDollar);
                    changeRemoved[0] = removeQuarters(rmvQ);
                    changeRemoved[1] = removeDimes(rmvD);
                    changeRemoved[2] = removeNickels(rmvN);
                    success = true;
                }
            }
        }
        return success;
    }
};