/*  Program: main.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 09/24/2018
    Description: The main driver/client program for the circle program.

    I certify that the code below is my own work.

	Exception(s): Altered book code.

*/

#include <iostream>
#include "circle.h"

using namespace std;

void report (Circles);

int main()
{
   Circles sphere(8);
   sphere.setCenter(9,10);
   report(sphere);
   Circles sphere1(2);
   report(sphere1);
   Circles sphere2;
   report(sphere2);
   Circles sphere3(15,16);
   report(sphere3);
   return 0;
}

void report(Circles sphere){
   sphere.printCircleStats();
   cout << "The area of the circle is " << sphere.findArea() << endl;
   cout << "The circumference of the circle is "
        << sphere.findCircumference() << endl << endl;

}

