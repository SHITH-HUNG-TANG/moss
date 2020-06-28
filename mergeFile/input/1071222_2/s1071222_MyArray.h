#ifndef MyArray_H
#define MyArray_H
#include<iostream>
using namespace std;

template <typename T>
class MyArray
{
	//modify this class into a template class
	friend ostream& operator<<(ostream&, const MyArray< T >&);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray< T >&);
	~MyArray();

	const MyArray< T >& operator=(const MyArray< T >&);
	bool operator==(const MyArray< T >&) const;
	bool operator!=(const MyArray< T >&) const;
	MyArray< T > operator+(const MyArray< T >&) const;	//new
	MyArray< T >& operator+=(const MyArray<T>&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, char item = ' ');
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

