#ifndef MYARRAY_H
#define MYARRAY_H
#include<iostream>
#include<string>
using namespace std;


template<typename T>
class MyArray {


	
public:
	template<typename M>
	friend ostream& operator<<(ostream&, const MyArray<M>& david);
	template<typename A>

	friend istream& operator>>(istream&, MyArray<A>&);
		MyArray(int Capacity=10 );
		MyArray(int Size, T value);
		~MyArray();
		MyArray(const MyArray&);
		
		const MyArray& operator=(const MyArray&);
		bool operator==(const MyArray&)const;
		bool operator!=(const MyArray&)const;
		MyArray<T> operator+(const MyArray<T>&) const;	//new
		MyArray<T>& operator+=(const MyArray<T>&);		//new

		int getSize()const;
		T& at(int);		//new
		T at(int) const;	//new
		int getCapacity()const;
		void resize(size_t,T);
		void reserve(size_t);
		void shrink_to_fit();	//new
		void clear();			//new
		bool isEmpty();
		T operator[](T)const;
		T& operator[](T);

protected:

		int size;
		int capacity;
		T* ptr;


};
template<typename T>
MyArray<T>::MyArray(int x, T y) {
	
	capacity = 10;
	if (x >= capacity) {
		capacity = capacity * 2;
	}
	size = x;
	ptr = new T[capacity];
	for (int i = 0;i < size;i++) {
		ptr[i] = y;
	}
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[]ptr;
}

template<typename T>
MyArray<T>::MyArray(int incapacity) {
	if (incapacity < 10)
		capacity = 10;
	
	else
		capacity = incapacity;
	ptr = new T[capacity];
	size = 0;
	
}

template<typename T>
MyArray<T>::MyArray(const MyArray& d) {

	size = d.size;
	capacity = d.capacity;
	ptr = new T[size];
	for (int i = 0;i < size;i++) {
		ptr[i] = d.ptr[i];
	}

}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray& d) {
	size = d.size;
	capacity = d.capacity;
	delete[]ptr;
	ptr = new T[capacity];
	for (int i = 0;i < size;i++) {
		ptr[i] = d.ptr[i];
	}
	return *this;

}
template<typename T>
bool MyArray<T>::operator==(const MyArray& d)const {
	if (size != d.size)
		return false;
	else {
		for (int i = 0;i < size;i++) {
			if (ptr[i] != d[i])
				return false;
		}
		return true;

	}

}

template<typename T>
bool MyArray<T>::operator!=(const MyArray& d)const {
	return !(*this == d);
}


template<typename T>
int MyArray<T>::getSize()const {

	return size;

}
template<typename T>

int MyArray<T>::getCapacity()const {

	return capacity;

}
template<typename T>
T MyArray<T>::operator[](T a)const {

	return ptr[a];

}
template<typename T>
T& MyArray<T>::operator[](T a) {

	return ptr[a];
}
template<typename T>
void MyArray<T>::resize(size_t n, T c) {

	int x;
	x = capacity;
	while (n > x) {
		x = x * 2;
	}
	reserve(x);
	if (n > size) {
		for (int i = size;i < n;i++) {
			ptr[i] = c;
		}

	}
	size = n;
}
template<typename T>
void MyArray<T>::reserve(size_t incapacity) {

	if (incapacity > capacity) {
		T* temp = new T[incapacity]();
		for (int i = 0;i < size;i++) {
			temp[i] = ptr[i];
		}
		capacity = incapacity;

		delete[]ptr;
		ptr = temp;
	}

}
template<typename T>
void MyArray<T>::shrink_to_fit() {
	capacity = size;
}
template<typename T>
void MyArray<T>::clear() {
	for (int i = 0;i < size;i++) {
		ptr[i] = NULL;
	}
	size = 0;
	capacity = 10;
}
template<typename T>
bool MyArray<T>::isEmpty() {
	for (int i = 0;i < size;i++) {
		if (ptr[i] != NULL) {
			return false;
			break;
		}
	}
	return true;
}
template<typename T>
T MyArray<T>::at(int x)const {

	return ptr[x];
}
template<typename T>
T& MyArray<T>::at(int x) {
	
	if (x >= size) {
		cout << "error" << endl;
	}

	return ptr[x];
}
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>&d) const {
	
	
	MyArray<T> sum;
	sum.size = size + d.size;
	while (sum.capacity < sum.size)
		sum.capacity = sum.capacity * 2;
	
	sum.ptr = new T[sum.capacity];
	for (int i = 0;i < size;i++) {
		sum.ptr[i] = ptr[i];
	}
	
	for (int i = 0;i < d.size;i++) {
		sum.ptr[i + size] = d.ptr[i];
	}
	return sum;

};
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& d) {
	
	int x = size;
	size += d.size;
	while (size > capacity)
		capacity = capacity * 2;
	T* temp = new T[x];
	for (int i = 0;i < x;i++) {
		temp[i] = ptr[i];
	}

	delete[] ptr;
	ptr = new T[capacity];
	for (int i = 0;i < x;i++) {
		ptr[i] = temp[i];
	}
	for (int i = x;i < size;i++) {
		ptr[i] = d.ptr[i-x];
	}
	return *this;

}

template<typename T>
ostream& operator<<(ostream& output, const MyArray<T>& david) {

	for (int i = 0;i < david.size;i++) {
		output << david.ptr[i] << " ";
	}
	return output;
}
template<typename T>
istream& operator >>(istream& input, MyArray<T>& david) {

	string x;
	getline(input, x);
	david.size = x.size();
	while (david.size > david.capacity)
		david.capacity = david.capacity * 2;
	david.ptr = new char[david.capacity];

	for (int i = 0;i < david.size;i++) {
		david.ptr[i] = x[i];
	}

	return input;
}
#endif

