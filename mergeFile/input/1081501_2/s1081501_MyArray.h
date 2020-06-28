#pragma once
#include<iostream>
#ifndef S1081501_MYARRAY_H
#define S1081501_MYARRAY_H
using namespace std;
template<typename T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& out, const MyArray&right)
	{
		{
			for (int i = 0; i < right.size; i++)
			{
				out << right.data[i]<<" ";
			}
			return out;
		}
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(int Size, T* value);
	MyArray(const MyArray &);
	~MyArray();
	
	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&) ;		//new
	T& operator[](int);
	T operator[](int) const;
	T at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};
#endif // !MyArray

