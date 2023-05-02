
#define _CRT_SECURE_NO_WARNINGS

#include "Employer.h"
#include <cstring>
#include <atomic>
void Employer::free(){
	if (name != nullptr) {
		delete name;
	}
}

void Employer::copyFrom(const Employer& other){
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	monthsWorking = other.monthsWorking;
	salary = other.salary;
}
void Employer::moveFrom(Employer&& other) {
	name = other.name;
	monthsWorking = other.monthsWorking;
	salary = other.salary;

	other.name = nullptr;
	other.monthsWorking = 0;
	other.salary = 0;
}

Employer::Employer(){
	name = new char[5];
	strcpy(name, "Ivan");
	salary = 700;
	monthsWorking = 12;
}

Employer::~Employer(){
	free();
}
Employer::Employer(const Employer& other) {
	copyFrom(other);
}
Employer& Employer::operator=(const Employer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
Employer::Employer(Employer&& other) {
	moveFrom(std::move(other));
}
Employer& Employer::operator=(Employer&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
