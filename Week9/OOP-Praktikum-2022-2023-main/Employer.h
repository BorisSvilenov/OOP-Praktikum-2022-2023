#ifndef EMPLOYER_H
#define EMPLOYER_H
class Employer{
private:
	char* name;
	int monthsWorking;
	double salary;
	
	void free();
	void copyFrom(const Employer& other);
	void moveFrom(Employer&& other);

public:
	Employer();
	~Employer();
	Employer(const Employer& other);
	Employer& operator=(const Employer& other);

	Employer(Employer&& other);
	Employer& operator=(Employer&& other);


};
#endif
