#include"s1071222_MyArray.h"
#include<iostream>
using namespace std;

template<typename T>
ostream& operator<< (ostream& output, const MyArray< T >& right)
{
	for (int i = 0; i < right.size; i++)
	{
		output << right.data[i] << " ";
	}
	return output;
}

template <typename T>
MyArray< T >::MyArray(int newSize)
{
	size = 0;
	capacity = newSize;
	data = new T[capacity]();
}

template <typename T>
MyArray< T >::MyArray(int newSize, T value) :MyArray()
{
	if (size < newSize)
		resize(newSize);
	for (int i = 0; i < newSize; i++)
	{
		data[i] = value;
	}
}

template <typename T>
MyArray< T >::MyArray(const MyArray< T >& right)
{
	size = right.size;
	capacity = right.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; i++)
		data[i] = right.data[i];
	for (int i = size; i < capacity; i++)
		data[i] = ' ';
}

template <typename T>
const MyArray< T >& MyArray< T >::operator=(const MyArray< T >& equal)
{
	if (&equal != this)
	{
		if (size != equal.size)
		{
			delete[] data;
			size = equal.size;
			capacity = equal.capacity;
			data = new T[capacity]();
		}
		for (int i = 0; i < size; i++)
		{
			data[i] = equal.data[i];
		}
	}
	return *this;
}

template <typename T>
bool MyArray< T >::operator==(const MyArray< T >& right)const
{
	if (size != right.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (data[i] != right.data[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
bool MyArray< T >::operator!=(const MyArray< T >& right)const
{
	if (size != right.size)
	{
		return true;
	}
	for (int i = 0; i < size; i++)
	{
		if (data[i] != right.data[i])
		{
			return true;
		}
	}
	return false;
}

template <typename T>
MyArray< T > MyArray< T >::operator+(const MyArray< T >& right)const
{
	/*MyArray x;
	int newSize = size + right.size;
	x.resize(newSize);
	for (int i = 0; i < size; i++)
		x.data[i] = data[i];
	for (int k = 0; k < right.size; k++)
		x.data[size + k] = right.data[k];
	x.data[size + right.size] = '\0';*/

	return MyArray(*this) += right;
}

template <typename T>
MyArray< T >& MyArray< T >::operator += (const MyArray< T >& right)
{
	int newSize = size + right.size;
	this->resize(newSize);
	for (int i = 0; i < right.size; i++)
		data[size - right.size + i] = right.data[i];

	return *this;
}

template <typename T>
T& MyArray< T >::operator[](int x)
{
	return data[x];
}

template <typename T>
T MyArray< T >::operator[](int x) const
{
	return data[x];
}

template <typename T>
T& MyArray< T >::at(int x)
{
	MyArray z(*this);
	z.shrink_to_fit();
	try {
		if (x >= size)
			throw out_of_range("get exception !!!");
		return data[x];
	}
	catch (out_of_range e) {
		cout << "get exception !!!";
		return data[x];
	}
}

template <typename T>
T MyArray< T >::at(int x)const
{
	MyArray z(*this);
	z.shrink_to_fit();
	try {
		if (x >= size)
			throw out_of_range("get exception !!!");
		cout << z.data[x];
	}
	catch (out_of_range e) {
		cout << "get exception !!!";
	}
	return z.data[x];
}

template <typename T>
int MyArray< T >::getSize() const
{
	return size;
}

template <typename T>
int MyArray< T >::getCapacity() const
{
	return capacity;
}

template <typename T>
void MyArray< T >::shrink_to_fit()
{
	MyArray x(*this);
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = x[i];
	capacity = size;
}

template <typename T>
void MyArray< T >::clear()
{
	MyArray x;
	x.resize(size);
	x.size = 0;
	*this = x;
}

template <typename T>
bool MyArray< T >::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template <typename T>
void MyArray< T >::resize(size_t newSize, char x)
{
	while (newSize >= capacity)
	{
		reserve(capacity * 2);
	}

	if (newSize > size)
	{
		for (int i = size; i < newSize; i++)
		{
			data[i] = x;
		}
	}

	if (newSize >= size)
		size = newSize;
}

template <typename T>
void MyArray< T >::reserve(size_t newSize)
{
	if (newSize > capacity)
	{
		T* temp = new T[newSize];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		capacity = newSize;
		delete[] data;
		data = temp;
	}
}

template <typename T>
MyArray< T >::~MyArray()
{
	delete[] data;
}

template class  MyArray<int>;
template class  MyArray<char>;
template class  MyArray<float>;
template class  MyArray<string>;