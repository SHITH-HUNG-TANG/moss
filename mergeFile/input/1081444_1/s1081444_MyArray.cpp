#include"s1081444_MyArray.h"

template<typename T>
ostream& operator<<(ostream &output, const MyArray<T> &a)
{
	for (int i = 0; i < a.size; ++i)
	{
		output << a.data[i];
		if (i < a.size - 1)
		{
			output << " ";
		}
	}
	return output;
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
	for (int i = 0; i < size; ++i)
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
	while (size > capacity)
	{
		reserve(capacity * 2);
	}
	for (int i = 0; i < size; ++i)
	{
		data[i] = value[i];
	}
}
template<typename T>
MyArray<T>::MyArray(const MyArray &copy)
{
	/*size = copy.size;
	capacity = copy.capacity;
	data = new T[capacity]();
	for (int i = 0; i < size; ++i)
	{
		data[i] = copy.data[i];
	}*/
	*this = copy;
}
template<typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}
template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray &right)
{
	size = right.size;
	capacity = right.capacity;
	data = new T[capacity]();
	for (int i = 0; i < size; ++i)
	{
		data[i] = right.data[i];
	}
	return *this;
}
template<typename T>
bool MyArray<T>::operator==(const MyArray &right) const
{
	if (size != right.size)
	{
		return false;
	}
	for (int i = 0; i < size; ++i)
	{
		if (data[i] != right.data[i])
		{
			return false;
		}
	}
	return true;
}
template<typename T>
bool MyArray<T>::operator!=(const MyArray &right) const
{
	return !(*this == right);
}
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray &addend) const
{
	MyArray<T> temp1(*this);
	MyArray<T> temp2(addend);
	int i = temp1.size;
	temp1.size = temp1.size + temp2.size;
	while (temp1.size > temp1.capacity)
	{
		temp1.reserve(temp1.capacity * 2);
	}
	for (int j = 0; i < temp1.size; ++i, ++j)
	{
		temp1.data[i] = temp2.data[j];
	}
	return temp1;
}
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray &right)
{
	MyArray<T> temp(right);
	int i = size;
	size += temp.size;
	while (size > capacity)
	{
		reserve(capacity * 2);
	}
	for (int j = 0; i < size; ++i, ++j)
	{
		data[i] = temp.data[j];
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
T& MyArray<T>::at(int index)
{
	if (index > size - 1)
	{
		throw out_of_range("");
	}
	else
	{
		return data[index];
	}
}
template<typename T>
T MyArray<T>::at(int index) const
{
	if (index > size - 1)
	{
		throw out_of_range("");
	}
	else
	{
		return data[index];
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
void MyArray<T>::resize(size_t s, T item)
{
	while (s > capacity)
	{
		reserve(capacity * 2);
	}
	if (s > size)
	{
		for (int i = size; i < s; ++i)
		{
			data[i] = item;
		}
	}
	size = s;
}
template<typename T>
void MyArray<T>::reserve(size_t n)
{
	if (n > capacity)
	{
		T *temp = new T[n]();
		for (int i = 0; (i < size) && (i < n); ++i)//i<n
		{
			temp[i] = data[i];
		}
		capacity = n;
		delete[] data;
		data = temp;
	}
}
template<typename T>
void MyArray<T>::shrink_to_fit()
{
	capacity = size;
	T *temp = new T[capacity]();
	for (int i = 0; i < size; ++i)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}
template<typename T>
void MyArray<T>::clear()
{
	size = 0;
}
template<typename T>
bool MyArray<T>::isEmpty()
{
	return size == 0;
}