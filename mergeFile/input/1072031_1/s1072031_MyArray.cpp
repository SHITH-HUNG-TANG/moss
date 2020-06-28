#include "s1072031_MyArray.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <class T>

MyArray < T >::MyArray(int a) {
	size = 0;
	capacity = a;
	data = new T[capacity];
}
template <class T>
MyArray < T >::MyArray(int a, T b) {
	size = a;
	capacity = a;
	data = new T[capacity];
	for (int i = 0; i < a; ++i) {
		data[i] = b;
	}
}

template <class T>
MyArray < T >::MyArray(const MyArray<T>& right) {
	size = right.size;
	capacity = size;
	data = new T[capacity];
	for (int i = 0; i < size; ++i) {
		data[i] = right.data[i];
	}
}

template <class T>

int MyArray < T >::getSize() const {
	return size;
}
template <class T>
int MyArray < T >::getCapacity() const {
	return capacity;
}
template <class T>
void MyArray < T >::reserve(int n) {
	/*if (n < capacity) {
		capacity = n;
	}*/
	if (n > capacity) {
		T* temp = new T[n];
		for (int i = 0; i < size; i++) {
			temp[i] = data[i];
		}
		capacity = n;
		delete[] data;
		data = temp;
	}
}
template <class T>
void MyArray < T >::resize(int n, T num) {
	while (n > capacity) {
		reserve(capacity * 2);
	}
	if (n > size)
		for (int i = size; i < n; i++) {
			data[i] = num;
		}
	size = n;
}
template <class T>
void MyArray < T >::resize(int n) {
	while (n > capacity) {
		reserve(capacity * 2);
	}
	size = n;
}
template <class T>
bool MyArray < T >::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void MyArray<T>::shrink_to_fit() {
	capacity = size;
}
template <class T>
void MyArray<T>::clear() {
	size = 0;
}
template <class T>
T& MyArray<T>::operator[](int n)
{
	if (n > size || n < 0)
		throw out_of_range("out of the array range");
	return data[n];
}
template <class T>
T MyArray<T>::operator[](int n) const {
	if (n > size || n < 0)
		throw out_of_range("out of the array range");
	return data[n];
}
template <class T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right) {
	size = right.size;
	capacity = right.capacity;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = right.data[i];
	}
	return *this;
}
template <class T>
bool MyArray<T>::operator==(const MyArray<T>& right) const {
	if (size != right.size)
		return false;
	else {
		for (int i = 0; i < size; i++) {
			if (data[i] != right.data[i]) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}
template <class T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const {
	if (*this == right) {
		return false;
	}
	else {
		return true;
	}
}
template <class T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right)const
{
	MyArray<T> result;
	result.size = size + right.size;
	result.capacity = capacity + right.capacity;
	result.data = new T[result.capacity];
	for (int i = 0; i < size; i++) {
		result.data[i] = data[i];
	}
	for (int j = 0; j < right.size; j++) {
		result.data[j + size] = right.data[j];
	}
	//cout << result << endl;
	return result;
}
template <class T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)
{
	int temp = size;
	size += right.size;
	(*this).reserve(capacity + right.capacity);
	for (int i = 0; i < right.size; i++) {
		data[i + temp] = right.data[i];
	}
	//*this = *this + right;
	return *this;
}



template <class T>
ostream& operator <<(ostream& output, const MyArray<T>& a) {
	/*for (int i = 0; i < a.size; i++) {
		output << a.data[i] << " ";
	}*/
	for (int i = 0; i < a.size; i++) {
		output << a.data[i];
	}
	output << endl;
	return output;
}
template <class T>
T& MyArray<T>::at(int n)
{
	if (n > size || n < 0)
		throw out_of_range("out of the array range");
	return data[n];
}
template <class T>
T MyArray<T>::at(int n) const
{
	if (n > size || n < 0)
		throw out_of_range("out of the array range");
	return data[n];
}


template <class T>
MyArray<T>::~MyArray()
{
	delete[]data;
}
