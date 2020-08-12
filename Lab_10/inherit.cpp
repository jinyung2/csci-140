/*  Program: inherit.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/10/2018	     
    Description: Class that implements a subclass to DogType, RaceDogType.

    I certify that the code below is my own work.
	
	Exception(s): Modified Book Code.

*/

#include <iostream>
#include <string>

using namespace std;

class DogType                                // Name of the base class
{
private:
    string name;                           // Name of dog
    double weight;                         // Weight of dog
    string color;                          // Color of dog
public:
    DogType()                              // Default constructor
    {
        name = "Unknown";
        weight = 0;
        color = "unknown";
    }

    DogType(string n, double w, string c)  // Constructor
    {
        name = n;
        weight = w;
        color = c;
    }

    void printDogInfo() const             // Prints dog information
    {
        cout << "The dog's name is " << name << endl;
        cout << "The dog's weight is " << weight << endl;
        cout << "The dog's color is " << color << endl << endl;
    }
};

class ShowDogType: public DogType
    // Notice the name of the derived class followed by a colon, then the
    // word public to indicate how it is inheriting members, and finally
    // the name of the base class from which it inherits those members.
{
private:
    int numOfContests;                    // Number of contests entered
    int numOfWins;                        // Number of contests won
public:
    ShowDogType(string n, double w, string c, int con, int win):
            DogType( n, w, c)
    {
        numOfContests = con;       // Assigns con to private variable numOfContests
        numOfWins = win;           // Assigns win to private variable numOfWins
        // The other 3 parameters (n, w, c) are passed to the base class constructor
        // who uses them to assign values to base class member variables name, weight,
        // and color.
    }

    ShowDogType(): DogType()
    {
        numOfContests = 0;        // Set contests to default value of 0.
        numOfWins = 0;            // Set wins to default value of 0.
        // The other member variables (name, weight, color) are given
        // default values by the call to the default constructor DogType()
    }

    void printShowDogInfo() const
    {
        printDogInfo();
        cout << "The dog has been entered in " << numOfContests  << " contests" << endl;
        cout << "The dog has won " << numOfWins << " contests" << endl <<endl;
    }
};

class RaceDogType : public DogType{
private:
    int races;
    int wins;
public:
    RaceDogType(string n, double w, string c, int races, int wins) : DogType(n,w,c){
        this->races = races;
        this->wins = wins;
    }
    RaceDogType() : DogType(){
        races = 0;
        wins = 0;
    }
    void printRaceDogInfo() const{
        printDogInfo();
        cout << "The dog has been entered in " << races << " races" << endl;
        cout << "The dog has won " << wins << " races" << endl << endl;
    }
};// Place the declaration here for class RaceDogType.
// It is also derived from class DogType.

int main()
{
    // Create 2 ShowDogType objects.
    ShowDogType  dog1("Fido", 12, "Black", 12, 2);
    ShowDogType  dog2;

    RaceDogType dog3("Anchovi", 14, "Black", 28, 27);
    RaceDogType dog4;// Fill in the code to define a RaceDogType object called dog3
    // that has the following information:
    // name --->  Anchovi
    // weight --> 14
    // color ---> Black
    // number of races -----> 28
    // number of wins  -----> 27

    // Fill in the code to define a RaceDogType object called dog4
    // that has all default values.

    dog1.printShowDogInfo();
    dog2.printShowDogInfo();

    dog3.printRaceDogInfo();
    dog4.printRaceDogInfo();// Fill in the code to print out all the information about dog3.
    // Fill in the code to print out all the information about dog4.

    return 0;
}