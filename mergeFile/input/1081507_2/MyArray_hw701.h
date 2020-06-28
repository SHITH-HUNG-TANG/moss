#pragma once 
#include<iostream> 
#include<stdexcept>
#include<exception>
using namespace std;/*
class out_of_range : public logic_error {
public:
	out_of_range() :logic_error("a") {}
};*/
template<typename T>
class MyArray { //modify this class into a template class 
	//template<typename T>
	friend ostream& operator<<(ostream& output, const MyArray<T>& a) {
		for (int i =0; i < a.size ; i++)
		{
			output <<a.data[i];
			if (i != a.size-1) output << ",";
		}
		output << endl;
		return output;
	}
	friend istream& operator>>(istream&, MyArray<T>&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray &);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray<T> operator+(const MyArray<T>&) const; //new 
	MyArray<T>& operator+=(const MyArray<T>&);  //new 
	T& operator[](int);
	T operator[](int) const;
	T& at(int);  //new 
	T at(int) const; //new 

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit(); //new 
	void clear();   //new 
	bool isEmpty();   //new 

private:
	int size;
	int capacity;
	T* data;
};
template<typename T>
MyArray<T>::MyArray(int Capacity)
	:size(0)
{
	capacity = Capacity;
	data = new T[capacity]{ 0 };
}
template<typename T>
MyArray<T>::MyArray(int Size, T value)
	:capacity(10)
{
	size = Size;
	while (size > capacity)capacity *= 2;

	data = new T[capacity]{ 0 };
	for (int i = 0; i < size; i++)
		data[i] = value;
}
template<typename T>
MyArray<T>::MyArray(const MyArray &arrayToCopy)
	: size(arrayToCopy.size)
	, capacity(arrayToCopy.capacity)
{
	data = new T[capacity]{ 0 };
	for (int i = 0; i < size; i++)
		data[i] = arrayToCopy.data[i];
}
template<typename T>
MyArray<T>::~MyArray()
{
	delete[]data;
}
template<typename T>
void MyArray<T>::reserve(size_t n)
{
	if (n > capacity) {
		T*temp = new T[n]{ 0 };
		for (int i = 0; i < n; i++)
			temp[i] = data[i];
		capacity = n;

		delete[] data;
		data = temp;
	}
}
template<typename T>
void MyArray<T>::resize(size_t n, T item)
{
	if (n < size)
		for (size_t i = n; i < size; i++)
			data[i] = 0;

	while (n > capacity)
		reserve(capacity * 2);

	if (n > size)
		for (size_t i = size; i < n; i++)
			data[i] = item;

	size = n;
}
template<typename T>
int MyArray<T>::getSize() const
{
	return size;
}
template<typename T>
int MyArray<T>::getCapacity()const
{
	return capacity;
}
template<typename T>
T &MyArray<T>::operator[](int subscript)
{
	return data[subscript];
}
template<typename T>
T MyArray<T>::operator[](int subscript)const
{
	return data[subscript];
}
template<typename T>
const MyArray<T>&MyArray<T>::operator=(const MyArray &right)
{
	if (&right != this) {
		if (size != right.size) {
			delete[]data;
			size = right.size;
			capacity = right.capacity;
			data = new T[size]{ 0 };
		}
		for (int i = 0; i < size; i++)
			data[i] = right.data[i];
	}
	return *this;
}
template<typename T>
bool MyArray<T>::operator==(const MyArray &right)const
{
	if (size != right.size)
		return false;

	for (int i = 0; i < size; i++)
		if (data[i] != right.data[i])return false;

	return true;
}
template<typename T>
istream &operator>>(istream &input, MyArray<T>& a)
{
	string num;
	input >> num;

	if (num[0] == '-')
		num = num.substr(1);

	a.resize(num.size());

	int pos = 0;
	while (num.size() > 1)
	{
		a[pos++] = stoi(num.substr(num.size() - 1));
		num = num.substr(0, num.size() - 1);
	}
	a[pos] = stoi(num);

	return input;
}
template<typename T>
bool MyArray<T>::operator!=(const MyArray& right) const
{
	return !(*this == right);
}

template<typename T>
void MyArray<T>::shrink_to_fit() {
	T *buffer = new T[size]{ 0 };
	for (int i = 0; i < size; i++)
		buffer[i] = data[i];
	capacity = size;

	delete[] data;
	data = buffer;
}
template<typename T>
void MyArray<T>::clear() {
	for (int i = 0; i < this->size; i++)
		data[i] = 0;
}
template<typename T>
T& MyArray<T>::at(int i) {
	if (i < 0 || i >= size) { throw out_of_range("out_of_range()"); }
	shrink_to_fit();
	return data[i];
}
template<typename T>
T MyArray<T>::at(int i)const {
	if (i < 0 || i >= size) { throw out_of_range("out_of_range()"); }
	shrink_to_fit();
	return data[i];
}
template<typename T>
bool MyArray<T>::isEmpty() {
	for (int i = 0; i < this->size; i++)
		if (data[i] != 0)return false;
	return true;
}
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right)const {
	MyArray plus;
	plus.size = size + right.size;
	plus.resize(plus.size, NULL);

	for (int i = 0; i < size; i++)
		plus.data[i] = data[i];
	for (int i = size; i < plus.size; i++)
		plus.data[i] = right.data[i - size];

	return plus;
}
template<typename T>
MyArray<T>&MyArray<T>::operator+=(const MyArray<T>& right) {
	MyArray add;
	add.size = size + right.size;
	add.resize(add.size, NULL);

	for (int i = 0; i < size; i++)
		add.data[i] = data[i];
	for (int i = size; i < add.size; i++)
		add.data[i] = right.data[i - size];

	*this = add;

	return *this;
}