/*  Program: Circle.h
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/10/2018	     
    Description: Header file for Circle class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#ifndef LAB_10_CIRCLE_H
#define LAB_10_CIRCLE_H

#include <iostream>
using namespace std;

class Circle {
private:
    int radius;
    int x;
    int y;
public:
    Circle(int x = 0, int y = 0, int r = 1);
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    friend double operator-(const Circle &c1, const Circle &c2);
};


#endif //LAB_10_CIRCLE_H
