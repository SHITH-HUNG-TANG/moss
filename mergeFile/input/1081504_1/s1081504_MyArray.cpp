#include "s1081504_MyArray.h"


template<typename T>
MyArray< T >::MyArray(int newCapactiy)//default constructor
{
	size = 0;
	data = new T[newCapactiy]();
	capacity = newCapactiy;
}
template<typename T>
MyArray< T >::MyArray(int newSize, T value)//initial constructor
{
	size = newSize;
	capacity = 10;
	if (newSize > capacity)
		while (newSize > capacity)
			capacity *= 2;
	else
		capacity = 10;

	data = new T[newSize]();
	for (int i(0); i < newSize; i++)
	{
		data[i] = value;
	}
}
template<typename T>
MyArray< T >::MyArray(T* arrayData, int newSize)//bonus constructor
{
	size = newSize;
	capacity = 10;
	if (newSize > capacity)
		while (newSize > capacity)
			capacity *= 2;
	else
		capacity = 10;

	data = new T[newSize]();
	for (int i(0); i < newSize; i++)
	{
		data[i] = arrayData[i];
	}
}
template<typename T>
MyArray< T >::~MyArray()//destructor
{
	delete[] data;
}
template<typename T>
MyArray< T >::MyArray(const MyArray& right)//copy constructor
{
	*this = right;
}
template<typename T>
MyArray< T >& MyArray< T >::operator=(const MyArray& right)
{
	if (this != &right)
	{
		data = new T[right.size + 1]();
		size = right.size;
		capacity = right.capacity;
		for (int i(0); i < right.size; i++)
		{
			data[i] = right.data[i];
		}
	}
	return *this;
}
template<typename T>
bool MyArray< T >::operator==(const MyArray& right)
{
	if (size == right.size)
		for (int i(size - 1); i >= 0 && data[i] == right.data[i]; i--)
			if (i == 0)
				return true;
	return false;
}
template<typename T>
bool MyArray< T >::operator!=(const MyArray& right)
{
	return !(*this == right);
}
template<typename T>
T MyArray< T >::operator[](int number) const
{
	return data[number];
}
template<typename T>
T& MyArray< T >::operator[](int number)
{
	return data[number];
}
template<typename T>
ostream& operator<<(ostream& out, const MyArray< T >& temp)
{
	for (int i(0); i < temp.getSize(); i++)
	{
		if (i < temp.getSize() - 1)
		{
			out << (T)temp[i] << " ";
		}
		else
			out << (T)temp[i] << " ";
	}
	return out;
}
template<typename T>
MyArray< T > MyArray< T >::operator+(const MyArray& right)
{
	MyArray temp(*this);
	temp.resize(temp.size + right.size);

	if (temp.size > temp.capacity)
	{
		while (temp.size > temp.capacity)
			reserve(temp.capacity * 2);
	}

	for (int i(size), j(0); i < right.size, j < right.size; i++, j++)
	{
		temp[i] = right[j];
	}
	return temp;
}
template<typename T>
MyArray< T >& MyArray< T >::operator+=(const MyArray& right)
{
	int tempSize(size);
	MyArray temp(*this);
	resize(size + right.size);

	if (temp.size > temp.capacity)
	{
		while (temp.size > temp.capacity)
			reserve(temp.capacity * 2);
	}

	for (int i(tempSize), j(0); i < right.size, j < right.size; i++, j++)
	{
		data[i] = right[j];
	}
	return *this;
}
template<typename T>
T& MyArray< T >::at(int index)
{
	if (index != 0 && (index - 1) <= size)
		return data[index];
	else if (index == 0)
		return data[index];
	else if (index != 0 && (index - 1) > size)
		throw out_of_range("");
}
template<typename T>
T MyArray< T >::at(int index) const
{
	if (index != 0 && (index - 1) <= size)
		return data[index];
	else if (index == 0)
		return data[index];
	else if (index != 0 && (index - 1) > size)
		throw out_of_range("");
}


template<typename T>
int MyArray< T >::getSize() const
{
	return size;
}
template<typename T>
int MyArray< T >::getCapacity() const
{
	return capacity;
}
template<typename T>
int* MyArray< T >::getData() const
{
	return data;
}
template<typename T>
void MyArray< T >::setData(int* newData)
{
	delete[] data;
	data = newData;
}
template<typename T>
void MyArray< T >::resize(size_t n, T item)
{
	while (n > capacity)
		reserve(capacity * 2);

	if (n > size)
	{
		for (int i(size); i < n; i++)
			data[i] = item;
	}
	size = n;
}
template<typename T>
void MyArray< T >::reserve(size_t n)
{
	if (n > capacity)
	{
		T* temp = new T[n]();
		for (int i = 0; i < size; i++)
			temp[i] = data[i];
		capacity = n;
		delete[] data;
		data = temp;
	}
}
template<typename T>
void MyArray< T >::shrink_to_fit()
{
	if (size < capacity)
	{
		capacity = size;
	}
}
template<typename T>
void MyArray< T >::clear()
{
	delete[] data;
	data = new T[1]();
	size = 0;
}
template<typename T>
bool MyArray< T >::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}