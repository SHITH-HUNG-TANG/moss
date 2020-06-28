#include "s1081420_MyArray.h"
#include<iostream>
#include <stdexcept> 
#include<stddef.h >
#define NULL 0
using namespace std;
using std::logic_error; 
using std::out_of_range;

//template <typename T>
//ostream& operator<<  (ostream& out, const MyArray<T>& right) {
//	for (int i = 0; i < right.getSize(); i++) out << right[i] << " ";
//	out << endl;
//	return out;
//}//輸出物件，中間含空格

template <typename T>
MyArray<T>::MyArray(int Capacity ) {
	size = 0;
	capacity = Capacity;
	data = new T[capacity]();
}//預設空間為capacity=10,size=0//每次空間格不夠時變成當下2倍大

template <typename T>
MyArray<T>::MyArray(size_t Size, T value) {
	size = Size;
	reserve(Size);
	data = new T[capacity]();
	for (int i = 0; i < Size; i++)data[i] = value;

}//ex.(3,5)陣列內容為3個5，value 的 type 要用template
 
  
  //Bouns->

template <typename T>
MyArray<T>::MyArray(T value[], int Size) {
	size = Size;
	reserve(Size);
	data = new T[capacity]();
	/*delete[]data;
	data = nullptr;*/
	for (int i = 0; i < Size; i++)data[i] = value[i];
}//傳入一個陣列讓陣列的內容放入Array(this)裡
 //Bouns<-

template <typename T>
MyArray<T>::MyArray(const MyArray<T> & right) {
	capacity = right.capacity;
	size = right.size;
	data = new T[capacity]();
	for (int i = 0; i < size; i++) {
		data[i] = right.data[i];
	}
}//copy constructor

template <typename T>
MyArray<T>::~MyArray() {
	size = 0;
	capacity = 0;
	delete[]data;
	data = nullptr;
}
template <typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right) {
	if (&right != this) // avoid self-assignment
	{
		if (size != right.size)
		{
			delete[]data; // release spac
			capacity = right.capacity;
			size = right.size; // resize this object
			data = new T[capacity](); // create space for array copy
		} // end inner if

		for (int i = 0; i < size; i++)
			data[i] = right.data[i]; // copy array into object
	} // end outer if
	return *this;
}//assigment operator

template <typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const {
	if (size != right.size)
		return false;
	else {
		for (int i = size - 1; i >= 0; i--) {
			if (data[i] != right.data[i])return false;
		}
		return true;
	}
}

template <typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const {
	return !(*this == right);
}

template <typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const {
	MyArray<T> sum(*this);
	size_t  newsize = this->getSize() + right.getSize();
	sum.resize(newsize,NULL);
	/*for (int i = 0; i < this->getSize(); i++) {
		buffer[i] = sum[i];
	}*/
	for (int i = this->getSize(); i < this->getSize() + right.getSize(); i++) {
		sum[i] = right[i - this->getSize()];
	}
	return sum;
}	//NEW回傳新的容器，並且原本的兩者本身值不變


template <typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right) {
	*this = *this + right;
	return *this;
}	//NEW回傳原容器修改過的結果


template<typename T>
T& MyArray<T>::operator[](int subscript) {
	if (subscript < 0 || subscript >= size) {
		cout << "Errror subscript(is [] not at)" << endl;
		exit(1);
	}
	return data[subscript];
}//可修改


template <typename T>
T MyArray<T>::operator[](int subscript) const {
	if (subscript < 0 || subscript >= size) {
		cout << "Errror subscript(is [] not at)" << endl;
		exit(1);
	}
	return data[subscript];
}//僅傳值


template <typename T>
T& MyArray<T>::at(int index) {
	try {
		if (index < 0 || index >= size)throw std::out_of_range("Error index");
		return  data[index];
	}
	catch(const std::out_of_range& oor){
		cerr << "Out of Range error: " << oor.what() << endl;
	}
}		//new。可修改，有範圍檢查之內容存取(exception)

template <typename T>
T MyArray<T>::at(int index) const {
	try {
		if (index < 0 || index >= size)throw std::out_of_range("Error index");
		return  data[index];
	}
	catch (const std::out_of_range& oor) {
		cerr << "Out of Range error: " << oor.what() << endl;
	}
}	//new。僅傳值，有範圍檢查之內容存取(exception)



template <typename T>
void MyArray<T>::resize(size_t newsize,T item) {
	if (newsize <= capacity) {
		if (newsize > size) {
			T* buffer = new T[capacity]();
			for (int i = 0; i < size; i++) {
				buffer[i] = data[i];
			}
			for (int i = size; i < newsize; i++) {
				buffer[i] = item;
			}
			delete[]data;
			data = buffer;
			size = newsize;
		}
		else {
			T* buffer = new T[capacity]();
			for (int i = 0; i < newsize; i++) {
				buffer[i] = data[i];
			}
			delete[]data;
			data = buffer;
			size = newsize;
		}
	}
	else {
		int newcap = capacity * 2;
		while (newsize > newcap)newcap *= 2;
		T* buffer = new T[newcap]();
		for (int i = 0; i < size; i++) {
			buffer[i] = data[i];
		}
		for (int i = size; i < newsize; i++) {
			buffer[i] = item;
		}
		delete[]data;
		data = buffer;
		size = newsize;
		capacity = newcap;
	}
}
template <typename T>
void  MyArray<T>::reserve(size_t newcap) {
	if (newcap <= capacity);
	else {
		while (newcap > capacity)capacity = newcap;
		T* buffer = new T[capacity]();
		for (int i = 0; i < size; i++) {
			buffer[i] = data[i];
		}
		delete[]data;
		data = buffer;
	}
}//將capacity直接變成所傳入的變數

template <typename T>
void MyArray<T>::shrink_to_fit() {
	capacity = size;
	T* buffer = new T[size];
	for (int i = 0; i < size; i++)
		buffer[i] = data[i];
	delete[] data;
	data = buffer;
}	//new。將capacity縮等於size

template <typename T>
void MyArray<T>::clear() {
	delete[]data;
	data = nullptr;
	resize(0);
}		//new。清除array內容


template <typename T>
bool MyArray<T>::isEmpty() {
	if (size != 0)return false;
	else {
		//if (data != nullptr)return false;
		return true;
	}
}	//new。檢查是否為空

//template class  MyArray<char*>;
//
template class  MyArray<int>;
template class  MyArray<char>;
template class  MyArray<string>;