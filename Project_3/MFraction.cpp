/*  Program: MFraction.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/5/2018
    Description: The implementation file for the MFraction class.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include "MFraction.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

MFraction::MFraction(int n, int d, int w){
    whole = w;
    numerator = n;
    denominator = d;
}

int MFraction::getDenominator() const { return denominator;}
int MFraction::getNumerator() const { return numerator; }
int MFraction::getWhole() const { return whole; }

MFraction &MFraction::setNumerator(int n){
    numerator = n;
    return *this;
}
MFraction &MFraction::setDenominator(int d){
    denominator = d;
    return *this;
}
MFraction &MFraction::setWhole(int w){
    whole = w;
    return *this;
}
MFraction MFraction::operator+ (const MFraction &s) const{
    int common = denominator*s.denominator;
    int num = 0;
    if (whole < 0){
        num += (whole*denominator-numerator)*s.denominator;
    }
    else{
        num += (whole*denominator+numerator)*s.denominator;
    }
    if (s.whole < 0){
        num += (s.whole*s.denominator-s.numerator)*denominator;
    }
    else{
        num += (s.whole*s.denominator+s.numerator)*denominator;
    }
    return simplify(num,common, 0);
}

MFraction MFraction::operator- (const MFraction &s) const{
    int common = denominator*s.denominator;
    int num = 0;
    if (whole < 0){
        num += (whole*denominator-numerator)*s.denominator;
    }
    else{
        num += (whole*denominator+numerator)*s.denominator;
    }
    if (s.whole < 0){
        num -= (s.whole*s.denominator-s.numerator)*denominator;
    }
    else{
        num -= (s.whole*s.denominator+s.numerator)*denominator;
    }
    return simplify(num, common, 0);
}
MFraction MFraction::operator* (const MFraction &s) const{
    int num = (whole * denominator + numerator) * (s.whole * s.denominator + s.numerator);
    int denom = denominator * s.denominator;
    return simplify(num,denom,0);
}
MFraction MFraction::operator/ (const MFraction &s) const{
    int num = (whole * denominator + numerator) * (s.denominator);
    int denom = (s.whole * s.denominator + s.numerator) * denominator;
    return simplify(num,denom,0);
}
MFraction MFraction::operator- () const{ // Negation
    MFraction result;
    if (whole == 0){
        result = simplifySigns(-numerator,denominator, whole);
    }else{
        result = simplifySigns(numerator,denominator,-whole);
    }
    return result;
}
void MFraction::printFloat() const{
    int num = numerator + whole*denominator;
    cout << "Its floating-point value is " << static_cast<double>(num)/denominator << endl << endl;
}
bool MFraction::operator< (const MFraction &s) const{
    if (whole < s.whole){
        return true;
    }
    else if (whole > s.whole){
        return false;
    }
    else{
        int common = denominator * s.denominator;

        return (numerator * common) < (s.numerator * common);
    }
}
bool MFraction::operator<= (const MFraction &s) const{
    if (whole < s.whole){
        return true;
    }
    else if (whole > s.whole){
        return false;
    }
    else{
        int common = denominator * s.denominator;

        return (numerator * common) <= (s.numerator * common);
    }
}
bool MFraction::operator> (const MFraction &s) const{
    if (whole > s.whole){
        return true;
    }
    else if (whole < s.whole){
        return false;
    }
    else{
        int common = denominator * s.denominator;

        return (numerator * common) > (s.numerator * common);
    }
}
bool MFraction::operator>= (const MFraction &s) const{
    if (whole > s.whole){
        return true;
    }
    else if (whole < s.whole){
        return false;
    }
    else{
        int common = denominator * s.denominator;

        return (numerator * common) >= (s.numerator * common);
    }
}
bool MFraction::operator== (const MFraction &s) const{
    int common = denominator * s.denominator;

    return whole == s.whole && ((numerator*common) == (s.numerator*common));
}

bool MFraction::operator!= (const MFraction &s) const{
    int common = denominator * s.denominator;

    return whole != s.whole || ((numerator*common) != (s.numerator*common));
}

istream& operator>> (istream &in, MFraction &f){
    f.setWhole(0).setNumerator(0).setDenominator(1);
    bool negate = false;
    if (in.peek() == 45){
        in.get();
        if (in.peek() == 32){
            negate = true;
        }
        else{
            in.putback(45);
        }
    }
    in >> f.whole;
    if (in.peek() != 10){
        if (in.peek() == 46){
            in.ignore();
        }
        if (in.peek() == 47){
            f.numerator = f.whole;
            f.whole = 0;
            in.ignore();
            in >> f.denominator;
        }
        else{
            char temp = in.get();
            char temp2;
            if (in.peek() == 42 || in.peek() == 43 || in.peek() == 45 || in.peek() == 47){
                temp2 = in.get();
                if (in.peek() == 32){
                    in.putback(temp2);
                    f.numerator = 0;
                    f.denominator = 1;
                }else{
                    in.putback(temp2);
                    in.putback(temp);
                    in >> f.numerator;
                    in.ignore();
                    in >> f.denominator;
                }
            }
            else{
                in.putback(temp);
                in >> f.numerator;
                in.ignore();
                in >> f.denominator;
            }
        }
    }
    if (negate){
        f = -f;
    }
    if (f.whole < 0 || f.whole > 0){
        if (f.numerator < 0 && f.denominator < 0){
            f.numerator = -f.numerator;
            f.denominator = -f.denominator;
        }
        else if(f.numerator < 0 ){
            f.whole = -f.whole;
            f.numerator = -f.numerator;
        }
        else if(f.denominator < 0){
            f.whole = -f.whole;
            f.denominator = -f.denominator;
        }
    }else{
        if ((f.numerator < 0 && f.denominator < 0)||(f.numerator > 0 &&f.denominator < 0)){
            f.numerator = -f.numerator;
            f.denominator = -f.denominator;
        }

    }

    return in;
}

ostream& operator<< (ostream &out, const MFraction &f){
    int w,n,d;
    w = f.whole;
    n = f.numerator;
    d = f.denominator;
    if (n != 0 && d != 0){
        if (abs(n) >= abs(d)){
            if (w < 0){ w -= n/d; }
            else{ w += n/d; }
            n = abs(n%d);
            d = abs(d);
        }
        if (n != 0){
            int GCM = f.GCD(n,d);
            n /= GCM;
            d /= GCM;
        }
    }
    if (w != 0){
        if (n != 0 ) {
            if ((n < 0 && d > 0) || (n > 0 && d < 0)){
                out << -w << " " << -n << "/" << d;
            }else{
                out << w << " " << n << "/" << d;
            }
        }
        else{
            out << w;
        }
    }else{
        if ( n != 0 ){
            if ((n < 0 && d > 0 )||(n > 0 && d > 0)){
                out << n << "/" << d;
            }
            else{
                out << -n << "/" << -d;
            }
        }else{
            out << w;
        }
    }
    return out;
}

int MFraction::GCD(int a, int b) const{
    if (abs(b) > abs(a)){
        int temp = b;
         b = a;
         a = temp;
    }
    if (a%b==0){
        return b;
    }
    return GCD(b,a%b);
}


MFraction MFraction::simplify(int n, int d, int w) const{
    if (n >= d){
        w += n/d;
        n = n%d;
    }
    if (n != 0){
        int common = GCD(n,d);
        n /= common;
        d /= common;
        return MFraction(n,d,w);
    }
    else{
        return MFraction(0,d,w);
    }
}

MFraction MFraction::simplifySigns(int numerator, int denominator, int whole) const {
    if (whole < 0 || whole > 0){
        if (numerator < 0 && denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
        else if(numerator < 0 ){
            whole = -whole;
            numerator = -numerator;
        }
        else if(denominator < 0){
            whole = -whole;
            denominator = -denominator;
        }
    }else{
        if ((numerator < 0 && denominator < 0)||(numerator > 0 &&denominator < 0)){
            numerator = -numerator;
            denominator = -denominator;
        }

    }
    return MFraction(numerator,denominator,whole);
}