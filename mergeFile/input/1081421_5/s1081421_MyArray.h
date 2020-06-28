#pragma once
#pragma once
#include<vector>
#include<iostream>
#include <exception>
#include<stdexcept>
using namespace std;
class Error : public exception
{
public:
	Error() :exception("out of range") {};
};
template <typename T>
class MyArray :public Error
{
	/*template <typename T>*/
	friend ostream &operator << (ostream& cout, const  MyArray<T>&right) {
		for (int i = 0; i < right.getSize(); i++) {
			cout << right.n[i] << " ";
		}
		return cout;
	}
public:
	MyArray() {
		n = new T[capacity]();
	};
	MyArray(int a);
	MyArray(int size, T value);
	MyArray(const MyArray&);
	~MyArray();
	const MyArray& operator = (const MyArray&);
	bool operator ==(const MyArray&);
	bool operator !=(const MyArray&);
	MyArray operator +(const MyArray&);
	MyArray operator +=(const MyArray&);
	T & operator[](int);
	T operator[](int)const;
	int getSize() const;
	int getCapacity()const;
	void resize(int size, T item);
	void reserve(int size);
	void shrink_to_fit();
	void clear();
	bool isEmpty();
	T& at(int);
	T& at(int)const;
private:
	int size = 0;
	int capacity = 10;
	T *n;
};
template <typename T>
MyArray<T>::MyArray(int a) {
	a = capacity;
	n = new T[capacity]();
}//OK
template <typename T>
MyArray<T>::MyArray(int num, T value) {
	if (num < 10) {
		n = new T[capacity]();
		resize(num, value);
	}
	else {
		while (capacity < num)
			capacity *= 2;
		size = num;
		n = new T[capacity]();
		for (int i = 0; i < num; i++)
			n[i] = value;
	}
}
template <typename T>
MyArray<T>::~MyArray() {
	delete[]n;
}
template <typename T>
MyArray<T>::MyArray(const MyArray<T> &copy) {
	capacity = copy.capacity;
	size = copy.size;
	n = new T[(capacity)]();
	for (int i = 0; i < size; i++)
		n[i] = copy[i];
}
template <typename T>
bool MyArray<T>:: operator==(const MyArray<T>&right) {
	if (size != right.size)
		return false;
	if (capacity != right.capacity)
		return false;
	for (int i = 0; i < size; i++) {
		if (n[i] != right.n[i])
			return false;
	}
	return true;
}
template <typename T>
bool  MyArray<T>::operator!=(const MyArray<T>&right)
{
	return !(*this == right);
}
template <typename T>
const MyArray<T>&MyArray<T>::operator=(const MyArray<T>&right)
{
	capacity = right.capacity;
	size = right.size;
	delete[] n;
	n = new T[(capacity)]();//rase the space first
	for (int i = 0; i < size; i++)
		n[i] = right.n[i];
	return *this;
}
//template <typename T>
//ostream &operator << (ostream& cout, const  MyArray<T>&right) {
//	for (int i = 0; i < right.getsize(); i++) {
//		cout << right.n[i] << " ";
//	}
//	cout << endl;
//	return cout;
//}

template <typename T>
T& MyArray<T>::operator[](int data) {
	return n[data];
}
template <typename T>
T MyArray<T>::operator[](int data)const {
	return n[data];
}
template <typename T>
int  MyArray<T>::getSize()const
{
	return size;
}
template <typename T>
int MyArray<T>::getCapacity()const
{
	return capacity;
}
template <typename T>
void MyArray<T>::resize(int a, T value)
{
	if (a < size) {
		capacity = 10;
		while (a > capacity) {
			reserve(capacity * 2);
		}
		for (int i = 0; i < 5; i++)
			n[i] = value;
		for (int i = a; i < capacity; i++)
		{
			n[i] = NULL;
		}
		size = a;
	}
	else {
		int temp = size;

		while (a > capacity) {
			reserve(capacity * 2);
		}
		for (int i = temp; i < a; i++) {
			n[i] = value;
		}
		size = a;
	}
}
template <typename T>
void MyArray<T>::reserve(int a) {
	capacity = a;
	T* temp = new T[capacity]();
	for (int i = 0; i < size; i++)
		temp[i] = n[i];
	delete[]n;
	n = temp;
}
template <typename T>
MyArray<T>MyArray<T>:: operator +(const MyArray<T>&right) {
	MyArray<T> temp;
	temp = *this;
	temp.resize(temp.getSize() + right.getSize(), 0);
	for (int a = 0, i = size; i < size + right.size; i++, a++) {
		temp[i] = right[a];

	}
	return temp;

}
template <typename T>
MyArray<T>MyArray<T>:: operator +=(const MyArray<T>&right) {
	/*resize(getsize() + right.getsize(), 0);
	for (int a = 0, i = getsize(); a < right.getsize(); i++, a++) {
		n[i] = right[a];
	}
	return *this;*/
	MyArray<T> temp;
	temp = *this;
	temp.resize(temp.getSize() + right.getSize(), 0);
	for (int a = 0, i = size; i < size + right.size; i++, a++) {
		temp[i] = right[a];
	}

	*this = temp;
	return *this;
}
template <typename T>
void MyArray<T>::shrink_to_fit() {
	MyArray temp;
	temp = *this;
	capacity = size;
	delete[] n;
	n = new T[capacity]();
	for (int i = 0; i < capacity; i++)
		n[i] = temp[i];

}
template <typename T>
void MyArray<T>::clear() {
	delete[] n;
	n = new T[capacity]();
	size = 0;
}
template <typename T>
bool MyArray<T>::isEmpty() {
	/*for (int i = 0; i < size; i++)
	{
		if (n[i] != ' ')
			return false;
	}*/
	if (size == 0)
		return true;
	else
		return false;
}
template <typename T>
T& MyArray<T>::at(int num) {

	if (num < 0 || num >= size)
	{
		throw  Error::Error();
	}
	return n[num];
}
template <typename T>
T& MyArray<T>::at(int num)const {
	if (num < 0 || num >= size)
	{
		throw Error::Error();
	}
	return n[num];

}

