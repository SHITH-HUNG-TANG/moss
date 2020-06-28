#pragma once
#include<iostream>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& os, const MyArray<T>& send) {
		for (int i = 0; i < send.size; i++) {
			cout << send.data[i];
			if (i != send.size)
				cout << ' ';
		}
		return os;
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray<T>&);
	~MyArray();

	const MyArray<T>& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray<T> operator+(const MyArray<T>&) const;	//new
	MyArray<T>& operator+=(const MyArray<T>&);		//new
	T & operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	//void resize(int item);
	void resize(size_t Sendsize, T item);
	void reserve(size_t Sendsize);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};

class wrongRange :public logic_error
{
public:
	wrongRange()
		:logic_error(" subscript out of range. ") {}

};