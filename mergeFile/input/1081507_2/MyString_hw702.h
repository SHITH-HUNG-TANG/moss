#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include<cstring>
#include<string>
#include <cmath>
#include "MyArray_hw701.h"
using namespace std;

class MyString : public MyArray<char>
{
	friend ostream &operator<<(ostream& output, const MyString& a);
	friend istream &operator>>(istream &input, MyString& a);
public:
	MyString() :MyArray(10) {};// Constructs an empty string, with a length of zero characters. // *default capacity = 10
	~MyString() {};
	MyString(const MyString &str) :MyArray((const MyArray&)str){}

	MyString(const MyString &str, size_t pos, size_t len = msize) 
		:MyArray()
	{
		resize(len,NULL);
		for (int i = pos; i < pos+len; i++)
			(*this)[i-pos]=str[i];
	} // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char *s)
		:MyArray()
	{
		resize(strlen(s),NULL);
		for (int i = 0; i < strlen(s); i++)
			(*this)[i] = *s;
		//strcpy_s(s,strlen(s),(*this));
	}// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	static const size_t msize = -1;//Note: maximum size. You may use SIZE_MAX at <cstdint>,too.

	MyString& append(const MyString &str);
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const;
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString &str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen = msize);
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize);
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString &str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString &str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
};
istream &operator>>(istream &input, MyString& a)
{
	string num;
	input >> num;

	a.resize(num.size(), NULL);

	for (int i = 0; i < num.size(); i++)
		a[i] = num[i];

	return input;
}
ostream &operator<<(ostream& output, const MyString& a) {
	output << (const MyArray<char>&)a;
	/*for (int i = 0; i < a.getSize(); i++)
	{
		output << a[i];
		if (i != a.getSize() - 1) output << ",";
	}
	output << endl;*/
	return output;
}
MyString &MyString::append(const MyString &str) {
	(*this) += str;
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const {
	MyString s;
	s.resize(len, NULL);
	int tmp = pos + len;
	for (int i = pos; i < tmp; i++)
		s[i - pos] = (*this)[i];
	return s;
}
MyString &MyString::insert(size_t pos, const MyString &str) {
	MyString s;
	s.resize((*this).getSize() + str.getSize(), NULL);
	for (int i = 0; i < pos; i++)
		s[i] = (*this)[i];
	for (int i = pos; i < str.getSize() + pos; i++)
		s[i] = str[i - pos];
	for (int i = str.getSize() + pos; i < str.getSize() + (*this).getSize(); i++)
		s[i] = (*this)[i - str.getSize()];

	*this = s;

	return *this;
}
MyString &MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen) {
	MyString s2;
	s2.resize(sublen - subpos + 1, NULL);//s2.getSize()
	for (int i = 0; i < sublen - subpos + 1; i++)
		s2[i] = str[i + subpos];

	return insert(pos, s2);
}
MyString &MyString::erase(size_t pos, size_t len) {
	MyString s4;
	s4.resize((*this).getSize()-len, NULL);

	for (int i = 0; i < pos; i++)
		s4[i] = (*this)[i];
	for (int i = pos; i < s4.getSize() + pos; i++)
		s4[i] = (*this)[i +len];

	(*this) = s4;

	return *this;
}
size_t MyString::find(const MyString &str, size_t pos) const {
	MyString tmp = *this;

	for (int i = pos; i < (*this).getSize(); i++) {
		if (tmp[i] == str[0]) {
			tmp=tmp.substr(i, str.getSize());
			if (tmp == str)return i;
		}
	}

	return msize;
}
size_t MyString::find_first_of(const MyString &str, size_t pos) const {
	int tmp = (*this).getSize();

	for (int i = pos; i < (*this).getSize(); i++)
		for (int j = 0; j < str.getSize(); j++)
			if ((*this)[i] == str[j] && tmp > j)
				tmp = j;

	if (tmp == (*this).getSize())return msize;
	else return tmp;
}
#endif;