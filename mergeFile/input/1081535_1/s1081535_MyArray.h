#ifndef MyArray_H
#define MyArray_H
#include<iostream>
#include<stdexcept>
using namespace std;

//modify this class into a template class
template <typename T>

class MyArray
{
	friend ostream& operator<<(ostream&output, const MyArray&x)
	{
		for (int i = 0; i < x.getSize(); i++)
		{
			output << x[i];
		}
		return output;
	}

	//friend istream& operator>>(istream&, MyArray&);
public:

	//default constructor for class MyArray(default capacity 10)

	MyArray(int	x = 10)
	{
		capacity = 10;
		data = new T[capacity]{};
		size = 0;
		int cset = capacity;
		while (x > cset)
		{
			cset *= 2;
		}
		reserve(cset);
	}

	//constructor fot class MyArray
	MyArray(int x, T y) //x is size ,y is data value
	{
		capacity = 10;
		data = new T[capacity]{ };
		size = 0;
		resize(x, y);
	}

	MyArray(int x, const T y[]) //x is size ,y is data value
	{
		capacity = 10;
		data = new T[capacity]{ };
		size = 0;
		for (int i = 0; i < x; i++)
		{
			push_back(y[i]);
		}
	}

	//copy constructor fot class MyArray
	MyArray(const MyArray &x)
	{
		capacity = x.capacity;
		size = x.size;
		data = new T[capacity]{};
		for (int i = 0; i < size; i++)
		{
			data[i] = x.data[i];
		}
	}

	//destructor for class MyArray
	~MyArray()
	{
		delete[]data;
	}

	//overloaded assignment operator
	const MyArray& operator=(const MyArray&x)
	{
		if (&x != this)
		{
			if (size != x.size)
			{
				delete[]data;
				size = x.size;
				data = new T[size];
			}
			for (int i = 0; i < size; i++)
			{
				data[i] = x.data[i];
			}
			capacity = x.capacity;
		}
		return *this;
	}

	//test both array are equal or not
	bool operator==(const MyArray&x) const
	{
		if (size != x.size) return false;
		for (int i = 0; i < size; i++)
		{
			if (data[i] != x.data[i])return false;
		}
		return true;
	}

	bool operator!=(const MyArray&x) const
	{
		if (size != x.size) return true;
		for (int i = 0; i < size; i++)
		{
			if (data[i] != x.data[i])return true;
		}
		return false;
	}


	MyArray operator+(const MyArray& x) const
	{
		MyArray plus;

		for (int i = 0; i < getSize(); i++)
		{
			plus.push_back(data[i]);
		}
		for (int i = 0; i < x.getSize(); i++)
		{
			plus.push_back(x.data[i]);
		}

		return plus;
	}

	////////////////
	MyArray& operator+=(const MyArray& x)
	{
		*this = *this + x;
		return *this;
	}

	//overloaded subscript operator for non-const MyArrays
	T& operator[](T x)
	{
		if (x < 0 || x >= size)
		{
			cerr << "\nError: Subscript " << x << " out of range" << endl;
			exit(1);
		}
		return data[x];
	}


	//overloaded subscript operator for const MyArrays
	T operator[](T x) const
	{
		if (x < 0 || x >= size)
		{
			cerr << "\nError: Subscript " << x << " out of range" << endl;
			exit(1);
		}
		return data[x];
	}


	T& at(T x)
	{
		if (x >= size)
		{
			throw out_of_range("out_of_range.");
		}
		else return data[x];
	}

	T at(T x) const
	{
		if (x >= size)
		{
			throw out_of_range("out_of_range.");
		}
		else return data[x];
	}

	//return size of MyArray
	int getSize() const
	{
		return size;
	}

	//return capacity of MyArray
	int getCapacity() const
	{
		return capacity;
	}

	//reset size&set data value
	void resize(size_t x, T c)//x is size ,c is data value
	{
		int y = size;
		if (size > x)size = x;
		for (int i = y; i < x; i++)
		{
			push_back(c);
		}
	}

	//reset capacity(double capacity)
	void reserve(size_t x)
	{
		if (x > capacity)
		{
			capacity = x;
			T *newdata = new T[capacity]{};
			for (int i = 0; i < size; i++) {
				newdata[i] = data[i];
			}
			delete[] data;
			//value = new int[capacity] {0};
			data = newdata;
			//delete[]newvalue;
		}
		else return;
	}

	//add data value
	void push_back(const T x)
	{
		size++;
		if (size > capacity)
		{
			reserve(capacity * 2);
		}
		data[size - 1] = x;
	}

	//delete data value
	void pop_back()
	{
		if (size == 0)return;
		size--;
	}

	void shrink_to_fit()
	{
		if (capacity != size)
		{
			capacity = size;
			T *newdata = new T[capacity]{};
			for (int i = 0; i < size; i++)
			{
				newdata[i] = data[i];
			}
			delete[]data;
			data = newdata;
		}
	}

	//clear data value
	void clear()
	{
		while (size > 0)
		{
			pop_back();
		}
	}

	//wheather array is empty
	bool isEmpty()
	{
		if (size == 0)return true;
		else return false;
	}

protected:
	int size;
	int capacity;
	T* data;
};
#endif // !MyArray
