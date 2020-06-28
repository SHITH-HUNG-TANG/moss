#ifndef MYARRAY
#define MYARRAY

#include <iostream>
using namespace std;

template < typename T >
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray<T>& toPrint)
	{
		for (int i = 0; i < toPrint.size; i++)
			output << toPrint.elem[i] << " ";

		output << endl;

		return output;
	}

	//friend istream& operator>>(istream&, MyArray<T>&);
public:
	MyArray(int Capacity = 10)
	{
		capacity = (Capacity > 0) ? Capacity : 10;
		size = 0;
	}

	MyArray(int Size, T value)
	{
		capacity = 10;
		resize(Size, value);
	}

	MyArray(const MyArray& toCopy)
	{
		size = toCopy.size;
		capacity = toCopy.capacity;

		elem = new T[capacity];

		for (int i = 0; i < size; i++)
			elem[i] = toCopy.elem[i];
	}

	~MyArray() 
	{
		delete[] elem;
	}

	const MyArray& operator=(const MyArray& toCopy)
	{
		size = toCopy.size;
		capacity = toCopy.capacity;

		elem = new T[capacity];

		for (int i = 0; i < size; i++)
			elem[i] = toCopy.elem[i];

		return *this;
	}

	bool operator==(const MyArray& right) const
	{
		if (size != right.size)
			return false;
		else {
			for (int i = 0; i < size; i++)
				if (elem[i] != right.elem[i])
					return false;
		}

		return true;
	}

	bool operator!=(const MyArray& right) const
	{
		return !(*this == right);
	}

	MyArray operator+(const MyArray& right) const	//new
	{
		MyArray< T > temp(*this);
		temp.resize(size + right.size);

		for (int i = size; i < size + right.size; i++)
			temp.elem[i] = right.elem[i - size];

		return temp;
	}

	MyArray& operator+=(const MyArray& right)		//new
	{
		MyArray< T > temp(*this);
		temp.resize(size + right.size);

		for (int i = size; i < size + right.size; i++)
			temp.elem[i] = right.elem[i - size];

		*this = temp;
		return *this;
	}

	T& operator[](int idx)
	{
		if (idx >= size)
			throw "out of range error!";
		return elem[idx];
	}

	T operator[](int idx) const
	{
		if (idx >= size)
			throw "out of range error!";
		return elem[idx];
	}

	T& at(int idx)		//new
	{
		if (idx >= size)
			throw "out of range error!";
		return elem[idx];
	}

	T at(int idx) const	//new
	{
		if (idx >= size)
			throw "out of range error!";
		return elem[idx];
	}

	int getSize() const
	{
		return size;
	}

	int getCapacity() const
	{
		return capacity;
	}

	void resize(size_t newSize)
	{
		MyArray< T > temp(*this);

		while (newSize >= temp.capacity)
			temp.reserve(temp.capacity * 2);

		if (newSize > size) {
			temp.size = newSize;

			for (int i = 0; i < size; i++)
				temp.elem[i] = elem[i];
		}
		else if (newSize < size)
			temp.size = newSize;
		else return;

		*this = temp;
	}

	void resize(size_t newSize, const T item)
	{
		MyArray< T > temp(*this);

		while (newSize >= temp.capacity)
			temp.reserve(temp.capacity * 2);

		if (newSize > size) {
			temp.size = newSize;

			for (int i = 0; i < size; i++)
				temp.elem[i] = elem[i];

			for (int i = size; i < newSize; i++)
				temp.elem[i] = item;
		}
		else if (newSize < size)
			temp.size = newSize;
		else return;

		*this = temp;
	}

	void reserve(size_t newCapa)
	{	
		if (newCapa > capacity) {
			capacity = newCapa;
			delete[] elem;
			elem = new T[capacity];
		}
		else return;
	}

	void shrink_to_fit()	//new
	{
		MyArray< T > temp = *this;

		temp.reserve(size);

		for (int i = 0; i < size; i++)
			temp.elem[i] = elem[i];

		*this = temp;
	}

	void clear()			//new
	{
		resize(0);
	}

	bool isEmpty()			//new
	{
		if (size == 0)
			return true;

		return false;
	}

protected:
	int size;
	int capacity;
	T* elem;
};

#endif // !MYARRAY

