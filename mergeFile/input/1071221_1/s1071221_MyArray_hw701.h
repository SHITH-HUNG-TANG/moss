#include<iostream>
#ifndef a
#define a
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray<T>& ans)
	{
		for (int i = 0; i < ans.size; i++)
		{
			output << ans.data[i] ;
		}
		return output;
	}
	friend istream& operator>>(istream& input, MyArray<T>& str) {

		string number;
		input >> number;
		str.size = number.size();
		for (int i = 0; i < str.size; i++)
		{
			str.data[i] = number[i];
		}
		return input;
	}
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(T value[], int Size);
	MyArray(const MyArray<T>&);
	~MyArray();
	const MyArray<T>& operator=(const MyArray<T>&);
	bool operator==(const MyArray<T>&) const;
	bool operator!=(const MyArray<T>&) const;
	MyArray<T> operator+(const MyArray<T>&) const;	//new
	MyArray<T>& operator+=(const MyArray<T>&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const ;
	int getCapacity() const;
	void resize(size_t size, char item=' ');
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new
protected:
	int size;
	int capacity = 10;
	T* data ;
};
#endif // !a
