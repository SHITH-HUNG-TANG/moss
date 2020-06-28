#pragma once
#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray& right)
	{
		for (int i = 0; i < right.size; i++)
			output << right.data[i] << " ";
		output << endl;
		return output;
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray()
	{
		size = 0;
		capacity = 10;
		data = new T[capacity]();
	}
	MyArray(int c)
	{
		size = (size <= 0) ? 0 : size;
		if (c <= 10)
			capacity = 10;
		else
			capacity = c;
		data = new T[capacity]();
	}
	MyArray(T s[], int value)
	{
		size = 0;
		int buf = size;
		data = new T[capacity]();
		resize(value ,'\0');
		for (int i = 0; i < value; i++)
			data[i + buf] = s[i];
	}
	MyArray(int s, T value)
	{
		size = 0;
		data = new T[capacity]();
		resize(s + size, value);
	}
	MyArray(const MyArray& right)
	{
		size = right.size;
		capacity = right.capacity;
		data = new T[capacity]();

		for (int i = 0; i < size; i++)
			data[i] = right.data[i];
	}
	~MyArray()
	{
		delete[] data;
	}
	
	const MyArray& operator=(const MyArray& right)
	{
		size = right.size;
		capacity = right.capacity;
		delete[] data;
		data = new T[capacity]();

		for (int i = 0; i < size; i++)
			data[i] = right.data[i];
		return *this;
	}
	bool operator==(const MyArray& right) const
	{
		if (size != right.size)
			return false;
		for (int i = 0; i < size; i++)
			if (data[i] != right.data[i])
				return false;
		return true;
	}
	bool operator!=(const MyArray& right) const
	{
		if (size == right.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] != right.data[i])
					return true;
			}
			return false;
		}
		return true;
	}
	MyArray operator+(const MyArray& right) const
	{
		MyArray temp;
		temp.size = 0;
		int buf = size;
		temp.resize((size+right.size),'\0');
		for (int i = 0; i < buf; i++)
			temp.data[i] = data[i];
		for (int i = 0; i < right.size; i++)
			temp.data[i+buf] =right.data[i];
		return temp;
	}
	MyArray& operator+=(const MyArray& right)
	{
		int buf = size;
		int temp = right.size;
		resize((size+right.size),'\0');
		for (int i = 0; i < temp; i++)
			data[i+buf] = right.data[i];
		return *this;
	}
	T& operator[](T c)
	{
		if (c < 0 || c >= size)
		{
			cerr << "\nError: Subscript" << c << "out of range" << endl;
			exit(1);
		}
		return data[c];
	}
	T operator[](T c) const
	{
		if (c < 0 || c >= size)
		{
			cerr << "\nError: Subscript" << c << "out of range" << endl;
			exit(1);
		}
		return data[c];
	}
	T& at(int place)
	{
		if (place < size)
			return data[place];
		if(place>=size)
			throw out_of_range("check range");
	}
	T at(int place) const
	{
		if (place < size)
			return data[place];
		if (place >= size)
			throw out_of_range("check range");
	}
	int getSize() const
	{
		return size;
	}
	int getCapacity() const
	{
		return capacity;
	}
	void resize(size_t s, T item)
	{
		if (size > s)
		{
			size = s;
			return;
		}
		while (s > capacity)
			reserve(capacity*2);
		if (s > size )
			for (int i = size; i < s; i++)
				data[i] = item;
		size = s;
	}
	void reserve(size_t s)
	{
		if (s > capacity)
		{
			T* temp = new T[s]();
			for (int i = 0; i < size; i++)
				temp[i] = data[i];
			capacity = s;
			delete[] data;
			data = temp;
		}
	}
	void shrink_to_fit()
	{
		capacity = size;
	}
	void clear()
	{
		size = 0;
		data = new T[capacity]();
	}
	bool isEmpty()
	{
		if ((size == 0 || size==1) && data[0] == '\0')
			return true;
		return false;
	}

protected:
	int size=0;
	int capacity=10;
	T* data;
};

//#endif // !MyArray
