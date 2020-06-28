#include <iostream>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string>
#include <exception>

using namespace std;

#include"s1083331_MyArray.h"

template class MyArray<char>;
template class MyArray<int>;

template<typename T>
MyArray<T>::MyArray(int newcapacity)
{
	size = 0;
	ptr = new T[newcapacity];
	capacity = newcapacity;
}

template<typename T>
MyArray<T>::MyArray(int newsize, T value)
{
	capacity = 10;

	while (capacity < newsize)
	{
		capacity *= 2;
	}

	ptr = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		ptr[i] = value;
	}

	size = newsize;
}

template<typename T>
MyArray<T>::MyArray(T arr[], int length)
{
	capacity = 10;

	if (capacity < length)
	{
		capacity *= 2;
	}

	ptr = new T [capacity];

	size = length;

	for (int i = 0; i < capacity; i++)
	{
		ptr[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		ptr[i] = arr[i];
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& num)
{
	*this = num;
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[]ptr;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& num)
{
	capacity = num.capacity;

	ptr = new T[capacity];

	size = num.size;

	for (int i = 0; i < size; i++)
	{
		ptr[i] = num.ptr[i];
	}

	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& num) const
{
	if (size == num.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] != num.ptr[i])
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& num) const
{
	if (*this == num)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& num) const
{
	MyArray<T> ans;

	int newsize = size + num.size;
	int size1 = size;

	ans.resize(newsize, 0);

	for (int i = 0; i < size1; i++)
	{
		ans.ptr[i] = ptr[i];
	}

	for (int i = 0; i < num.size; i++)
	{
		ans.ptr[i + size1] = num.ptr[i];
	}

	return ans;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& num)
{
	int newsize = size + num.size;
	int size1 = size;

	resize(newsize, 0);

	for (int i = 0; i < num.size; i++)
	{
		ptr[i + size1] = num[i];
	}

	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int i)
{
	if (i >= size && i < 0)
	{
		cerr << "out of range" << endl;
		exit(1);
	}
	else
	{
		return ptr[i];
	}

}

template<typename T>
T MyArray<T>::operator[](int i) const
{
	if (i >= size && i < 0)
	{
		cerr << "out of range" << endl;
		exit(1);
	}
	else
	{
		return ptr[i];
	}
}

template<typename T>
T& MyArray<T>::at(int i)
{
	if (i >= size || i < 0)
	{
		throw Error();
	}
	else
	{
		return ptr[i];
	}
}

template<typename T>
T MyArray<T>::at(int i) const
{
	if (i >= size || i < 0)
	{
		throw Error();
	}
	else
	{
		return ptr[i];
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
void MyArray<T>::resize(size_t newsize, T item)
{
	if (newsize > size)
	{
		if (newsize > capacity)
		{
			int newcapacity = capacity;

			while (newcapacity < newsize)
			{
				newcapacity *= 2;
			}

			reserve(newcapacity);
		}

		for (int i = size; i < newsize; i++)
		{
			ptr[i] = item;
		}

		size = newsize;

	}
	else if (newsize < size)
	{
		T* newptr = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			newptr[i] = 0;
		}

		for (int i = 0; i < newsize; i++)
		{
			newptr[i] = ptr[i];
		}

		size = newsize;
	}
	else if (newsize == 0)
	{
		T* newptr = new T[1];

		newptr[0] = 0;

		delete[]ptr;

		ptr = newptr;
	}

}

template<typename T>
void MyArray<T>::reserve(size_t newcapacity)
{
	if (newcapacity > capacity)
	{
		T* newptr = new T[newcapacity];

		if (size > newcapacity)
		{
			size = newcapacity;
		}

		for (int i = 0; i < newcapacity; i++)
		{
			newptr[i] = 0;
		}

		for (int i = 0; i < size; i++)
		{
			newptr[i] = ptr[i];
		}

		capacity = newcapacity;

		delete[]ptr;

		ptr = newptr;
	}
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	T* newptr = new T[size];

	capacity = size;

	for (int i = 0; i < capacity; i++)
	{
		newptr[i] = ptr[i];
	}

	ptr = newptr;
}

template<typename T>
void MyArray<T>::clear()
{
	size = 0;

	T* newptr = new T[capacity];

	delete[]ptr;

	ptr = newptr;

}

template<typename T>
bool MyArray<T>::isEmpty() const
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



