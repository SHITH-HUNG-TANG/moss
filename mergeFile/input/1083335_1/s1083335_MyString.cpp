#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <limits.h>
#include<string>
#include"s1083335_MyString.h"
using namespace std;

MyString::MyString() 
	: MyArray()
{   }

MyString::MyString(const MyString& str)
	: MyArray(str)
{	}

MyString::MyString(const MyString& str, size_t pos, size_t len ) 
	: MyArray(5,'b')
{
	resize(str.getSize() - pos, ' ');
}

MyString::MyString(const char* s)
	: MyArray(1, 'a')
{
	if (NULL == s) { 
		resize(1,' ');
	}        
	int size = strlen(s);
	resize(size+1, '1');

	int i;
	for (i = 0;i < size;i++) {
		at(i) = s[i];
	}
	at(i) = '\0';
}

MyString::~MyString()
{   }
 
istream& operator>>(istream& in, MyString& right) {

	string temp;
	in >> temp;
	right.resize(temp.length(), '\0');
	for (int i = 0;i < right.getSize();i++) {
		right[i] = temp[i];
	}
	return in;
}

MyString& MyString::append(const MyString& str)
{
	*this += str;
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	if ((pos + len) >= getSize()) {
		throw Error(); 
	}  
	MyString x;        
	x.resize(len+1, '0');
	int i;
	int j = 0;
	for (i = pos;i < pos + len; i++) {
		x.at(j++) = at(i);
	}
	x.at(j) = '\0';
	return x;	
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	if (pos >= getSize()) {
		throw Error();
	}
	MyString x;
	x.resize(getSize() + str.getSize() + 1, '0');	
	int i = 0, j = 0, k = 0;

	for (i = 0;i < pos; i++) {
		x.at(j++) = at(i);
	}
	for (k = 0;k < str.getSize();k++) {
		x.at(j++) = str.at(k);
	}
	for (i = pos;i < getSize();i++) {
		x.at(j++) = at(i);
	}
	x.at(j) = '\0';

	*this = x;
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	if (pos >= getSize()) {
		throw Error();
	}
	if (subpos >= str.getSize()) {
		throw Error();
	}
	MyString x;
	x.resize(getSize() + sublen + 1, '0');
	int i = 0, j = 0, k = 0;

	for (i = 0;i < pos; i++) {
		x.at(j++) = at(i); //cc_
	}
	for (k = subpos;k < subpos + sublen;k++) { //1+2
		x.at(j++) = str.at(k);
	}
	for (i = pos;i < getSize();i++) {
		x.at(j++) = at(i);
	}
	x.at(j) = '\0';

	*this = x;
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (pos >= getSize()) {
		throw Error();
	}
	MyString x;
	x.resize(getSize() - len + 1, '0');
	int i = 0, j = 0, k = 0;

	for (i = 0;i < pos; i++) {
		x.at(j++) = at(i);
	}
	for (i = pos+len;i < getSize();i++) {
		x.at(j++) = at(i);
	}
	x.at(j) = '\0';

	*this = x;
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos ) const
{
	if (pos >= getSize()) {
		throw Error();
	}

	int i = 0, j = 0, k = 0, flag = 0;
	char firstC=str.at(0);

	for (i = 0;i < getSize()-str.getSize(); i++) {
		flag = 0;
		if (at(i) == firstC) {
			for (k = 0;k < str.getSize();k++) {
				if (at(i + k) != str.at(k)) {
					flag = 1;
				}
			}	
			if (flag == 0) {
				return i;
			}
		}
	}
	return -1;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	if (pos >= getSize()) {
		throw Error();
	}
	int i = 0, j = 0, k = 0, flag = 0;
	char firstC = str.at(0);

	for (i = 0;i < getSize() - str.getSize(); i++) {
		for (k = 0;k < str.getSize();k++) {
			if (at(i) == str.at(k)) {
				return i;
			}
		}
	}
	return -1;
}
