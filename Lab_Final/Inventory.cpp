/*  Program: Inventory.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 12/10/2018	     
    Description: Implementation file for inventory class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include "Inventory.h"

using namespace std;

Inventory::Inventory(int in, int q, double p) {
    itemNumber = in;
    quantity = q;
    price = p;
}

void Inventory::setItemNumber(int in) {
    itemNumber = in;
}

void Inventory::setQuantity(int q) {
    if (q > 0){
        quantity = q;
    }
}

void Inventory::setPrice(double p) {
    if (p > 0){
        price = p;
    }
}

int Inventory::getItemNumber() const {
    return itemNumber;
}

int Inventory::getQuantity() const {
    return quantity;
}

double Inventory::getPrice() const {
    return price;
}

double Inventory::totalPrice() const {
    return price*quantity;
}

bool Inventory::removeOne() {
    if (quantity > 0){
        quantity--;
        return true;
    }
    else{
        return false;
    }
}
