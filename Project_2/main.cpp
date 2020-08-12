/*  Program: main.cpp
    Author: Jin Choi
    Class:	CSCI 140
    Date: 10/10/2018
    Description: A program that can perform integer addition, subtraction and multiplication for numbers that are too large for primitive data types.

    I certify that the code below is my own work.

	Exception(s): N/A

*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const int MAX_DIGIT = 20;
typedef int number[MAX_DIGIT];

bool validate(char);
void print(int[], int);
bool computeArray(number);
void numberToArray(string, number);
string arrayToString(number);
bool add(number, number);
bool subtract(number, number);
bool multiply(number, number);
bool validDigit(string);

int main() {
    int valid = 0;
    string firstNumber, secondNumber;
    char oper;
    int numberOne[MAX_DIGIT];
    int numberTwo[MAX_DIGIT];

    cout << "Author: Jin Choi\nThis program performs integer addition, subtraction and multiplication for big integers utilizing arrays.\n\n";
    while (true){
        cout << "Enter an expression --> ";
        cin >> firstNumber >> oper >> secondNumber;
        if (firstNumber == "0" && oper == '%' && secondNumber == "0"){
            cout << "There are " << valid << " valid operations.\nThanks for using my program. Good bye!";
            break;
        }
        else if (!validDigit(firstNumber) || !validDigit(secondNumber) || !validate(oper)){
            if (!validDigit(firstNumber) || !validDigit(secondNumber)){
                cout << "Invalid operand (bad digit)\n\n";
            }
            else{
                cout << "Invalid operator\n\n";
            }
            cin.clear();
            cin.ignore(INTMAX_MAX, '\n');
        }
        else if (firstNumber.length() > MAX_DIGIT || secondNumber.length() > MAX_DIGIT){
            cout << "Invalid operand (too large)\n\n";
        }
        else {
            numberToArray(firstNumber, numberOne);
            numberToArray(secondNumber, numberTwo);
            if (oper == '+'){
                if(add(numberOne, numberTwo)){
                    cout << firstNumber << " " << oper << " " << secondNumber << " = " << arrayToString(numberOne) << endl << endl;
                    valid++;
                }
                else{
                    cout << "Integer overflow\n\n";
                }
            }
            else if (oper == '-'){
                if (subtract(numberOne, numberTwo)){
                    cout << firstNumber << " " << oper << " " << secondNumber << " = " << arrayToString(numberOne) << endl << endl;
                    valid++;
                }
            }
            else if (oper == '*'){
                if (multiply(numberOne, numberTwo)){
                    cout << firstNumber << " " << oper << " " << secondNumber << " = " << arrayToString(numberOne) << endl << endl;
                    valid++;
                }
                else{
                    cout << "Integer overflow\n\n";
                }
            }
            cout << "For Debugging:\nContents of first array ";
            print(numberOne, MAX_DIGIT);
            cout << endl << "Contents of second array ";
            print(numberTwo, MAX_DIGIT);
        }
    }
    
    return 0;
}

bool validate(char oper){
    return !(oper != '+' && oper != '-' && oper != '*');
}

bool add(number nums, number nums2){
    for (int i = 0; i < MAX_DIGIT; i++){
        nums[i] = nums[i] + nums2[i];
    }
    return computeArray(nums);
}

bool subtract(number nums, number nums2) {
    for (int i = 0; i < MAX_DIGIT; i++){
        nums[i] = nums[i] - nums2[i];
    }
    return computeArray(nums);
}

bool multiply(number nums, number nums2){
    int length = 0;
    int tempOne[MAX_DIGIT] = {0};
    int tempTwo[MAX_DIGIT];
    for (int i = MAX_DIGIT - 1; i >= 0; i--){
        if (nums2[i] != 0){
            length = i + 1;
            break;
        }
    }
    for (int i = 0; i < length; i++){
        for (int j = 0; j < MAX_DIGIT; j++){
            tempTwo[j] = nums[j] * nums2[i];
            tempTwo[j] *= static_cast<int>(pow(10, i));
        }
        if(!add(tempOne, tempTwo)){
            return false;
        }
    }
    for (int i = 0; i < MAX_DIGIT; i++){
        nums[i] = tempOne[i];
    }
    return true;
}

void numberToArray(string number, int array[]){
    int j = number.length()-1;
    for (int i = 0; i < MAX_DIGIT; i++){
        if (i < number.length()){
            array[j--] = atoi(number.substr(i,1).c_str());
        }
        else{
            array[i] = 0;
        }
    }
}

string arrayToString(number nums){
    string result;
    int index = 0;
    for (int i = MAX_DIGIT - 1; i >= 0; i--){
        if (nums[i] != 0){
            index = i;
            break;
        }
    }
    for (int j = index; j >= 0; j--){
        result += to_string(nums[j]);
    }
    return result;
}

bool computeArray(number num){
    for (int i = 0; i < MAX_DIGIT; i++){
        if (num[i] > 9){
            if (i == MAX_DIGIT-1){
                return false;
            }
            int temp = num[i]/10;
            num[i] %= 10;
            num[i+1] += temp;
        }
        if (num[i] < 0){
            if (i == MAX_DIGIT - 1){
                cout << "First operand less than second operand, negative result." << endl;
                return false;
            }
            num[i] += 10;
            num[i+1] -= 1;
        }
    }
    return true;
}

void print(number nums, int size){
    for (int i = 0; i < size; i++){
        cout << "[" << nums[i] << "]";
    }
    cout << endl;

}

bool validDigit(string number){
    const char *q = number.c_str();
    for (int i  = 0; i < number.length(); i++){
        if (!isdigit(*(q+i))){
            return false;
        }
    }
    return true;
}