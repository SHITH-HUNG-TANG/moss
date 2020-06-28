#include"s1071221_MyArray_hw701.h"
#include<algorithm>
#include<iostream>
#include <stdexcept>
using namespace std;

/*template<typename T>
ostream& operator<<(ostream& output, const MyArray<T>& ans)
{
	for (int i = 0; i < ans.size; i++)
	{
		output << ans.data[i] << " ";
	}
	output << endl;
	return output;
}*/
template<typename T>
MyArray<T>::MyArray(int Capacity)
{
	size = 0;
	Capacity = capacity;
	data = new T[Capacity]();
}

template<typename T>
MyArray<T>::MyArray(int Size, T value)
{
	size = Size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = value;
	}
}
template <typename T>
MyArray<T>::MyArray(T value[], int Size)
{
	size = Size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = value[i];
	}
}
template<typename T>
MyArray<T>::MyArray(const MyArray<T>& ans)
{
	capacity = ans.capacity;
	size = ans.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = ans.data[i];
	}
}

template<typename T>
MyArray<T>::~MyArray()
{
	//delete[]data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& output)//save
{
	if (this != &output)//確保this指的位置和right的位置不同 以避免自己呼叫後傳入自己
	{
		if (size != output.size)//分配新的陣列
		{
			delete[]data;//釋放
			size = output.size;//重新調整大小
			data = new T[size];//create space for array copy
		}
		for (int i = 0; i < size; i++)
		{
			data[i] = output.data[i];//copy array into object
		}
	}
	return *this;
}

template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const//save
{
	if (size != right.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != right.data[i])
			{
				return false;
			}
		}
	}
	return false;
}

template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}

template <typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const
{
	MyArray ans;
	ans.size = size + right.size;
	T* buffer = new T[ans.size]();
	for (int i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}
	for (int i = size; i < ans.size; i++)
	{
		buffer[i] = right.data[i - size];
	}
	ans.resize(ans.size);
	delete[]ans.data;
	ans.data = buffer;
	return ans;
}

template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)
{
	/*MyArray ans;
	ans.size = size + right.size;
	T* buffer = new T[ans.size]();
	for (int i = 0; i < size; i++)
	{
		buffer[i] = data[i];
	}
	for (int i = size; i < ans.size; i++)
	{
		buffer[i] = right.data[i - size];
	}
	ans.resize(ans.size);
	delete[]ans.data;
	ans.data = buffer;
	return *this;*/
	* this = *this + right;
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
T& MyArray<T>::at(int i)
{
	try
	{
		return data[i];
	}
	catch (const out_of_range& oor)
	{
		cerr << "Out of Range error: " << oor.what() << endl;
	}
}

template<typename T>
T MyArray<T>::at(int i) const
{
	try
	{
		return data[i];
	}
	catch (const out_of_range& oor)
	{
		cerr << "Out of Range error: " << oor.what() << endl;
	}
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

template <typename T>
void MyArray<T>::resize(size_t n, char c)
{
	if (n <= size)
	{
		size = n;
	}
	else
	{
		reserve(n);
		for (; size < n; size++)
		{
			data[size] = c;
		}
		size = n;
	}
}
template <typename T>
void  MyArray<T>::reserve(size_t n)
{
	if (n > capacity)
	{
		capacity = max(int(n), 2 * capacity);
		T* new_data_ptr = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			new_data_ptr[i] = data[i];
		}
		delete[] data;
		data = new_data_ptr;
	}
}//將capacity直接變成所傳入的變數
template<typename T>
void MyArray<T>::shrink_to_fit()//save
{
	;
	T* buffer = new T[size];
	for (int i = 0; i < size; i++)
		buffer[i] = data[i];
	delete[] data;
	data = buffer;
}

template<typename T>
void  MyArray<T>::clear()//save
{
	if (!(isEmpty()))
	{
		size = 0;
	}
}

template<typename T>
bool  MyArray<T>::isEmpty()//save
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template class  MyArray<int>;
template class  MyArray<char>;
template class MyArray<float>;
template class  MyArray<string>;