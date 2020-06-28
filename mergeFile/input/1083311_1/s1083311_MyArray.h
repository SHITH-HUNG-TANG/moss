#pragma once 
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MyArray
{
	friend ostream& operator<<(ostream& output, const MyArray<T>& right)
	{
		for (int i = 0; i < right.size; i++)
			output << right.data[i] << " ";
		return output;
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int cap);
	MyArray(int space, T value);
	MyArray();
	MyArray(const MyArray<T>& arrayToCopy);
	~MyArray();

	const MyArray<T>& operator=(const MyArray<T>& right);
	bool operator==(const MyArray<T>& right) const;
	bool operator!=(const MyArray<T>& right) const;
	MyArray<T> operator+(const MyArray<T>& right) const;
	MyArray<T>& operator+=(const MyArray<T>& right);
	T& operator[](int subscript);
	T operator[](int subscript) const;
	T& at(int subscript);
	T at(int subscript) const;

	int getSize() const;
	int getCapacity() const;
	void resize(size_t n, T item);
	void reserve(size_t n);
	void shrink_to_fit();
	void clear();
	bool isEmpty();

private:
	int size;
	int capacity;
	T* data;
};
class outOfRange :public logic_error
{
public:
	outOfRange()
		:logic_error(" subscript out of range. ") {}

};
