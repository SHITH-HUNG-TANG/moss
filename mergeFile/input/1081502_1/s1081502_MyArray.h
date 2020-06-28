#pragma once
#ifndef S1081502_MYARRAY_H
#define S1081502_MYARRAY_H
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray& a)
	{
		int max = a.size;
		for (int i = 0; i < max; i++)
		{
			output << a.ptr[i] << " ";
		}
		return output;
	}
	friend istream& operator>>(istream& input, MyArray& a)
	{
		string str;
		getline(input, str);
		a.resize(str.size(), '\0');
		while (a.getSize() > a.getCapacity())
		{
			a.reserve(a.getCapacity() * 2);
		}
		for (int i = 0; i < a.getSize(); i++)
		{
			a[i] = str[i];
		}
		return input;
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(T* value, int Size);
	MyArray(const MyArray&);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item = '\0');
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* ptr;
};
#endif // !MyArray
