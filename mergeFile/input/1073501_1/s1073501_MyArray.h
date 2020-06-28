#ifndef Header
#define Header
#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
template< typename T >
class MyArray {	//modify this class into a template class
	friend ostream& operator<<(ostream&out, const MyArray&obj) {
		for (int i = 0; i < obj.size; i++) {
			out << obj.data[i];
		}
		cout << endl;
		return out;
	};
	/*friend istream& operator>>(istream&, MyArray&);*/
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray&);
	~MyArray();
	//MyArray(int Size, T[]);
	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray<T> operator+(const MyArray&) const;	//new
	MyArray<T>& operator+=(const MyArray&);		//new
	int& operator[](int);
	int operator[](int) const;
	T& at(int);		//new
	T at(int) const;//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);//n,c
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new
protected:
	int size;
	int capacity;
	T* data;
};
//template class  MyArray <char>;
//template class  MyArray <int>;
#endif // !MyArray


