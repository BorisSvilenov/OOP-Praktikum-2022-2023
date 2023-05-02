
#ifndef PROFILE_H
#define PROFILE_H

#include <fstream>

const int MAX_SIZE = 1024;
class Profile{
private:
	char* username;
	char* password;

	void free();
	void copyFrom(const Profile& other);
	void moveFrom(Profile&& other);
public:
	Profile();
	~Profile();
	Profile(const char* username,const char* password);
	Profile(const Profile& other);
	Profile& operator=(const Profile& other);

	Profile(Profile&& other);
	Profile& operator=(Profile&& other);


	bool isUsernameUnique(const char* username, std::ifstream& file);
	void writeProfileToFile(const Profile& profile, std::ofstream & file);
	void saveToFile(const char* fileName, const Profile* profiles, int n);
	void parseField(char* dest, char*& source);
	void parseProfile(Profile& profile, char* line);
	void getLinesCount(std::ifstream& file, int& n);
	void readProfiles(Profile*& profiles, std::ifstream & file, int& count);
};
#endif
