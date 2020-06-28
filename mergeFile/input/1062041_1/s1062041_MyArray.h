#pragma once
#ifndef s1062041_MyArray_h
#define s1062041_MyArray_h

#include <iostream>
using namespace std;

template<typename T>
class MyArray {
	
	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T> &);
	//friend istream& operator>>(istream&, const MyArray&);

public:
	MyArray(int = 10);
	MyArray(int size, T value);	//.
	MyArray(const MyArray<T>&);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);	//new

	int& operator[](int);
	int operator[](int) const;
	T& at(int);	//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t n, T);
	void reserve(size_t n = 0);
	void shrink_to_fit();	//new
	void clear();	//new
	bool isEmpty();	//new
	
	
protected:
	T* data;
	int size = 0;
	int capacity;

};

#endif // !s1062041_MyArray_h

template<typename T>
MyArray<T>::MyArray(int arrcapacity) {
	capacity = (arrcapacity > 10 ? arrcapacity : 10);
	data = new T[capacity]();
	/*for (int i = 0; i < capacity; i++) {
		data[i] = 0;
	}*/
}

template<typename T>
MyArray<T>::MyArray(int s, T value) {
	capacity = 10;
	data = new T[capacity]();
	for (int i = 0; i < s; i++) {
		resize(1, value);
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T> &arr) :capacity(arr.getCapacity()) {
	data = new T[capacity];
	size = arr.getSize();
	for (int i = 0; i < capacity; i++) {
		data[i] = arr.data[i];
	}
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[] data;
}

template<typename T>
const MyArray<T> &MyArray<T>::operator=(const MyArray<T> &right) {
	
	if (&right != this) {
		if (getCapacity() != right.getCapacity()) {
			delete[] data;
			capacity = right.getCapacity();
			size = right.getSize();
			data = new T[capacity];
		}
		capacity = right.getCapacity();
		size = right.getSize();
		for (int i = 0; i < right.getSize(); i++) {
			data[i] = right.data[i];
		}
	}

	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T> &right) const {
	if (getSize() != right.getSize())
		return false;
	for (int i = 0; i < getSize(); i++) {
		if (data[i] != right.data[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T> &right) const {
	return !(*this == right);
}

//operator +
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const {

	MyArray<T> sum(10);
	
	for (int i = 0; i < getSize(); i++) {
		sum.resize(1, data[i]);
	}
	
	sum += right;

	return sum;
}

//operator +=
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right) {
	for (int i = 0; i < right.getSize(); i++) {
		resize(1, right.data[i]);
	}
	
	return *this;
}

template<typename T>
int& MyArray<T>::operator[](int sub) {
	if (sub < 0 || sub >= getSize()) {
		cerr << "\nError: Subscript " << sub << " out of range" << endl;
		exit(1);
	}

	return data[sub];
}

template<typename T>
int MyArray<T>::operator[](int sub) const {
	if (sub < 0 || sub >= getSize()) {
		cerr << "\nError: Subscript " << sub << " out of range" << endl;
		exit(1);
	}
	return data[sub];
}

template<typename T>
void MyArray<T>::resize(size_t n, T c) {
	while (getSize()+n > getCapacity()) {
		reserve(getCapacity() * 2);
	}
	for (int i = getSize(); i < getSize()+n; i++) {
		data[i] = c;
	}
	size = getSize() + n;
}

template<typename T>
void MyArray<T>::reserve(size_t n) {
	MyArray<T> tmp(n);
	for (int i = 0; i < getSize(); i++) {
		tmp.data[i] = data[i];
	}
	tmp.size = getSize();

	*this = tmp;
}

template<typename T>
int MyArray<T>::getSize() const {
	return size;
}

template<typename T>
int MyArray<T>::getCapacity() const {
	return capacity;
}

//new
//shrink to fit
template<typename T>
void MyArray<T>::shrink_to_fit() {
	MyArray<T> tmp(getSize());
	tmp.size = getSize();
	for (int i = 0; i < getSize(); i++) {
		tmp.data[i] = data[i];
	}
	*this = tmp;
}

//clear
template<typename T>
void MyArray<T>::clear() {
	size = 0;
}

//isEmpty
template<typename T>
bool MyArray<T>::isEmpty() {
	if (getSize() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//at
template<typename T>
T& MyArray<T>::at(int index) {
	if (index < 0 || index >= getSize()) {
		cerr << "\nError: Subscript " << index << " out of range" << endl;
	}
	else {
		return data[index];
	}
}
template<typename T>
T MyArray<T>::at(int index) const {
	if (index < 0 || index >= getSize()) {
		cerr << "\nError: Subscript " << index << " out of range" << endl;
		exit(1);
	}
	else {
		return data[index];
	}
}

template<typename T>
ostream& operator<<(ostream &output, const MyArray<T> &arr) {

	for (int i = 0; i < arr.size; i++) {
		
		output << arr.data[i] << ",";
	}


	return output;
}