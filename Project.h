#ifndef PROJECT_H
#define PROJECT_H
class Project{
private:
	char* name;
	int diff;

	void free();
	void copyFrom(const Project& other);
	void moveFrom(Project&& other);
public:
	Project();
	~Project();
	Project(const Project& other);
	Project& operator=(const Project& other);

	Project(Project&& other);
	Project& operator=(Project&& other);

};
#endif
