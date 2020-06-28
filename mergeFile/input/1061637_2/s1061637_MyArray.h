#pragma once
#include<iostream>
using namespace std;
template<class T>
#ifndef xxxxx
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& os , const MyArray<T>& str)
	{
		{
			for (int i =0; i <str.size; i++)
				os << str.data[i];
			return os;
		}
	}
	//friend istream& operator>>(istream&, MyArray<T>&);
public:
	MyArray(size_t Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray<T>&);
	~MyArray();

	const MyArray<T>& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray<T> operator+(const MyArray<T>&);
	//MyArray<T> operator+(const MyArray<T>& right);
	const MyArray<T>& operator+=(const MyArray<T>&);//new
	
	T& operator[](int);
	const T operator[](int) const;//¤£À´
	T& at(int);		//new
	const T& at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

protected:
	int size;
	int capacity;
	T* data;
};
#endif // !MyArray
