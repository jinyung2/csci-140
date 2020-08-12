/*  Program: Time.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/16/2018	     
    Description: Implementation file for Time.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include "Time.h"
#include <iostream>
#include <iomanip>

Time::Time(int h, int m){
    if (h < 0 || h > 23){hour = 0;}
    else{ hour = h; }
    if (m < 0 || m > 59){ minute = 0; }
    else{ minute = m; }
}
void Time::setHour(int h){
    if (!(h > 23 || h < 0)){
        hour = h;
    }
}
void Time::setMinute(int m){
    if (!(m > 59 || m < 0)){
        minute = m;
    }
}
int Time::getHour() { return hour; }
int Time::getMinute() {return minute; }
void Time::print() {
    int result = hour;
    if (result > 12) {result %= 12;}
    cout << result << ":" << setfill('0') << setw(2) << minute;
    if (hour < 12){cout << " AM";}
    else { cout << " PM";}
    cout << endl;
}
void Time::advance(){
    minute++;
    if (minute == 60){
        hour++;
        minute = 0;
        if (hour == 24){ hour = 0;}
    }
}

