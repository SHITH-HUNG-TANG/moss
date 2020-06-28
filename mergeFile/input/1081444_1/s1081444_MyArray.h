#pragma once

#ifndef S1081444_MYARRAY_H
#define S1081444_MYARRAY_H

#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class MyArray
{
	friend ostream& operator<<(ostream &output, const MyArray<T> &a)
	{
		for (int i = 0; i < a.size; ++i)
		{
			output << a.data[i];
			if (i < a.size - 1)
			{
				output << " ";
			}
		}
		return output;
	}
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(int Size, T* value);
	MyArray(const MyArray &);
	~MyArray();

	const MyArray& operator=(const MyArray &);
	bool operator==(const MyArray &) const;
	bool operator!=(const MyArray &) const;
	MyArray operator+(const MyArray &) const;
	MyArray& operator+=(const MyArray &);
	T &operator[](int);
	T operator[](int) const;
	T &at(int);
	T at(int) const;

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();
	void clear();
	bool isEmpty();
private:
	int size;
	int capacity;
	T* data;
};

#endif