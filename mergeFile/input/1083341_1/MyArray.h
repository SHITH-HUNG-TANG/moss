#ifndef s1083341_H
#define s1083341_H
#include<iostream>
#include <stdexcept>
using namespace std;

class Error : public exception
{
public:
	Error() :exception("out of range") {};
};
template<typename T>
class MyArray : public Error
{
	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray<T>&);
	~MyArray();

	const MyArray& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray operator+(const MyArray<T>&) const; //new
	MyArray& operator+=(const MyArray<T>&);  //new
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
ostream& operator<< (ostream& output, const MyArray <T>& x)
{
	for (int i = 0; i < x.size; i++)
	{
		output << x.data[i];
		cout << " ";
	}
	return output;
}

template<typename T>
MyArray<T>::MyArray(int arraySize)
{
	capacity = (arraySize > 0 ? arraySize : 10);
	//size = capacity;
	size = 0;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

template<typename T>
MyArray<T>::MyArray(int Size, T value) {
	data = new T[Size];
	for (int i = 0; i < Size; i++) {
		data[i] = value;
	}
	size = Size;
	capacity = 10;
	while (Size > capacity) {
		capacity *= 2;
	}
}
template<typename T>
MyArray<T>::MyArray(const MyArray<T>& arrayToCopy)
{
	capacity = arrayToCopy.capacity;
	size = arrayToCopy.size;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
		data[i] = arrayToCopy.data[i];
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[]data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right)
{
	if (&right != this)
	{
		if (size != right.size)
		{
			delete[]data;
			capacity = right.capacity;
			size = right.size;
			data = new T[right.capacity];
		}
		for (int i = 0; i < size; i++)
			data[i] = right.data[i];
	}
	return *this;
}
template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const
{
	if (size != right.size)
		return false;
	for (int i = 0; i < size; i++) {
		if (data[i] != right.data[i])
			return false;
	}
	return true;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}

template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const {
	MyArray<T> ans;
	int inheritancesize = size + right.size;
	ans.resize(inheritancesize, '0');

	for (int i = 0; i < size; i++) {
		ans.data[i] = data[i];
	}
	for (int i = size; i < inheritancesize; i++) {
		ans.data[i] = right.data[i - size];
	}
	return ans;
}

template<typename T>
MyArray<T>& MyArray<T>:: operator+=(const MyArray<T>& right) {
	MyArray<T> ans;
	int inheritancesize = size + right.size;
	ans.resize(inheritancesize, '0');

	for (int i = 0; i < size; i++) {
		ans.data[i] = data[i];
	}
	for (int i = size; i < inheritancesize; i++) {
		ans.data[i] = right.data[i - size];
	}
	*this = ans;
	return *this;//因為改變自己 所以要回傳this
}

template<typename T>
T& MyArray<T>::operator[](int subscript)
{
	if (subscript < 0 || subscript >= size)
	{
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T MyArray<T>::operator[](int subscript) const
{
	if (subscript < 0 || subscript >= size)
	{
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit(1);
	}
	return data[subscript];
}

template<typename T>
T& MyArray<T>::at(int subscript) {
	if (subscript < 0 || subscript >= size)
	{
		throw Error();
	}
	else
		return data[subscript];
}

template<typename T>
T MyArray<T>::at(int subscript) const {
	if (subscript < 0 || subscript >= size)
	{
		throw Error();
	}
	else
		return data[subscript];
}

template<typename T>
int MyArray<T>::getSize()const
{
	return size;
}

template<typename T>
int MyArray<T>::getCapacity()const
{
	return capacity;
}

template<typename T>
void MyArray<T>::resize(size_t n, T item) //change size
{
	/*if (n > capacity)
	{
		reserve(2 * capacity);
		if (n > capacity) {
			reserve(n);
		}
	}*/
	while (n > capacity)
	{
		reserve(2 * capacity);
	}
	for (int i = size; i < n; i++)
	{
		data[i] = item;
	}
	size = n;
}

template<typename T>
void MyArray<T>::reserve(size_t n) //change capacity
{
	T* x = new T[n]();
	for (int i = 0; i < size; i++)
	{
		x[i] = data[i];
	}
	delete[]data;
	data = x;
	capacity = n;
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	capacity = size;
}

template<typename T>
void MyArray<T>::clear() {
	size = 0;
	capacity = 0;
}

template<typename T>
bool MyArray<T>::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

#endif // !MyArray
