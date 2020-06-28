#include "s1083311_MyArray.h"
#include <string>

template<typename T>
MyArray<T>::MyArray(int cap)
{
	size = 0;
	capacity = cap;
	data = new T[capacity]();

}

template<typename T>
MyArray<T>::MyArray(int space, T value)
{
	size = space;
	capacity = 10;
	resize(size, T());
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
		data[i] = value;

}

template<typename T>
MyArray<T>::MyArray()
{
	size = 0;
	capacity = 10;
	data = new T[capacity]();
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& arrayToCopy)
{
	size = arrayToCopy.size;
	capacity = arrayToCopy.capacity;
	data = new T[size]();
	for (int i = 0; i < size; i++)
		data[i] = arrayToCopy.data[i];

}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right)
{
	if (&right != this) //判斷是否為同個class
	{
		if (size != right.size)
		{
			delete[] data; //release space
			size = right.size;  //resize the object
			capacity = right.capacity;
			data = new T[size]();
		}
		capacity = right.capacity;
		for (int i = 0; i < size; i++)
			data[i] = right.data[i]; //copy 
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const
{
	if (size == right.size)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (data[i] != right.data[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const
{
	MyArray <T> sum;
	delete[] sum.data;
	sum.size = size + right.size;
	sum.data = new T[sum.size]();
	for (int i = 0; i < size; i++)
		sum[i] = data[i];
	for (int i = size; i < sum.size; i++)
		sum[i] = right.data[i - size];

	return sum;

}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)
{
	MyArray <T> temp;
	temp = *this;
	size += right.size;
	delete[] data;
	data = new T[size]();
	for (int i = 0; i < size; i++)
		data[i] = temp.data[i];
	for (int i = temp.size; i < size; i++)
		data[i] = right.data[i - temp.size];

	resize(size, T());
	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int subscript)
{
	//check for subscript out-of-range error
	if (subscript < 0 || subscript >= size)
	{
		cout << "\nError: Subscript " << subscript << " Out of Range" << endl;
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T MyArray<T>::operator[](int subscript) const
{
	//check for subscript out-of-range error
	if (subscript < 0 || subscript >= size)
	{
		cout << "\nError: Subscript " << subscript << " Out of Range" << endl;
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T& MyArray<T>::at(int subscript)
{
	//check for subscript out-of-range error
	if (subscript < 0 || subscript >= size)
	{
		throw outOfRange();
	}
	return data[subscript];
}

template<typename T>
T MyArray<T>::at(int subscript) const
{
	//check for subscript out-of-range error
	if (subscript < 0 || subscript >= size)
	{
		throw outOfRange();
	}
	return data[subscript];
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
	while (capacity < n)
		reserve(capacity * 2);

	if (n < size)
		size = n;
	else if (n > size)
	{
		MyArray <T> temp;
		temp = *this;
		delete[] data;
		size = n;
		data = new T[size]();
		for (int i = 0; i < temp.size; i++)
			data[i] = temp.data[i];
		for (int i = temp.size; i < size; i++)
			data[i] = item;

	}
	
}

template<typename T>
void MyArray<T>::reserve(size_t n)
{	
	/*while (n > capacity)
		capacity *= 2;*/
	capacity = n;
	
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	capacity = size;
	MyArray <T> temp;
	temp = *this;
	delete[] data;
	data = new T[capacity]();
	for (int i = 0; i < temp.size; i++)
		data[i] = temp[i];

}

template<typename T>
void MyArray<T>::clear()
{
	size = 0;
	shrink_to_fit();
}

template<typename T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template class MyArray <char>;
template class MyArray <int>;
template class MyArray <double>;
template class MyArray <string>;