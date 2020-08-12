/*  Program: RecMemberTest.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 10/24/2018
    Description: Recursive function that finds a value in an array.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

bool isMember(const int a[], int n , int key);

int main() {
    int a[10];
    cout << "Enter 10 numbers separated by spaces" << endl;
    for (int &i : a) {
        cin >> i;
    }
    cout << "Enter value you are searching for: ";
    int find;
    cin >> find;
    if (isMember(a,10,find)){
        cout << "The value was found.";
    }
    else{
        cout << "The value was not found.";
    }
    return 0;
}

bool isMember(const int a[], int n , int key){
    if (a[n] == key){return true;}
    if (n == -1) {return false;}
    return isMember(a, n-1,key);
}