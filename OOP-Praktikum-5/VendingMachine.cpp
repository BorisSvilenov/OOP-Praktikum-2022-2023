#include "VendingMachineTemplate.h"
#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;
int currentId = 0;

VendingMachine::VendingMachine() {
	this->id = currentId;
	currentId++;
	this->address = new char[MAX_SIZE];
	
	this->inventory=Inventory();

	this->warningMessages = new char* [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		this->warningMessages[i] = new char[MAX_SIZE];
	}
	this->numWarningMsgs = 0;
	this->capacity = 10;
}

VendingMachine::VendingMachine(char* address, Inventory inventory)
{
	this->id = currentId;
	currentId++;
	strcpy(this->address, address);
	this->inventory = inventory;
	this->warningMessages = new char* [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		this->warningMessages[i] = new char[MAX_SIZE];
	}
	this->numWarningMsgs = 0;
	this->capacity = 10;

}

VendingMachine::VendingMachine(VendingMachine const& other)
{
	this->id = currentId;
	currentId++;
	if (this->address != nullptr) {
		delete this->address;
	}
	this->address = new char[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE, i++) {
		this->address[i] = other.address[i];
	}
	this->inventory = other.inventory;
	if (this->warningMessages != nullptr) {
		for (int i = 0; i < MAX_SIZE; i++) {
			delete this->warningMessages[i];
		}
		delete this->warningMessages;
	}

	//za dovurshvane
}
