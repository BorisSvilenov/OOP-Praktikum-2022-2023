#include <iostream>
#include "classEvent.h"
#include <cstring>
void Event::free() {
	if (this->name != nullptr) {
		delete name;
	}
}
void Event::copy(const Event& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	strcpy(description, other.description);
	start = other.start;
	end = other.end;

}
Event::~Event() {
	free();
}
Event::Event() {
	name = new char[4];
	strcpy(name, "N/A");
	strcpy(description, "N/A");
	start = Date();
	end = Date();

}
Event::Event(const char* name, const char description[MAX_SIZE], Date start, Date end) {
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	strcpy(this->description, description);
	this->start = start;
	this->end = end;
}

Event::Event(const Event& other) {
	this->copy(other);
}
Event& Event::operator=(const Event& other) {
	if (this != &other) {
		this->free();
		this->copy(other);
	}
	return *this;

}
Event::Event(Event&& other) {
	name = other.name;
	strcpy(description, other.description);
	start = other.start;
	end = other.end;

	other.name = nullptr;
	strcpy(other.description, "N/A");
	other.start = Date();
	other.end = Date();
}
Event& Event::operator=(Event&& other) {
	if (this != &other) {
		this->free();

		name = other.name;
		strcpy(description, other.description);
		start = other.start;
		end = other.end;

		other.name = nullptr;
		strcpy(other.description, "N/A");
		other.start = Date();
		other.end = Date();
	}
	return *this;

}
