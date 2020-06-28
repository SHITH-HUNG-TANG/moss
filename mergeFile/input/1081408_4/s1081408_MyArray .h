#include<iostream>
#include<string>
#include<stdexcept>
#include<algorithm>
using namespace std;
#ifndef S1081408_MYARRAY_H
#define S1081408_MYARRAY_H

template<typename T>
class MyArray {	//modify this class into a template class
public:
	MyArray(int = 10);
	MyArray(int, const T&);
	MyArray(const MyArray&);
	~MyArray();
	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray<T>&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	int& operator[](int);
	int operator[](int) const;
	T at(int);		    //new
	T at(int) const;	//new
	int getSize() const;
	int getCapacity() const;
	void resize(size_t, T);
	void reserve(size_t);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new
	MyArray arr(T[], int);
private:
	int size;
	int capacity = 10;
	T* data=new T[capacity]();
};
#endif // !s1081408_MyArray_h

template<typename T>
ostream& operator<<(ostream& output, const MyArray<T>& N) {
	for (int i = 0; i < N.getSize(); i++) {
		if (i != N.getSize() - 1) output << N.at(i) << " ";
		else output << N.at(i);
	}
	return output;
}

template<typename T>
MyArray<T>::MyArray(int newcapacity)
{
	if (newcapacity <= 10) capacity = 10;
	else capacity = newcapacity;
	size = 0;
	data = new T[capacity]();
}

template<typename T>
MyArray<T>::MyArray(int newsize, const T& value)
{
	size = newsize;
	data = new T[size]();
	for (int i = 0; i < size; i++)data[i] = value;
	while (capacity < newsize)reserve(capacity * 2);
	data = new T[capacity]();
	for (int i = 0; i < size; i++)data[i] = value;
}

template<typename T>
MyArray<T>::MyArray(const MyArray& arraytocopy)
	:size(arraytocopy.size), capacity(arraytocopy.capacity)
{
	T* buffer = new T[capacity]();
	for (int i = 0; i < size; i++) buffer[i] = arraytocopy.data[i];
	data = buffer;
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[]data;
}


template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray& N) {
	if (N != *this) {
		delete[]data;
		size = N.size;
		capacity = N.capacity;
		data = new T[capacity]();
		for (int i = 0; i < size; i++)data[i] = N.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& N)const {
	if (size != N.size)return false;
	for (int i = 0; i < size; i++) {
		if (data[i] != N.data[i])return false;
	}
	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray& N)const {
	if (size != N.size)return true;
	else {
		for (int i = 0; i < size; i++) {
			if (data[i] == N.data[i] && i < size - 1) continue;
			else if (data[i] != N.data[i])return false;
			else if (data[i] == N.data[i] && i == size - 1) return true;
		}
	}
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray& N)const {
	MyArray t;
	t.size = size;
	t.capacity = capacity;
	t.data = new T[t.capacity]();
	for (int i = 0; i < size; i++) {
		t.data[i] = data[i];
	}
	t.resize(t.size + N.size, NULL);
	for (int j = size, k = 0; j < size + N.size; j++, k++) {
		t.data[j] = N.data[k];
	}
	return t;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& N) {
	resize(size + N.size, NULL);
	for (int j = size - N.size, k = 0; j < size; j++, k++)data[j] = N.data[k];
	return *this;
}

template<typename T>
int& MyArray<T>::operator[](int subscript) {  //§ï­È
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit(1);
	}
	return data[subscript];
}

template<typename T>
int MyArray<T>::operator[](int subscript)const { //¦^¶Ç­È
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T MyArray<T>::at(int index) {
	out_of_range e("    *Out of range error.");
	if (index >= size || index < 0)throw e;
	else return data[index];
}

template<typename T>
T MyArray<T>::at(int index)const {
	out_of_range e("    *Out of range error.");
	if (index >= size || index < 0)throw e;
	else return data[index];
}

template<typename T>
int MyArray<T>::getSize() const { return size; }

template<typename T>
int MyArray<T>::getCapacity() const { return capacity; }

template<typename T>
void MyArray<T>::resize(size_t newsize, T a) {
	while (newsize > capacity)reserve(capacity * 2);
	if (newsize > size) {
		for (int i = size; i < newsize; i++) data[i] = a;
	}
	size = newsize;
}

template<typename T>
void MyArray<T>::reserve(size_t newcap) {
	if (size > newcap) {
		T* buffer = new T[size]();
		for (int i = 0; i < size; i++)buffer[i] = data[i];
		capacity = newcap;
		data = buffer;
	}else {
		T* buffer = new T[newcap]();
		for (int i = 0; i < size; i++)buffer[i] = data[i];
		capacity = newcap;
		data = buffer;
	}

}

template<typename T>
void MyArray<T>::shrink_to_fit() {
	capacity = size;
	T* buffer;
	buffer = data;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)data[i] = buffer[i];
}


template<typename T>
void MyArray<T>::clear() {
	size = 0;
}

template<typename T>
bool MyArray<T>::isEmpty() {
	if (size == 0)return true;
	else return false;
}

template<typename T>
MyArray<T> MyArray<T>::arr(T x[], int length) {
	MyArray y;
	sort(x, x + length);
	y.size = length;
	while (y.capacity < y.size)y.capacity *= 2;
	y.data = new T[y.capacity]();
	for (int i = 0; i < y.size; i++)y.data[i] = x[i];
	return y;
}