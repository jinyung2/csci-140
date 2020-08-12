/*  Program: circle.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 09/24/2018
    Description: The implementation file for the circle program.

    I certify that the code below is my own work.

	Exception(s): Altered book code.

*/

#include <iostream>
#include "circle.h"

using namespace std;

Circles::Circles()
{
    setCenter(0,0);
    radius = 1;
}
Circles::Circles(float r){
    radius = r;
    setCenter(0,0);
}

Circles::Circles(int x, int y, float r){
    radius = r;
    setCenter(x,y);
}
/*
Circles::Circles(int x, int y){
    setCenter(x,y);
}*/

double Circles::findArea(){
    return radius * radius * PI;
}// Fill in the code to implement the findArea member function

double Circles::findCircumference(){
    return 2 * radius * PI;
}// Fill in the code to implement the findCircumference member function


void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.

{
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x
         << "," << center_y << ")" << endl;
}

void Circles::setCenter(int x, int y)
// This procedure will take the coordinates of the center of the circle from
// the user and place them in the appropriate member data.

{
    center_x = x;
    center_y = y;
}

Circles::~Circles(){
    cout << "This conludes the Circles class\n\n";
}
