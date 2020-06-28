
#ifndef S1083302_MYARRAY_H
#define S1083302_MYARRAY_H
#include<iostream>
#include<ostream>
#include<stdexcept>
#include<exception>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray<T>&);
	~MyArray();


	const MyArray<T>& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray<T> operator+(const MyArray<T>&) const;	//new
	MyArray<T>& operator+=(const MyArray<T>&);		//new
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

private:
	int size;
	int capacity = 10;
	T* data;
};
// !MyArray
class at_exception :public logic_error
{
public:
	at_exception()
		:logic_error("error: out of range") {};
};
template<typename T>
ostream& operator<<(ostream& input, const MyArray<T>& right)
{
	for (int i = 0;i < right.size;i++)
	{
		input << right.data[i] << " ";
	}
	return input;
}
template<typename T>
MyArray<T>::MyArray(int Capacity)
{
	size = 0;
	//while (Capacity > capacity)
		//capacity *= 2;
	capacity = Capacity;
	data = new T[capacity];
}

template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	while (Size > capacity)
		capacity *= 2;
	data = new T[capacity];
	size = Size;
	for (int i = 0;i < size;i++)
		data[i] = value;
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& right)
{
	capacity = right.capacity;
	size = right.size;
	data = new T[capacity];
	for (int i = 0;i < size;i++)
		data[i] = right.data[i];
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[]data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right)
{
	resize(right.size, '0');
	for (int i = 0;i < right.size;i++)
	{
		data[i] = right.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const
{
	if (size != right.size)
		return false;
	else
	{
		for (int i = 0;i < size;i++)
		{
			if (data[i] != right[i])
				return false;
		}
		return true;
	}
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const
{
	MyArray<T> ans;
	ans.resize(size + right.size, '0');
	for (int i = 0;i < size;i++)
		ans.data[i] = data[i];
	for (int i = size;i < ans.size;i++)
		ans.data[i] = right.data[i - size];
	return ans;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)
{
	MyArray<T> ans;
	ans.resize(size + right.size, '0');
	for (int i = 0;i < size;i++)
		ans.data[i] = data[i];
	for (int i = size;i < ans.size;i++)
		ans.data[i] = right.data[i - size];

	*this = ans;
	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int sub)
{
	return data[sub];
}

template<typename T>
T MyArray<T>::operator[](int sub) const
{
	return data[sub];
}

template<typename T>
T& MyArray<T>::at(int sub)
{
	if (sub < 0 || sub >= size)
	{
		throw at_exception();
	}
	return data[sub];
}

template<typename T>
T MyArray<T>::at(int sub) const
{
	if (sub < 0 || sub >= size)
	{
		throw at_exception();
	}
	return data[sub];
}

template<typename T>
int MyArray<T>::getSize() const
{
	return size;
}

template<typename T>
int MyArray<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void MyArray<T>::resize(size_t n, T item)
{
	while (n > capacity)
	{
		reserve(2 * capacity);
	}
	for (int i = size;i < n;i++)
		data[i] = item;
	size = n;
}

template<typename T>
void MyArray<T>::reserve(size_t n)
{
	T* temp = new T[n]();
	for (int i = 0;i < size;i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	capacity = n;
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	reserve(size);
}

template<typename T>
void MyArray<T>::clear()
{
	resize(0, '\0');
}

template<typename T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

#endif // !1
#pragma once
