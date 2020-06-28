#ifndef S1081504_MYARRAY_H
#define S1081504_MYARRAY_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class MyArray
{
	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray&);
public:

	MyArray(int capacity = 10);
	MyArray(int size, T value);
	MyArray(T* arrayData, int size);
	~MyArray();
	MyArray(const MyArray&);

	MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&);
	bool operator!=(const MyArray&);
	MyArray operator+(const MyArray&);
	MyArray& operator+=(const MyArray&);
	T operator[](int) const;
	T& operator[] (int);
	T& at(int);
	T at(int) const;

	int getSize() const;
	int getCapacity() const;
	int* getData() const;
	void setData(int* newPtr);
	void resize(size_t n, T item = '\0');
	void reserve(size_t n = 0);
	void shrink_to_fit();
	void clear();
	bool isEmpty();

private:
	int size = 0;
	int capacity;
	T* data;
};

#endif