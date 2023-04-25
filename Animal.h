#ifndef ANIMAL_H
#define ANIMAL_H


class Animal{
private:

	char* name;
	char* species;

	void free();
	void copyFrom(const Animal& other);
	void moveFrom(Animal&& other);
public:

	Animal();
	~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

	Animal(Animal&& other);
	Animal& operator=(Animal&& other);
	
	virtual void talk() = 0;
};

#endif

