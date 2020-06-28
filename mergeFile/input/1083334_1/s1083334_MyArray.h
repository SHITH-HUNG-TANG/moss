#ifndef MY_ARRAY
#define MY_ARRAY
#include<iostream>
using namespace std;

template< typename T >
class MyArray {		//modify this class into a template class
	friend ostream& operator<<(ostream& output, const MyArray<T> &a) {
		for (int i = 0; i < a.size; i++) {
			output << a.data[i];
		}
		return output;
	}
	//friend istream& operator>>(istream&, MyArray&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray &);
	~MyArray();
	
	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&) ;		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item=NULL);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};


#endif // !MyArray

