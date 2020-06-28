#include <iostream>
#include <exception>
#include "s1083308_MyArray.h"
using namespace std;

template<typename T>
MyArray<T>::MyArray(int Capacity)
{
	capacity = Capacity;
	while (size > capacity)
		reserve(capacity * 2);
	size = 0;
	data = new T[capacity];
}

template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	capacity = 10;
	while (Size > capacity)
		reserve(capacity * 2);
	data = new T[capacity];
	size = Size;
	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}

}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& copy)
{
	*this = copy; //modify
	//size = copy.getSize();
	//capacity = copy.getCapacity();
	//delete[] data;
	//data = new T[capacity];

	//for (int i = 0; i < size; i++)
	//	data[i] = copy.data[i];
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& copy)
{
	size = copy.getSize();
	capacity = copy.getCapacity();
	//delete[] data; //modify
	data = new T[capacity];

	for (int i = 0; i < size; i++)
		data[i] = copy.data[i];

	return *this;
}

template <typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& right) const
{
	if (size != right.size)
		return false;

	for (int i = 0; i < size; i++)
		if (data[i] != right.data[i])
			return false;

	return true;
}

template<typename T>
bool MyArray<T>:: operator!=(const MyArray& bignum) const
{
	return !(*this == bignum);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right)
{
	MyArray a(*this);
	a += right;
	return a;
}//new

template<typename T>
MyArray<T>& MyArray<T>:: operator+=(const MyArray<T>& right)
{
	int orisize = size;
	int newsize = size + right.size;

	resize(newsize, 0);

	for (int i = 0; i < newsize; i++)
	{
		if (i >= orisize)
			data[i] = right.data[i - orisize];
	}

	return *this;
}//new

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

//
template<typename T>
T& MyArray<T>:: operator[](int num)
{
	if (num < 0 || num >= size)
	{
		cerr << "Error" << endl;
	}

	return  data[num];
}

template<typename T>
T MyArray<T>::operator[](int num) const
{
	if (num < 0 || num >= size)
	{
		cerr << "Error" << endl;
	}

	return data[num] ;
}

template<typename T>
void MyArray<T>::resize(size_t Size, T item)
{
	if (Size > size)
	{
		while (Size > capacity)
		{
			capacity *= 2;
		}

		T* temp = new T[capacity];

		for (int i = 0; i < Size; i++)
		{
			temp[i] = item;
		}

		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		size = Size;

		delete[] data;

		data = temp;
	}
	else
	{
		T* temp = new T[size];

		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		size = Size;
		delete[] data;
		data = temp;
	}


}

template<typename T>
void MyArray<T>::reserve(size_t Capacity)
{
	if (Capacity > capacity)
		capacity = Capacity;

	T* temp = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;

	data = temp;
}

template<typename T>
T& MyArray<T>::at(int num)
{
	if (num < 0 || num >= size)
	{
		throw Error();
	}
	else
		return data[num];
}

template<typename T>
T MyArray<T>::at(int num) const
{
	if (num < 0 || num >= size)
	{
		throw Error();
	}
	else
		return data[num];
}

template<typename T>
ostream& operator<<(ostream& out, const MyArray <T>& right)
{
	cout << right.data[0];
	for (int i = 1; i < right.size; i++)
		out << " , " << right.data[i];

	return out;
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	reserve(size);
}

template<typename T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}


template<typename T>
void MyArray<T>::clear()
{
	size = 0;
	capacity = 10;
	delete[] data;
	data = new T[capacity];
}

template class MyArray<int>;
template class MyArray<char>;