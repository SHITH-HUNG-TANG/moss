//#define  _CRT_SECURE_NO_WARNINGS
#include "s1081545_MyArray.h"
#include <string>

template <class T>
MyArray<T>::MyArray(int Capacity = DefaultCapacity)
{
	this->size = 0;
	this->capacity = (Capacity > 0 ? Capacity : DefaultCapacity);
	this->data = new T[this->capacity]{};
}

template <class T>
MyArray<T>::MyArray(int Size, T value)
{
	int curCapacity = DefaultCapacity;
	while (Size >= curCapacity)
		curCapacity *= 2;
	this->data = new T[curCapacity]{};
	this->capacity = curCapacity;
	this->size = Size;
	for (int i = 0; i < Size; i++)
		this->data[i] = value;
}

template <class T>
MyArray<T>::MyArray(const MyArray &objAry)
{
	this->size = objAry.size;
	this->capacity = objAry.capacity;
	this->data = new T[this->capacity]{};
	for (int i = 0; i < this->size; i++)
		this->data[i] = objAry.data[i];
}

template <class T>
MyArray<T>::MyArray(const T* inAry, int Size)
{
	int curCapacity = DefaultCapacity;
	while (Size >= curCapacity)
		curCapacity *= 2;
	this->data = new T[curCapacity]{};
	this->capacity = curCapacity;
	this->size = Size;
	for (int i = 0; i < Size; i++)
		this->data[i] = inAry[i];
}

template <class T>
MyArray<T>::~MyArray()
{
	delete[] this->data;
}

template <class T>
const MyArray<T>& MyArray<T>::operator=(const MyArray&objAry)
{
	if (*this == objAry)
		return *this;
	T *newData = new T[objAry.capacity]{};
	for (int i = 0; i < objAry.size; i++)
		newData[i] = objAry.data[i];
	delete[] this->data;
	this->data = newData;
	this->Size = objAry.Size;
	this->Capacity = objAry.Capacity;
	return *this;
}

template <class T>
bool MyArray<T>::operator==(const MyArray&objAry) const
{
	if (this->size != objAry.size)
		return false;
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] != objAry.data[i])
			return false;
	}
	return true;
}

template <class T>
bool MyArray<T>::operator!=(const MyArray&objAry) const
{
	return !(*this == objAry);
}

template <class T>
MyArray<T> MyArray<T>::operator+(const MyArray& objAry) const
{
	MyArray<T> ResArray(*this);
	ResArray.size = ResArray.size + objAry.size;
	int curCapacity = ResArray.capacity;
	while (ResArray.size >= curCapacity)
		curCapacity *= 2;
	ResArray.reserve(curCapacity);
	for (int i = this->size; i < ResArray.size; i++)
		ResArray.data[i] = objAry.data[i - this->size];
	return ResArray;
}

template <class T>
MyArray<T>& MyArray<T>::operator+=(const MyArray& objAry)
{
	int curCapacity = this->capacity;
	while (this->size + objAry.size >= curCapacity)
		curCapacity *= 2;
	this->reserve(curCapacity);
	for (int i = 0; i < objAry.size; i++)
		this->data[i + this->size] = objAry.data[i];
	this->size = this->size + objAry.size;
	return *this;
}

template <class T>
MyArray<T> MyArray<T>::operator+(const int& input) const
{
	MyArray<T> ResArray(*this);
	if (is_same<T, int>::value)
	{
		for (int i = 0; i < ResArray.size; i++)
			ResArray.data[i] += input;
	}
	return ResArray;
}

template <class T>
MyArray<T> MyArray<T>::operator-(const int& input) const
{
	MyArray<T> ResArray(*this);
	if (is_same<T, int>::value)
	{
		for (int i = 0; i < ResArray.size; i++)
			ResArray.data[i] -= input;
	}
	return ResArray;
}

template <class T>
MyArray<T> MyArray<T>::operator*(const int& input) const
{
	MyArray<T> ResArray(*this);
	if (is_same<T, int>::value)
	{
		for (int i = 0; i < ResArray.size; i++)
			ResArray.data[i] *= input;
	}
	return ResArray;
}

template <class T>
T& MyArray<T>::operator[](int Index)
{
	if (Index <0 || Index >= this->capacity)
	{
		throw out_of_range("Array error: Out of range");
	}
	return this->data[Index];
}

template <class T>
T MyArray<T>::operator[](int Index) const
{
	if (Index <0 || Index >= this->capacity)
	{
		throw out_of_range("Array error: Out of range");
	}
	return this->data[Index];
}

template <class T>
T& MyArray<T>::at(int Index)
{
	if (Index <0 || Index >= this->capacity)
	{
		throw out_of_range("Array error: Out of range");
	}
	return this->data[Index];
}

template <class T>
T MyArray<T>::at(int Index) const
{
	if (Index <0 || Index >= this->capacity)
	{
		throw out_of_range("Array error: Out of range");
	}
	return this->data[Index];
}

template <class T>
int MyArray<T>::getSize() const
{
	return this->size;
}

template <class T>
int MyArray<T>::getCapacity() const
{
	return this->capacity;
}

template <class T>
void MyArray<T>::resize(size_t newSize, T item)
{
	if (newSize >= (size_t)this->capacity || newSize == (size_t)this->size)
		return; // newSize more than original capacity or equal to original size, do nothing

	if (newSize < (size_t)this->size)
	{
		for (int i = newSize; i < this->size; i++)
			this->data[i] = 0;
	}
	else if (newSize >(size_t)this->size)
	{
		for (size_t i = this->Size; i < newSize; i++)
			this->data[i] = item;
	}
	this->size = newSize;
}

template <class T>
void MyArray<T>::reserve(size_t newCapacity)
{
	if (newCapacity <= (size_t)this->capacity)
		return;        // nothing happen
	T *newData = new T[newCapacity]{};
	for (int i = 0; i < this->size; i++)
		newData[i] = this->data[i];
	delete[] this->data;
	this->data = newData;
	this->capacity = newCapacity;
}

template <class T>
void MyArray<T>::shrink_to_fit()
{
	int newCapacity = this->size;
	T *newData = new T[newCapacity]{};
	for (int i = 0; i < this->size; i++)
		newData[i] = this->data[i];
	delete[] this->data;
	this->data = newData;
	this->capacity = newCapacity;
}

template <class T>
void MyArray<T>::clear()
{
	if (isEmpty())
		return;

	delete[] this->data;
	this->data = new T[this->capacity]{};
	this->size = 0;
}

template <class T>
bool MyArray<T>::isEmpty()
{
	if (this->size == 0)
		return true;
	else
		return false;
}

template <class T>
ostream& operator<<(ostream& out, const MyArray<T>& objAry)
{
	for (int i = 0; i < objAry.size; i++)
		cout << objAry.data[i] << " ";
	return out;
}

template <class T>
istream& operator>>(istream& input, MyArray<T>& objAry)
{
	string strInput;
	input >> strInput;

	string delimiter = ",";
	int ind = 0;
	size_t pos = 0;
	while ((pos = strInput.find(delimiter)) != string::npos)
	{
		string token = strInput.substr(0, pos);
		if (is_same<T, int>::value)
			objAry.data[ind++] = stoi(token);
		else
		{
			char cStr[2];
			strcpy_s(cStr, token.c_str());
			objAry.data[ind++] = cStr[0];
		}
		strInput.erase(0, pos + delimiter.length());
	}
	objAry.size = ind;

	return input;
}