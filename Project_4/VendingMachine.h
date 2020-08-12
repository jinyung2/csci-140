/*  Program: VendingMachine.h
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/12/2018	     
    Description: Header file for vending machine class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/
#ifndef PROJECT_4_VENDINGMACHINE_H
#define PROJECT_4_VENDINGMACHINE_H

#include <string>
#include <vector>
#include <iomanip>
#include "ChangeMachine.cpp"
#include "Inventory.cpp"

using namespace std;

struct initInfo{
    int dollars, quarters, dimes, nickels;
};

struct availProd{
    int initialQuantity;
    int ID = 0;
    string selection;
    int quantity;
    int price;
    string name;
};

struct transaction{
    int trans, cost, paid, pDollar, pQuarter, pDime, pNickel, change, quarter, dime, nickel;
    string select;
};

struct transactionCC{
    int trans;
    string select;
    int cost, paid, lastFour;
};

class VendingMachine {
protected:
    int transNum = 1;
    initInfo init = {0,0,0,0};
    string model;
    ChangeMachine changeMachine;
    int numProduct;
    vector<availProd*> products;
    vector<transaction*> trans;
public:
    VendingMachine(string model, int numProducts);
    VendingMachine(string model, int numProducts, int Q, int D, int N);
    ~VendingMachine();
    virtual void stockMachine(Inventory&, string, int, int);
    virtual void startUp() = 0;
    virtual void makeSelection(string select);
    virtual void generateReport();
    virtual string modelNumber(){ return model; };
    void printItemList();
    bool validate(string cardNumber);
};


#endif //PROJECT_4_VENDINGMACHINE_H