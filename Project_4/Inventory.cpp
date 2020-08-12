/*  Program: Inventory.cpp
    Author: Jin Choi     
    Class: CSCI 140     
    Date: 11/21/2018	     
    Description: The class that handles the main stock inventory where products are pulled from.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;



class Inventory{
protected:
    struct product{
        int ID;
        int quantity;
        int price;
        string name;
    };
    int size;
    vector<product*> list;
    void addProduct(int ID, int quantity, int price, string name){
        product *prod = new product;
        prod->ID = ID;
        prod->price = price;
        prod->quantity = quantity;
        prod->name = name;
        list.push_back(prod);
    }

public:
    Inventory(fstream &in){
        while (!in.eof()){
            char c = in.peek();
            if (c == -1){
                break;
            }
            int ID, quantity, price;
            string name;
            in >> ID >> quantity >> price;
            getline(in, name, '\r');
            addProduct(ID,quantity,price,name);
            in.ignore(1);
        }
        size = list.size();
    }

    ~Inventory(){
        for (auto &p :list){
            delete p;
            p = nullptr;
        }
    }


    int removeProduct(int ID, int quantity){
        product *product = nullptr;
        for (auto &a : list){
            if (a->ID == ID){
                product = a;
            }
        }
        if (product != nullptr){
            if (quantity == 0){
                return 0;
            }
            if (quantity > product->quantity){
                int temp = product->quantity;
                product->quantity = 0;
                return temp;
            }
            else{
                product->quantity -= quantity;
                return quantity;
            }
        }
    }
    void print(){
        cout << "ID   Quantity  Price  Name" << endl;
        for (auto &p : list){
            cout << left << setw(5) << p->ID << setw(10) << p->quantity << setw(7) << p->price << p->name << endl;
        }
    }

    string nameLookUp(int ID){
        for (auto &p : list){
            if (p->ID == ID){
                return p->name;
            }
        }
        return "";
    }

    int priceLookUp(int ID){
        for (auto &p : list){
            if (p->ID == ID){
                return p->price;
            }
        }
        return 0;
    }
};