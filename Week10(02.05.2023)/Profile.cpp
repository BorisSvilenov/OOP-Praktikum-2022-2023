#include "Profile.h"
#include <cstring>
#include <iostream>


void Profile::free(){
	if (username != nullptr) {
		delete username;
	}
	if (password != nullptr) {
		delete password;
	}

}

void Profile::copyFrom(const Profile& other){
	username = new char[strlen(other.username) + 1];
	password = new char[strlen(other.password) + 1];
	strcpy(username, other.username);
	strcpy(password, other.password);
}
void Profile::moveFrom(Profile&& other) {
	username = other.username;
	password = other.password;

	other.username = nullptr;
	other.password = nullptr;

}

Profile::Profile(){

	username = new char[4];
	password = new char[4];
	strcpy(username, "N/A");
	strcpy(password, "N/A");
}

Profile::~Profile(){
	free();
}

Profile::Profile(const char* username, const char* password){
	this->username = new char[strlen(username) + 1];
	this->password = new char[strlen(password) + 1];
	strcpy(this->username, username);
	strcpy(this->password, password);


}

Profile::Profile(const Profile& other){
	copyFrom(other);
}

Profile& Profile::operator=(const Profile& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Profile::Profile(Profile&& other){
	moveFrom(std::memmove(other));
}

Profile& Profile::operator=(Profile&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::memmove(other));
	}
	return *this;
}

bool Profile::isUsernameUnique(const char* username, std::ifstream& file){
	
	while (file.is_open()) {


	}
}

void Profile::writeProfileToFile(const Profile& profile, std::ofstream& file){
	file << profile.username << ';' << profile.password << std::endl;
}

void Profile::saveToFile(const char* fileName, const Profile* profiles, int n){
	std::ofstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "Error";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isUsernameUnique(profiles[i].username, file)) {
			writeProfileToFile(profiles[i], file);
		}
	}
	file.close();

}

void Profile::parseField(char* dest, char*& source){

		while (*source != '\0' && *source != ',')
		{
			*dest = *source;

			dest++;
			source++;
		}

		source++;
		*dest = '\0';
	
}

void Profile::parseProfile(Profile& profile, char* line){
	parseField(profile.username, line);
	parseField(profile.password, line);

}

void Profile::getLinesCount(std::ifstream& file, int& n){
	char buff[MAX_SIZE];
	int count = 0;

	while (!file.is_open()) {
		file.getline(buff, MAX_SIZE);
		count++;
	}
	n = count;

	file.seekg(0, std::ios::beg);

}

void Profile::readProfiles(Profile*& profiles, std::ifstream& file, int& count){
	getLinesCount(file, count);

	profiles = new Profile[count];

	char line[MAX_SIZE];
}



