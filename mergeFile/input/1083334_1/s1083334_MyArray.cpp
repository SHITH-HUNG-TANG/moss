#include"s1083334_MyArray.h"
#include<string>
#include<iomanip>
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range

template< typename T >
MyArray<T>::MyArray(int Capacity) {
	capacity = Capacity;
	data = new T[capacity]();
	size = 0;
}
template< typename T >
MyArray<T>::MyArray(int Size, T value) {
	size = Size;
	capacity = size * 2;
	data = new T[capacity]();
	for (int i = 0; i < size; i++) {
		data[i] = value;
	}
}
template< typename T >
MyArray<T>::MyArray(const MyArray &a) 
	:size(a.size), capacity(a.capacity)
{
	data = new T [capacity]();
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
}

template< typename T >
MyArray<T>::~MyArray() {
	delete[]data;
}
template< typename T >
const MyArray<T>& MyArray<T>::operator=(const MyArray& a) {
	if (a != *this) {
		if (capacity != a.capacity) {
			delete[]data;
			capacity = a.capacity;
			data = new T[capacity]();
		}
		resize(a.size);
		for (int i = 0; i < size; i++) {
			data[i] = a.data[i];
		}
	}
	return *this;
}
template< typename T >
bool MyArray<T>::operator==(const MyArray& a)const {
	if (size != a.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (data[i] != a.data[i]) {
			return false;
		}
	}
	return true;
}
template< typename T >
bool MyArray<T>::operator!=(const MyArray &a)const {
	if (size != a.size) {
		return true;
	}
	for (int i = 0; i < size; i++) {
		if (data[i] != a.data[i]) {
			return true;
		}
	}
	return false;
}
template< typename T >
MyArray<T> MyArray<T>::operator+(const MyArray &a) const {
	MyArray<T> temp;
	delete[]temp.data;
	temp.data = new T[temp.capacity]();
	temp.resize(size + a.size);
	for (int i = 0; i < size; i++) {
		temp.data[i] = data[i];
	}
	int x = 0;
	for (int i = size; i < temp.size; i++) {
		temp.data[i] = a.data[x++];
	}
	return temp;
}
template< typename T >
MyArray<T>& MyArray<T>::operator+=(const MyArray &a) {
	int s = size;
	resize(size + a.size);
	for (int i = 0; i < s; i++) {
		data[i] = data[i];
	}
	for (int i = s; i < size; i++) {
		data[i] = a.data[i - s];
	}
	return *this;
}
template< typename T >
T& MyArray<T>::operator[](int a) {
	return data[a];
}
template< typename T >
T MyArray<T>::operator[](int a)const {
	return data[a];
}
template< typename T >
T& MyArray<T>::at(int a) {
	if (a >= size) {
		throw out_of_range("out_of_range");
	}
	return data[a];
}
template< typename T >
T MyArray<T>::at(int a) const {
	if (a >= size) {
		throw out_of_range("out_of_range");
	}
	return data[a];
}
template< typename T >
int MyArray<T>::getSize() const {
	return size;
}
template< typename T >
int MyArray<T>::getCapacity() const {
	return capacity;
}
template< typename T >
void  MyArray<T>::resize(size_t size, T item) {
	if (size > this->size) {
		if (size > capacity) {
			reserve(size);
		}
		for (int i = this->size; i < capacity; i++) {
			data[i] = item;
		}
	}
	else if (size < this->size) {
		T *temp = new T[capacity]();
		for (int i = 0; i < (int)size - 1; i++) {
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;
	}
	this->size = size;
}
template< typename T >
void MyArray<T>::reserve(size_t size) {
	while (size > capacity) {
		capacity *= 2;
	}
	T *temp = new T[capacity]();
	for (int i = 0; i < this->size; i++) {
		temp[i] = data[i];
	}
	delete[]data;
	data = temp;
}
template< typename T >
void MyArray<T>::shrink_to_fit() {
	capacity = size;
	T *temp = new T[capacity]();
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	delete[]data;
	data = temp;
}
template< typename T >
void MyArray<T>::clear() {
	resize(0);
}
template< typename T >
bool MyArray<T>::isEmpty() {
	if (size == 0) {
		return 1;
	}
	return 0;
}
