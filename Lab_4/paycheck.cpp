/*  Program: paycheck.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 09/24/18
    Description: A program from the book that utilizes a function to calculate paycheck.

    I certify that the code below is my own work.

	Exception(s): This is code provided by the book, with minor edits.

*/


#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
void printDescription(); 
void computePaycheck(float, int, float&, float&); 

int main()
{
	float payRate;
	float grossPay;
	float netPay;
	int hours;
	
	cout << setprecision(2) << fixed;
	
	cout << "Welcome to the Pay Roll Program" << endl; 
	
	printDescription(); //Call to Description function
	
	cout << "Please input the pay per hour" << endl;
	cin >> payRate;
	
	cout << endl << "Please input the number of hours worked" << endl;
	cin >> hours;
	cout << endl << endl;
	
	computePaycheck(payRate,hours,grossPay,netPay);
	
	cout << "The gross pay is $ " << grossPay << endl; //  Fill in the code to output grosspay
	
	cout << "The net pay is $" << netPay << endl;
	
	cout << "We hoped you enjoyed this program" << endl;
	
	return 0;
}




//   ********************************************************************
//                         printDescription
//   
//   task:     This function prints a program description
//   data in:  none
//   data out: none
//
//   ********************************************************************



void printDescription() //The function heading
{
    cout << "************************************************"  << endl << endl;
    cout << "This program takes two numbers (pay rate & hours)" << endl;
	cout << "and  multiplies them to get gross pay "            << endl;   
    cout << "it then calculates net pay by subtracting 15%"     << endl;
	cout << "************************************************"  << endl << endl;
}




//  *********************************************************************
//                        computePaycheck
//   
//   task:     This function takes rate and time and multiples them to
//             get gross pay and then finds net pay by subtracting 15%.
//   data in:  pay rate and time in hours worked
//   data out: the gross and net pay
//
//   ********************************************************************




void computePaycheck(float rate, int time, float& gross, float& net)

{		 
	gross = rate * time;
	net = gross * 0.85;

    //  Fill in the code to find grosspay and net pay
			 
}
