/*  Program: TimeApp.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/16/2018	     
    Description: An application to test our Time classes. Utilizes and array of Time objects and pointers.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    const int NUM = 5;
    Time time[NUM] = {Time(0,30), Time(11,59), Time(23,59), Time(50,80), Time(8,45)};
    cout << "Initial Times: \n";// Note: Time object at index 3 is a validation check for constructor.
    for (int i = 0; i < NUM; i++){
        cout << "The hour value is : " << (*(time+i)).getHour() << endl;
        cout << "The minute value is : " << (*(time+i)).getMinute() << endl;
        (*(time+i)).print();
    }
    time->setHour(12);
    (time+1)->advance();
    (time+2)->advance();
    (time+3)->setHour(17);
    (time+3)->setMinute(42);
    (time+4)->setHour(400); // Validation check
    (time+4)->setMinute(400); // Validation check
    //After edit
    cout << endl << "Final Times: \n";
    for (int i = 0; i < NUM; i++){
        cout << "The hour value is : " << (*(time+i)).getHour() << endl;
        cout << "The minute value is : " << (*(time+i)).getMinute() << endl;
        (time+i)->print(); // Note: (*(time+i)).print() and (time+i)->print() are the same thing.
                            // utilizing structure pointer operators is for clarity in code.
    }

    return 0;
}