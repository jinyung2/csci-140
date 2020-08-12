/*  Program: VendingMachineDriver.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 12/03/2018
    Description: Main driver class that reads from the input files and runs the program.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "VendingMachine.h"
#include "VendA.cpp"
#include "VendB.cpp"
#include "VendC.cpp"
#include "VendD.cpp"

using namespace std;

static int NUM_MODEL = 4;


int main() {
    fstream machines;
    fstream products;
    fstream report;
    string code;
    cout << "Please enter a startup code --> ";
    cin >> code;
    if (code == "csci140"){
        cout << "Initializing machines. Pleast wait ... " << endl;
        machines.open("../machines.txt");
        products.open("../products.txt");
        vector<VendingMachine*> list[NUM_MODEL];
        Inventory stockList(products);
        VendingMachine *vPtr = nullptr;
        string model = "";
        int numberMachines = 0;
        int Q, D, N, num, ID, quantity;
        string selection;

        while (!machines.eof()){
            char c = machines.peek();
            machines >> model;
            machines >> numberMachines;
            for (int i = 0; i < numberMachines; i++){
                machines >> Q >> D >> N >> num;
                char option = model.substr(3,1).c_str()[0];
                switch(option){
                    case 'A': {vPtr = new VendA(model,num,Q,D,N);list[0].push_back(dynamic_cast<VendA*>(vPtr)); } break;
                    case 'B': {vPtr = new VendB(model,num,Q,D,N); list[1].push_back(dynamic_cast<VendB*>(vPtr));} break;
                    case 'C': {vPtr = new VendC(model,num); list[2].push_back(dynamic_cast<VendC*>(vPtr));} break;
                    case 'D': {vPtr = new VendD(model,num,Q,D,N); list[3].push_back(dynamic_cast<VendD*>(vPtr));} break;
                    default: cout << "Invalid Input."; break;
                }
                for (int j = 0; j < num; j++){
                    machines >> selection >> ID >> quantity;
                    vPtr->stockMachine(stockList, selection, ID, quantity);
                }
            }
            machines.ignore(2);
            vPtr = nullptr;
        }

        delete vPtr;
        cout << "Machines are ready.\nAvailable machines: ";
        string s;
        for (int i = 0; i < NUM_MODEL; i++){
            if (list[i].size() > 0){
                for (auto &v : list[i]){
                        s += v->modelNumber();
                        s += ", ";
                }
            }
        }
        s.erase(s.size()-2,s.size()-1);
        cout << s << endl << endl;
        while(true){
            string choice;
            char option;
            cout << "Select a machine --> ";
            cin >> choice;
            if (choice == "csci140"){
                for (int i = 0; i < NUM_MODEL; i++){
                    for (int j = 0; j < list[i].size(); j++){
                        VendingMachine *vPtr  = list[i][j];
                        vPtr->generateReport();
                    }
                }
                break;
            }
            option = toupper(choice.c_str()[3]);
            int machNum = choice.c_str()[4]-48;
            if (option < 'A' || option > 'D'){
                cout << "Model does not exist." << endl;
            }else if (machNum > list[option-65].size()) {
                cout << "Instance of Machine does not exist." << endl;
            }else{
                VendingMachine *vCurr = list[option-65][machNum-1];
                vCurr->startUp();
                vCurr->printItemList();

                string selection;
                cout << "Select an item --> ";
                cin >> selection;
                vCurr->makeSelection(selection);

            }
            cin.clear();
            cin.ignore(INTMAX_MAX,'\n');
        }


    }
    else{
        cout << "Code Incorrect, Program Terminating.";
    }
    return 0;
}
