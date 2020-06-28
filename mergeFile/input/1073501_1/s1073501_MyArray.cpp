#include"s1073501_MyArray.h"
template< typename T >
MyArray<T>::MyArray(int c) {
	this->size = 0;
	this->capacity = 10;
	this->data = new T[c]{ NULL };
}
template<typename T>
MyArray<T>::MyArray(int Size, T value) {
	this->size = Size;
	this->capacity = 10;
	while (this->size > this->capacity) {
		capacity *= 2;
	}
	this->data = new T[capacity]{ NULL };
	for (int i = 0; i < size; i++) {
		this->data[i] = value;
	}
}

template< typename T >
MyArray<T>::MyArray(const MyArray& a) {
	this->size = a.size;
	this->capacity = a.capacity;
	this->data = new T[capacity]{ NULL };
	for (int i = 0; i < a.size; i++) {
		this->data[i] = a.data[i];
	}
}
template< typename T >
MyArray<T>::~MyArray() {
	data = NULL;
	delete[] data;
	size = 0;
	capacity = 0;
}

template< typename T >
int MyArray<T>::getSize() const {
	return size;
}
template< typename T >
int MyArray<T>::getCapacity() const {
	return capacity;
}
template< typename T >
void MyArray<T>::resize(size_t n, T c) {//可貸一個參數或兩個沒帶c就預設為0
	clear();
	while (n > capacity)
		reserve(capacity * 2);
	if (n > size) {
		for (int i = size; i < n; i++) {//超過size的職初始化
			data[i] = c;
		}
	}
	size = n;

}
template< typename T >
void MyArray<T>::reserve(size_t n) {
	if (n > capacity) {
		T* tmp = new T[n]();
		for (int i = 0; i < size; i++) {
			tmp[i] = data[i];
		}
		capacity = n;
		delete[]data;
		data = tmp;
	}
}
template<typename T>
void MyArray<T>::shrink_to_fit() {
	capacity = size;
}
template<typename T>
void MyArray<T>::clear() {
	//cout << "data is clear !"<< endl;
	size = 0;

}
template<typename T>
bool MyArray<T>::isEmpty() {
	if (size != 0) {
		cout << "data is not empty!" << endl;
		return false;
	}
	else {
		cout << "data is empty!" <<endl;
		return true;
	}
		
}
template< typename T >
int& MyArray<T>::operator[](int x)//[]中括號用於將資料進行條件篩選的指標(indexing)
{
	if (x < 0 || x >= size) {
		cout << "error"<<endl;
	}
	return this->data[x];
}
template< typename T >
int MyArray<T>::operator[](int x) const {
	/*if (x < 0 || x >= size) {
		cout << "error" << endl;
	}*/
	return this->data[x];
}

template<typename T>
T& MyArray<T>::at(int index){
	if (index > size)
		throw out_of_range(" is out of range");
	return data[index];
}

template<typename T>
T MyArray<T>::at(int index) const{
	if (index > size) 
		throw out_of_range(" is out of range ! ");
	
	return data[index];
	
	
}


template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray&x) {
	this->size = x.size;
	this->capacity = x.capacity;
	data = NULL;
	delete[] data;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		this->data[i] = x.data[i];
	}

	return *this;
}

template< typename T >
bool MyArray<T>::operator==(const MyArray& x)const {
	if (this->size != x.size) {
		return false;
	}
	else {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i] != x.data[i]) {
				return false;
			}
			return true;
		}
	}
}
template< typename T >
bool MyArray<T>::operator!=(const MyArray& x) const {
	return !(*this == x);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray &obj) const {
	MyArray tmp;
	tmp.size = this->size + obj.size;
	cout << "tmp size:" << tmp.size << endl;;
	tmp.resize(tmp.size,0);
	for (int i = 0; i < this->size; i++) {
		tmp.data[i] = this->data[i];
	}
	for (int j = this->size; j < tmp.size; j++) {
		tmp.data[j] = obj.data[j - size];	//Tmp.data[obj.size］=obj.data[0]
	}
		return tmp;
}
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& obj){
	MyArray tmp;
	int s = this->size;
	tmp.size = s+ obj.size;
	tmp.resize(tmp.size, 0);
	cout << "tmp size:" << tmp.size << endl;
	for (int i = 0; i < this->size; i++) {
		tmp.data[i] = this->data[i];
	}
	for (int j = this->size; j < tmp.size; j++) {
		tmp.data[j] = obj.data[j - size];
	}
	//cout << "tmp:" << tmp;
	*this = tmp;
	return *this;

}
