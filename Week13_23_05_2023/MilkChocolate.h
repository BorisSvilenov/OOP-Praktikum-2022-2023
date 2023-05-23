#ifndef MILKCHOCOLATE_H
#define MILCHOCOLATE_H
#include "Chocolate.h"
#include <iostream>

class MilkChocolate : virtual public Chocolate<int> {
protected:
	int milkPercentage;
public:
	MilkChocolate(int id, int milkPercentage) {
		this->id = id;
		setMilkPercentage(milkPercentage);
	};
	void setMilkPercentage(int milkPercentage) {
		if (milkPercentage >= 35 && milkPercentage <= 100) {
			this->milkPercentage = milkPercentage;
		}
	};
	void print() override {
		std::cout << "MilkChocolateID:" << id << "MilkPercentage" << milkPercentage << std::endl;
	};


};
#endif 

