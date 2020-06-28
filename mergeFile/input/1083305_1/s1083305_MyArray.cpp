#include"s1083305_MyArray.h"
using namespace std;

template<typename T>
MyArray<T>::MyArray(int Capacity)
{
	size = 0;
	capacity = Capacity;
	data = new T [capacity];
}

template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	size = Size;
	capacity = 10;
	while (capacity < size)
		capacity *= 2;
	data = new T [capacity];
	for (int i = 0; i < Size; i++) {
		data[i] = value;
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& n)
{
	size = n.size;
	capacity = n.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = n.data[i];
	}
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[] data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& send)
{
	if (*this == send)
		return *this;
	size = send.size;
	capacity = send.capacity;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = send.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& send) const
{
	if (size != send.size)
		return false;
	if (capacity != send.capacity)
		return false;
	for (int i = 0; i < size; i++) {
		if (data[i] != send.data[i])
			return false;
	}
	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& send) const
{
	if (*this == send)
		return false;
	else
		return true;
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& send) const
{
	MyArray<T> ans(100);
	ans.size = size + send.size;
	ans.capacity = (capacity < send.capacity) ? send.capacity : capacity;
	while (ans.capacity < ans.size)
		ans.capacity *= 2;
	delete[] ans.data;
	ans.data = new T[ans.capacity];
	for (int i = 0; i < ans.size; i++) {
		ans.data[i] = (i < size) ? data[i] : send.data[i - size];
	}
	return ans;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& send)
{
	int a = size;
	size += send.size;
	if (capacity < send.capacity)
		capacity = send.capacity;
	while (capacity < size)
		capacity *= 2;
	reserve(capacity);
	for (int i = 0; i < send.size; i++) {  //還沒思考清楚
		data[i + a] = send.data[i];
	}
	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int subscript)
{
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript << " out of range\n";
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T MyArray<T>::operator[](int subscript) const
{
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript << " out of range\n";
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T& MyArray<T>::at(int subscript)
{
	if (subscript < 0 || subscript >= size) {
		//throw wrongRange();
		cerr << "\nError: Subscript " << subscript << " out of range\n";
		exit(1);
	}
	else
		return data[subscript];
}

template<typename T>
T MyArray<T>::at(int subscript) const
{
	if (subscript < 0 || subscript >= size) {
		//throw wrongRange();
		cerr << "\nError: Subscript " << subscript << " out of range\n";
		exit(1);
	}
	else
		return data[subscript];
}

template<typename T>
int MyArray<T>::getSize() const
{
	return size;
}

template<typename T>
int MyArray<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void MyArray<T>::resize(size_t Sendsize, T item)
{
	int oldsize = size;
	MyArray<T> tem = *this;
	if (size > Sendsize) {
		size = Sendsize;
		delete[] data;
		data = new T[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = tem.data[i];
		}
	}
	else { // size < 輸入值
		while (capacity < Sendsize) {
			capacity *= 2;
		}
		delete[] data;
		data = new T[capacity];
		size = Sendsize;
		for (int i = 0; i < size; i++) {
			if (i < oldsize)
				data[i] = tem.data[i];
			else
				data[i] = item;
		}
	}
}

template<typename T>
void MyArray<T>::reserve(size_t Sendcapacity)
{
	MyArray<T> tem = *this;
	capacity = Sendcapacity;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = tem.data[i];
	}
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	MyArray<T> tem = *this;
	if (capacity > size)
		capacity = size;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = tem.data[i];
	}
}

template<typename T>
void MyArray<T>::clear()
{
	size = 0;
	delete[] data;
	data = new T[capacity];
}

template<typename T>
bool MyArray<T>::isEmpty() //
{
	if (size == 0)
		return true;
	else
		return false;
}

template class MyArray<char>;
template class MyArray<int>;
template class MyArray<string>;