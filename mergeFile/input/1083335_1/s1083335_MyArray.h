
#include<iostream>
#ifndef ARRAY_H
#define ARRAY_H
using namespace std;

class Error : public exception
{
public:
	Error() :exception("out of range") {};
};

template<typename T>
class MyArray : public Error
{	//modify this class into a template class

	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray&);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity = 10;
	T* data;
};
#endif // !MyArray

template<typename T>
ostream& operator<<(ostream& output, const MyArray<T>& x)
{
	for (int i = 0;i < x.size;i++)
	{
		output << x.data[i];
		//if (i != x.size - 1)
		cout << " ";
	}
	return output;
}

template<typename T>
MyArray<T>::MyArray(int arraySize)
{
	size = 0;
	/*
	while (arraySize > capacity) {
		capacity *= 2;
	}
	*/
	capacity = arraySize;
	data = new T[capacity]();
}

template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	while (Size > capacity) {
		capacity *= 2;
	}
	data = new T[capacity];
	size = Size;
	for (int i = 0;i < Size;i++) {

		data[i] = value;
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray& copy)
{
	capacity = copy.capacity;
	size = copy.size;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
		data[i] = copy.data[i];
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
			data = new T[capacity];

		}
		for (int i = 0;i < size;i++)
			data[i] = right.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& right) const
{
	if (size != right.size)
		return false;
	for (int i = 0;i < size;i++) {
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
MyArray<T> MyArray<T>::operator+(const MyArray<T>& a) const
{
	MyArray<T> ans;
	//cout << "t"<< endl;
	ans.resize(size + a.size, '0');
	for (int i = 0; i < size; i++) {
		ans.data[i] = data[i];
	}
	for (int i = size; i < ans.size; i++) {
		ans.data[i] = a.data[i - size];
	}
	cout << "ans=" << ans << endl;
	return ans;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& a)
{
	MyArray<T> ans;
	ans.resize(size + a.size, '0');
	for (int i = 0; i < size; i++) {
		ans.data[i] = data[i];
	}
	for (int i = size; i < ans.size; i++) {
		ans.data[i] = a.data[i - size];
	}
	*this = ans;
	return *this;
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
T& MyArray<T>::at(int sub)
{
	if (sub < 0 || sub >= size)
	{
		throw Error();
	}
	return data[sub];
}

template<typename T>
T MyArray<T>::at(int sub) const
{
	if (sub < 0 || sub >= size)
	{
		throw Error();
	}
	return data[sub];
}

template<typename T>
void  MyArray<T>::resize(size_t n, T value) //change size
{
	/*
	if (n > capacity)
	{
		reserve(2 * capacity);
		if (n > capacity) {
			reserve(n);
		}
	}
	*/
	while (n > capacity)
	{
		reserve(2 * capacity);
	}
	for (int i = size;i < n;i++)
	{
		data[i] = value;
	}
	size = n;
}

template<typename T>
void MyArray<T>::reserve(size_t n) //change capacity
{
	T* x = new T[n]();
	for (int i = 0;i < size;i++)
	{
		x[i] = data[i];
	}
	delete[]data;
	data = x;
	capacity = n;
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
void  MyArray<T>::shrink_to_fit()
{
	capacity = size;
}

template<typename T>
void  MyArray<T>::clear()
{
	for (int i = 0;i < size;i++) {
		data[i] = '\0';
	}
}

template<typename T>
bool MyArray<T>::isEmpty()
{
	for (int i = 0;i < size;i++) {

		if (data[i] == '\0')
			return true;
		else
			return false;
	}
}

