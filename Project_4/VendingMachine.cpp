/*  Program: VendingMachine.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 12/03/2018
    Description: The main abstract class for the Vending Machine. Contains implementation to initialize various shared features for each different model. Implements pure virtual functions that are required to be overrided in derived classes.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include "VendingMachine.h"

VendingMachine::VendingMachine(string model, int numProducts) {
    this->numProduct = numProducts;
    this->model = model;
}


VendingMachine::VendingMachine(string model, int numProducts, int Q, int D, int N) {
    this->numProduct = numProducts;
    this->model = model;
    changeMachine.insertChange(Q,D,N);
    init.quarters = Q;
    init.dimes = D;
    init.nickels = N;
}

VendingMachine::~VendingMachine() {
    for (auto &p : products){
        delete p;
        p = nullptr;
    }
}

void VendingMachine::stockMachine(Inventory &inven, string selection, int ID, int quantity) {
    string name = "";
    int price = 0;
    int availQuantity = inven.removeProduct(ID, quantity);
    name = inven.nameLookUp(ID);
    price = inven.priceLookUp(ID);
    availProd *temp = new availProd;
    temp->ID = ID;
    temp->initialQuantity = quantity;
    temp->selection = selection;
    temp->quantity = quantity;
    temp->price = price;
    temp->name = name;
    products.push_back(temp);
}

void VendingMachine::printItemList() {
    cout << "Available items:" << endl;
    for (int i = 0; i < products.size(); i++) {
        cout << right << setw(6) << products[i]->selection
             << setw(4) << products[i]->price << left << products[i]->name << endl;
    }
}

void VendingMachine::makeSelection(string select) {
    bool valid = false;
    availProd *pCurr;
    for (auto &p : products){
        if (toupper(p->selection.c_str()[1]) == toupper(select.c_str()[1])){
            pCurr = p;
            valid = true;
            cout << "You selected \"" << p->name << "\"." << endl;
            cout << fixed << setprecision(2) << "The cost of this item is " << p->price << " cents." << endl;
            break;
        }
    }
    if (valid){
        int insertedAmount = 0;
        cout << "Insert your money -->";
        int curr = 0;
        int inserted[4] = {0};
        while(cin >> curr){
            if (curr == 0) { break; }
            if (curr == 100) {
                inserted[0]++;
                insertedAmount += 100;
            }
            else if(curr == 25){
                inserted[1]++;
                insertedAmount += 25;
            }else if(curr == 10){
                inserted[2]++;
                insertedAmount += 10;
            }
            else if (curr == 5){
                inserted[3]++;
                insertedAmount += 5;
            }
        }
        if (insertedAmount == 0){
            cout << "You chose to cancel your transaction." << endl;
        }
        else if (insertedAmount < pCurr->price){
            cout << "Not enough money inserted." << endl;
        }
        else if ((insertedAmount - pCurr->price) > changeMachine.totalBal()){
            cout << "Insufficient change." << endl;
        }
        else{
            int costOfItem = pCurr->price;
            int initQ, initD, initN;
            int change[3] = {0};
            if (pCurr-> quantity == 0){
                cout << "Product is out of stock." << endl;
            }else{
                if (changeMachine.giveChange(change, costOfItem, inserted[0], inserted[1],inserted[2],inserted[3])){
                    pCurr->quantity -= 1;
                    transaction *tPtr = new transaction;
                    tPtr->trans = transNum;
                    transNum++;
                    tPtr->select = select;
                    tPtr->cost = costOfItem;
                    tPtr->paid = insertedAmount;
                    tPtr->pDollar = inserted[0];
                    tPtr->pQuarter = inserted[1];
                    tPtr->pDime = inserted[2];
                    tPtr->pNickel = inserted[3];
                    tPtr->change = insertedAmount - costOfItem;
                    tPtr->quarter = change[0];
                    tPtr->dime = change[1];
                    tPtr-> nickel = change[2];
                    trans.push_back(tPtr);
                    cout << "Your change of " << fixed << setprecision(2) <<insertedAmount - costOfItem << " is given as:" << endl;
                    cout << '\t' << left << setw(12) << "quarter(s): " << tPtr->quarter << endl;
                    cout << '\t' << left << setw(12) << "dimes(s): " << tPtr->dime << endl;
                    cout << '\t' << left << setw(12) << "nickels(s): " << tPtr->nickel << endl;
                    cout << "Thank you! Please take your item." << endl << endl;
                }
                else{
                    cout << "Insufficient Change." << endl;
                    cout << "Your transaction cannot be processed." << endl;
                    cout << "Please take back your money." << endl << endl;
                }
            }
        }
    }
    else{
        cout << "Invalid Selection." << endl;
    }
}

bool VendingMachine::validate(string cardNumber) {
    if (cardNumber.length() < 13 || cardNumber.length() > 16){
        return false;
    }else{
        int totalEven = 0;
        int totalOdd = 0;
        int totalSum = 0;
        for (int i = 1; i < cardNumber.length(); i+=2){
            int currOdd = stoi(cardNumber.substr(cardNumber.length()-i,1));
            int curr = stoi(cardNumber.substr(cardNumber.length()-1-i,1));
            curr *= 2;
            if (curr > 9){
                string temp = to_string(curr);
                curr = stoi(temp.substr(0,1)) + stoi(temp.substr(1,1));
            }
            totalEven += curr;
            totalOdd += currOdd;
        }
        totalSum = totalEven + totalOdd;
        return totalSum%10 == 0;
    }
}

void VendingMachine::generateReport() {
    cout << "Current Balance: $" << static_cast<double>(changeMachine.totalBal())/100
    << " (" << changeMachine.getDollars() << " $, " << changeMachine.getQuarters() << " Q "
    << changeMachine.getDimes() << " D " << changeMachine.getNickels() << " N)" << endl << endl;
    cout << "Code     ID     Description         Initial    Current" << endl;
    for (auto &p : products){
        cout << setw(3) << p->selection << setw(9) << p->ID << "   " << setw(20) << left << p->name
        << setw(4) << right << p->initialQuantity << setw(10) << p->quantity << endl;
    }
    cout << endl;
}


