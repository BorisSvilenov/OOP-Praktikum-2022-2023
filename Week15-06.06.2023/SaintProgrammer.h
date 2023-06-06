#ifndef SAINTPROGRAMMER_H
#define SAINTPROGRAMMER_H

#include "Mentor.h"
#include "Programmer.h"


class SaintProgrammer: public Mentor,public Programmer{
private:
	
	int annualRaise;
public:
	virtual double get_annual_raise_multiplier();

};
#endif

