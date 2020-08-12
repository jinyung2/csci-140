/*
    Program: BasicShape.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 11/21/2018
    Description: Implements an abstract class BasicShape, and tests two derived class Circle and Rectangle.

    I certify that the code below is my own work.

	Exception(s): N/A
*/

#include <cmath>
#include <iostream>

using namespace std;

class BasicShape{
protected:
    double area;
public:
    double getArea() const { return area;}
    virtual void calcArea() = 0;
};

class Circle : public BasicShape{
protected:
    long centerX;
    long centerY;
    double radius;
public:
    Circle(long x, long y, double r) : centerX(x), centerY(y), radius(r){
        calcArea();
    };
    long getCenterX() const { return centerX; }
    long getCenterY() const { return centerY; }
    void calcArea() override { area = M_PI * radius * radius; }
};

class Rectangle : public BasicShape{
protected:
    long width;
    long length;
public:
    Rectangle(long width, long length) : width(width), length(length) {
        calcArea();
    }
    long getWidth() const { return width; }
    long getLength() const { return length; }
    void calcArea() override { area = length * width; }
};

int main(){
    Circle c1(0,0,3);
    cout << "(X,Y) Coordinate: (" << c1.getCenterX() << "," << c1.getCenterY() << ")" << endl;
    cout << "Area of circle: " << c1.getArea() << endl << endl;
    Rectangle r1(5,10);
    cout << "Length and Width: " << r1.getLength() << " and " << r1.getWidth() << endl;
    cout << "Area of Rectangle: " << r1.getArea() << endl;

}