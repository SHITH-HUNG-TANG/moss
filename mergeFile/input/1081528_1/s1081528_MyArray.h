#pragma once
#ifndef MYARRAY_H
#define MYARRAY_H

#include<iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& out, const MyArray& arr)
	{
		out << arr.data[0];
		for (int i = 1; i < arr.size; i++) {
			out << " " << arr.data[i];
		}
		return out;
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10)
	{
		size = 0;
		capacity = (Capacity > 0 ? Capacity : 10);
		data = new T[capacity]();
	}

	MyArray(int Size, T value)
	{
		capacity = 10;
		data = new T[capacity]();
		if (Size > size) {
			while (Size + 1 > capacity) {
				reserve(capacity * 2);
			}
			for (int i = 0; i < Size; i++) {
				data[i] = value;
			}
		}
		size = Size;
	}

	MyArray(const MyArray& arr)
	{
		size = arr.size;
		capacity = arr.capacity;
		data = new T[arr.capacity]();
		while (arr.size + 1 > capacity) {
			reserve(capacity * 2);
		}
		for (int i = 0; i < arr.size; i++) {
			data[i] = arr.data[i];
		}
	}

	~MyArray()
	{
		delete[] data;
	}
	
	const MyArray& operator=(const MyArray& right)
	{
		if (this != &right) {
			if (size != right.size) {
				delete[] data;
				size = right.size;
				data = new T[capacity]();
			}
			while (size + 1 > capacity) {
				reserve(capacity * 2);
			}
			for (int i = 0; i < size; i++) {
				data[i] = right.data[i];
			}
		}
		return *this;
	}

	bool operator==(const MyArray& right) const
	{
		if (size != right.size) {
			return false;
		}
		for (int i = 0; i < size; i++) {
			if (data[i] != right.data[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const MyArray& right) const
	{
		return !(*this == right);
	}

	MyArray operator+(const MyArray& right) const
	{
		MyArray temp;
		temp.resize(size + right.size, 0);
		for (int i = 0; i < size; i++) {
			temp.data[i] = data[i];
		}
		for (int i = size, j = 0; i < size + right.size, j < right.size; i++, j++) {
			temp.data[i] = right.data[j];
		}
		return temp;
	}

	MyArray& operator+=(const MyArray& right)
	{
		MyArray temp;
		temp = (*this) + right;
		(*this) = temp;
		return *this;
	}

	T& operator[](int n)
	{
		if (n < 0 || n >= capacity) {
			exit(1);
		}
		return data[n];
	}

	T operator[](int n) const
	{
		if (n < 0 || n >= capacity) {
			exit(1);
		}
		return data[n];
	}
	T& at(int n)
	{
		if (n > size - 1) {
			throw out_of_range("Out of range!!");
		}
		else {
			return data[n];
		}
	}

	T at(int n) const
	{
		if (n > size - 1) {
			throw out_of_range("Out of range!!");
		}
		else {
			return data[n];
		}
	}

	int getSize() const
	{
		return size;
	}

	int getCapacity() const
	{
		return capacity;
	}

	void resize(size_t n, T item)
	{
		while (n + 1 > capacity) {
			reserve(capacity * 2);
		}
		if (n > size) {
			for (int i = size; i < n; i++) {
				data[i] = item;
			}
		}
		else {
			for (int i = size; i < capacity; i++) {
				data[i] = 0;
			}
		}
		size = n;
	}

	void reserve(size_t n)
	{
		MyArray temp;
		delete[] temp.data;
		if (n > capacity) {
			temp.capacity = n;
		}
		else {
			temp.capacity = capacity;
		}
		temp.data = new T[temp.capacity]();
		temp.size = size;
		for (int i = 0; i < capacity; i++) {
			temp.data[i] = data[i];
		}
		capacity = temp.capacity;
		delete[] data;
		data = new T[capacity]();
		(*this) = temp;
	}

	void shrink_to_fit()
	{
		MyArray temp;
		delete[] temp.data;
		capacity = size;
		temp.capacity = size;
		temp.size = size;
		temp.data = new T[temp.capacity]();
		for (int i = 0; i < size; i++) {
			temp.data[i] = data[i];
		}
		delete[] data;
		data = new T[capacity]();
		(*this) = temp;
	}

	void clear()
	{
		MyArray temp;
		delete[] temp.data;
		temp.capacity = capacity;
		temp.size = 0;
		temp.data = new T[temp.capacity]();
		*this = temp;
	}

	bool isEmpty()
	{
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	int size;
	int capacity;
	T* data;
};
#endif // !MYARRAY_H

