#include "Sorted.h"
#include <iostream>

int main() {
	Sorted<int> s;
	int a = 4;
	int b = 5;
	int c = 921;
	s.add(a);
	s.add(b);
	s.add(a);
	s.add(c);
	s.add(b);
	s.add(b); 
	
	s.print();

	s.remove(c);
	//remove() ne raboti optimalno
	s.print();

}

