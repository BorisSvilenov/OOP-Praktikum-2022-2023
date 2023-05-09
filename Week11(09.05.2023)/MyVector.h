#ifndef MYVECTOR_H
#define MYVECTOR_H


template<class T>
class MyVector{
private:
	T* arr = nullptr;
	
	int size;
	int capacity;


	void free();
	void resize(int capacity);
	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);

public:
	MyVector();
	~MyVector();
	MyVector(const MyVector& other);
	MyVector<T>& operator=(const MyVector& other);

	MyVector(MyVector&& other);
	MyVector<T>& operator=(MyVector&& other);

	void addElement(T element);
	T operator[](int i)const;
	T& operator[](int i);

	void apply(T(*func)(T&));


};
#endif
template<class T>
inline void MyVector<T>::apply(T(*func)(T&)) {
	for (int i = 0; i < size; i++) {
		arr[i]=func(arr[i]);
	}
	
}

template<class T>
inline void MyVector<T>::free(){
	if (arr != nullptr) {
		delete[] arr;
	}
}

template<class T>
inline void MyVector<T>::resize(int capacity){
	if (capacity <= size) {
		return;
	}
		this->capacity = capacity;
		T* newArr = new T[capacity];
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;

}

template<class T>
inline void MyVector<T>::copyFrom(const MyVector& other){
	if (other.arr != nullptr) {
		size = other.size;
		capacity = other.capacity;

		arr = new T[capacity];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}

}

template<class T>
inline void MyVector<T>::moveFrom(MyVector&& other){
	size = other.size;
	capacity = other.capacity;
	arr = other.arr;

	other.arr = nullptr;
	other.size = 0;
	other.capacity = 0;



}

template<class T>
inline MyVector<T>::MyVector(){
	size = 0;
	capacity = 4;
}

template<class T>
inline MyVector<T>::~MyVector(){
	free();
}

template<class T>
inline MyVector<T>::MyVector(const MyVector& other){
	copyFrom(other);
}

template<class T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
inline MyVector<T>::MyVector(MyVector&& other){
	moveFrom(other);
}

template<class T>
inline MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
	if (this != &other) {
		free();
		moveFrom(other);
	}
	return *this;
}

template<class T>
inline void MyVector<T>::addElement(T element){
	if (size + 1 >= capacity) {
		resize(capacity*2);
	}
	arr[size+1] = element;
	size++;
}

template<class T>
inline T MyVector<T>::operator[](int i) const
{
	if (i >= 0 && i <= size) {
		return arr[i];
	}
	
}

template<class T>
inline T& MyVector<T>::operator[](int i)
{
	if (i >= 0 && i <= size) {
		return arr[i];
	}
	
}






