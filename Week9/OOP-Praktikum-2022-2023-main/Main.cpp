
#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
int main()
{
	Dog dog1;
	Cat cat1;
	Dog dog2;
	Cat cat2;
	Animal* animals[4]={ &cat1,&cat2,&dog1,&dog2 };
	
	for (int i = 0; i < 4; i++) {
		animals[i]->talk();
	}
}
