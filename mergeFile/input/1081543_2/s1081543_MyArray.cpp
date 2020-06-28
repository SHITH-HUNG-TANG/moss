#include"s1081543_MyArray.h"


template<typename T>
ostream& operator<<(ostream& out, const MyArray<T>& num)
{
	for (int i = 0; i < num.size; i++)
	{
		cout << num.data[i] << " ";
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

	for (int i = 0; i < Size; i++)
	{
		data[i] = value;
	}
}

template<typename T>
MyArray<T>::MyArray(int Size, T* value)
{
	size = Size;

	capacity = 10;

	data = new T[capacity];

	while (size > capacity)
	{
		reserve(capacity * 2);
	}

	for (int i = 0; i < size; i++)
	{
		data[i] = value[i];
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
	delete[] data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right)
{
	size = right.size;

	capacity = right.capacity;

	data = new T[capacity]();

	delete[] data;

	data = new T[capacity]();

	for (int i = 0; i < size; i++)
	{
		data[i] = right.data[i];
	}

	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const
{
	if (getSize() != right.getSize())
	{
		return false;
	}

	for (int i = getSize() - 1; i >= 0; i--)
	{
		if (data[i] == right.data[i])
		{

		}
		else
		{
			return false;
		}
	}

	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const	//new
{
	MyArray<T> temp(*this);

	temp.size += right.size;

	while (temp.size > temp.capacity)
	{
		temp.reserve(capacity * 2);
	}

	for (int i = size, j = 0; i < temp.size; i++, j++)
	{
		temp.data[i] = right.data[j];
	}

	return temp;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)		//new
{
	MyArray<T> temp(*this);

	temp.size += right.size;

	while (temp.size > temp.capacity)
	{
		temp.reserve(temp.capacity * 2);
	}

	for (int i = size, j = 0; i < temp.size; i++, j++)
	{
		temp.data[i] = right.data[j];
	}

	*this = temp;

	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int num)
{
	return data[num];
}

template<typename T>
T MyArray<T>::operator[](int num) const
{
	return data[num];
}

template<typename T>
T& MyArray<T>::at(int n)		//new
{
	if (n > size - 1)
	{
		throw out_of_range(" Out of range");
	}
	else
	{
		return data[n];
	}

}

template<typename T>
T MyArray<T>::at(int n) const	//new
{
	if (n > size - 1)
	{
		throw out_of_range(" Out of range");
	}
	else
	{
		return data[n];
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
void MyArray<T>::resize(size_t n, T item)
{
	while (n > capacity)
	{
		reserve(capacity * 2);
	}

	if (n > size)
	{
		for (int i = size; i < n; i++)
		{
			data[i] = item;
		}
	}

	size = n;
}

template<typename T>
void MyArray<T>::reserve(size_t n)
{
	if (n > capacity)
	{
		T* temp = new T[n]();

		for (int i = 0; i < n && i < size; i++)
		{
			temp[i] = data[i];
		}

		capacity = n;

		data = temp;
	}
}

template<typename T>
void MyArray<T>::shrink_to_fit()	//new
{
	T* buffer = new T[size]();

	for (int i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}

	capacity = size;

	delete[] data;

	data = buffer;
}

template<typename T>
void MyArray<T>::clear()		//new
{
	resize(0, 0);
}

template<typename T>
bool MyArray<T>::isEmpty()		//new
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
