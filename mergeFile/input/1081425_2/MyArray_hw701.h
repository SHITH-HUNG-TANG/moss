#pragma once
#include<iostream>
#include <stdexcept>
using namespace std;

#ifndef MYARRAY_H
#define MYARRAY_H

template<typename T>
class MyArray;

template<typename T>
std::ostream& operator<<(std::ostream&,const MyArray<T> &);


template <typename T>
class MyArray {	//modify this class into a template class
	friend std::ostream& operator<< <>(std::ostream&,const MyArray<T> &);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
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
	int getCapacity() const;
	void resize(size_t size, T item = 0);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};

template<typename T>
ostream& operator<<(ostream& os, const MyArray<T>& arr){
	for(int i = 0 ; i < arr.getSize() ;i++){
		cout<<arr[i]<<" ";
	}
	return os;
}

template<typename T>
MyArray<T>::MyArray(int capacity){
	if(capacity > 0){
		this->capacity = capacity;
		this->size = 0;
		data = new T[capacity];
	}else{
		this->capacity = this->size = 0;
		data = nullptr;
	}
}

template<typename T>
MyArray<T>::MyArray(int size,T value){
	if(size > 0){
		this->capacity = this->size = size;
		data = new T[size];
		for(int i = 0 ; i< size ;i++){
			data[i] = value;
		}
	}else{
		this->capacity = this->size = 0;
		data = nullptr;
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray & arr2){
	this->capacity = this->size = 0;
	*this = arr2;
}

template<typename T>
MyArray<T>::~MyArray(){
	if(data != nullptr){
		delete[] data;
	}
}

template<typename T>
const MyArray<T> & MyArray<T>::operator=(const MyArray& arr2){
	this->resize(arr2.getSize());
	for(int i = 0 ; i < this->getSize() ;i++){
		this->data[i] = arr2.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& arr2) const{
	if(this->getSize() != arr2.getSize()){
		return false;
	}
	for(int i = 0 ; i < this->getSize() ;i++){
		if((*this)[i] != arr2[i]){
			return false;
		}
	}
	return true;

}

template<typename T>
bool MyArray<T>::operator!=(const MyArray& arr2) const{
	return !(*this == arr2);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& arr2) const{
	MyArray<T> tmp(this->getSize() + arr2.getSize());
	tmp.resize(this->getSize() + arr2.getSize());
	if(this->getSize() + arr2.getSize() > 0){

		int newsize = this->getSize() + arr2.getSize();
		for(int i = 0 ; i < this->getSize() ; i++){
			tmp[i] = (*this)[i];
		}
		for(int i = 0 ; i < arr2.getSize();i++){
			tmp[this->getSize() + i] = arr2[i];
		}
	}
	return tmp;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& arr2){
	if(this->getSize() + arr2.getSize() > 0){
		int newsize = this->getSize() + arr2.getSize();

		T* tmp = new T[newsize];

		for(int i = 0 ; i < this->getSize() ; i++){
			tmp[i] = (*this)[i];
		}
		for(int i = 0 ; i < arr2.getSize();i++){
			tmp[this->getSize() + i] = arr2[i];
		}

		delete[] data;
		data=tmp;
		this->size = newsize;
	}
	return *this;
}

template<typename T>
T& MyArray<T>::operator[](int index){
	return data[index];
}

template<typename T>
T MyArray<T>::operator[](int index) const{
	return data[index];
}

template<typename T>
T& MyArray<T>::at(int index){
	if(index < 0 || index >= size){
		throw std::out_of_range("List Out Of Range!");
	}
	return data[index];
}

template<typename T>
T MyArray<T>::at(int index) const{
	if(index < 0 || index >= size){
		throw std::out_of_range("List Out Of Range!");
	}
	return data[index];
}

template<typename T>
int MyArray<T>::getSize() const{
	return size;
}

template<typename T>
int MyArray<T>::getCapacity() const{
	return capacity;
}

template<typename T>
void MyArray<T>::resize(size_t size,T item){
	if(size > this->size){
		if(size > this->capacity){
			reserve(size);
		}

		for(int i = this->size ; i < size ;i++){
			data[i] = item;
		}
	}

	this->size = size;
}

template<typename T>
void MyArray<T>::reserve(size_t size){
	if(this->capacity >= size){
		return;
	}

	int newCapacity = this->capacity;
	if(newCapacity == 0){
		newCapacity = size;
	}else{
		while(newCapacity < size){
			newCapacity *= 2;
		}
	}

	T* tmp;
	tmp = new T[newCapacity];


	for(int i = 0 ; i < this->size ;i++){
		tmp[i] = data[i];
	}

	if(this->capacity > 0){
		delete[] data;
	}

	data = tmp;
	this->capacity = newCapacity;
	
}

template<typename T>
void MyArray<T>::shrink_to_fit(){
	T* tmp = new T[this->size];
	if(this->capacity > 0){
		for(int i = 0 ; i < this->size ;i++){
			tmp[i] = data[i];
		}

		delete[] data;
	}
	data = tmp;
	this->capacity = this->size;

}

template<typename T>
void MyArray<T>::clear(){
	this->size = 0;
}

template<typename T>
bool MyArray<T>::isEmpty(){
	return this->size == 0;
}

#endif // !MyArray

