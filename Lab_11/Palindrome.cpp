/*  Program: Palindrome.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/21/2018	     
    Description: Program to test whether an inputted string is a palindrome.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>

using namespace std;

bool palindrome(string);
bool palindromeRec(string, int, int);

int main() {
    while(true){
        cout << "Input a word (enter 0 to quit): ";
        string word;
        cin >> word;
        if (word == "0"){
            cout << "Program Terminating.";
            break;
        }
        if (word.length() > 50){
            cout << "Word Length too long." << endl << endl;
        }
        else{
            if (palindrome(word) && palindromeRec(word, 0, word.length() - 1)){
                cout << word << " is a palindrome." << endl;
            }
            else{
                cout << word << " is NOT a palindrome." << endl;
            }
        }
    }
    return 0;
}

bool palindrome(string s){
    for (int i = 0; i < s.length()/2; i++){
        if (s.substr(i,1) != s.substr(s.length()-1-i,1)){
            return false;
        }
    }
    return true;
}

bool palindromeRec(string s, int init, int final){
    if (init > final){ return true;}
    if (s.substr(init,1)!= s.substr(final,1)){ return false;}
    return palindromeRec(s, init + 1, final - 1);
}