#ifndef INTERN_H
#define INTERN_H




#include "Employee.h"
#include "Project.h"


enum class Education {
	SECOND,BACHELOR,MASTER_DEGREE,PROGRAMMING_COURSE

};


class Intern: public Employee{
private:
	Project project;
	Education ed;
	unsigned int internExperience;
	int internRaisePercentage;

public:

	virtual double get_annual_raise_multiplier();

};

#endif

