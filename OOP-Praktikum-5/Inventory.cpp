#include "VendingMachineTemplate.h"
#include <iostream>


Inventory::Inventory()
{
	this->salty = 0;
	this->drinks = 0;
	this->sweet = 0;
}

Inventory::Inventory(int salty, int sweet, int drinks)
{
	changeSalty(salty);
	changeSweets(sweet);
	changeDrinks(drinks);
}

Inventory& Inventory::operator=(Inventory const& other)
{
	if (this != &other) {
		this->changeDrinks(other.drinks);
		this->changeSalty(other.salty);
		this->changeSweets(other.sweet);
	}
	return *this;
}

void Inventory::changeSalty(int quantity) {
	if (quantity < 0) {
		this->salty = 0;
		return;
	}
	this->salty = quantity;
}
void Inventory::changeDrinks(int quantity) {
	if (quantity < 0) {
		this->drinks = 0;
		return;
	}
	this->drinks = quantity;
}
void Inventory::changeSweets(int quantity) {
	if (quantity < 0) {
		this->sweet = 0;
		return;
	}
	this->sweet = quantity;
}
void Inventory::print() {
	std::cout << "Salty=" << this->salty << " Drinks=" << this->drinks << " Sweets=" << this->sweet << endl;
}
