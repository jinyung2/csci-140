/*  Program: files.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/28/2018
    Description: Takes in an input file payroll.cpp and outputs the data

    I certify that the code below is my own work.

	Exception(s): Book code with code blocks filled in.

*/

// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream payfile;
	ofstream out; // Fill in the code to define payfile as an input file
	float gross;
	float net;
	float hours;
	float payRate;
    float stateTax;
	float fedTax;


    cout << fixed << setprecision(2) << showpoint;
    payfile.open("/home/john/CLionProjects/Lab_12/payroll.cpp");// FILL IN THE CODE TO OPEN payfile AND ATTACH IT TO THE PHYSICAL FILE
    out.open("/home/john/CLionProjects/Lab_12/pay.out");// NAMED payroll.dat
    out << fixed << setprecision(2) << showpoint;
	// FILL IN CODE TO WRITE A CONDITIONAL STATEMENT TO CHECK IF payfile
	// DOES NOT EXIST.
    if (!payfile) {
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	cout << "Payrate      Hours    Gross Pay       Net Pay"
           << endl   << endl;
    out << "Payrate      Hours    Gross Pay       Net Pay"
         << endl   << endl;
    payfile >> hours; // FILL IN CODE TO PRIME THE READ FOR THE payfile FILE.
     // FILL IN CODE TO WRITE A LOOP CONDITION TO RUN WHILE payfile HAS MORE 
     // DATA TO PROCESS.
	while (!payfile.eof()){
	   payfile >> payRate >> stateTax >> fedTax;
	   gross = payRate * hours;
	   net = gross - (gross * stateTax) - (gross * fedTax);
	   cout << payRate << setw(15) << hours << setw(12) << gross
              << setw(12)  << net << endl;
	   out << payRate << setw(15) << hours << setw(12) << gross
             << setw(12)  << net << endl;
	   payfile >> hours; // FILL IN THE CODE TO FINISH THIS WITH THE APPROPRIATE
		          // VARIABLE TO BE INPUT
	}
	payfile.close();
	out.close();
      return 0;
}