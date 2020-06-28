//#define  _CRT_SECURE_NO_WARNINGS
#ifndef s1081545_MyArray_H
#define s1081545_MyArray_H
#pragma once
#include<iostream>

#define DefaultCapacity  10 

using namespace std;

template <class T>
class MyArray
{	//modify this class into a template class
	template<class U>
	friend ostream& operator<<(ostream&, const MyArray<U>&);
	template<class U>
	friend istream& operator>>(istream&, MyArray<U>&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray&);
	MyArray(const T[], int);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	MyArray operator+(const int&) const;
	MyArray operator-(const int&) const;
	MyArray operator*(const int&) const;
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();

protected:
	int size;
	int capacity;
	T* data;
};
#endif // !MyArray
