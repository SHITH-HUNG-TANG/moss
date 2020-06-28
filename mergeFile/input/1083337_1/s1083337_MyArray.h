#include<iostream>
using namespace std;



template<typename T>
class MyArray {

	class out_of_range : public logic_error
	{
	public:
		explicit out_of_range(const string& what_arg);
		explicit out_of_range(const char* what_arg);
	};


	friend ostream& operator<<(ostream& output, const MyArray& value) {
		for (int i = 0; i < value.size; i++) {
			output << value.data[i] << " ";
		}
		return output;
	}
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray&);
	~MyArray();

	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);		//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int);		//new
	T at(int) const;	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};

template<typename T>
MyArray<T>::MyArray(int  value) {
	capacity = value;
	size = 0 ;
	data = new T[capacity]();
}
template<typename T>
MyArray<T>::MyArray(int  Size, T value) {
	if (size < 0) {
		size = 0 ;
		capacity = 10;
		data = new T[capacity]();
	}
	else {
		size = Size;
		capacity = 10;
		while (size > capacity) {
			capacity *= 2;
		}
		data = new T[capacity]();
		for (int i = 0; i < size; i++) {
			data[i] = value;
		}
	}
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& value) {
	size = value.size;
	capacity = value.capacity;
	data = new T[capacity]();
	for (int i = 0; i < size; i++) {
		data[i] = value.data[i];
	}
}

template<typename T>
MyArray<T>::~MyArray() {
	delete[] data;
}

template<typename T>
const MyArray<T>& MyArray<T>::operator = (const MyArray<T>& value) {
	size = value.size;
	capacity = value.capacity;
	delete[]data;
	data = new T[capacity]();
	for (int i = 0; i < size; i++) {
		data[i] = value.data[i];
	}
	return (*this);
}

template<typename T>
bool  MyArray<T>::operator == (const MyArray<T>& value)const {
	if (size != value.size) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (data[i] != value.data[i]) {
				return false;
			}
		}
		return true;
	}
}

template<typename T>
bool   MyArray<T>::operator!=(const MyArray<T>& value)const {
	if (size != value.size) {
		return true;
	}
	else {
		for (int i = 0; i < (size > value.size ? size : value.size); i++) {
			if (data[i] != value.data[i]) {
				return true;
			}
		}
		return false;
	}
}

template<typename T>
MyArray<T> MyArray<T>:: operator+(const MyArray<T>& value) const {

	MyArray temp(value.size + (*this).size, '\0');				//new 新空間

	for (int i = 0; i < (*this).size; i++) {										// 放前者的字串
		temp.data[i] = (*this).data[i];
	}
	for (int i = (*this).size, j = 0; i < temp.size; i++, j++) {			// 放後者的字串
		temp.data[i] = value.data[j];
	}
	return temp;
}
template<typename T>
MyArray<T>& MyArray<T>:: operator+= (const MyArray<T>& value) {
	int old = (*this).size;
	(*this).resize((*this).size + value.size, '\0');
	for (int i = old, j = 0; i < (*this).size; i++, j++) {
		(*this).data[i] = value.data[j];
	}
	return *this;
}

//reset size
template<typename T>
void MyArray<T>::resize(size_t N, T c) {
	int tempcapacity = capacity;
	if (N > capacity) {
		while (N > tempcapacity) {
			tempcapacity *= 2;
		}
		reserve(tempcapacity);
		for (int i = (*this).size; i < N; i++) {
			(*this).data[i] = c;
		}
		(*this).size = N;
	}
	else {
		for (int i = (*this).size; i < N; i++) {
			(*this).data[i] = c;
		}
		(*this).size = N;
	}
}

template<typename T>
// reset capacity
void MyArray<T>::reserve(size_t N) {
	MyArray temp;

	if (N > capacity) {
		temp.capacity = N;
	}
	else {
		temp.capacity = capacity;
	}

	temp.data = new T[temp.capacity]();
	temp.size = size;
	for (std::size_t n = 0; n < size; n++) {
		temp.data[n] = data[n];
	}
	(*this) = temp;
}

template<typename T>
//return size
int MyArray<T>::getSize()const {
	return size;
}

template<typename T>
//return capacity
int MyArray<T>::getCapacity()const {
	return capacity;
}

template<typename T>
T& MyArray<T>::operator[](int value) {
	return data[value];
}

template<typename T>
T MyArray<T>:: operator[](int value)const {
	return data[value];
}

template<typename T >
T& MyArray<T>::at(int value) {
	if (value < size) {
		return data[value];
	}
	else {
		throw  std::out_of_range(" Out of range!!");
	}
}

template<typename T>
T MyArray<T>::at(int  value) const {
	if (value < size) {
		return data[value];
	}
	else {
		throw  std::out_of_range(" Out of range!!");
	}
}

template<typename T>
void MyArray<T>::shrink_to_fit() {
	capacity = size;
}

template<typename T >
void MyArray<T>::clear() {
	delete[]data;
	size = 1;
	data = new T[size]();
}

template<typename T>
bool MyArray<T>::isEmpty() {

	for (int i = 0; i < size; i++) {
		if (data[i] != '\0') {
			return false;
		}
	}
	return true;
}
