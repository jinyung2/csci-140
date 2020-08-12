/*  Program: circle.h
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 09/24/2018	     
    Description: A header file for the circle class.

    I certify that the code below is my own work.
	
	Exception(s): Altered book code.

*/
#ifndef LAB_5_CIRCLE_H
#define LAB_5_CIRCLE_H

class Circles
{
    public:
        void setCenter(int x, int y);
        double findArea();
        double findCircumference();
        void printCircleStats(); // This outputs the radius and center of the circle.
        Circles (int x, int y, float r = 1.0);
        /*Circles(int x, int y);*/
        Circles (float r);
        Circles();

        ~Circles();
    private:
        float  radius;
        int    center_x;
        int    center_y;
};


const double PI = 3.14;


#endif //LAB_5_CIRCLE_H
