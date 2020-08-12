/*  Program: main.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/11/2018	     
    Description: A main driver containing functions for IntegerTestScores,
    unitConversion, as well as Lab 5.6 Option 1 for the survey.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

void integerTestScores();
void unitConversion();
void survey();


int main() {
    integerTestScores();
    unitConversion();
    survey();
    return 0;
}

void integerTestScores(){
    int scoreOne, scoreTwo, scoreThree;
    float avgScore;
    int highest;
    int median;
    bool loop = true;
    while (loop){
        cout << "Enter three test scores (0 ~ 100): ";
        cin >> scoreOne >> scoreTwo >> scoreThree;
        if (scoreOne < 0 || scoreOne > 100 || scoreTwo < 0 || scoreTwo > 100 || scoreThree < 0 || scoreThree > 100){
            cout << "Invalid score input.\n";
        }
        else{
            int total = scoreOne + scoreTwo + scoreThree;
            avgScore = static_cast<float>(total)/3;
            highest = scoreOne;
            median = scoreOne;
            if (scoreTwo >= scoreOne){
                if (scoreTwo >= scoreThree){
                    if (scoreThree > scoreOne){
                        median = scoreThree;
                    }
                    highest = scoreTwo;
                }
                else{
                    median = scoreTwo;
                    highest = scoreThree;
                }
            }
            else if (scoreThree >= scoreOne){
                    median = scoreOne;
                    highest = scoreThree;
            }
            else{
                if (scoreThree >= scoreTwo){
                    median = scoreThree;
                }
                else{
                    median = scoreTwo;
                }
            }

            cout << "Average score: " << fixed << setprecision(1) << avgScore << endl
                 << "Highest score: " << highest << endl
                 << "Median score: " << median << endl << endl;
        }
        cout << "Continue? (Y) or (N): ";
        char select;
        cin >> select;
        select = tolower(select);
        if (select == 'n') {
            cout << "Terminating Program.";
            loop = false; }
    }

}

void unitConversion(){
    const float INT_METER = 0.0254;
    int selection;
    double meter;
    int feet, inches;
    feet = inches = 0;
    meter = 0;
    while(true){
        cout << "Input 1 for Feet and Inches to Meter and 2 for Meter to Feet and Inches: ";
        cin >> selection;
        switch(selection){
            case 1: {
                cout << "Enter feet and inches separated by space: ";
                cin >> feet >> inches;
                int totalInch = inches + feet * 12;
                meter = INT_METER * totalInch;
                cout << "\nMeter value: " << fixed << setprecision(2) << meter << endl << endl;
            }
                break;
            case 2: {
                cout << "Enter meter: ";
                cin >> meter;
                int resultInch = static_cast<int>(round(meter / INT_METER));
                feet = resultInch / 12;
                inches = resultInch % 12;
                cout << "\nFeet and Inches value: " << feet << " feet " << inches << " inches" << endl << endl;
            }
                break;
            default: cout << "Invalid Input. Terminating Program."; break;
        }
        if (selection != 1 && selection != 2){
            break;
        }
    }
}

void survey(){
    int coffee, tea, coke, orange;
    coffee = tea = coke = orange = 0;
    cout << "\t1. Coffee\t2. Tea\t3. Coke\t4. Orange Juice\n\n";
    int input = 0;
    int counter = 1;
    do{
        cout << "Please input the favorite beverage of person #" << counter << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << endl;
        cin >> input;
        switch (input){
            case 1: coffee++; break;
            case 2: tea++; break;
            case 3: coke++; break;
            case 4: orange++; break;
            default: cout << endl << endl; break;
        }
        counter++;
    }while(input != -1);
    cout << left <<  "Beverage" << setw(24) << right << "Number of Votes" << endl
        << string(32,'*') << endl;
    cout << setw(17) << left << "Coffee" << coffee << endl;
    cout << setw(17) << left << "Tea" << tea << endl;
    cout << setw(17) << left <<"Coke" << coke << endl;
    cout << setw(17) << left<< "Orange Juice" << orange << endl;
}