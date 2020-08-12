/*  Program:     
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/28/2018	     
    Description: 

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

const int NAME_SIZE = 15;

struct Employee{
    char name[NAME_SIZE + 1];
    int ID;
    int b;
    int c;
    int salary;
};

int main() {
    Employee record;

    ifstream employee("/home/john/CLionProjects/Lab_12/employee.in");
    fstream records("/home/john/CLionProjects/Lab_12/employee.out", ios::in | ios::out | ios::binary);
    if (!employee){
        cout << "Error opening file.";
        return 1;
    }

    while (!employee.eof()){
        int index = 0;
        employee.get(name,)

        index++;
    }
    records.write((char *) &record, sizeof(record));
    return 0;
}