#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include "s1072031_MyArray.h"
#include "s1072031_MyArray.cpp"
using namespace std;

class MyString : public MyArray <char>
{
	/*friend ostream& operator<<(ostream& output, const MyString& str) {
		for (int i = 0; i < str.size; i++) {
			output << str.data[i] << " ";
		}
		output << endl;
		return output;
	}*/

public:
	MyString();
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10
	MyString(const char s) :MyArray<char>() {
		size = 1;
		(*this).data[0] = s;
	}

	MyString(const MyString& str);
	// Constructs a copy of "str". (copy constructor)

	MyString(const MyString& str, size_t pos, size_t len = msize); // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char* s);
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	//~MyString();
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append(const MyString& str);
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const;
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString& str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize);
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize);
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	int find(const MyString& str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	int find_first_of(const MyString& str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.



}; // end class MyString
MyString::MyString() :MyArray<char>() {

}
MyString::MyString(const MyString& str) : MyArray<char>() {
	*this = str;
}
MyString::MyString(const MyString& str, size_t pos, size_t len) : MyArray<char>() {
	*this = str.substr(pos, len);
}
MyString::MyString(const char* s) : MyArray<char>() {

	while (*s != '\0') {
		MyString tmp(*s);
		append(tmp);
		++s;
	}
}
MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString temp;
	temp.resize(size + str.size); 
	
	for (int i = 0; i < pos; i++) {
		temp.data[i] = data[i];
	}
	
	for (int i = 0; i < str.size; i++) {
		temp.data[pos + i] = str.data[i];
	}
	
	for (int i = 0; i < size-pos; i++) {
		temp.data[pos + i + str.size] = data[pos + i];
	}
	
	*this = temp;
	return *this;
}
MyString& MyString::append(const MyString& str) {
	*this += str;
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
	MyString tmp;
	tmp.size = len;
	for (int i = 0; i < len; i++) {
		tmp.data[i] = (*this).data[pos + i];
	}
	return tmp;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen) {
	MyString tmp;
	tmp.resize(size + sublen);
	for (int i = 0; i < pos; i++) {
		tmp.data[i] = data[i];
	}
	for (int j = 0; j < sublen; j++) {
		tmp.data[pos + j] = str.data[subpos + j];
	}
	
	for (int j = 0; j < size - pos; j++) {
		tmp.data[pos +sublen+ j] = data[pos + j];
	}
	*this = tmp;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len) {
	MyString tmp;
	tmp.size = size - len;
	for (int i = 0; i < pos; i++) {
		tmp.data[i] = data[i];
	}
	for (int j = 0; j < tmp.size; j++) {
		tmp.data[pos + j] = data[pos + len + j];
	}
	*this = tmp;
	return *this;
}
int MyString:: find(const MyString& str, size_t pos) const {
	bool check = false;
	int n = 0;
	for (int i = pos; i < size; i++) {
		if (data[i] == str.data[0]) {
			for (int j = 1; j < str.size; j++) {
				if (data[i+j] != str.data[j]) {
					check = false;
				}
				else if (data[i + j] == str.data[j] && j == str.size - 1) {
					check = true;
					n = i;
					break;
				}
			}
		}
		if (check == true) {
			break;
		}
	}
	if (check == true) {
		return n;
	}
	else if(check==false) {
		return msize;
	}
}
int MyString::find_first_of(const MyString& str, size_t pos) const {
	int n;
	bool check = false;
	for (int i = pos; i < size; i++) {
		for (int j = 0; j < str.size; j++) {
			if (data[i] == str.data[j]) {
				check = true;
				n = i;
				break;
			}
		}
		if (check == true) {
			break;
		}
	}
	if (check == true) {
		return n;
	}else if (check == false) {
		return  msize;
	}
}
#endif