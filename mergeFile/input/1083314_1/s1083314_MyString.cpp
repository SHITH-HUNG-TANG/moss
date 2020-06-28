#include <cstdint>
#include"s1083314_MyArray.h"
#include"s1083314_MyString.h"

template<typename T>
MyString<T>::MyString(const MyString& str, size_t pos, size_t len)
{
	MyArray<T>* it1 = this;
	const MyArray<T>* it2 = &str;
	it1->resize(len, T());
	int i = 0;
	for (unsigned int i = 0, j = pos; i < len; i++, j++) {
		it1->at(i) = it2->at(j);
	}
}

template<typename T>
MyString<T>::MyString(const char* s)
{
	MyArray<T>* it = this;
	it->resize(strlen(s), T());
	for (unsigned int i = 0; i < it->getSize(); i++) {
		it->at(i) = s[i];
	}
}

template<typename T>
MyString<T>::~MyString() {}

template<typename T>
MyString<T>& MyString<T>::append(const MyString<T>& str)
{
	MyArray<T>* Sum = this;
	const MyArray<T>* Str = &str;
	int i = Sum->getSize();
	Sum->resize(Sum->getSize() + Str->getSize(), T());
	for (unsigned int j = 0; j < Str->getSize(); i++, j++)
		Sum->at(i) = Str->at(j);
	return *this;
}

template<typename T>
MyString<T> MyString<T>::substr(size_t pos, size_t len) const
{	
	return MyString<T>(*this, pos, len);//msize?
}

template<typename T>
MyString<T>& MyString<T>::insert(size_t pos, const MyString& str)
{
	MyArray<T>* Sum = this;
	const MyArray<T>* Str = &str;
	
	int newSize = Sum->getSize() + Str->getSize();
	int originSize = Sum->getSize();
	int Site = pos;
	Sum->resize(newSize, T());

	/*for (int i = pos; i < originSize; i++) {
		Sum->at(i + Str->getSize()) = Sum->at(i);
	}*/
	for (int i = originSize-1; i > pos-1; i--) {
		Sum->at(i + Str->getSize()) = Sum->at(i);
	}
	for (int i = 0; i < Str->getSize(); i++) {
		Sum->at(Site) = Str->at(i);
		Site++;
	}
	
	return *this;
}

template<typename T>
MyString<T>& MyString<T>::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	//MyString<T>* Sum = this;
	//const MyArray<T>* Str = new MyString<T>(str, subpos, sublen);
	//Sum->insert(pos, Str);
	MyString<T> New(str, subpos, sublen);
	insert(pos, New);
	return *this;
}

template<typename T>
MyString<T>& MyString<T>::erase(size_t pos, size_t len)
{
	MyString<T>* Sum = this;
	for (int i = pos; i < Sum->getSize()-len; i++)
		Sum->at(i) = Sum->at(i + len);
	Sum->getSize() -= len;
	return *this;
}

template<typename T>
size_t MyString<T>::find(const MyString& str, size_t pos) const
{
	const MyString<T>* Sum = this;
	const MyArray<T>* Str = &str;

	if (Str->getSize() == 0 || Str->getSize() > Sum->getSize())
		return -1;

	bool isFound = true;
	for (int i = pos; i < Sum->getSize(); i++) {
		isFound = true;
		for (int j = 0; j < Str->getSize(); j++) {
			if (Sum->at(i + j) != Str->at(j)) {
				isFound = false;
				break;
			}
		}
		if (isFound)
			return i;
	}
	if (!isFound)
		return -1;
}


template<typename T>
size_t MyString<T>::find_first_of(const MyString& str, size_t pos) const
{
	const MyString<T>* Sum = this;
	const MyArray<T>* Str = &str;

	if (Str->getSize() == 0 || Str->getSize() > Sum->getSize())
		return -1;

	bool isFound = false;
	for (int i = pos; i < Sum->getSize(); i++) {
		for (int j = 0; j < Str->getSize(); j++) {
			if (Sum->at(i) == Str->at(j)) {
				isFound = true;
				return i;
			}

		}
	}

	//if (!isFound)
		return -1;
}

