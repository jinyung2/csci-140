/*  Program: VoteCount.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 12/10/18
    Description: Takes in number of candidates and votes. Keeps count of valid and invalid votes. outputs the winner with # of votes, in the case of a tie, the higher ID wins.

    I certify that the code below is my own work.

	Exception(s): N/A

*/


#include <iostream>

using namespace std;

void outputHighest(int* ptr, int size);

int main() {
    cout << "Author: Jin Choi" << endl << endl;
    cout << "Enter number of candidates --> ";
    int numCandidates = 0;
    int valid = 0;
    int invalid = 0;
    cin >> numCandidates;
    int *ptr;
    ptr = new int[numCandidates];
    cout << "Enter votes --> ";
    int votes;
    while (cin >> votes){
        if (votes == 0){
            break;
        }
        if (votes > numCandidates){
            invalid++;
        }
        else{
            valid++;
            ptr[votes-1]++;
        }
    }
    cout << "There are " << valid << " valid votes and " << invalid << " invalid votes." << endl;
    outputHighest(ptr, numCandidates);
    delete [] ptr;
    ptr = nullptr;
}

void outputHighest(int* ptr, int size){
    int highest = 0;
    for (int i = 0; i < size; i++){
        int temp = ptr[i];
        highest = ptr[highest] <= ptr[i] ? i : highest;
    }
    cout << "Candidate " << highest + 1 << " won the election with " << ptr[highest] << " votes.";
}


