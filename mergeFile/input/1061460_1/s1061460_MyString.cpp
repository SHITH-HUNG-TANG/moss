#include"s1061460_MyString.h"
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

template<typename T>
MyArray<T>::MyArray(int c) {
	size = 0;
	capacity = c;
	ptr = new T[capacity]();
}

template<typename T>
MyArray<T>::MyArray(int Size, T value) {
	size = Size;
	capacity = 10;
	reserve(Size);
	/*if (Size > capacity) {
		capacity = Size;
	}*/
	ptr = new T[size];
	for (int i = 0; i < size; i++)
		MyArray<T>::ptr[i] = value;
}

template<typename T>
MyArray<T>::MyArray(const MyArray& A) {
	size = A.size;
	capacity = A.capacity;
	ptr = new T[size];
	for (int i = 0; i < size; i++)
		ptr[i] = A.ptr[i];
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[] ptr;
}

template<typename T>
int MyArray<T>::getCapacity() const {
	return capacity;
}

template<typename T>
int MyArray<T>::getSize() const {
	return size;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray& right) {
	delete[] ptr;
	ptr = new T[right.capacity];
	size = right.size;
	capacity = right.capacity;
	for (int i = 0; i < right.size; i++)
		ptr[i] = right.ptr[i]; // copy array into object

	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& right) const {
	if (size != right.size)
		return false;    // arrays of different sizes

	for (int i = 0; i < size; i++)
		if (ptr[i] != right.ptr[i])
			return false; // arrays are not equal

	return true;        // arrays are equal
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray& right) const {
	return !(*this == right);
}

template<typename T>
void MyArray<T>::reserve(size_t c)
{
	if (c > capacity) {
		T* temp = new T[c]();
		for (int i = 0; i < size; i++)
			temp[i] = ptr[i];
		capacity = c;
		delete[] ptr;
		ptr = temp;
	}
}

template<typename T>
void MyArray<T>::resize(size_t s, T c)
{
	while (s > capacity)
		reserve(capacity * 2);
	if (s > size)
		for (int i = size; i < s; i++) {
			ptr[i] = c;
		}
	size = s;
}

template<typename T>
void MyArray<T>::resize(int s)
{
	while (s > capacity)
		reserve(capacity * 2);
	size = s;
}

template class MyArray<int>;
template class MyArray<char>;
template class MyArray<std::string>;