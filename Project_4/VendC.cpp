/*  Program: VendC.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/13/2018	     
    Description: Derived class of VendingMachine, able to accept credit card as payment.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <string>
#include "VendingMachine.h"

static int currNoC = 1;

class VendC : public VendingMachine{
protected:
    vector<transactionCC*> transCC;
    int machineNumber;
public:

    VendC(string model, int numProducts) : VendingMachine(model, numProducts){
        machineNumber = currNoC;
        currNoC++;
    }

    ~VendC(){
        for (auto &t : transCC){
            delete t;
            t = nullptr;
        }
    }
    void generateReport() override {
        if (!transCC.empty()){
            cout << "Machine: " << modelNumber() << endl;
            int total = 25*init.quarters + 10*init.dimes + 5*init.nickels;
            int totalCost = 0;
            cout << "Initial Balance: $" << fixed << setprecision(2) << static_cast<double>(total)/100 <<
            " (" << init.dollars << " $, "
            << init.quarters << " Q, " << init.dimes << " D, "
            << init.nickels << " N)" << endl << endl;
            cout << "Trans Item     Cost     Paid Last 4 digits of credit card" << endl;
            for (auto &t : transCC){
                totalCost += t->cost;
                cout << right << setw(3) << t->trans << setw(7) << t->select << setw(8)
                << t->cost << setw(9) << t->paid << setw(6) << t->lastFour << endl;
            }
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
        cout << "This machine accepts credit card only." << endl;
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
                }else{
                    pCurr->quantity -= 1;
                    transactionCC *tPtr = new transactionCC;
                    tPtr->trans = transNum;
                    transNum++;
                    tPtr->select = select;
                    tPtr->cost = pCurr->price;
                    tPtr->paid = pCurr->price;
                    tPtr->lastFour = stoi(cardNumber.substr(12,4));
                    transCC.push_back(tPtr);
                    cout << "Your credit card was successfully charged for $" << fixed << setprecision(2) << static_cast<double>(pCurr->price)/100 << "." << endl;
                    cout << "Thank you! Please take your item." << endl;
                }
            }
        }
        else{
            cout << "Invalid Selection." << endl;
        }
    }
};

