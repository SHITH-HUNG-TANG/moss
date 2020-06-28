#ifndef MYARRAY_H
#define MYARRAY_H
#include<iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class

	template<typename T>friend ostream& operator<<(ostream&, const MyArray<T>&);
	template<typename T>friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int in_capacity = 10);
	MyArray(int s, T v);
	MyArray(const MyArray &);
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
	void setSize(int i);
	int getCapacity() const;
	void resize(size_t size, T item = 0);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new
	T getValue(int index);
	T getValue(int index)const;
	void setValue(int index,T value);
private:
	int size;
	int capacity;
	T* data;
};
template<typename T>
MyArray<T>::MyArray(int in_capacity) {
	capacity = in_capacity;
	size = 0;
	data = new T[capacity]();
}

template<typename T>
MyArray<T>::MyArray(int s, T v) {
	capacity = 10;
	if (s > capacity) {
		reserve(2 * capacity);
	}
	size = s;
	data = new T[capacity]();
	for (int i = 0; i < size; i++) {
		data[i] = v;
	}
}



template<typename T>
MyArray<T>::MyArray(const MyArray<T>& right) {
	capacity = right.capacity;
	size = right.size;
	data = new T[capacity]();
	for (int i = 0; i < right.size; i++) {
		data[i] = right.data[i];
	}
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[]data;
}

template<typename T>
const MyArray<T>& MyArray<T>:: operator=(const MyArray& right) {
	if (capacity < right.capacity) {
		capacity = right.capacity;
		delete[]data;
		data = new T[capacity]();
	}
	for (int i = 0; i < right.size; i++) {
		data[i] = right.data[i];
	}
	setSize(right.size);
	return *this;
}

template<typename T>
bool MyArray<T>:: operator==(const MyArray& right) const {
	if (size != right.size) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (data[i] != right.data[i]) {
				return false;
			}
		}
		return true;
	}
}

template<typename T>
bool MyArray<T>:: operator!=(const MyArray& right) const {
	if (!(*this == right)) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
MyArray<T> MyArray<T>:: operator+(const MyArray& right) const {
	MyArray b = *this;
	int k = size + right.size;
	b.reserve(k);
	b.size = k;
	for (int i = size; i < k; i++) {
		int t = 0;
		b.data[i] = right.data[t];
		t++;
	}

	return b;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& right) {
	int k = size + right.size;
	reserve(k);
	int t = size;
	size = k;
	for (int i = t; i < k; i++) {
		int t = 0;
		data[i] = right.data[t];
		t++;
	}
	return *this;
}

template<typename T>
T& MyArray<T>:: operator[](int i) {
	return data[i];
}

template<typename T>
T MyArray<T>::operator[](int i) const {
	return data[i];
}

template<typename T>
T& MyArray<T>::at(int i) {
	if (i > size) {
		throw out_of_range("index is out of range");
	}
	return data[i];
}

template<typename T>
T MyArray<T>::at(int i) const {
	if (i > size) {
		throw out_of_range("index is out of range");
	}
	return data[i];
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
void MyArray<T>::resize(size_t s, T item) {

	if (size > s) {
		for (int i = s; i < size; i++) {
			data[i] = NULL;
		}
		size = s;
	}
	else if (size == s) {
		return;
	}
	else {
		while (capacity < s) {
			reserve(2 * capacity);
		}
		for (int i = size; i < s; i++) {
			data[i] = item;
		}
		size = s;
	}
}
template<>
void MyArray<string>::resize(size_t s, string item) {

	if (size > s) {
		for (int i = s; i < size; i++) {
			data[i] = "";
		}
		size = s;
	}
	else if (size == s) {
		return;
	}
	else {
		while (capacity < s) {
			reserve(2 * capacity);
		}
		for (int i = size; i < s; i++) {
			data[i] = item;
		}
		size = s;
	}
}

template<typename T>
void MyArray<T>::reserve(size_t newcapacity) {
	T* t = new T[newcapacity]();
	for (int i = 0; i < size; i++) {
		t[i] = data[i];
	}
	delete[]data;
	data = t;
	capacity = newcapacity;
}

template<typename T>
void MyArray<T>::shrink_to_fit() {
	reserve(size);
}

template<typename T>
void MyArray<T>::clear() {
	for (int i = 0; i < size; i++) {
		data[i] = NULL;
	}
}
template<>
void MyArray<string>::clear() {
	for (int i = 0; i < size; i++) {
		data[i] = "";
	}
}

template<typename T>
bool MyArray<T>::isEmpty() {
	for (int i = 0; i < size; i++) {
		if (data[i] != NULL) {
			return false;
		}
	}
	return true;
}
template<>
bool MyArray<string>::isEmpty() {
	for (int i = 0; i < size; i++) {
		if (data[i] != "") {
			return false;
		}
	}
	return true;
}

template<typename T>
ostream& operator <<(ostream& out, const MyArray<T>& right) {
	for (int i = 0; i < right.size; i++) {
		out << right.data[i] << " ";
	}
	return out;
}
template<>
ostream& operator <<(ostream& out, const MyArray<char>& right) {
	for (int i = 0; i < right.size; i++) {
		out << right.data[i];
	}
	return out;
}
template<typename T>
istream& operator>>(istream& in, MyArray<T>& right) {
	string digit;
	getline(in, digit);
	while (right.getCapacity() < digit.length()) {
		right.reserve(2 * right.getCapacity());
	}
	right.setSize(digit.length());
	for (int i = 0; i < digit.length(); i++) {
		right.setValue(i, digit[i]);
	}
	return in;
}


template<typename T>
T MyArray<T>::getValue(int index) {
	return data[index];
}
template<typename T>
T MyArray<T>::getValue(int index)const {
	return data[index];
}

template<typename T>
void MyArray<T>::setValue(int index,T value) {
	data[index] = value;
}
template<typename T>
void MyArray<T>::setSize(int i) {
	size = i;
}


#endif // !MyArray

