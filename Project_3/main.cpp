/*  Program: main.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/5/2018
    Description: The driver file for the MFraction class that executes the program.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include "MFraction.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Pair{
    char oper;
    int count;
};



int main() {
    cout << "Jin Choi's Mixed Fractions Tutorial Program" << endl << endl;
    cout << "Please follow instructions carefully.\nEnter your operation like 1 1/2 + 1/4.\nEnter 0/1 % 0/1 to stop the program." << endl << endl;
    int correct = 0, total = 0;
    struct Pair signs[4] = {
            {'+',0},
            {'-',0},
            {'*',0},
            {'/',0}
    };
    vector<MFraction> oper1;
    vector<char> operators;
    vector<MFraction> oper2;
    MFraction frac1, frac2, frac3;
    MFraction response;
    char oper;
    while(true){
        cout << setw(28) << "Please enter your operation " << "--> ";
        cin >> frac1;
        cin >> oper;
        cin >> frac2;
        bool valid = true;
        if (frac1.getDenominator() == 0){
            cout << frac1 << " is an invalid operand" << endl << endl;
            valid = false;
        }
        if (frac2.getDenominator() == 0){
            cout << frac2 << " is an invalid operand" << endl << endl;
            valid = false;
        }
        if (oper == '/' && frac2.getWhole() == 0 && frac2.getNumerator() == 0){
            cout << "Invalid expression, division by 0." << endl << endl;
            valid = false;
        }
        if (frac1.getWhole() == 0 && frac1.getNumerator()==0 && frac1.getDenominator()==1 && oper == '%' && frac2.getWhole()==0 && frac2.getNumerator()==0 && frac2.getDenominator()==1) {
            cout << "You answer " << correct << " out of " << total << " questions correctly.\n\n";
            cout << "The problems with incorrect answers:\n";
            int n = oper1.size();
            for (int i = 0 ; i < n;i++){
                cout << oper1.back() << " " << operators.back() << " " << oper2.back();
                oper1.pop_back();
                operators.pop_back();
                oper2.pop_back();
                cout << endl;
            }
            int max = 0;
            for (int i = 0; i < 3; i++){
                max = signs[max].count < signs[i].count ? i : max;
            }
            cout << endl << "It seems like you have the most problem with ";
            for (int i = 0; i < 3; i++){
                if (signs[i].count == signs[max].count){
                    if (i == 2){
                        cout << signs[i].oper << " ";
                    }
                    else{
                        cout << signs[i].oper << ", ";
                    }
                }
            }
            cout << " operation(s).";
            break;
        }if (valid){
            switch (oper){
                case '+': frac3 = frac1 + frac2; break;
                case '-': frac3 = frac1 - frac2; break;
                case '*': frac3 = frac1 * frac2; break;
                case '/': frac3 = frac1 / frac2; break;
                default: cout << oper << " is an invalid operator" << endl << endl; valid = false; break;
            }
        }
        if (valid){
            cout << setw(28) << left << "Please enter your result" << "--> ";
            cin >> response;
            if (frac3 == response){
                cout << "Congratulations! It is correct." << endl;
                correct++;
            }
            else{
                oper1.push_back(frac1);
                operators.push_back(oper);
                oper2.push_back(frac2);
                switch (oper){
                    case '+': signs[0].count++; break;
                    case '-': signs[1].count++; break;
                    case '*': signs[2].count++; break;
                    case '/': signs[3].count++; break;
                    default: break;
                }
                cout << "It is incorrect. The correct answer is" << endl;
                cout << frac1 << " " << oper << " " << frac2 << " = " << frac3 << endl;
            }
            frac3.printFloat();
            total++;
        }
        cin.clear();
        cin.ignore(INTMAX_MAX, '\n');
    }
    return 0;
}
