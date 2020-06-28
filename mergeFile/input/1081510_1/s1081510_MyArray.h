#pragma once
#ifndef S1081510_MYARRAY_H
#define S1081510_MYARRAY_H
#include<iostream>
#include<vector>
#include<cstdlib>
#include <stdexcept>
#include<string>
using namespace std;

template<typename T>
class MyArray
{	//modify this class into a template class
	template<typename T>friend ostream& operator<<(ostream&, const MyArray<T>&);
	template<typename T>friend istream& operator>>(istream&, MyArray<T>&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray &);
	~MyArray();

	const MyArray& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray operator+(const MyArray<T>&) const;	//new
	MyArray& operator+=(const MyArray<T>&);		//new
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
	bool isEmpty();			//new

protected:
	int size;
	int capacity;
	T* data;
};

template<typename T>
MyArray<T>::MyArray(int C)
{
	size = 0;
	capacity = C;
	data = new T[capacity]();
}


template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	size = Size;
	capacity = 10;
	data = new T[capacity]();
	if (size > capacity)
		resize(size, 0);
	for (int i = 0; i < size; i++)
		data[i] = value;
}

template<typename T>
MyArray<T>::MyArray(const MyArray&copy)
	:size(copy.size),
	capacity(copy.capacity)
{
	data = new T[capacity];
	for (int i = 0; i < size; i++)
		data[i] = copy.data[i];
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}

template<typename T>
int MyArray<T>::getSize()const
{
	return size;
}

template<typename T>
int MyArray<T>::getCapacity()const
{
	return capacity;
}

template<typename T>
const MyArray<T> &MyArray<T>::operator=(const MyArray<T>&right)
{
	size = right.size;
	capacity = right.capacity;
	delete[]data;
	data = new T[capacity];
	for (int i = 0; i < size; i++)
		data[i] = right.data[i];
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>&right)const
{
	if (size != right.size)
		return false;
	for (int i = 0; i < size; i++)
		if (data[i] != right.data[i])
			return false;
	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>&right)const
{
	if (size != right.size)
		return true;
	else
		for (int i = 0; i < size - 1; i++)
			if (data[i] != right.data[i])
				return true;
	return false;
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>&right) const
{
	MyArray add;
	add.resize(size + right.size, 0);
	for (int i = 0; i < size; i++)
		add.data[i] = data[i];
	int j = 0;
	for (int i = size; i < add.size; i++)
	{
		add.data[i] = right.data[j];
		j++;
	}
	return add;
}

template<typename T>
MyArray<T> &MyArray<T>:: operator+=(const MyArray<T>&right)
{
	int presize = size;
	resize(size + right.size, 0);
	int j = 0;
	for (int i = presize; i < size; i++)
	{
		data[i] += right.data[j];
		j++;
	}
	return *this;
}

template<typename T>
T &MyArray<T>::operator[](int subscript)
{
	return data[subscript];
}

template<typename T>
T MyArray<T>::operator[](int subscript)const
{
	return data[subscript];
}

template<typename T>
T &MyArray<T>::at(int index)
{
	if (index >= size)
		throw out_of_range("&MyArray<T>::at(index)");
	else
		return data[index];
}

template<typename T>
T MyArray<T>::at(int index) const
{

	if (index >= size)
		throw out_of_range("MyArray<T>::at(index) const");
	else
		return data[index];
}

template<typename T>
void MyArray<T>::resize(size_t n, T c)
{
	while (n > capacity)
		reserve(capacity * 2);
	if (n > size)
	{
		for (int i = size; i < n; i++)
			data[i] = c;
	}
	size = n;
}

template<typename T>
void MyArray<T>::reserve(size_t m)
{
	if (m > capacity)
	{
		T*data2 = new T[m]();
		for (int i = 0; i < size; i++)
			data2[i] = data[i];
		delete[] data;
		data = data2;
	}
	capacity = m;
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	capacity = size;
	reserve(capacity);
}

template<typename T>
void MyArray<T>::clear()
{
	for (int i = 0; i < capacity; i++)
		data[i] = 0;
	resize(0, '\0');
	reserve(10);
}

template<typename T>
bool MyArray<T>::isEmpty()
{
	for (int i = 0; i < capacity; i++)
	{
		if (data[i] != 0)
			return false;
	}
	return true;
}

template<typename T>
istream &operator>>(istream &input, MyArray<T>&a)
{
	string b;
	input >> b;
	int size2 = b.length();
	a.resize(size2, '\0');
	for (int i = 0; i < size2; i++)
		a.data[i] = b[i];

	return input;
}

template<typename T>
ostream &operator<<(ostream &output, const MyArray<T>&a)
{
	for (int i = 0; i < a.size; i++)
		output << a.data[i] ;
	return output;
}


#endif // !MyArray

#pragma once
