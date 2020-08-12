/*  Program: MFraction.h
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/5/2018
    Description: The header file for the MFraction class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#ifndef PROJECT_3_MFRACTION_H
#define PROJECT_3_MFRACTION_H

#include <iostream>
#include <string>

using namespace std;

class MFraction {
private:
    int numerator;
    int denominator;
    int whole;
    MFraction simplify(int, int, int) const;
    MFraction simplifySigns(int, int, int) const;
    int GCD(int a, int b) const;
public:
    MFraction(int n = 0, int d = 1,int w = 0);
    int getDenominator() const;
    int getNumerator() const;
    int getWhole() const;
    MFraction& setNumerator(int n);
    MFraction& setDenominator(int d);
    MFraction& setWhole(int w);
    MFraction operator+ (const MFraction &s) const;
    MFraction operator- (const MFraction &s) const;
    MFraction operator* (const MFraction &s) const;
    MFraction operator/ (const MFraction &s) const;
    MFraction operator- () const;
    void printFloat() const;
    bool operator<(const MFraction &s) const;
    bool operator<= (const MFraction &s) const;
    bool operator> (const MFraction &s) const;
    bool operator>= (const MFraction &s) const;
    bool operator== (const MFraction &s) const;
    bool operator!= (const MFraction &s) const;
    friend istream& operator>> (istream &in, MFraction &f);
    friend ostream& operator<< (ostream &out, const MFraction &f);
};


#endif //PROJECT_3_MFRACTION_H
