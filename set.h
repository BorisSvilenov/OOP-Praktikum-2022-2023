#ifndef set_h
#define set_h

class Set {
private:
	int* elements;
	int numElements;
	int capacity;

	void resize();
public:
	Set();
	Set(Set const& other);
	Set& operator=(Set const& other);
	~Set();

	bool addElement(int const element);
	bool deleteElement(const int element);
	void print();
	void setUnion(const Set other);
	void setIntersection(const Set other);


};


#endif // !set_h

