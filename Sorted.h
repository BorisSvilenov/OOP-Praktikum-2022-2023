#ifndef SORTED_H
#define SORTED_H

#include <iostream>
template<typename T>

class Sorted{
private:
	T* arr;
	unsigned int size;
	unsigned int capacity;

	void resize();
	void free();
	void copyFrom(const Sorted<T>& other);
	void moveFrom(Sorted<T>& other);

public:
	Sorted();
	~Sorted();
	Sorted(const Sorted<T>& other);
	Sorted<T>& operator=(const Sorted<T>& other);

	//Move семанкита
	Sorted(Sorted<T>&& other);
	Sorted<T>& operator=(Sorted<T>&& other);
	
	void add(T& elem);
	void remove(T& elem);
	void print();

};

#endif

template<typename T>
inline void Sorted<T>::resize(){
	capacity *= 2;
	T* newArr = new T[capacity];
	for (unsigned int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

template<typename T>
inline void Sorted<T>::free(){
	if (arr != nullptr) {
		delete arr;
	}
}

template<typename T>
inline void Sorted<T>::copyFrom(const Sorted<T>& other){
	arr = new T[other->capacity];
	size = other.size;
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}

}

template<typename T>
inline void Sorted<T>::moveFrom(Sorted<T>& other){
	arr = other.arr;
	size = other.size;
	capacity = other.capacity;

	other.arr = nullptr;
	other.size = 0;
	other.capacity = 0;
	
}

template<typename T>
inline Sorted<T>::Sorted(){
	size = 0;
	capacity = 4;
	arr = new T[capacity];

}

template<typename T>
inline Sorted<T>::~Sorted(){
	free();
}


template<typename T>
inline Sorted<T>::Sorted(const Sorted<T>& other){
	copyFrom(other);
}

template<typename T>
inline Sorted<T>& Sorted<T>::operator=(const Sorted<T>& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Sorted<T>::Sorted(Sorted<T>&& other){
	moveFrom(other);
}

template<typename T>
inline Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other){
	if (this != other) {
		free();
		moveFrom(other);
	}
	return *this;
}

template<typename T>
inline void Sorted<T>::add(T& elem){
	arr[size] = elem;
	size++;
	if (size >= capacity) {
		resize();
	}
	
}

template<typename T>
inline void Sorted<T>::remove(T& elem){
	int found = 0;
	unsigned int total = capacity;
	for (unsigned int i = 0; i < capacity; i++) {
		if (arr[i] == elem) {
			for (unsigned int j = i; j < total - 1; j++) {
				arr[j] = arr[j + 1];
			}
			found++;
			i--;
			total--;
		}
	}
	if (found == 0) {
		std::cout << "Element doest exist";
	}
	else {
		std::cout << "Element deleted";
	}
}

template<typename T>
inline void Sorted<T>::print(){
	for (unsigned int i = 0; i < size; i++) {
		std::cout << "Arr[" << i << "]=" << arr[i] << std::endl;
	}

}

