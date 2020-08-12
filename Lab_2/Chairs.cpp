/*  Program: Chairs.cpp
    Author: Jin Choi
    Class: CSCI 140
    Date: 9/4/18
    Description: compute total sales of various chairs using const float data types.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>

using namespace std;

    const float AMERICAN_COLONIAL = 85.00;
    const float MODERN = 57.50;
    const float FRENCH_CLASSICAL = 127.75;

int main() {
    int numAmerican;
    int numModern;
    int numFrench;
    float totalAmerican;
    float totalModern;
    float totalFrench;

    cout << "Please input the number of American Colonial chairs sold" << endl;
    cin >> numAmerican;
    cout << "Please input the number of Modern chairs sold" << endl;
    cin >> numModern;
    cout << "Please input the number of French Classical chairs sold" << endl;
    cin >> numFrench;
    totalAmerican = AMERICAN_COLONIAL * numAmerican;
    totalModern = MODERN * numModern;
    totalFrench = FRENCH_CLASSICAL * numFrench;

    cout << "Total sales of each:" << endl
        << "American colonial: $" << totalAmerican << endl
        << "Modern: $" << totalModern << endl
        << "French Classical: $" << totalFrench << endl
        << "Total sales: $" << totalAmerican + totalModern + totalFrench;

}