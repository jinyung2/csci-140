/*  Program: VendD.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/13/2018
    Description: Derived class of VendingMachine class that is able to take both credit card and dollar bills as a method of payment.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <string>
#include "VendingMachine.h"

static int currNoD = 1;

class VendD : public VendingMachine{
protected:
    vector<transactionCC*> transCC;
    int machineNumber;
public:
    VendD(string model, int numProducts, int Q, int D, int N) : VendingMachine(model,numProducts,Q,D,N){
        machineNumber = currNoD;
        currNoD++;
    }
    ~VendD(){
        for (auto &t : transCC){
            delete t;
            t = nullptr;
        }
    }

    void generateReport() override {
        cout << "Machine: " << modelNumber() << endl;
        int total = 25*init.quarters + 10* init.dimes + 5*init.nickels;
        int totalCost = 0;
        cout << "Initial Balance: $" << fixed << setprecision(2) <<static_cast<double>(total)/100 <<
             " (" << init.dollars << " $, "
             << init.quarters << " Q, " << init.dimes << " D, "
             << init.nickels << " N)" << endl << endl;
        if (!trans.empty()){
            cout << "Trans Item     Cost     Paid ($, Q, D, N) Changes(Q, D, N)" << endl;
            for (auto &t : trans){
                totalCost += t->cost;
                cout << right << setw(3) << t->trans << setw(7) << t->select << setw(8)
                     << t->cost << setw(9) << t->paid << "  (" << t->pDollar << setw(3)
                     << t->pQuarter << setw(3) << t->pDime << setw(3) << t->pNickel << ")"
                     << setw(7) << t->change << "  (" << t->quarter << setw(3) << t->dime << setw(3) << t->nickel << ")"<< endl;
            }
        }
        if (!transCC.empty()){

            cout << "Trans Item     Cost     Paid Last 4 digits of credit card" << endl;
            for (auto &t : transCC){
                totalCost += t->cost;
                cout << right << setw(3) << t->trans << setw(7) << t->select << setw(8)
                     << t->cost << setw(9) << t->paid << setw(6) << t->lastFour << endl;
            }
        }
        if (!transCC.empty() || !trans.empty()){
            cout << "Total Cost: " << totalCost << endl << endl;
            VendingMachine::generateReport();
        }

    }

    string modelNumber() override {
        string result = VendingMachine::modelNumber();
        result += to_string(machineNumber);
        return result;
    }

    void startUp() override {
        cout << "This machine accepts both dollar and credit card." << endl;
    }

    void makeSelection(string select) override {
        bool valid = false;
        availProd *pCurr;
        for (auto &p : products){
            if (toupper(p->selection.c_str()[1]) == toupper(select.c_str()[1])){
                pCurr = p;
                valid = true;
                cout << "You selected \"" << p->name << "\"." << endl;
                cout << "The cost of this item is " << p->price << " cents." << endl;
                break;
            }
        }
        if (valid){
            int DollarOrCC;
            while(true){
                cout << "Purchase options:\n\t1. Credit Card\n\t2. Dollar Bill\n\t'Q' to Quit-->";
                cin>>DollarOrCC;
                if (cin.fail()){
                    cout << "Invalid option selected." << endl;
                }
                if (DollarOrCC == 1){
                    cout << "Credit Card option selected." << endl;
                    break;
                }
                else if (DollarOrCC == 2){
                    cout << "Dollar Bill option selected." << endl;
                    break;
                }
                else if (DollarOrCC == 'Q'){
                    cout << "Cancelling transaction." << endl << endl;
                    break;
                }
            }
            if (DollarOrCC == 1){
                string cardNumber;
                int failure = 0;
                while (failure < 2){
                    cout << "Enter your credit card number -->";
                    cin >> cardNumber;
                    if (validate(cardNumber)){
                        break;
                    }
                    else{
                        cout << "Invalid credit card number was entered." << endl;
                        failure++;
                    }
                }
                if (failure == 2){
                    cout << "Too many invalid card numbers." << endl;
                }else{
                    //purchase
                    if (pCurr-> quantity == 0){
                        cout << "Product is out of stock." << endl;
                    }
                    else {
                        pCurr->quantity -= 1;
                        transactionCC *tPtr = new transactionCC;
                        tPtr->trans = transNum;
                        transNum++;
                        tPtr->select = select;
                        tPtr->cost = pCurr->price;
                        tPtr->paid = pCurr->price;
                        tPtr->lastFour = stoi(cardNumber.substr(12,4));
                        transCC.push_back(tPtr);
                        cout << "Your credit card was successfully charged for $" <<fixed << setprecision(2) << static_cast<double>(pCurr->price)/100 << "." << endl;
                        cout << "Thank you! Please take your item." << endl;
                    }
                }
            }
            else if(DollarOrCC == 2) {
                int insertedAmount = 0;
                cout << "Insert your money -->";
                int curr = 0;
                int inserted[4] = {0};
                while (cin >> curr) {
                    if (curr == 0) { break; }
                    if (curr == 100) {
                        inserted[0]++;
                        insertedAmount += 100;
                    } else if (curr == 25) {
                        inserted[1]++;
                        insertedAmount += 25;
                    } else if (curr == 10) {
                        inserted[2]++;
                        insertedAmount += 10;
                    } else if (curr == 5) {
                        inserted[3]++;
                        insertedAmount += 5;
                    }
                }
                if (insertedAmount == 0) {
                    cout << "You chose to cancel your transaction." << endl;
                } else if (insertedAmount < pCurr->price) {
                    cout << "Not enough money inserted." << endl;
                } else if ((insertedAmount - pCurr->price) > changeMachine.totalBal()) {
                    cout << "Insufficient change." << endl;
                } else {
                    //purchase, give change
                    int costOfItem = pCurr->price;
                    int numDollars = inserted[0];
                    int change[3] = {0};
                    if (pCurr-> quantity == 0){
                        cout << "Product is out of stock." << endl;
                    }else{
                        if (changeMachine.giveChange(change, costOfItem, numDollars, inserted[1], inserted[2],inserted[3])) {
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
                            tPtr->nickel = change[2];
                            trans.push_back(tPtr);
                            cout << "Your change of " << insertedAmount - costOfItem << " is given as:" << endl;
                            cout << '\t' << left << setw(12) << "quarter(s): " << tPtr->quarter << endl;
                            cout << '\t' << left << setw(12) << "dimes(s): " << tPtr->dime << endl;
                            cout << '\t' << left << setw(12) << "nickels(s): " << tPtr->nickel << endl;
                            cout << "Thank you! Please take your item." << endl << endl;
                        } else {
                            cout << "Insufficient Change." << endl;
                            cout << "Your transaction cannot be processed." << endl;
                            cout << "Please take back your money." << endl << endl;

                        }
                    }

                }
            }
        }
        else{
            cout << "Invalid Selection." << endl;
        }
    }
};
