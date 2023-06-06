#ifndef MENTOR_H
#define MENTOR_H


#include <vector>
#include "Employee.h"
#include "Intern.h"


class Mentor : virtual public Employee{
protected:
	std::vector<Intern> interns;
	unsigned int mentorExperience;
	int mentorRaisePercentage;

public:
	virtual double get_annual_raise_multiplier();
};

#endif

