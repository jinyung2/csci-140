/*  Program: Circle.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/10/2018	     
    Description: Implementation file for the Circle class.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include "Circle.h"
#include <math.h>

Circle::Circle(int x, int y, int r) {
    if (x > 0){ this->x = x; }
    else { x = 0; }
    if (y > 0){ this->y = y; }
    else { y = 0;}
    if (r > 0){ radius = r; }
    else {radius = 1;}
}

void Circle::setX(int x) {
    if (x > 0){
        this->x = x;
    }
}

void Circle::setY(int y) {
    if (y > 0){
        this->y = y;
    }
}

int Circle::getX() const {
    return x;
}

int Circle::getY() const {
    return y;
}

double operator-(const Circle &c1, const Circle &c2) {
    return sqrt(pow(c1.x-c2.x,2) + pow(c1.y-c2.y,2));
}
