#pragma once
#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class

	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
	
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

class Out_of_range : public logic_error
{
public:
	Out_of_range()
		:logic_error("out of range") {};
};
//template<typename T>
//class Stack
//{
//	public:
//		Stack(int = 10);

//		~Stack() {
//			delete[] stackPtr;
//		}
//		bool push(const t&);
//		bool pop(T&);

		//top: 得到最上面的值
		//push: 再拿一個盤子往上疊
		//pop : 拿掉最上面的盤子
//};

template<typename T>
MyArray<T>::MyArray(int arraysize)
{

	//	if (arraysize > 10)
	size = 0;
	//	while (arraysize > capacity)
	capacity = arraysize;
	data = new T[capacity]();



}
template<typename T>
MyArray<T>::MyArray(int n, T m)
{
	size = n;
	while (n > capacity) { capacity *= 2; }
	data = new T[capacity];
	for (int i = 0; i < n; i++) { data[i] = m; }

}

template<typename T>
MyArray<T>::MyArray(const MyArray& right)//copy
{
	size = right.size;
	capacity = right.capacity;
	data = new T[capacity]();
	for (int i = 0; i < size; i++)
		data[i] = right.data[i];
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[]data;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray& right) const
{
	return !(*this == right);
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray& right)
{
	if (&right != this)
	{
		if (size != right.size)
		{
			delete[]data;
			size = right.size;
			capacity = right.capacity;
			data = new T[capacity]();
		}
		for (int i = 0; i < size; i++)
			data[i] = right.data[i];
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray& right) const
{
	if (size != right.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (data[i] != right.data[i])
			return false;
	}
	return true;
}

template<typename T>
T& MyArray<T>::operator[](int sub)
{
	if (sub < 0 || sub >= size)
	{
		cerr << "error" << sub << "out of range" << endl;
		exit(1);
	}
	return data[sub];
}

template<typename T>
T MyArray<T>::operator[](int sub) const
{
	if (sub < 0 || sub >= size)
	{
		cerr << "error" << sub << "out of range" << endl;
		exit(1);
	}
	return data[sub];
}

template<typename T>
void MyArray<T>::resize(size_t n, T value)
{
	while (n > capacity)
	{
		reserve(2 * capacity);
	}
	for (int i = size; i < n; i++)
		data[i] = value;
	size = n;
}

template<typename T>
void MyArray<T>::reserve(size_t n)
{
	T* temp = new T[n]();
	for (int i = 0; i < size; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	capacity = n;
}

template<typename T>
ostream& operator<<(ostream& output, const MyArray<T>& a)
{

	for (int i = 0; i < a.size; i++)
	{
		output << a.data[i];
		output << " ";
	}

	return output;
}

template<typename T>
int MyArray<T>::getSize() const
{
	return size;
}

template<typename T>
int MyArray<T>::getCapacity() const
{
	return capacity;
}






template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& aaa) const
{
	MyArray<T> b;
	b.resize(size + aaa.size, 'a');
	for (int i = 0; i < size; i++) { b.data[i] = data[i]; }
	for (int i = size; i < b.size; i++) { b.data[i] = aaa.data[i - size]; }

	//data[i]=data[i] + aaa;

	return b;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& aaa)
{

	// TODO: 於此處插入 return 陳述式
	MyArray<T> b;
	b.resize(size + aaa.size, 'a');
	for (int i = 0; i < size; i++) { b.data[i] = data[i]; }
	for (int i = size; i < b.size; i++) { b.data[i] = aaa.data[i - size]; }

	//data[i]=data[i] + aaa;
	resize(b.size, 'a');
	for (int i = 0; i < b.size; i++) { data[i] = b.data[i]; }
	return *this;
}

template<typename T>
T& MyArray<T>::at(int sub)
{

	// TODO: 於此處插入 
	if (sub < 0 || sub >= size)
	{
		throw Out_of_range();
	}
	return data[sub];
}

template<typename T>
T MyArray<T>::at(int sub) const
{
	if (sub < 0 || sub >= size)
	{
		throw Out_of_range();
	}
	return data[sub];
}

template<typename T>
void MyArray<T>::shrink_to_fit()
{
	T* buffer = new T[size];
	for (int i = 0; i < getSize(); i++)
		buffer[i] = data[i];
	delete[] data;
	data = buffer;
	capacity = size;
}

template<typename T>
void MyArray<T>::clear()
{
	size = 0;
}

template<typename T>
bool MyArray<T>::isEmpty()//空的
{
	if (size == 0) { return true; }
	else { return false; }
}

