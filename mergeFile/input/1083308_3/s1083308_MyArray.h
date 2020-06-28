
#ifndef MYARRAY_H
#define MYARRAY_H
#include<iostream>
using namespace std;

class Error : public exception
{
public:
	Error() :exception("out of range") {};
};
template<typename T>
class MyArray :public Error
{	//modify this class into a template class

	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);

	//friend istream& operator>>(istream&, MyArray<T>&);
public:
	MyArray(int Capacity = 10);

	MyArray(int Size, T value);

	MyArray(const MyArray<T>&);

	~MyArray();

	const MyArray<T>& operator=(const MyArray<T>&);

	bool operator==(const MyArray<T>&) const;

	bool operator!=(const MyArray<T>&) const;

	MyArray operator+(const MyArray<T>&);	//new

	MyArray& operator+=(const MyArray<T>&);		//new

	T& operator[](int);

	T operator[](int) const;

	T& at(int);		//new

	T at(int) const;	//new

	int getSize() const;

	int getCapacity() const;

	void resize(size_t Size, T item);

	void reserve(size_t Capacity);

	void shrink_to_fit();	//new

	void clear();			//new

	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};


#endif // !MyArray



