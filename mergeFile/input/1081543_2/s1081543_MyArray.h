#pragma once

#ifndef S1081543_MYARRAY_H

#define S1081543_MYARRAY_H

#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>

using namespace std;

template<typename T>
class MyArray
{	//modify this class into a template class
	friend ostream& operator<<(ostream& out, const MyArray<T>& num)
	{
		for (int i = 0; i < num.size; i++)
		{
			cout << num.data[i] << " ";
		}

		return out;
	}

	/*friend istream& operator>>(istream& in, MyArray& right)
	{
		string s;

		in >> s;

		right.resize(s.size(),'0');

		if (right.getSize() > right.getCapacity())
		{
			right.reserve(right.getCapacity() * 2);
		}

		for (int i = 0; i < right.getSize(); i++)
		{
			right[i] = s.begin();
			s.erase(s.begin());
		}
	}*/
public:
	MyArray(int Capacity = 10);

	MyArray(int Size, T value); //new

	MyArray(const MyArray<T>&);

	MyArray(int Size, T* value);

	~MyArray();

	
	const MyArray& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray operator+(const MyArray<T>&) const;	//new
	MyArray& operator+=(const MyArray<T>&) ;		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
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
	T *data;
};
#endif // !MyArray


