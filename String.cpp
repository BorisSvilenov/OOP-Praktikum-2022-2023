#include <iostream>
#include "classString.h"
#include <cstring>

void String::setString(const char* str) {
	if (this->str != nullptr) {
		delete this->str;
	}
	int n = strlen(str) + 1;
	this->str = new char[n];
	for (int i = 0; i < n; i++) {
		this->str[i] = str[i];
	}
}
void String::resize()
{
	int n = strlen(this->str) * 2;
	char* temp = new char[n];
	for (int i = 0; i < n; i++) {
		temp[i] = this->str[i];
	}
	delete this->str;
	this->str = temp;
	delete temp;
}
String::String() {
	this->str = new char[1];
}
String::String(const char* str) {
	setString(str);
}
String::~String() {
	delete this->str;
}
String::String(String const& other) {
	if (this->str != nullptr) {
		delete this->str;
	}
	int n = strlen(other.str) + 1;
	this->str = new char[n];
	for (int i = 0; i < n; i++) {
		this->str[i] = other.str[i];
	}
}
String& String::operator=(String const& other) {
	if (this->str != nullptr) {
		delete this->str;
	}
	int n = strlen(other.str) + 1;
	this->str = new char[n];
	for (int i = 0; i < n; i++) {
		this->str[i] = other.str[i];
	}
	return *this;
}
String::String(String&& other) {
	this->str = other.str;
	other.str = nullptr; 
}

String& String::operator=(String&& other)
{
	if (this != &other) {
		delete this->str;


		this->str = other.str;
		other.str = nullptr;
	}
	return *this;
}

String& String::operator+=(String const& other)
{
	int n = 0;
	if (this->str == nullptr) {
		n = strlen(other.str) + 1;
		this->str = new char[n];

		for (int i = 0; i < n; i++) {
			this->str[i] = other.str[i];
		}

		return *this;
	}
	while (sizeof(this->str) / sizeof(char) < sizeof(other.str) / sizeof(char)) {
		resize();
	}
	n = strlen(this->str);
	for (int i = 0; i < strlen(other.str); i++) {
		this->str[n + i] = str[i];
	}

	return *this;
}

String& String::operator+=(const char* str)
{
	int n = 0;
	if (this->str == nullptr) {
		n = strlen(str)+1;
		this->str = new char[n];
		for (int i = 0; i < n; i++) {
			this->str[i] = str[i];
		}

		return *this;
	}
	while (sizeof(this->str)/sizeof(char) < sizeof(str) / sizeof(char)) {
		resize();
	}
	n = strlen(this->str);
	for (int i = 0; i < strlen(str); i++) {
		this->str[n + i] = str[i];
	}

	return *this;
}

String& String::operator+(String const& other)
{
	while (sizeof(this->str) / sizeof(char) < (strlen(this->str)+strlen(other.str)) ) {
		resize();
	}
	strcat(this->str, other.str);
}



