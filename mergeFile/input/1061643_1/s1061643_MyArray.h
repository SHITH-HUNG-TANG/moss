#ifndef MyArray_H
#define MyArray_H
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <class T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& out, const MyArray<T>& outPoint)
	{
		for (int i = 0; i < outPoint.size; i++)
			out << outPoint.data[i];

		out << endl;

		return out;
	};
	friend istream& operator>>(istream& in, MyArray<T>& inPoint)
	{
		string input;
		in >> input;

		for (int i = 0; i < input.size(); i++)
		{
			inPoint.size += 1;
			while (inPoint.getCapacity() <= inPoint.getSize())
				inPoint.reserve(inPoint.getCapacity() * 2);
			
			inPoint.data[i] = input[i];
		}
		return in;
	};
public:
	MyArray(T arr[], int arrSize)//Bonus
	{
		capacity = 10;
		while (arrSize >= capacity)
			capacity *= 2;
		data = new T[capacity];
		size = arrSize;
		for (int i = 0; i < size; i++)
			data[i] = arr[i];
	};
	MyArray(int Capacity = 10)
	{
		capacity = (Capacity > 0) ? Capacity : 10;
		size = 0;
		data = new T[capacity];
	};
	MyArray(int Size, T value)
	{
		capacity = 10;
		while (Size >= capacity)
			capacity *= 2;
		data = new T[capacity];
		size = Size;
		for (int i = 0; i < Size; i++)
			data[i] = value;
	};
	MyArray(const MyArray<T> & a)
	{
		capacity = a.capacity;
		size = a.size;
		data = new T[capacity];
		for (int i = 0; i < a.capacity; i++)
			data[i] = a.data[i];
	};
	virtual ~MyArray()
	{
		delete[] data;
	};
	
	const MyArray<T>& operator=(const MyArray<T>& a)
	{
		delete[] data;
		capacity = a.capacity;
		size = a.size;
		data = new T[capacity];
		for (int i = 0; i < a.capacity; i++)
			data[i] = a.data[i];
		return *this;
	};
	bool operator==(const MyArray& a) const;
	bool operator!=(const MyArray& a) const;
	MyArray<T> operator+(const MyArray<T>& a) const
	{
		MyArray<T> temp;
		temp.size = getSize() + a.getSize();
		while (temp.getCapacity() <= temp.getSize())
			temp.reserve(temp.getCapacity() * 2);

		for (int i = 0; i < getSize(); i++)
			temp.data[i] = data[i];

		for (int i = getSize(); i < temp.getSize(); i++)
			temp.data[i] = a.data[i - getSize()];

		return temp;
	};	//new
	MyArray<T>& operator+=(const MyArray<T>& a)
	{
		while (getCapacity() <= getSize())
			reserve(getCapacity() * 2);

		for (int i = getSize(); i < getSize() + a.getSize(); i++)
			data[i] = a.data[i - getSize()];

		size += a.getSize();
		return *this;
	};		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t n, T item);
	void reserve(size_t n);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};

template <class T>
bool MyArray<T>::operator==(const MyArray& a) const
{
	if (capacity != a.capacity)
		return false;
	else
	{
		for (int i = 0; i < capacity; i++)
			if (data[i] != a.data[i])
				return false;

		return true;
	}
}

template <class T>
bool MyArray<T>::operator!=(const MyArray& a) const
{
	return !(*this == a);
}

template <class T>
T& MyArray<T>::operator[](int subscript)
{
	if (subscript < 0 || subscript >= capacity)
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;

	return data[subscript];
}

template <class T>
T MyArray<T>::operator[](int subscript)const
{
	if (subscript < 0 || subscript >= capacity)
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;

	return data[subscript];
}

template <class T>
int MyArray<T>::getSize()const
{
	return size;
}

template <class T>
int MyArray<T>::getCapacity()const
{
	return capacity;
}

template <class T>
void MyArray<T>::reserve(size_t n)
{
	if (n > capacity)
	{
		T *temp = new T[capacity];

		for (int i = 0; i < capacity; i++)
			temp[i] = data[i];

		delete[] data;
		data = new T[n];

		for (int i = 0; i < capacity; i++)
			data[i] = temp[i];

		delete[] temp;

		capacity = n;
	}
}

template <class T>
void MyArray<T>::resize(size_t n, T item)
{
	if (n >= capacity)
	{
		while (capacity <= n)
			reserve(capacity * 2);
		for (int i = size; i < capacity; i++)
			data[i] = item;
		size = n;
	}
	else if (n > size && n < capacity)
	{
		for (int i = size; i < n; i++)
			data[i] = item;
		size = n;
	}
	else if (n < size)
	{
		for (int i = n; i < capacity; i++)
			data[i] = '\0';
		size = n;
	}
}

template <class T>
void MyArray<T>::shrink_to_fit()
{
	T *temp = new T[capacity];

	for (int i = 0; i < capacity; i++)
		temp[i] = data[i];

	delete[] data;
	data = new T[size];

	for (int i = 0; i < size; i++)
		data[i] = temp[i];

	delete[] temp;

	capacity = size;
}

template <class T>
void MyArray<T>::clear()
{
	delete[] data;
	data = new T[capacity];
	size = 0;
}

template <class T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template <class T>
T& MyArray<T>::at(int subscript)
{
	if (subscript < 0 || subscript >= capacity)
		throw out_of_range(to_string(subscript) + " out of range");

	return data[subscript];
}

template <class T>
T MyArray<T>::at(int subscript) const
{
	if (subscript < 0 || subscript >= capacity)
		throw out_of_range(to_string(subscript) + " out of range");

	return data[subscript];
}

#endif // !MyArray