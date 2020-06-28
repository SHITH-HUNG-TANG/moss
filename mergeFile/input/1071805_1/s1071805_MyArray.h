#pragma once
#ifndef S1071805_MYARRAY_H
#define S1071805_MYARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;

template <typename T>
class MyArray {	//modify this class into a template class
	template <typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray();
	//MyArray(int Capacity = 10);
	MyArray(int s);
	MyArray(int s, T value);
	MyArray(const MyArray&);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	//T getValue(int index);
	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new
protected:
	int size;
	int capacity;
	T *data;
};
#endif // !S1071805_MYARRAY_H

template <typename T>
MyArray<T>::MyArray()
{
	size = 0;
	capacity = 10;
	data = new T[capacity]();
}

template <typename T>
MyArray<T>::MyArray(int s)
{
	if (s > 0)
	{
		size = s;
		if (s * 2 < 10)
			capacity = 10;
		else
			capacity = s * 2;
		data = new T[capacity]();
	}
	else
	{
		size = 0;
		capacity = 10;
		data = new T[capacity]();
	}
}

template <typename T>
MyArray<T>::MyArray(int s, T value)
{
	if (s < 0)
	{
		size = 0;
		capacity = 10;
		data = new T[capacity]();
	}
	else
		size = s;

	if (s * 2 < 10)
		capacity = 10;
	else
		capacity = s * 2;
	data = new T[capacity];

	for (int i = 0; i < s; i++)
		data[i] = value;
}

template <typename T>
MyArray<T>::MyArray(const MyArray& right)
{
	size = right.size;
	capacity = right.capacity;
	data = new T[capacity];

	for (int i = 0; i < right.size; i++)
		data[i] = right.data[i];
}

template <typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}

template <typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray& right)
{
	size = right.size;
	capacity = right.capacity;
	delete[] data;
	data = new T[capacity];

	for (int i = 0; i < size; i++)
		data[i] = right.data[i];

	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& right) const
{
	if (size != right.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
			if (data[i] != right.data[i])
				return false;
		return false;
	}
}


template<typename T>
bool MyArray<T>::operator!=(const MyArray& right) const
{
	int counter = 0;
	if (size == right.size)
	{
		for (int i = 0; i < size; i++)
			if (data[i] == right.size)
				counter++;

		if (counter == size)
			return false;
		return true;
	}
	return true;
}

template <typename T>
MyArray<T> MyArray<T>::operator+(const MyArray& right) const
{
	MyArray temp(0);
	temp.resize(size + right.size, 0);

	for (int i = 0; i < size; i++)
		temp.data[i] = data[i];

	for (int i = 0; i < right.size; i++)
		temp.data[i + size] = right.data[i];

	return temp;
}

template <typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& right)
{
	int tempsize = size;
	size += right.size;
	resize(size, 0);

	for (int i = 0; i < right.size; i++)
	{
		data[i + tempsize] = right.data[i];
	}

	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int index)
{
	if (index > size || index < 0)
		throw out_of_range("out of the array range");
	return data[index];
}

template<typename T>
T MyArray<T>::operator[](int index) const
{
	if (index > size || index < 0)
		throw out_of_range("out of the array range");
	return data[index];
}

template<typename T>
T& MyArray<T>::at(int index)
{
	if (index > size || index < 0)
		throw out_of_range("out of the array range");
	return data[index];
}

template<typename T>
T MyArray<T>::at(int index) const
{
	if (index > size || index < 0)
		throw out_of_range("out of the array range");
	return data[index];
}

template <typename T>
int MyArray<T>::getSize() const
{
	return size;
}

template <typename T>
int MyArray<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void MyArray<T>::resize(size_t s, T item)
{
	while (s > capacity)
	{
		reserve(capacity * 2);
	}

	if (s > size)
	{
		for (int i = size; i < s; i++)
			data[i] = item;
	}

	size = s;
}

template<typename T>
void MyArray<T>::reserve(size_t s)
{
	if (s > capacity)
	{
		T* temp = new T[s]();
		for (int i = 0; i < size; i++)
			temp[i] = data[i];
		capacity = s;

		delete[] data;
		data = temp;
	}
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	capacity = size;
}

template<typename T>
void MyArray<T>::clear()
{
	for (int i = 0; i < size; i++)
		data[i] = 0;

	size = 0;
	capacity = 10;
}

template<typename T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template <typename T>
ostream& operator<<(ostream& output, const MyArray<T>& myarray)
{
	for (int i = 0; i < myarray.size; i++)
	{
		output << myarray[i] << " ";
	}
	return output;
}