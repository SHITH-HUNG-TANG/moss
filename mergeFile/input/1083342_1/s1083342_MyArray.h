#ifndef MyArray_H
#define MyArray_H
#include<iostream>
#include<stdexcept>
using namespace std;
template<typename T>

class MyArray
{

	friend ostream& operator<<(ostream& output, const MyArray& i)
	{
		if (i.size == 0)
		{
			cout << "nothing";
		}
		for (int j = 0;j < i.size;j++)
		{
			output << i.data[j] ;
		}
		return output;
	}
public:
	MyArray(int Capacity = 10)
	{
		size = 0;
		capacity = Capacity;
		data = new T[capacity]();
	}

	MyArray(int  Size, T value)
	{
		size = 0;
		capacity = 10;
		data = new T[capacity]();
		for (int i = 0;i < Size;i++)
		{
			this->push_back(value);
		}
	}

	MyArray(T x[], int Size)
	{
		size = 0;
		capacity = 10;
		data = new T[capacity]();
		for (int i = 0;i < Size;i++)
		{
			this->push_back(x[i]);
		}
	}

	MyArray(const MyArray& i)
	{
		size = i.size;
		capacity = i.capacity;
		data = new T[i.capacity]();
		for (int j = 0;j < i.size;j++)
		{
			data[j] = i.data[j];
		}
	}

	~MyArray()
	{
		delete[]data;
	}

	const  MyArray& operator=(const MyArray& i)
	{
		if (&i != this)
		{
			if (size != i.size)
			{
				delete[]data;
				size = i.size;
				data = new T[size];
			}
			for (int j = 0;j < size;j++)
			{
				data[j] = i.data[j];
			}
		}
		capacity = i.capacity;
		return *this;
	}

	bool operator==(const MyArray& i)const
	{
		if (size != i.size)
		{
			return false;
		}
		for (int p = 0;p < size;p++)
		{
			if (data[p] != i.data[p])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const MyArray& i)const
	{
		return !(*this == i);
	}

	MyArray operator+(const MyArray i) const
	{
		MyArray h;
		h.resize(size + i.size, 0);
		for (int i = 0;i < size;i++)
		{
			h.data[i] = data[i];
		}
		int c = 0;
		for (int k = size;k < i.size + size;k++)
		{

			h.data[k] = i.data[c];
			c++;
		}
		return h;
	}

	MyArray& operator+=(const MyArray& i)
	{
		MyArray t;
		t = (*this) + i;
		(*this) = t;
		return *this;
	}

	T& operator[](int i)
	{
		if (i < 0 || i >= size)
		{
			cerr << "\nError: Subscript" << i << "out of range" << endl;
			exit(1);
		}
		return data[i];
	}

	T operator[](int i)const
	{
		if (i < 0 || i >= size)
		{
			cerr << "\nError: Subscript" << i << "out of range" << endl;
			exit(1);
		}
		return data[i];
	}

	T& at(int i)
	{
		if (i > size - 1)
		{
			throw out_of_range("out_of_range");
		}
		else
		{
			return data[i];
		}
	}

	T at(int i) const
	{
		if (i > size - 1)
		{
			throw out_of_range("out_of_range");
		}
		else
		{
			return data[i];
		}
	}

	int getSize() const
	{
		return size;
	}

	int getCapacity()const
	{
		return capacity;
	}

	void resize(size_t n, T c)
	{
		int h = size;
		if (size > n)
		{
			size = n;
		}
		for (int i = h;i < n;i++)
		{
			push_back(c);
		}
	}

	void reserve(size_t n)
	{
		if (n <= capacity)
		{
			return;
		}
		capacity = n;
		T* data1 = new T[capacity]();
		for (int i = 0;i < size;i++)
		{
			data1[i] = data[i];
		}
		delete[]data;
		data = data1;
	}

	void shrink_to_fit()
	{
		capacity = size;
		T* data1 = new T[capacity]();
		for (int i = 0;i < size;i++)
		{
			data1[i] = data[i];
		}
		delete[]data;
		data = data1;
	}

	void clear()
	{
		/*for (int i = 0;i < size;i++)
		{
			data.pop_back();
		}*/
		size = 0;
		capacity = capacity;
	}

	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

	void push_back(const T i)
	{
		if (size + 1 > capacity)
		{
			reserve(capacity * 2);
		}
		data[size] = i;
		size = size + 1;
	}

	void pop_back()
	{
		if (size < 1)
		{
			return;
		}
		size = size - 1;
	}
protected:
	int  size;           //­ìint size;    
	int  capacity;       //­ìint capacity; 
	T* data;             //­ìint* data; 
};
#endif 


