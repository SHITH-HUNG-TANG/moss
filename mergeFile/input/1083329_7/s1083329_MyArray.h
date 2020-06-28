#ifndef s1083329_MyArray_H
#define s1083329_MyArray_H
#include<iostream>
#include <string>
#include <exception>
using namespace std;

class out :public exception
{
public:
	out()
		:exception("out_of_range") {};
};

template<typename T>
class MyArray :public out {	//modify this class into a template class
	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
	friend istream& operator>><T>(istream&, MyArray<T>&);
public:
	MyArray();
	MyArray(int Size, T value);
	MyArray(const MyArray<T>&);
	~MyArray();

	MyArray& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray operator+(const MyArray<T>&) const;	//new
	MyArray& operator+=(const MyArray<T>&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item = 0);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty()const;			//new

private:
	int size;
	int capacity;
	T* data;
};

#endif // !MyArray