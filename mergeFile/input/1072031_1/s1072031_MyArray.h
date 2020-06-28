#ifndef MYARRAY_H
#define MYARRAY_H
#include<iostream>
using namespace std;
template <class T>
class MyArray {	//modify this class into a template class
	template <class T>
	friend ostream& operator<<(ostream&, const MyArray&);
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

	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(int size, T item);
	void resize(int size);
	void reserve(int size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

//private:
	int size;
	int capacity;
	T* data;
};
#endif // !MyArray

