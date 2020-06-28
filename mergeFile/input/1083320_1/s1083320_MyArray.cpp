
#include<iostream>
#include<iomanip>
#include<stdexcept>
#include "s1083320_MyArray.h"
#include "s1083320_MyString.h"

template< class T >MyArray<T>::MyArray(int num)
{
	size = 0;
	capacity = num;
	data = new T[capacity];
}

template< class T > MyArray<T>::~MyArray()
{
	delete data;
}

template< class T >MyArray<T>::MyArray<T>(const MyArray& copy)
{
	size = copy.size;
	capacity = copy.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; ++i) data[i] = copy.data[i];
}

template< class T > MyArray<T>::MyArray(int num, T value)
{
	size = num;
	capacity = size * 2;
	data = new T[capacity];
	for (int i = 0; i < num; ++i)
	{
		data[i] = value;
	}
}

template< class T >void MyArray<T>::push_back(const T& item)
{
	if (size == capacity)
	{
		this->reserve(size * 2);
		size += 1;
		data[size - 1] = item;
	}
	else
	{
		size += 1;
		data[size - 1] = item;
	}
}

template< class T >void MyArray<T>::pop_back()
{
	if (size >= 1) this->resize(size - 1);
}

template< class T >void MyArray<T>::resize(unsigned int num)
{
	MyArray a(*this);
	delete[] data;
	size = num;
	if (capacity < size) capacity = size * 2;
	data = new T[capacity];
	for (int i = 0; i < size; ++i) data[i] = a.data[i];
}

template< class T >void MyArray<T>::resize(unsigned int num, const T& item)
{
	if (num > size)for (int i = size; i < num; ++i) this->push_back(item);
}

template< class T >void MyArray<T>::reserve(unsigned int num)
{
	if (num > capacity)
	{
		MyArray a(10);
		delete[] a.data;
		a.capacity = num;
		a.size = size;
		a.data = new T[num];
		for (int i = 0; i < size; ++i) a.data[i] = data[i];
		*this = a;
	}
}

template< class T >T& MyArray<T>::at(int num)
{
	try {
		if (num > size) throw exception();
		return data[num];
	}
	catch (exception& out)
	{
		cerr << "Error : Subscription Out of Range when using function 'at()' " << endl;
		system("pause");
		exit(0);
	}
}

template< class T >T MyArray<T>::at(int num) const
{
	try {
		if (num > size) throw exception();
		return data[num];
	}
	catch (exception& out)
	{
		cerr << "Error : Subscription Out of Range when using function 'at()' " << out.what();
	}
}

template< class T >bool MyArray<T>::isEmpty()
{
	if (size == 0) return true;
	else return false;
}

template< class T >int MyArray<T>::getCapacity() const
{
	return capacity;
}

template< class T >int MyArray<T>::getSize() const
{
	return size;
}

template< class T >const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& copy)
{
	delete[] data;
	capacity = copy.capacity;
	size = copy.size;
	data = new T[copy.capacity];
	for (int i = 0; i < size; ++i) data[i] = copy.data[i];
	return *this;
}

template< class T >bool MyArray<T>::operator==(const MyArray<T>& copy) const
{
	if (size != copy.size) return false;
	for (int i = 0; i < size; ++i)
	{
		if (data[i] != copy.data[i])return false;
	}
	return true;
}

template< class T >bool MyArray<T>::operator!=(const MyArray<T>& copy) const
{
	if (*this == copy) return false;
	else return true;

}

template< class T >MyArray<T> MyArray<T>::operator+(const MyArray<T>& copy) const
{
	MyArray<T> a(10);
	delete[] a.data;
	a.size = size + copy.size;
	a.capacity = a.size * 2;
	a.data = new T[a.capacity];
	for (int i = 0; i < size; ++i) a.data[i] = data[i];
	for (int j = 0; j < copy.size; ++j) a.data[size + j] = copy.data[j];
	return a;
}

template< class T >MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& copy)
{
	for (int i = 0; i < copy.size; ++i) this->push_back(copy.data[i]);
	return *this;
}

template< class T >void MyArray<T>::clear()
{
	delete[] data;
	size = 0;
	data = new T[capacity];
}

template< class T >void MyArray<T>::shrink_to_fit()
{
	MyArray a(*this);
	a.capacity = a.size;
	delete[] a.data;
	a.data = new T[a.capacity];
	for (int i = 0; i < size; ++i) a.data[i] = data[i];
	//----------------------return-------------------
	size = a.size;
	capacity = a.capacity;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; ++i) data[i] = a.data[i];
}

template< class T >T MyArray<T>::operator[](int num) const
{
	try {
		if (num > size) throw exception();
		return data[num];
	}
	catch (exception& out)
	{
		cerr << "Error : Subscription Out of Range when using operator[]" << endl;
		system("pause");
		exit(0);
	}
}

template< class T >void MyArray<T>::set(int pos, T item)
{
	data[pos] = item;
}

template< class T >T& MyArray<T>::operator[](int num)
{
	try {
		if (num > size) throw exception();
		return data[num];
	}
	catch (exception& out)
	{
		cerr << "Error : Subscription Out of Range when using operator[]" << endl;
		system("pause");
		exit(0);
	}
}


template class MyArray<int>;
template class MyArray<char>;