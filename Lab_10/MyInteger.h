// Created by T. Vo for CSCI 140 Fall 2018
#ifndef MYINTEGER_H
#define MYINTEGER_H

#include <iostream>

using namespace std;

class MyInteger
{
private:
	int *pValue;

public:
	MyInteger(int v = 0);
	~MyInteger();
	void setValue(int v);
	int getValue() const;
	void operator=(const MyInteger &r);
	MyInteger operator+(const MyInteger &r) const;
	MyInteger operator-(const MyInteger &r) const;
	bool operator==(const MyInteger &r) const;

	friend ostream &operator<<(ostream &out, const MyInteger &r);
	friend istream &operator>>(istream &in, MyInteger &r);
};
#endif