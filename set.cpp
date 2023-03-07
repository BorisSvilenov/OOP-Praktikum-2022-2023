#include <iostream>
#include "set.h"

Set::Set() {
	this->capacity = 10;
	this->numElements = 0;
	this->elements = new int[this->capacity];
}

void Set::resize() {
	this->capacity *= 2;
	int* temp = new int[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		temp[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = temp;
	delete[] temp;
}
Set::Set(Set const& other) {
	if (this->elements != nullptr) {
		delete[] this->elements;
	}
	while (other.capacity > this->capacity) {
		resize();
	}
	this->elements = new int[this->capacity];
	for (int i = 0; i < other.numElements; i++) {
		this->elements[i] = other.elements[i];
	}
	this->capacity = other.capacity;
	this->numElements = other.numElements;
}
Set& Set::operator=(Set const& other) {
	if (this != & other) {
		if (this->elements != nullptr) {
			delete[] this->elements;
		}
		while (other.capacity > this->capacity) {
			resize();
		}
		this->elements = new int[this->capacity];
		for (int i = 0; i < other.numElements; i++) {
			this->elements[i] = other.elements[i];
		}
		this->capacity = other.capacity;
		this->numElements = other.numElements;

	}
	return *this;
}
Set::~Set() {
	delete[] this->elements;
}

bool Set::addElement(int const element) {
	for (int i = 0; i < this->capacity; i++) {
		if (this->elements[i] == element) {
			return false;
		}
	}
	this->numElements++;
	if (this->numElements >= this->capacity) {
		resize();
	}
	this->elements[numElements] = element;
	return true;

}
bool Set::deleteElement(int const element) {
	for (int i = 0; i < this->numElements; i++) {
		if (this->elements[i] != element) {
			return false;
		}
	}

	for (int i = 0; i < this->numElements; i++) {
		if (this->elements[i] == element) {
			for (int j = i; j < this->numElements - 1; j++) {
				this->elements[j] = this->elements[j + 1];
			}
			i--;
			this->numElements--;
		}
	}
	return true;
}
void Set::print() {
	for (int i = 0; i < this->numElements; i++) {
		std::cout << "Element[" << i << "]=" << this->elements[i] << " , ";
	}
}
void Set::setUnion(const Set other) {
	int* temp = new int[this->capacity];
	for (int i = 0; i < this->numElements; i++) {
		for(int j=0;j<other.numElements;j++)
	}
	//za domashno
}
