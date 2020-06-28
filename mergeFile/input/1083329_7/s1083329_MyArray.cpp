#include<iostream>
#include <string>
using namespace std;
#include "s1083329_MyArray.h"
#include <exception>
template<typename T>
MyArray<T>::MyArray() {
	size = 0;
	capacity = 10;
	data = new T[capacity]();
	for (int i = 0; i < capacity; i++)
	{
		data[i] = 0;
	}
}

template<typename T>
MyArray<T>::MyArray(int Size, T value) {
	size = Size;
	capacity = 10;
	while (size > capacity)capacity *= 2;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		data[i] = value;
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& newone) {
	size = newone.size;
	capacity = newone.capacity;
	data = new T[newone.capacity]();
	for (int i = 0; i < capacity; i++)
	{
		data[i] = newone.data[i];
	}
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[]data;
}

template<typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& n) {
	capacity = n.capacity;
	size = n.size;
	data = new T[n.capacity]();
	for (int i = 0; i < n.capacity; i++)
	{
		data[i] = n.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& a) const {
	if (size != a.size)return false;
	else {
		for (int i = 0; i < size; i++) {
			if (a.data[i] != data[i])return false;
		}
	}
	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const {
	return!(*this == right);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& a) const {
	MyArray b(size + a.size, 0);
	/*for (int i = 0; i < a.size; i++)
		cout << a.data[i] << endl;*/
	int j = 0;
	for (int i = 0; i < size; i++)b.data[i] = data[i];
	for (int i = size; i < b.size; i++)
	{
		//for (int j = 0; j < a.size; j++)
		b.data[i] = a.data[j];
		j++;
	}
	return b;
}

template<typename T>
MyArray<T>& MyArray<T>:: operator+=(const MyArray<T>& b) {
	int tsize = size;
	resize(size + b.size, 0);
	int j = 0;
	/*for(int i=0;i<b.size;i++)
	cout << b.data[i] << endl;*/
	for (int i = tsize; i < size; i++)
	{
		//for (int j = 0; j < b.size; j++)
		data[i] = b.data[j];
		j++;
	}
	return *this;
}

template<typename T>
T& MyArray<T>:: operator[](int subscript) {
	return data[subscript];
}

template<typename T>
T MyArray<T>::operator[](int subscript) const {
	return data[subscript];
}

template<typename T>
T& MyArray<T>::at(int a) {
	if (a >= size)throw out();
	return data[a];
}

template<typename T>
T MyArray<T>::at(int a) const {
	if (a >= size)throw out();
	return data[a];
}

template<typename T>
int MyArray<T>::getSize() const {
	return size;
}

template<typename T>
int MyArray<T>::getCapacity() const {
	return capacity;
}

template<typename T>
void MyArray<T>::resize(size_t a, T item) {
	//cout << a << endl << size << endl;
	while (a > capacity)
	{
		reserve(capacity * 2);
	}
	if (a >= size)
	{
		for (int i = size; i < a; i++)
		{
			data[i] = item;
		}
	}
	else {
		for (int i = a; i < size; i++)data[i] = 0;
	}
	size = a;
}

template<typename T>
void MyArray<T>::reserve(size_t cap) {
	if (cap > capacity)capacity = cap;
	T* temp = new T[capacity]();
	//   if (capacity > cap) {
	for (int i = 0; i < capacity; i++)temp[i] = 0;
	for (int i = 0; i < capacity; i++) {
		temp[i] = data[i];
	}
	data = temp;

	/* else {
	 for (int i = 0; i < cap; i++)temp[i] = 0;
	 for (int i = 0; i < capacity; i++) {
	 temp[i] = data[i];
	 }
	 data = temp;
	 }*/
	if (size > cap) {
		size = cap;
	}

}

template<typename T>
void MyArray<T>::shrink_to_fit() {
	T* temp = new T[size];
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	capacity = size;
	data = temp;
}

template<typename T>
void MyArray<T>::clear() {
	size = 0;
	for (int i = 0; i < capacity; i++) {
		data[i] = 0;
	}
	capacity = 10;
}

template<typename T>
bool MyArray<T>::isEmpty()const {
	if (size == 0)return true;
	else return false;
}

template<typename T>
ostream& operator<<(ostream& output, const MyArray<T>& ans)
{
	if (ans.isEmpty() == true)output << " is empty" << endl;
	for (int i = 0; i < ans.size; i++) {
		output << ans.data[i];
		output << ", ";
	}
	return output;
}

template<typename T>
istream& operator>>(istream& input, MyArray<T>& ans)
{
	string a;
	input >> a;
	int al = a.length();
	ans.resize(al, 0);
	/*cout <<"anssize = "<< ans.getSize() << endl;
	for (int i = 0; i < al ; i++)
	{
		cout << a[i] << endl;
	}*/
	for (int i = 0; i < al ; i++)
	{
		ans.data[i] = a[i];
	}	
	return input;
}