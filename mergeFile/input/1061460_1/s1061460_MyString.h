//s1061460 hw7-1 myarray
#ifndef PG2MyString_H
#define PG2MyString_H
#include<iostream>
#include<math.h>
#include<string>
#include <exception>
#include <stdexcept> 
using namespace std;

template<typename T>
class MyArray {
	friend ostream& operator<<(ostream& output, const  MyArray& A) {
		for (int i = 0; i < A.size; i++) {
			output << " " << A.ptr[i] << ",";
		}
		return output;
	}

public:
	MyArray(int c = 10);
	MyArray(int Size, T value);
	MyArray(const MyArray& A);
	~MyArray();
	int getSize() const;
	int getCapacity() const;
	void resize(int s);
	void resize(size_t s, T c);
	void reserve(size_t c);
	const MyArray& operator=(const MyArray& right);
	bool operator==(const MyArray& right) const;
	bool operator!=(const MyArray& right) const;
	MyArray operator+(const MyArray& right)
	{
		MyArray x(*this);
		int size2 = size + right.size;
		ptr = new T[size2];
		for (int q = 0; q < size; q++) {
			ptr[q] = x.ptr[q];
		}
		int i = 0;
		for (int j = size; j < size2; j++) {
			if (i < right.size)
				ptr[j] = right.ptr[i];
			i++;
		}
		size = size2;
		return *this;
	}	//new
	MyArray& operator+=(const MyArray& right)
	{
		MyArray x(*this);
		int size2 = size + right.size;
		ptr = new T[size2];
		for (int q = 0; q < size; q++) {
			ptr[q] = x.ptr[q];
		}
		int i = 0;
		for (int j = size; j < size2; j++) {
			if (i < right.size)
				ptr[j] = right.ptr[i];
			i++;
		}
		size = size2;
		return *this;
	}
	T& operator[](int sub) {
		return ptr[sub]; // reference return
	}
	T operator[](int sub)const {
		return ptr[sub]; // const reference return
	}
	void shrink_to_fit() {
		capacity = size;
	}	//new
	void clear() {
		delete[] ptr;
		size = 0;
	}
	bool isEmpty() {
		if (size != 0)
			return false;
		else
			return true;
	}

	T& at(int a) {
		if (a < 1 || a >= size)
			throw out_of_range("out of range\n");
		return ptr[a];
	}

protected:
	int size;
	int capacity;
	T* ptr;

};

template<typename T>
class MyString : public MyArray<char>
{
	//friend ostream &operator<<(ostream& output, const MyString& str);

public:
	MyString() {
		size = 0;
		capacity = 10;
		ptr = new T[capacity]();
	}
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString(const MyString& str)
		//:MyArray(str)
	{
		size = str.size;
		capacity = str.capacity;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = str.ptr[i];
	}
	// Constructs a copy of "str". (copy constructor)

	MyString(const MyString& str, size_t pos, size_t len = msize) {
		while (len > capacity)
			reserve(capacity * 2);
		if (len > size)
			for (int i = 0; i < len; i++) {
				ptr[i] = str[pos + i];
			}
		size = len;
	}// (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char* s) {
		size = strlen(s);
		reserve(size);
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = s[i];
	}
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	~MyString()
	{
	}
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append(const MyString& str) {
		*this += str;
		return *this;
	}
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, const size_t len) {
		MyString la(*this);
		MyString nw;
		nw.resize(len, 0);
		int j = 0;
		for (int i = pos; i < pos + len; i++) {
			nw[j] = la[i];
			j++;
		}
		//nw.ptr[len] = '\0';
		return nw;
	}
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString& str) {
		char* last = ptr;
		size += str.size;
		//reserve(size);
		int j = 0;
		ptr = new char[size];
		for (int i = 0; i < pos; i++) {
			ptr[i] = last[i];

		}
		for (int i = pos; i < pos + str.size; i++) {

			ptr[i] = str.ptr[j];
			j++;
		}
		for (int i = pos + str.size; i < size; i++) {
			ptr[i] = last[i - str.size];
		}
		*(ptr + size) = '\0';
		return *this;
	}
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize) {
		char* last = ptr;
		size += sublen;
		reserve(size);
		int j = 0;
		ptr = new char[size];
		for (int i = 0; i < pos; i++) {
			*(ptr + i) = *(last + i);
		}
		for (int i = pos; i < pos + sublen; i++) {
			*(ptr + i) = str.ptr[subpos + j];
			j++;
		}
		for (int i = pos + sublen; i < size; i++) {
			*(ptr + i) = last[i - sublen];
		}
		*(ptr + size) = '\0';
		return *this;
	}
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize) {
		char* last = ptr;
		size -= len;
		ptr = new char[size];
		for (int i = 0; i < pos; i++) {
			ptr[i] = last[i];
		}
		for (int i = pos; i < size; i++) {
			ptr[i] = last[i + len];
		}
		*(ptr + size) = '\0';
		return *this;
	}
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString& str, size_t pos = 0) const {
		/*if (str == NULL || pos >= size)
			throw out_of_range("msize(-1)");
		//return MyString::msize;
		size_t a;
		int count = 0;
		for (int i = 0; i < str.size; i++) {
			for (int j = pos; j < size; j++) {
				if (str.ptr[i] == ptr[j])
				{
					for (int k = 0; k < size; k++) {
						if (str[i + k] == ptr[j + k]) {
							count++;
						}
					}
				}
				if (count == size - pos)
					a = j;
			}
		}
		return a;*/
		if (str == NULL || pos >= size)
			throw out_of_range("msize(-1)");
		//return MyString::msize;
		size_t a;
		int count = 0;
		int min_index;
		int test = 0;
		for (int i = 0; i < str.size; i++) {
			for (int j = pos; j < size; j++) {
				if (str.ptr[i] == ptr[j])
				{
					for (int k = 0; k < size - pos; k++) {
						if (str[i + k] == ptr[j + k]) {
							count++;
						}
					}
				}
				if (count == size - pos) {
					a = i;
					test++;
					if (test == 1)
						min_index = a;
					min_index = min_index < a ? min_index : a;
				}
			}
		}
		return min_index;
	}
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString& str, size_t pos = 0) const {
		if (str == NULL || pos >= size)
			throw out_of_range("msize(-1)");
		//return MyString::msize;
		int coun;
		int min_index;
		int test = 0;
		for (int i = 0; i < str.size; i++) {
			for (int j = pos; j < size; j++) {
				if (str.ptr[i] == ptr[j])
				{
					coun = i;
					test++;
					if (test == 1)
						min_index = coun;
					min_index = min_index < coun ? min_index : coun;
				}

			}
		}
		return min_index;
	}
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif