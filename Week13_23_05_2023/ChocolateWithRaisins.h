#ifndef CHOCOLATEWITHRAISINS_H
#define CHOCOLATEWITHRAISINS_H

#include "Chocolate.h"
#include <iostream>
template <typename T>
class ChocolateWithRaisins: virtual public Chocolate<T>{
private:
	unsigned int raisinsPercentage;
public:

	ChocolateWithRaisins(T id, unsigned int raisinsPercentage) {
		this->id = id;
		setRaisinsPercentage(raisinsPercentage);
	};
	void setRaisinsPercentage(unsigned int raisinsPercentage) {
		if (raisinsPercentage >= 20 && raisinsPercentage <= 100) {
			this->raisinsPercentage = raisinsPercentage;
		}
	};
	void print() override {
		std::cout << "ChocolateWithRaisinsID:" << id << "RaisinsPercentage" << raisinsPercentage << std::endl;
	};

};
#endif