template class MyString <char>;


































//#pragma once
//#ifndef S1083314_MyString_H
//#define S1083314_MyString_H
//#include <iostream>
//#include "s1083314_MyArray.h"
//using namespace std;
//
//template<typename T>
//class MyString : public MyArray<T>
//{
//	//friend ostream &operator<<(ostream& output, const MyString& str);
//
//public:
//	MyString() :MyArray<T>::myCapacity(10), MyArray<T>::mySize(0), MyArray<T>::data(new T[10]()) {}
//	// Constructs an empty string, with a length of zero characters. 
//	// *default capacity = 10
//
//
//	MyString(const MyString& str);// : MyArray<T>::Capacity(str.getCapacity()), MyArray<T>::Size(str.getSize()), MyArray<T>::data(str.data) {}
//		/*MyArray<T>::Capacity(str.getCapacity());
//		MyArray<T>::Size(str.getSize());
//		MyArray<T>::data(str.data);
//	}*/
//	// Constructs a copy of "str". (copy constructor)
//
//
//	MyString(const MyString& str, size_t pos, size_t len = msize); /*{
//		this->getSize(len);
//		if (len > 10)
//			this->getCapacity(len);
//		else
//			this->getCapacity(10);
//
//		this->data = new T[this->getCapacity()]();
//		int i = 0;
//		for (int j = pos; i < len, j < pos + len; j++, i++) {
//			*(this->data + i) = *(str + j);
//		}
//	}*/
//	// (substring constructor)
//	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
//	// (or until the end of str, if either str is too short or if len is string::msize).
//
//	MyString(const char* s);
//	// Copies the array of character (C-string) pointed by s.
//	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
//	// The sequence is copied as the new value for the string.
//
//	~MyString(); /*{
//		if (data != nullptr) {
//			delete[]data;
//		}
//	}*/
//	// Destroys the string object.
//
//	static const size_t msize = -1;
//	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.
//
//	MyString& append(const MyString& str); /*{
//		MyString<T> Add(*this);
//		Add.getSize() = str.getSize() + this->getSize();
//		Add.resize(Add.getSize());
//
//		int i = this->getSize();
//		for (int j = 0; j < str.getSize(); i++, j++)
//			Add[i] = str[j];
//
//		return Add;
//	}*/
//	// Appends a str on the tail of current MyString. 
//	// *Return the reference of itself
//
//	MyString substr(size_t pos, size_t len = msize) const; /*{
//		MyString<T> Sub(*this, pos, len);
//
//		return Sub;
//	}*/
//	// The substring is the portion of the object that starts at character position pos and spans len characters 
//	// (or until the end of the string, whichever comes first).
//	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
//
//	MyString& insert(size_t pos, const MyString& str);
//	// Inserts a copy of a str at "pos".
//	// example: str = "to be question", str2 = "the "
//	// str.insert(6,str2); 
//	// = to be (the )question = to be the question
//	// *Return the reference of itself
//
//	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize);
//	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
//	// begins at the character position subpos and spans sublen characters (or until the end of str).
//	// example: str = "to be the question", str3 = "or not to be"
//	// str.insert(6,str3,3,4); // to be (not )the question
//	// *Return the reference of itself
//
//	MyString& erase(size_t pos, size_t len = msize);
//	// Erases the portion of the string value that begins at the character position pos and spans len characters 
//	// (or until the end of the string, if either the content is too short or if len is string::msize.)
//	// *Return the reference of itself
//
//	size_t find(const MyString& str, size_t pos = 0) const;
//	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
//	// for the first occurrence of the string str.
//	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.
//
//	size_t find_first_of(const MyString& str, size_t pos = 0) const;
//	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
//	// for the first character that matches *any* of the characters of the string str.
//	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
//
//	//You may add several helper functions or operators here
//	//...
//}; // end class MyString
//
//#endif //S1083314_MyString_H

