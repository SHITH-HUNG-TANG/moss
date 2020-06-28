#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include "MyArray_hw701.h"
using namespace std;


class MyString : public MyArray<char>
{
	/*template<char>friend ostream &operator<<(ostream& output, const MyString<char>& str);
	template<char>friend istream &operator>>(istream& in, MyString<char>&str);*/

public:
	MyString(); 
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString( const MyString &str ); 
	// Constructs a copy of "str". (copy constructor)

	MyString( const MyString &str, size_t pos, size_t len = msize ); // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString( const char *s ); 
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	~MyString(); 
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append( const MyString &str ); 
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const;
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert( size_t pos, const MyString &str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert( size_t pos, const MyString &str, size_t subpos, size_t sublen = msize );
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase( size_t pos, size_t len = msize ); 
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find( const MyString &str, size_t pos = 0 ) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of( const MyString &str, size_t pos = 0 ) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString
//constructor
MyString::MyString():MyArray() {
	
}

 //copy constructor
MyString::MyString(const MyString& str):MyArray(str) {
}
 //substr constructor
MyString::MyString(const MyString& str, size_t pos, size_t len) {
	while (len > getCapacity()) {
		reserve(2 * getCapacity());
	}
	setSize(len);
	for (int i = 0; i < len; i++) {
		setValue(i, str.getValue(pos));
		pos++;
	}
}

     //
MyString::MyString(const char* s):MyArray() {
	if (strlen(s) > getCapacity()) {
		reserve(2 * getCapacity());
	}
	for (int i = 0; i < strlen(s); i++) {
		setValue(i, s[i]);
	}
	setSize(strlen(s));
}


MyString::~MyString() {
}


MyString& MyString::append(const MyString& str) {
	int k = getSize() + str.getSize();
	while (k > getCapacity()) {
		reserve(2 * getCapacity());
	}
	int t = 0;
	for (int i = getSize(); i < k; i++) {
		
		setValue(i,str.getValue(t));
		t++;
	}
	setSize(k);
	return *this;
}



MyString MyString::substr(size_t pos, size_t len) const {
	MyString str2;
	while (str2.getCapacity() < len) {
		str2.reserve(2 * str2.getCapacity());
	}
	str2.setSize(len);
	
	for (int i = 0; i < len; i++) {
		str2.setValue(i,getValue(pos));
		pos++;
	}
	return str2;
}


MyString& MyString::insert(size_t pos, const MyString& str) {
	if (pos < getSize()) {
		while (getSize() + str.getSize() > getCapacity()) {
			reserve(2 * getCapacity());
		}
		for (int i = getSize() - 1; i >= pos; i--) {
			setValue(i + str.getSize(), getValue(i));
		}
		for (int i = 0; i < str.getSize(); i++) {
			int k = 0;
			setValue(pos, str.getValue(k));
			pos++;
			k++;
		}
		setSize(getSize() + str.getSize());
	}
	else {
		cout << "not insert" << endl;
	}
	return *this;
}


MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen) {
	if (pos < getSize()) {
		while (getSize() + sublen > getCapacity()) {
			reserve(2 * getCapacity());
		}
		for (int i = getSize() - 1; i >= pos; i--) {
			setValue(i + sublen, getValue(i));
		}
		for (int i = 0; i < sublen; i++) {
			setValue(pos, str.getValue(subpos));
			pos++;
			subpos++;
		}
		setSize(getSize() + sublen);
	}
	else {
		cout << "not insert" << endl;
	}
	
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len) {
	for (int i = 0; i < len; i++) {
		setValue(pos, NULL);
		pos++;
	}
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const {
	for (int i = pos; i < getSize(); i++) {
		if (str.getValue(0) == getValue(i)) {
			int t = i;
			i++;
			int k = 1;
			while (k < str.getSize()) {
				if (str.getValue(k) == getValue(i)) {
					k++;
					i++;
				}
				else {
					break;
				}
			}
			if (k == 4) {
				return t;
			}
		}
			
	}
	return msize;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const {
	for (int i = pos; i < getSize(); i++) {
		for (int k = 0; k < str.getSize(); k++) {
			if (str.getValue(k) == getValue(i)) {
				return i;
			}
		}
	}
	return msize;
}

/*template <char>
ostream& operator<<(ostream& output, const MyString<char>& str) {
	for (int i = 0; i < str.getSize(); i++) {
		output << str.getValue(i);
	}
	return output;
}
template <char>
istream& operator>>(istream& in, MyString<char>& str) {
	string digit;
	in.get(digit);
	while (str.getCapacity() < digit.length()) {
		str.reserve(2 * str.getCapacity());
	}
	for (int i = 0; i < digit.length(); i++) {
		str.setValue(i, digit[i]);
	}
	return in;
}*/
#endif