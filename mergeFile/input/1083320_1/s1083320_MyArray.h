#ifndef s1083320_MyArray_H
#define s1083320_MyArray_H
#include<string>
#include<iostream>
using namespace std;

template< class T >
class MyArray : public exception
{	//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray& ans)
	{
		for (int i = 0; i < ans.size; ++i)
		{
			if ((i) % 5 == 0 && i != ans.size && i != 0) output << ",";
			output << ans.data[i];
		}
		return output;
	}
	friend istream& operator>>(istream& input, MyArray& ans)
	{
		string str;
		input >> str;
		ans.resize(str.length());
		for (int i = 0; i < ans.size; ++i)
		{
			ans.data[i] = str[i];
		}
		return input;
	}
public:
	MyArray(int num = 10);
	MyArray(int, T);
	MyArray(const MyArray &);
	~MyArray();
	const MyArray& operator=(const MyArray& copy);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	void set(int, T);
	int getSize() const;
	int getCapacity() const;
	void resize(unsigned int, const T&);
	void resize(unsigned int);
	void reserve(unsigned int);
	void shrink_to_fit();	//new
	void clear();			//new
	void pop_back();
	void push_back(const T&);
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};



#endif


