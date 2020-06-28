#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include <string>
#include "s1081528_MyArray.h"
using namespace std;

class MyString : public MyArray <char> {
	friend ostream &operator<<(ostream& output, const MyString& str)
	{
		for (int i = 0; i < str.getSize(); i++) {
			output << str[i];
		}
		return output;
	}

	friend istream &operator>>(istream& input, MyString& str)
	{
		string s;
		getline(input, s);
		str.resize(s.length(), 0);
		for (int i = 0; i < str.getSize(); i++) {
			str[i] = s[i];
		}
		return input;
	}

public:
	MyString()
	{
		(*this).reserve(10);
	}
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString(const MyString &str)
	{
		(*this).resize(str.getSize(), 0);
		for (int i = 0; i < str.getSize(); i++) {
			(*this)[i] = str[i];
		}
	}
	// Constructs a copy of "str". (copy constructor)

	MyString(const MyString &str, size_t pos, size_t len = msize)
	{
		try {
			str.at(pos);
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
		}
		if (pos < str.getSize()) {
			if (len == msize || len > str.getSize()) {
				(*this).resize(str.getSize() - pos, 0);
				for (int i = 0, j = pos; j < str.getSize(); i++, j++) {
					(*this)[i] = str[j];
				}
			}
			else {
				(*this).resize(len, 0);
				for (int i = 0, j = pos; i < len, j < pos + len; i++, j++) {
					(*this)[i] = str[j];
				}
			}
		}	
	}
	// (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char *s)
	{
		(*this).resize(strlen(s), 0);
		for (int i = 0; i < (*this).getSize(); i++) {
			(*this)[i] = s[i];
		}
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

	MyString& append(const MyString &str)
	{
		MyString temp;
		temp.resize((*this).getSize() + str.getSize(), 0);
		for (int i = 0; i < (*this).getSize(); i++) {
			temp[i] = (*this)[i];
		}
		for (int i = (*this).getSize(), j = 0; i < temp.getSize(), j < str.getSize(); i++, j++) {
			temp[i] = str[j];
		}
		*this = temp;
		return *this;
	}
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const
	{
		MyString temp((*this), pos, len);
		return temp;
	}
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString &str)
	{
		try {
			(*this).at(pos);
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return *this;
		}
		MyString temp;
		temp.resize((*this).getSize() + str.getSize(), 0);
		for (int i = 0; i < pos; i++) {
			temp[i] = (*this)[i];
		}
		for (int i = pos, j = 0; i < str.getSize() + pos, j < str.getSize(); i++, j++) {
			temp[i] = str[j];
		}
		for (int i = str.getSize() + pos, j = pos; i < temp.getSize(), j < (*this).getSize(); i++, j++) {
			temp[i] = (*this)[j];
		}
		*this = temp;
		return *this;		
	}
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen = msize)
	{
		MyString tmp(str, subpos, sublen);
		(*this).insert(pos, tmp);
		return *this;
	}
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize)
	{
		try {
			(*this).at(pos);
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return *this;
		}
		if (len == msize || len > (*this).getSize()) {
			for (int i = pos; i < (*this).getSize(); i++) {
				(*this)[i] = 0;
			}
			(*this).resize(pos - 1, 0);
		}
		else {
			for (int i = pos; i < pos + len; i++) {
				(*this)[i] = 0;
			}
			for (int i = pos, j = pos + len; j < (*this).getSize(); i++, j++) {
				(*this)[i] = (*this)[j];
				(*this)[j] = 0;
			}
			(*this).resize((*this).getSize() - len, 0);
		}
		return *this;
	}
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString &str, size_t pos = 0) const
	{
		try {
			(*this).at(pos);
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return msize;
		}
		int i;
		bool f = false;
		for (i = pos; i < (*this).getSize(); i++) {
			MyString temp;
			temp = (*this).substr(i, str.getSize());
			if (temp == str) {
				f = true;
				break;
			}
		}
		if (f) {
			return i;
		}
		return msize;
	}
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString &str, size_t pos = 0) const
	{
		try {
			(*this).at(pos);
		}
		catch (out_of_range &e) {
			cout << e.what() << endl;
			return msize;
		}
		int i;
		bool f = false;
		for (i = pos; i < (*this).getSize(); i++) {
			for (int j = 0; j < str.getSize(); j++) {
				if ((*this)[i] == str[j]) {
					f = true;
					break;
				}
			}
			if (f) {
				break;
			}
		}
		if (f) {
			return i;
		}
		return msize;
	}
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif