#ifndef BLACKCHOCOLATE_H
#define BLACKCHOCOLATE_H
#include "Chocolate.h"
#include <string>
#include <iostream>

class BlackChocolate : virtual public Chocolate<std::string> {
private:
	unsigned int cocoaPercentage;
public:
	BlackChocolate(std::string id, unsigned int cocoaPercentage) {
		setID(id);
		setCocoaPercentage(cocoaPercentage);
	};
	bool isIDValid(std::string id) {
		for (int i = 0; i < id.length(); i++) {
			if ((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= 'a' && id[i] <= 'z')) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	};
	void setID(std::string id) {
		if (isIDValid(id)) {
			this->id = id;
		}
		else {
			throw std::exception("Illegal blackChocolateId");
		}
	};
	void setCocoaPercentage(unsigned int cocoaPercentage) {
		if (cocoaPercentage >= 80 && cocoaPercentage <= 100) {
			this->cocoaPercentage = cocoaPercentage;
		}
	};
	void print() override {
		std::cout << "BlackChocolateID" << id << "CocoaPercentage:" << cocoaPercentage << std::endl;
	};


};
#endif
