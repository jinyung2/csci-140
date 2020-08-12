/*  Program: MyInteger.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/29/2018	     
    Description: Implementation file for MyInteger class.i

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "MyInteger.h"

using namespace std;

MyInteger::MyInteger(int v) {
    value = v;
}

void MyInteger::setValue(int v) {
    value = v;
}

int MyInteger::getValue() const {
    return value;
}

MyInteger MyInteger::operator+(const MyInteger &r) const {
    return MyInteger(value + r.value);
}

MyInteger MyInteger::operator-(const MyInteger &r) const {
    return MyInteger(value - r.value);
}

bool MyInteger::operator==(const MyInteger &r) const {
    return value == r.value;
}

ostream &operator<<(ostream &out, const MyInteger &r) {
    out << r.value;
    return out;
}

istream &operator>>(istream &in, MyInteger &r) {
    in >> r.value;
    return in;
}
