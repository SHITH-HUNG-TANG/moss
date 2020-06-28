#pragma once
#include<iostream>
#include<exception>
using namespace std;

template<typename T>
class MyArray{	//modify this class into a template class
	template<typename T>
	friend ostream& operator<<(ostream&output,const MyArray<T>&right);
	/*friend istream& operator>>(istream&input, MyArray<T>&right);*/
public:
	MyArray(int Capacity = 10);
	MyArray(T*, int);
	MyArray(int Size, T value);

	MyArray(const MyArray&);
	~MyArray();
	
	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&) ;		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t newsize, T item);
	void reserve(size_t newcap);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};
template<typename T>
MyArray<T> ::MyArray(int Capacity) {
	data = new T[10];
	capacity = 10;
	size = 0;
}
template<typename T>
MyArray<T> ::MyArray(T*arr, int Size) {

	size = Size;
	capacity = 10;
	data = new T[10];
	for (int i = 0;i < Size;i++)
		data[i] = arr[i];
}
template<typename T>
MyArray<T> ::MyArray(int Size, T value) {
	capacity = 10;
	if (Size > 10)
		capacity = Size;
	data = new T[capacity];
	for (int i = 0;i < Size;i++)
		data[i] = value;
}
template<typename T>
MyArray<T> ::MyArray(const MyArray&right) {
	capacity = right.getCapacity();
	size = right.getSize();
	data = new T[capacity];
	for (int i = 0;i < size;i++) {
		data[i] = right[i];
	}
}
template<typename T>
MyArray<T> ::~MyArray() {
	delete[]data;
}
template<typename T>
const MyArray<T>& MyArray<T> :: operator=(const MyArray&right)
{
	capacity = right.getCapacity();
	size = right.getSize();
	delete[]this->data;
	data = new T[capacity];
	for (int i = 0;i < size;i++) {
		data[i] = right[i];
	}
	return*this;
}
template<typename T>
bool MyArray<T> ::operator==(const MyArray&right)const
{
	if (size != right.getSize())
		return false;
	if (capacity != right.getCapacity())
		return false;
	for (int i = 0;i < size;i++)
		if (data[i] != right[i])
			return false;
	return true;

}
template<typename T>
bool MyArray<T> :: operator!=(const MyArray&right) const
{
	return !(*this == right);
}
template<typename T>
MyArray<T> MyArray<T> ::operator+(const MyArray&right) const
{
	MyArray<T> sum(10);
	sum.resize(size + right.getSize(), 0);
	for (int i = 0;i < size;i++)
		sum[i] = data[i];
	for (int i = size, j = 0;j < right.getSize();i++, j++)
		sum[i] = right[j];
	return sum;

}
template<typename T>
MyArray<T>&MyArray<T>::operator+=(const MyArray&right)
{
	int tmpsize = getSize();
	resize(getSize() + right.getSize(), 0);
	for (int i = tmpsize, j = 0;j < right.getSize();i++, j++)
		data[i] = right[j];
	return*this;
}
template<typename T>
T& MyArray<T>::operator[](int pos)
{
	return data[pos];
}
template<typename T>
T MyArray<T> :: operator[](int pos) const
{
	return data[pos];
}
template<typename T>
T& MyArray<T> ::at(int pos)
{

	if (pos < 0 || pos >= size) {
		throw"out of range!!";
	}
	else {
		return data[pos];
	}


}


template<typename T>
T MyArray<T> ::at(int pos) const
{
	if (pos < 0 || pos >= size) {
		throw"out of range!!";
	}
	else {
		return data[pos];
	}
}
template<typename T>
int MyArray<T> ::getSize() const
{
	return size;
}
template<typename T>
int MyArray<T> ::getCapacity() const
{
	return capacity;
}
template<typename T>
void MyArray<T>::resize(size_t newsize, T item)
{
	if (newsize == size)
		return;
	else if (newsize < size) {
		T *tmp = new T[capacity];
		for (int i = 0;i < newsize;i++)
			tmp[i] = data[i];
		delete[]data;
		data = tmp;
	}
	else
	{
		while (newsize > capacity)
			reserve(2 * capacity);
		for (int i = size; i < newsize;i++)
			data[i] = item;
	}
	size = newsize;
}
template<typename T>
void MyArray<T>::reserve(size_t newcap)
{
	if (newcap <= capacity)
		return;
	T*tmp = new T[newcap];
	for (int i = 0;i < size;i++)
		tmp[i] = data[i];
	delete[]data;
	data = tmp;
	capacity = newcap;
}
template<typename T>
void MyArray<T>::shrink_to_fit()
{
	if (capacity == size)
		return;
	T *tmp = new T[size];
	for (int i = 0;i < size;i++)
		tmp[i] = data[i];
	delete[]data;
	data = tmp;
	capacity = size;

}
template<typename T>
void MyArray<T>::clear() {
	delete[]data;
	data = new T[capacity];
	size = 0;
}
template<typename T>
bool MyArray<T>::isEmpty() {
	if (size == 0)
		return true;
	return false;
}
template<typename T>
ostream& operator<<(ostream&output, const MyArray<T>&right)
{
	for (int i = 0;i < right.size;i++)
	{
		output << " ";
		output << right[i];
		output << ",";
	}
	return output;
}
