

#define _CRT_SECURE_NO_WARNINGS

#include "Animal.h"
#include <cstring>
#include <atomic>

void Animal::free(){

	if (name != nullptr) {
		delete name;
	}
	if (species != nullptr) {
		delete name;
	}
}

void Animal::copyFrom(const Animal& other){
	name = new char[strlen(other.name) + 1];
	species = new char[strlen(other.species)+1];
	strcpy(name, other.name);
	strcpy(name, other.name);

}

void Animal::moveFrom(Animal&& other){
	name = other.name;
	species = other.species;

	other.name = nullptr;
	other.species = nullptr;
}

Animal::Animal(){
	name = new char[4];
	strcpy(name,"N/A");
	species = new char[4];
	strcpy(species, "N/A");

}

Animal::~Animal(){
	free();
}

Animal::Animal(const Animal& other){
	copyFrom(other);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Animal::Animal(Animal&& other){
	moveFrom(std::move(other));
}

Animal& Animal::operator=(Animal&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
