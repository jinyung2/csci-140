/*  Program: scores.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/24/2018
    Description: A program that reads in scores into an array, with the size determined at run time. Utilizes dynamic arrays.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>

using namespace std;

double avg(int*, int);
void print(int*,int);
void bubble(int*, int);

int main() {
    int num = 0;
    cout  << "Please input the number of scores" << endl;
    cin >> num;
    int *scoreArr = new int[num];
    for (int i = 0; i < num; i++){
        cout << "Please enter a score" << endl;
        cin >> *(scoreArr+i);
    }
    cout << "The average of the scores is " << avg(scoreArr,num) << endl << endl;
    cout << "Here are the scores in ascending order" << endl;
    bubble(scoreArr, num);
    print(scoreArr, num);

    delete [] scoreArr;
    return 0;
}

double avg(int *scores, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += *(scores + i);
    }
    double result = sum / static_cast<double>(size);
    return result;
}

void print(int *scores, int size){
    for (int i = 0; i < size; i++){
        cout << *(scores+i) << endl;
    }
}

void bubble(int* scores, int size){
    bool swap;
    int final = 0;
    do {
        swap = false;
        for (int i = 0; i < size - final - 1; i++){
            if (*(scores+i)>*(scores+1+i)){
                swap = true;
                int temp = *(scores+i);
                *(scores+i) = *(scores+1+i);
                *(scores+1+i) = temp;
            }
        }
        final++;
    }while(swap);
}