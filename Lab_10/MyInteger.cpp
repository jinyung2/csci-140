/*  Program: MyInteger.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/29/2018	     
    Description: Implementation file for MyInteger class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "MyInteger.h"

using namespace std;

MyInteger::MyInteger(int v) {
    pValue = new int;
    *pValue = v;
}
MyInteger::~MyInteger(){
    delete pValue;
    pValue = nullptr;
}

void MyInteger::setValue(int v) {
    *pValue = v;
}

int MyInteger::getValue() const {
    return *pValue;
}

void MyInteger::operator=(const MyInteger &r){
    pValue = new int;
    *pValue = r.getValue();
}

MyInteger MyInteger::operator+(const MyInteger &r) const {
    return MyInteger(*pValue + r.getValue());
}

MyInteger MyInteger::operator-(const MyInteger &r) const {
    return MyInteger(*pValue - r.getValue());
}

bool MyInteger::operator==(const MyInteger &r) const {
    return *pValue == r.getValue();
}

ostream &operator<<(ostream &out, const MyInteger &r) {
    out << r.getValue();
    return out;
}

istream &operator>>(istream &in, MyInteger &r) {
    in >> *(r.pValue);
    return in;
}
