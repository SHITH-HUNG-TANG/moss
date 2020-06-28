#include"s1061637_MyArray.h"
#include<cstdlib>
template <class T>
MyArray<T>::MyArray(size_t cap) :size(0)
{
	this->capacity = cap;	
	data = new T[this->capacity];
}
template <class T>
MyArray<T>::MyArray(const MyArray & right)
{
	this->capacity = right.capacity;
	this->size = right.size;
	data = new T[this->capacity];
	for (size_t i=0; i < size; i++)
		this->data[i] = right.data[i];

}
template <class T>
MyArray<T>::MyArray(int size, T value)
{
	this->capacity = size*2;
	this->size = size;
	data = new T[this->capacity];
	for (size_t i = 0; i < size; i++)
		this->data[i] = value;

}
template <class T>
MyArray<T>::~MyArray() { delete []data; }
template <class T>
const MyArray<T>& MyArray<T>::operator= (const MyArray & right)
{
	delete[]this->data;
	this->capacity = right.capacity;
	this->size = right.size;
	
	data = new T[right.capacity];
	for (size_t i = 0; i < right.size; i++)
	{
		this->data[i] = right.data[i];
	}
	return *this;
}
template <class T>
bool MyArray<T>::operator == (const MyArray & right)const
{
	if (this->size != right.size)
		return 0;
	else 
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->data[i] != right.data[i])
				return 0;
		}
	return 1;
}

template <class T>
bool MyArray<T>::operator != (const MyArray & right)const
{
	return *this == right;
}

template <class T>
T& MyArray<T>::operator[](int input)
{
	return data[input];
}
template <class T>
const T  MyArray<T>::operator[](int input)const
{

	return this->data[input];
}
template <class T>
int MyArray<T>::getSize()const
{
	return size;
}
template <class T>
int MyArray<T>::getCapacity()const
{
	return   capacity;
}
template <class T>
void MyArray<T>::resize(size_t n, T c)
{
	while (n > capacity)
		 reserve(2* capacity);
	if (n > size)
		for (size_t i = size; i < n; i++)
			data[i] = c;
	size = n;
}
template <class T>
void MyArray<T>::reserve(size_t input) 
{
	if(capacity< input)
	{
		T *temp = new T[input];
		copy(data,data+size,temp);
		delete[]data;

		data = temp;
	    capacity = input;
	}
	
}
/*template <class T>
ostream &operator<<(ostream & os , const MyArray<T>& arr)
{
	int i = 0;
	while (i < arr.size)
		os << arr[i];
	return os;
}*/
/*ostream &operator<<(ostream & os, const MyArray<char>& arr)
{
	int i = arr.size;
	while (--i >= 0)
		os << arr[i];
	return os;
}*/
template <class T>
void MyArray<T>::shrink_to_fit()
{
	MyArray<T>temp(*this);
	this->data = new T[this->size];
	copy(temp.data, temp.data + this->size, this->data);
	this->capacity = this->size;
}
template <class T>
bool MyArray<T>::isEmpty()
{
	if (this->size == 0)
		return 1;
	return 0;
}
template <class T>
void MyArray<T>::clear()
{
	if(!isEmpty())
		size = 0;
}
template <class T>
T& MyArray<T>::at(int input)
{
	if (size < input)
	{
		cout << "outoflist";
		throw(std::out_of_range("outoflist"));
	}
	else
		return data[input-1];
}
	//new

template <class T>
const T&  MyArray<T>::at(int input)const
{
	if (size < input)
	{
		cout << "outoflist";
		exit(0);	
	}
	else
		return data[input - 1];
}
template <class T>
const MyArray<T>& MyArray<T>::operator+= (const MyArray<T> & str)
{

	this->reserve(this->size + str.size);
	copy( str.data , str.data+ str.size, this->data+ this->size);
	this->size = this->size + str.size;
	return *this;
}
template <class T>
MyArray<T>  MyArray<T>:: operator+ (const MyArray<T>& right)
{
	
		MyArray<T>temp;
		temp.reserve(this->size + right.size);
		copy(this->data, this->data + this->size,temp.data);
		copy(right.data , right.data + right.size , temp.data+size);
		temp.size = this->size + right.size;
		return  temp;
	
}


/*template <class T>
istream& operator>>(istream&, MyArray<T>&)
{
	
}*/

template class MyArray<char>;
template class MyArray<long long int>;




