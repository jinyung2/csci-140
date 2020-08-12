/*  Program: Grades.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/28/2018
    Description: takes data from graderoll.dat and outputs.

    I certify that the code below is my own work.

	Exception(s): Book code with code blocks filled in.

*/


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// This program reads records from a file.  The file contains the
// following: student's name, two test grades and final exam grade. 
// It then prints this information to the screen.


const int NAMESIZE = 15;
const int MAXRECORDS = 50;
struct Grades                             // declares a structure
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int final;
	char letter;
	
};

typedef Grades gradeType[MAXRECORDS];    
 // This makes gradeType a data type
 // that holds MAXRECORDS
 // Grades structures.



void readIt(ifstream& inData, Grades gradeRec[], int &total);// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.


int main()

{    
	 ifstream indata;
	 indata.open("/home/john/CLionProjects/Lab_12/graderoll.dat");
	 int numRecord;                // number of records read in
	 gradeType studentRecord; 
     
	if(!indata)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	readIt(indata,studentRecord,numRecord);// FILL IN THE CODE TO CALL THE FUNCTION ReadIt.
	 
	// output the information 
    for (int count = 0; count < numRecord; count++)
	{
	   cout << studentRecord[count].name << setw(10) 
		    << studentRecord[count].test1
		    << setw(10) << studentRecord[count].test2;
	   cout << setw(10) << studentRecord[count].final << setw(10) << studentRecord[count].letter << endl;
	}                
	indata.close();
	return 0;
}

//**************************************************************
//					readIt
//
//  task:	  This procedure reads records into an array of 
//            records from an input file and keeps track of the 
//		      total number of records
//  data in:  data file containing information to be placed in
//            the array
//  data out: an array of records and the number of records
//
//**************************************************************

void readIt(ifstream& inData, Grades gradeRec[], int &total)// FILL IN THE CODE FOR THE FORMAL PARAMETERS AND THEIR
            // DATA  TYPES. 
		   //  inData, gradeRec and total are the formal parameters
		   //  total is passed by reference)

{
   total = 0;
  
   inData.get(gradeRec[total].name, NAMESIZE);
   while (inData)
   {
     inData >> gradeRec[total].test1 >> gradeRec[total].test2 >> gradeRec[total].final;// FILL IN THE CODE TO READ test1
     // FILL IN THE CODE TO READ test2
     // FILL IN THE CODE TO READ final

     double avg = 0.3*gradeRec[total].test1 + 0.3*gradeRec[total].test2 + 0.4*gradeRec[total].final;
	 if (avg > 90){
	     gradeRec[total].letter = 'A';
	 }else if (avg > 80){
         gradeRec[total].letter = 'B';
	 }else if (avg > 70){
         gradeRec[total].letter = 'C';
	 }else if (avg > 60){
         gradeRec[total].letter = 'D';
	 }else{
         gradeRec[total].letter = 'F';
	 }
     total++;     // add one to total

     inData.ignore(INTMAX_MAX,'\n');// FILL IN THE CODE TO CONSUME THE END OF LINE
     inData.get(gradeRec[total].name, NAMESIZE);// FILL IN THE CODE TO READ name

  }

}
