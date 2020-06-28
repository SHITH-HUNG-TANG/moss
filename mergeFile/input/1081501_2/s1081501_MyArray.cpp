#include<iostream>
#include"s1081501_MyArray.h"
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const MyArray<T>&right)
{
	for (int i = 0; i < right.size; i++)
	{
		out << right.data[i];
	}
	return out;
}
template<typename T>
MyArray<T>::MyArray(int Capacity)
{
	size = 0;
	capacity = Capacity;
	data = new T[capacity]();
}
template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	size = Size;
	capacity = 10;
	data = new T[capacity]();
	while (size > capacity)
	{
		reserve(capacity * 2);
	}
	
	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}	
}
template<typename T>
MyArray<T>::MyArray(int Size, T* value)
{
	size = Size;
	capacity = 10;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
	{
		data[i] = value[i];
	}
}
template<typename T>
MyArray<T>::MyArray(const MyArray&right)
{
	*this = right;
}
template<typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}
template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray&right)
{
	size = right.size;
	capacity = right.capacity;
	delete [] data;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
	{
		data[i] = right.data[i];
	}
	return *this;
}
template<typename T>
bool MyArray<T>::operator==(const MyArray&right) const
{
	if (size != right.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != right.data[i])
			{
				return false;
			}
			return true;
		}
	}
}
template<typename T>
bool MyArray<T>::operator!=(const MyArray&right) const
{
	return !(*this == right);
}
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray& right) const
{
	MyArray<T> a(*this);
	a.size = size + right.size;
	while (a.size > a.capacity)
	{
		a.reserve(a.capacity * 2);
	}
	int j = 0;
	for (int i = size ; i < a.size; i++)
	{
		a.data[i] = right.data[j];
		j++;
	}
	return a;
}
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray&right)
{
	size = size + right.size;
	while (size > capacity)
	{
		reserve(capacity * 2);
	}
	int j = 0;
	for (int i = size-right.size; i < size; i++)
	{
		
		data[i] = right.data[j];
		j++;
	}
	return *this;
}
template<typename T>
T& MyArray<T>::operator[](int index)
{
	return data[index];
}
template<typename T>
T MyArray<T>::operator[](int index) const
{
	return data[index];
}
template<typename T>
T MyArray<T>::at(int a)
{
	if (a < size)
	{
		return data[a];
	}
	else
	{
		throw out_of_range("have a error");
	}
}
	
template<typename T>
T MyArray<T>::at(int a) const
{
	if (a < size)
	{
		return data[a];
	}
	else
	{
		throw out_of_range("have a error");
	}
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
void MyArray<T>::resize(size_t s,T item)
{
	while (s > capacity)
	{
		reserve(capacity * 2);
	}
	if (s > size)
	{
		for (int i = size; i < s; i++)
		{
			data[i] = item;
		}
	}
	size = s;
}
template<typename T>
void MyArray<T>::reserve(size_t Capacity) //有改過 追加i < Capacity
{
	if (Capacity > capacity)
	{

		T* temp = new T[Capacity]();
		for (int i = 0; i < size && i < Capacity; i++)
		{
			temp[i] = data[i];
		}
		capacity = Capacity;
		delete[] data;
		data = temp;
	}
}
template<typename T>
void MyArray<T>::shrink_to_fit()
{
	if (size < capacity)
	{
		T* temp = new T[size]();
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		capacity = size;
		delete[] data;
		data = temp;
	}
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
		cout << "yes "<< endl;
		return true;
	}
	else
	{
		cout << "no" << endl;
		return false;
	}
}