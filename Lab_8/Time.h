/*  Program: Time.h
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 10/24/2018
    Description: A header file for the Time class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#ifndef LAB_7_TIME_H
#define LAB_7_TIME_H

using namespace std;

class Time {
private:
    int hour;
    int minute;
public:
    Time(int h = 0,int m = 0);
    void setHour(int h);
    void setMinute(int m);
    int getHour();
    int getMinute();
    void print();
    void advance(int m = 1);
    void back();
    int minSinceMidnight() const;

};


#endif //LAB_7_TIME_H
