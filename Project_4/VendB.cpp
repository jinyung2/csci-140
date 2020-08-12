/*  Program: VendB.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/13/2018
    Description: Derived class of VendingMachine, able to accept coins and dollar bills as method of payment.

    I certify that the code below is my own work.

	Exception(s): N/A

*/
#include "VendingMachine.h"

static int currNoB = 1;

class VendB : public VendingMachine {

protected:
    int machineNumber;
public:
    VendB(string model, int numProducts, int Q, int D, int N) : VendingMachine(model,numProducts,Q,D,N){
        machineNumber = currNoB;
        currNoB++;
    }

    void generateReport() override {
        if (!trans.empty()){
            cout << "Machine: " << modelNumber() << endl;
            int total = 25*init.quarters + 10*init.dimes + 5*init.nickels;
            int totalCost = 0;
            cout << "Initial Balance: $" <<fixed << setprecision(2) << static_cast<double>(total)/100 <<
                 " (" << init.dollars << " $, "
                 << init.quarters << " Q, " << init.dimes << " D, "
                 << init.nickels << " N)" << endl << endl;
            cout << "Trans Item     Cost     Paid ($, Q, D, N) Changes(Q, D, N)" << endl;
            for (auto &t : trans){
                totalCost += t->cost;
                cout << right << setw(3) << t->trans << setw(7) << t->select << setw(8)
                     << t->cost << setw(9) << t->paid << "  (" << t->pDollar << setw(3)
                     << t->pQuarter << setw(3) << t->pDime << setw(3) << t->pNickel << ")"
                     << setw(7) << t->change << "  (" << t->quarter << setw(3) << t->dime << setw(3) << t->nickel << ")" << endl;
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
        cout << "This machine accepts one-dollar bills and coins." << endl;
    }
};
