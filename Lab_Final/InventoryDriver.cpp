/*  Program: InventoryDriver.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 12/10/2018	     
    Description: Driver for the inventory class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    cout << "Author: Jin Choi" << endl << endl;
    ifstream invenfile("../inventory.txt");
    int lines = 0;
    string s;
    while (getline(invenfile, s)){
        lines++;
    }
    cout << "Number of records: " << lines << endl;
    Inventory inven[lines];
    int size = 0;
    invenfile.close();
    invenfile.open("../inventory.txt");
    while(!invenfile.eof()){
        int in, q;
        double p;
        invenfile >> in >> q >> p;
        inven[size].setItemNumber(in);
        inven[size].setQuantity(q);
        inven[size].setPrice(p);
        size++;
        invenfile.ignore(2);
    }

    cout << "Which record doyou want to update?  ";
    int selection = 0;
    cin >> selection;
    cout << "Current information about record " << selection << endl;
    cout << left << setw(14) << "Item:" << inven[selection].getItemNumber() << endl;
    cout << left << setw(14) << "Quantity:" << inven[selection].getQuantity() << endl;
    cout << left << setw(14) << "Price Each:" << inven[selection].getPrice() << endl;
    cout << left << setw(14) << "Price Total:" << inven[selection].totalPrice() << endl;

    inven[selection].removeOne();

    cout << endl;
    cout << "Updated information about record " << selection << endl;
    cout << left << setw(14) << "Item:" << inven[selection].getItemNumber() << endl;
    cout << left << setw(14) << "Quantity:" << inven[selection].getQuantity() << endl;
    cout << left << setw(14) << "Price Each:" << inven[selection].getPrice() << endl;
    cout << left << setw(14) << "Price Total:" << inven[selection].totalPrice() << endl;

    invenfile.close();
    return 0;
}