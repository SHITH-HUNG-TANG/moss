#ifndef S1083322_MYARRAY_H
#define S1083322_MYARRAY_H
#include<iostream>
#include<string>
using namespace std;
template <class T>
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray& a)
	{
		for (int i = 0; i < a.size; i++)
		{
			output << a.data[i];
		}
		return output;
	}
	//friend istream& operator>>(istream&, MyArray&);
	friend istream& operator>>(istream& input, MyArray& right)
	{
		string Temp;
		input >> Temp;
		right.size = Temp.length();
		for (int i = 0; i < Temp.length(); i++)
		{
			right.data[i] = Temp[i];
		}
		return input;
	}
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray &);
	~MyArray();

	const MyArray& operator=(const MyArray &);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);//new
	T at(int);		//new
	int at(int) const;  //new

	int getSize() const;
	int getCapacity() const;
	void setSize(int);
	void setCapacity(int);
	void setData(int,T);
	T getData(int)const;
	T operator[](int)const;

	void resize(int size, T item);
	void reserve(int);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new


private:
	int size;
	int capacity;
	T* data;
};

#endif // !MyArray