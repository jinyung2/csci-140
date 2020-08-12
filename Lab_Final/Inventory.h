// This is the Inventory.h file.
// It contains the Inventory class declaration.
// Fall 18 -- version 1

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
	int itemNumber;
	int quantity;
	double price;
public:
	// Default constructor
	Inventory()
	{
	    itemNumber = quantity = 0;
	    price = 0.0; 
	}

	// Overloaded constructor
	Inventory(int in, int q, double p);	// Defined in Inventory.cpp

	// Mutators (i.e., "setters") defined in Inventory.cpp
	void setItemNumber(int in);
	void setQuantity(int q);
	void setPrice(double p);

	// Accessors (i.e., "getters") defined in Inventory.cpp
	int getItemNumber() const;
	int getQuantity() const;
	double getPrice() const;

	// Services defined in Inventory.cpp
	double totalPrice() const;		// price * quantity
	bool removeOne();	// subtract 1 from quantity if applicable
};
#endif
