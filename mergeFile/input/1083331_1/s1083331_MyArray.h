#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <exception>

using namespace std;

class Error : public exception
{
public:
	Error() :exception("out of range") {};
};

template<typename T>
class MyArray :public Error
{
	friend ostream& operator<<(ostream& out, const MyArray<T>& ans)
	{
		if (ans.isEmpty())
		{
			cout << "is empty";
			return out;
		}
		else
		{
			out << ans.ptr[0];

			for (int i = 1; i < ans.size; i++)
			{
				out << ", " << ans.ptr[i];
			}

			return out;
		}
	}

public:
	MyArray(int newcapacity = 10); //constructor
	MyArray(int newsize, T value);
	MyArray(T arr[], int length);
	MyArray(const MyArray<T>& num); // copy constructor
	~MyArray();

	const MyArray<T>& operator=(const MyArray<T>& num);
	bool operator==(const MyArray<T>& num) const;
	bool operator!=(const MyArray<T>& num) const;
	MyArray<T> operator+(const MyArray<T>& num) const;
	MyArray<T>& operator+=(const MyArray<T>& num);
	T& operator[](int i);
	T operator[](int i) const;
	T& at(int i);		//new
	T at(int i) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t newsize, T item = '\0');
	void reserve(size_t newsize);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty() const;		//new

private:
	int size = 0;
	int capacity;
	T* ptr;
};




#endif