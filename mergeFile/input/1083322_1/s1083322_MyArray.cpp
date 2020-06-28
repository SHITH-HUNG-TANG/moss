#include<iostream>
#include"s1083322_MyArray.h"
using namespace std;
template <class T>MyArray<T>::MyArray(int Capacity)
{
	size = 0;
	capacity = Capacity;
	data = new T[capacity]{ 0 };
}
template <class T>MyArray<T>::MyArray(int Size, T value)
{
	capacity = 10;
	size = Size;
	data = new T[capacity]{ 0 };
	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}
}
template <class T>MyArray<T>::MyArray(const MyArray<T> &copy)
{
	size = copy.size;
	capacity = copy.capacity;
	data = new T[capacity]{ 0 };
	for (int i = 0; i < size; i++)
	{
		data[i] = copy.data[i];
	}
}//copy constructer
template <class T>MyArray<T>::~MyArray() { delete[]data; }


template <class T>const MyArray<T>& MyArray<T>::operator=(const MyArray<T> &right)
{
	size = right.size;
	capacity = right.capacity;
	data = new T[capacity]{ 0 };
	for (int i = 0; i < size; i++)
	{
		data[i] = right.data[i];
	}
	return *this;
}
template <class T>bool MyArray<T>::operator==(const MyArray<T> &right)const
{
	if (size != right.size)
	{
		return false;
	}
	else
		return true;
}
template <class T>bool MyArray<T>::operator!=(const MyArray<T> &right)const
{
	if (size != right.size)
	{
		return true;
	}
	else
		return false;
}
template <class T>MyArray<T> MyArray<T>::operator+(const MyArray<T> &right)const
{
	MyArray sum(*this);
	if (size + right.size > sum.capacity) { sum.capacity *= 2; sum.reserve(sum.capacity); }
	int index = 0;
	for (int i = size; i < size + right.size; i++)
	{
		sum.data[i] = right.data[index];
		index++;
	}
	sum.size = size + right.size;
	return sum;
}
template <class T>MyArray<T>& MyArray<T>::operator+=(const MyArray<T>&right)
{
	if (size + right.size > capacity) { capacity *= 2; reserve(capacity); }
	int index = 0;
	for (int i = size; i < size + right.size; i++)
	{
		data[i] = right.data[index];
		index++;
	}
	size += right.size;
	return *this;
}
template <class T>T MyArray<T>::at(int a)
{
	return data[a];
}
template <class T>int MyArray<T>::at(int a)const
{
	return data[a];
}

template <class T>int MyArray<T>::getCapacity()const { return capacity; }
template <class T>int MyArray<T>::getSize()const { return size; }
template <class T>void MyArray<T>::setSize(int Size) { size = Size; }
template <class T>void MyArray<T>::setCapacity(int Capacity) { capacity = Capacity; }
template <class T>T MyArray<T>::getData(int index)const { return data[index]; }
template <class T>void MyArray<T>::setData(int index, T item) { data[index] = item; }
template <class T>T MyArray<T>::operator[](int index)const { return data[index]; }

template <class T>void MyArray<T>::resize(int Capacity, T item)
{
	if (capacity > Capacity) 
	{	
		reserve(Capacity); 
		size = Capacity; 
		capacity = Capacity;
	}
	else if (capacity < Capacity)
	{
		reserve(Capacity);
		capacity = Capacity;
		size = Capacity;
		for (int i = capacity; i < Capacity; i++)
		{
			data[i] = item;
		}
	}
}
template <class T>void MyArray<T>::reserve(int capacity)
{
	MyArray temp(*this);
	delete[]data;
	data = new T[capacity]{ 0 };
	for (int i = 0; i < temp.size; i++)
	{
		data[i] = temp.data[i];
	}
}
template <class T>void MyArray<T>::shrink_to_fit()
{
	capacity = size;
	reserve(capacity);
}
template <class T>void MyArray<T>::clear()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = '\0';
	}
	size = 0;
}
template <class T>bool MyArray<T>::isEmpty()
{
	if (capacity == size)return false;
	else return true;
}
template class MyArray <int>;
template class MyArray <char>;
//new