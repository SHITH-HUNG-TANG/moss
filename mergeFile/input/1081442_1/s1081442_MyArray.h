#pragma once
#include<iostream>
#include<stdexcept>
using namespace std;

template <typename T>
class MyArray
{	//modify this class into a template class
	template <typename T>
	friend ostream& operator<<(ostream& output, const MyArray<T>& right);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray<T>& copy);//
	~MyArray();//

	const MyArray<T>& operator=(const MyArray<T>& right); //
	bool operator==(const MyArray<T>& right) const; //
	bool operator!=(const MyArray<T>& right) const; //
	MyArray<T> operator+(const MyArray<T>& right) const;	//new
	MyArray<T>& operator+=(const MyArray<T>& right);		//new
	T& operator[](int num);//
	T operator[](int num) const;//
	T& at(int num);		//new
	T at(int num) const;	//new

	int getSize() const;//
	int getCapacity() const;//
	void resize(size_t s, T item);
	void reserve(size_t s);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};
class outofrange :public logic_error
{
public:
	outofrange()
		:logic_error("Out Of Range ") {}
};

template<typename T>
inline MyArray<T>::MyArray(int Capacity)
{
	capacity = Capacity;
	size = 0;
	data = new T[capacity];
}

template<typename T>
inline MyArray< T>::MyArray(int Size, T value)
{
	capacity = 10;
	size = Size;
	while (size > capacity)
	{
		capacity *= 2;
	}
	data = new T[capacity]();

	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}
	
}

template<typename T>
inline MyArray<T>::MyArray(const MyArray<T>& copy)
{
	capacity = copy.capacity;
	size = copy.size;
	data = new T[size]();
	for (int i = 0; i < size; i++)
		data[i] = copy.data[i];
}

template<typename T>
inline MyArray<T>::~MyArray()
{
	delete[] data;
}

template<typename T>
inline const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right)
{
	if (&right != this)
	{
		if (size != right.size)
		{
			delete[] data;
			size = right.size;
			data = new T[size]();
		}
		for (int i = 0; i < size; i++)
			data[i] = right.data[i];
	}
	return *this;
}

template<typename T>
inline bool MyArray<T>::operator==(const MyArray<T>& right) const
{
	if (size != right.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (data[i] != right.data[i])
			return false;
	}
	return true;
}

template<typename T>
inline bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}

template<typename T>
inline MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const
{
	MyArray<T> sum;
	sum.size = size + right.size;
	sum.data = new T[sum.size]();
	for (int i = 0; i < size; i++)
	{
		sum.data[i] = data[i];
	}
	for (int i = size; i < sum.size; i++)
	{
		sum.data[i] = right.data[i - size];
	}
	return sum;
}

template<typename T>
inline MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)
{
	//data + = right.data;
	MyArray<T> passive;
	passive.data = new T[size]();

	for (int i = 0; i < size; i++)
	{
		passive.data[i] = data[i];
	}
	size = size + right.size;
	data = new T[size];
	for (int i = 0; i < size - right.size; i++)
	{
		data[i] = passive.data[i];
	}
	for (int i = size - right.size; i < size; i++)
	{
		data[i] = right.data[i - size + right.size];
	}

	return *this;
}

template<typename T>
inline T& MyArray<T>::operator[](int num)
{
	if (num < 0 || num >= size)
	{
		cout << "\nError: Subscript " << num << " Out of Range" << endl;
		exit(1);
	}
	return data[num];
}

template<typename T>
inline T MyArray<T>::operator[](int num) const
{
	if (num < 0 || num >= size)
	{
		cout << "\nError: Subscript " << num << " Out of Range" << endl;
		exit(1);
	}
	return data[num];
}

template<typename T>
inline T& MyArray<T>::at(int num)
{
	if (num < 0 || num >= size)
	{
		throw outofrange();
	}
	return data[num];
}

template<typename T>
inline T MyArray<T>::at(int num) const
{

	if (num < 0 || num >= size)
	{
		throw outofrange();
	}
	return data[num];
}

template<typename T>
inline int MyArray<T>::getSize() const
{
	return size;
}
template<typename T>
inline int MyArray<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
inline void MyArray<T>::resize(size_t s, T item)
{
	while (s > capacity)
		reserve(capacity * 2);
	if (s > size)
	{
		T* temp = new T[s]();
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		capacity = s;
		delete[] data;
		data = new T[s]();
		for (int i = 0; i < s; i++)
		{
			data[i] = temp[i];
		}
	
	}
	for (int i = size; i < s; i++)
			data[i] = item;
	size = s;
}

template<typename T>
inline void MyArray<T>::reserve(size_t s)
{
	if (s > capacity)
	{
		T* temp = new T[s]();
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		capacity = s;
		delete[] data;
		data = new T[s]();
		for (int i = 0; i < s; i++)
		{
			data[i] = temp[i];
		}
	}
}

template<typename T>
inline void MyArray<T>::shrink_to_fit()
{
	capacity = size;
}

template<typename T>
inline void MyArray<T>::clear()
{
	size = 0;
	capacity = 0;
}

template<typename T>
inline bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

template<typename T>
inline ostream& operator<<(ostream& output, const MyArray<T>& right)
{
	for (int i = 0; i < right.size; ++i)
	{
		output << right.data[i] << " ";
	}
	return output;
}
#pragma once
