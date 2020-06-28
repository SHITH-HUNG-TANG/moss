#pragma once
#ifndef S1083314_MYARRAY_H
#define S1083314_MYARRAY_H
#include<iostream>
#include<exception>
#include<string>
using namespace std;

class ErrorNumber :public exception {
public:
	ErrorNumber()
		:exception("Out of range exception") {};
};


template <typename T>
class MyArray :public ErrorNumber {	//modify this class into a template class

	/*template <typename Ty>
	friend ostream& operator<<(ostream& output, const Ty& right) {

		if (right.data == T()) {
			output << T();
			return output;
		}

		for (int i = 0; i < right.mySize; i++) {
			output << *(right.data + i);
		}
		return output;
	}*/

	friend istream& operator>>(istream& input, MyArray<T>& right)
	{
		string NewStr;
		input >> NewStr;
		right.resize(NewStr.length(), '/0');

		for (int i = 0; i < right.getSize(); i++) {
			right[i] = NewStr[i];
		}
		return input;
	}

	friend ostream& operator<<(ostream& output, const MyArray<T>& right) {
		/*if (right.data == T()) {
			output << T();
			return output;
		}*/

		for (unsigned int i = 0; i < right.getSize(); i++) {
			output << right[i];
		}
		return output;
	}

public:

	MyArray(int Capacity = 10)
	{
		mySize = 0;
		data = new T[Capacity]();
		myCapacity = Capacity;
	}

	MyArray(int Size, T value) {
		mySize = Size;
		myCapacity = Size;//
		data = new T[Size]();
		for (int i = 0; i < mySize; i++) {
			*(data + i) = value;
		}
	}

	MyArray(const MyArray<T>& word) {
		data = new T[word.myCapacity]();
		for (unsigned int i = 0; i < word.mySize; i++) {
			*(data + i) = *(word.data + i);
		}
		mySize = word.mySize;
		myCapacity = word.myCapacity;
	}

	~MyArray() {
		if (data != nullptr) {
			delete[]data;
		}
	}

	const MyArray<T>& operator=(const MyArray<T>& x) {
		if (this != &x) {
			T* New = new T[x.myCapacity]();
			for (int i = 0; i < x.mySize; i++) {
				*(New + i) = *(x.data + i);
			}
			if (data != nullptr)
				delete[] data;
			data = &New[0];
			mySize = x.mySize;
			myCapacity = x.myCapacity;
		}
		return *this;
	}

	bool operator==(const MyArray<T>& x) const {
		if (mySize != x.mySize)
			return false;

		for (int i = 0; i < mySize; i++) {
			if (data[i] != x.data[i])
				return false;
		}

		return true;
	}

	bool operator!=(const MyArray<T>& x) const {
		return !(*this == x);  //return false
	}

	MyArray<T> operator+(const MyArray<T>& input) const {
		MyArray<T> Sum(*this);
		int Size = mySize + input.mySize;

		Sum.resize(Size, T());

		int i = mySize;
		for (int j = 0; j < input.mySize; i++, j++)
			Sum.data[i] = input.data[j];
		return Sum;
	}

	MyArray<T>& operator+=(const MyArray<T>& input) {
		*this = *this + input;
		return *this;
	}

	T& operator[](int x) {
		return data[x];
	}

	T operator[](int x) const {
		return data[x];
	}

	T& at(unsigned int n) {
		if (n >= 0 && n < mySize)
			return data[n];
		else {
			throw ErrorNumber();
		}
	}	    //new

	T at(unsigned int n) const {
		if (n >= 0 && n < mySize) {
			return data[n];
		}
		else {
			throw ErrorNumber();
		}/**/
	}

	size_t getSize() const {
		return mySize;
	}

	size_t& getSize()  {
		return mySize;
	}/**/

	size_t getCapacity() const {
		return myCapacity;
	}

	size_t& getCapacity() {
		return myCapacity;
	}/**/

	//return number
	T*& getData() {
		return data;
	}

	//return number
	T* getData()const {
		return data;
	}

	void resize(size_t size, T value) {
		if (size > myCapacity) {
			this->reserve(size);
		}

		for (unsigned int i = mySize; i < size; i++) {
			data[i] = value;
		}
		mySize = size;
	}

	void reserve(size_t n) {
		if (myCapacity * 2 >= n) {
			myCapacity *= 2;
		}
		else {
			myCapacity = n;
		}

		T* New = new T[myCapacity]();
		for (unsigned int i = 0; i < mySize; i++) {
			New[i] = data[i];
		}
		if (data != nullptr)
			delete[]data;
		data = &New[0];
	}

	void shrink_to_fit() {

		myCapacity = mySize;

		T* New = new T[myCapacity];
		for (int i = 0; i < mySize; i++) {
			New[i] = data[i];
		}
		if (data != nullptr)
			delete[] data;
		data = &New[0];
	}	//new

	void clear() {
		mySize = 0;
		T* New = new T[myCapacity]();
		if (data != nullptr)
			delete[] data;
		data = &New[0];
	}			//new

	bool isEmpty() {

		if (mySize == 0)
			return true;

		return false;
	}		//new

private:
	size_t mySize;
	size_t myCapacity;
	T* data;
};

#endif // !MyArray
