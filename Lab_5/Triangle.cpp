/*  Program: Triangle.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/24/2018	     
    Description: A program that takes 3 inputs and computes if it is a valid triangle. If it is it will output the type of triangle (scalene, isoceles or equilateral).

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>

using namespace std;

void inputSides(double &s1, double &s2, double &s3);
string triangleType(double s1, double s2, double s3);

int main() {
    double s1, s2, s3;
    s1 = s2 = s3 = 0.0;
    do {
        inputSides(s1,s2,s3);
        if (s1 == 0 && s2 == 0 && s3 == 0){
            cout << "Terminating Program.";
            break;
        }
        cout << triangleType(s1,s2,s3) << endl;
    }while(true);
    return 0;
}

void inputSides(double &s1, double &s2, double &s3){
    cout << "Input three triangle side lengths (0 0 0 to Terminate): ";
    cin >> s1 >> s2 >> s3;
}

string triangleType(double s1, double s2, double s3){
    string result = "The triangle is ";
    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1){
        result += "invalid.";
    }
    else{
        result += "valid. It is a ";
        if (s1 == s2 && s2 == s3){
            result += "equilateral ";
        }
        else if ((s1 == s2 && s1 != s3) || (s2 == s3 && s2 != s1) || (s1 == s3 && s1 != s2)){
            result += "isocele s";
        }
        else {
            result += "scalene ";
        }
        result += "triangle.\n";
    }
    return result;
}
