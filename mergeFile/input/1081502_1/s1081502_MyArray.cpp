#include<iostream>
#include<stdexcept>
#include"s1081502_MyArray.h"
using namespace std;

template<typename T>
MyArray<T>::MyArray(int r_Capacity)
{
	size = 0;
	capacity = r_Capacity;
	ptr = new T[capacity]();
}
template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	size = Size;
	capacity = size;
	ptr = new T[capacity]();
	for (int i = 0; i < size; i++)
	{
		ptr[i] = value;
	}
}
template<typename T>
MyArray<T>::MyArray(T* value, int Size)
{
	size = Size;
	capacity = 10;
	while (size > capacity)
	{
		reserve(capacity * 2);
	}
	ptr = new T[capacity]();
	for (int i = 0; i < size; i++)
	{
		ptr[i] = value[i];
	}
}
template<typename T>
MyArray<T>::MyArray(const MyArray& MyArrayToCopy)
{
	size = MyArrayToCopy.size;
	capacity = MyArrayToCopy.capacity;
	ptr = new T[capacity];

	for (int i = 0; i < size; i++)
		ptr[i] = MyArrayToCopy.ptr[i];
}
template<typename T>
MyArray<T>::~MyArray()
{
	delete[] ptr;
}
template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray& right)
{
	if (&right != this)
	{
		if (size != right.size)
		{
			delete[] ptr;
			size = right.size;
			capacity = right.capacity;
			ptr = new T[size];
		}
		for (int i = 0; i < size; i++)
			ptr[i] = right.ptr[i];
	}
	return *this;
}
template<typename T>
bool MyArray<T>::operator==(const MyArray& right)const
{
	if (size != right.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] != right.ptr[i])
				return false;
		}
		return true;
	}
}
template<typename T>
bool MyArray<T>::operator!=(const MyArray& right)const
{
	return !(*this == right);
}
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray& right)const
{
	MyArray<T> a(*this);
	a.resize(a.size + right.size);
	for (int i = a.size - right.size, j = 0; i < a.size; i++, j++)
	{
		a.ptr[i] = right.ptr[j];
	}
	return a;
}
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& right)
{
	resize(size + right.size);
	for (int i = size - right.size, j = 0; i < size; i++, j++)
	{
		ptr[i] = right.ptr[j];
	}
	return *this;
}
template<typename T>
T& MyArray<T>::operator[](int subscript)
{
	return ptr[subscript];
}
template<typename T>
T MyArray<T>::operator[](int subscript)const
{
	return ptr[subscript];
}
template<typename T>
T& MyArray<T>::at(int right)
{
	if (right > size - 1)
	{
		throw out_of_range("");
	}
	else
	{
		return ptr[right];
	}
}
template<typename T>
T MyArray<T>::at(int right)const
{
	if (right > size - 1)
	{
		throw out_of_range("");
	}
	else
	{
		return ptr[right];
	}
}
template<typename T>
int MyArray<T>::getSize() const {
	return size;
}
template<typename T>
int MyArray<T>::getCapacity() const {
	return capacity;
}
template<typename T>
void MyArray<T>::resize(size_t n, T c)
{
	while (n > capacity)
		reserve(capacity * 2);
	if (n > size)
		for (int i = size; i < n; i++)
			ptr[i] = c;
	size = n;
}
template<typename T>
void MyArray<T>::reserve(size_t r_Capacity)
{
	if (r_Capacity > capacity)
	{
		T* temp = new T[r_Capacity]();
		for (int i = 0; i < size && i < r_Capacity; i++)
			temp[i] = ptr[i];
		capacity = r_Capacity;

		delete[] ptr;
		ptr = temp;
	}
}
template<typename T>
void MyArray<T>::shrink_to_fit()
{
	T* temp = new T[size]();
	for (int i = 0; i < size; i++)
		temp[i] = ptr[i];
	capacity = size;

	delete[] ptr;
	ptr = temp;
}
template<typename T>
void MyArray<T>::clear()
{
	size = 0;
}
template<typename T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}