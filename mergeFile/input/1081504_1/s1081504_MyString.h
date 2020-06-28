#ifndef S1081504_MyString_H
#define S1081504_MyString_H
#include <iostream>
#include <string>
#include "s1081504_MyArray.cpp"

using namespace std;

class MyString : public MyArray<char>
{
	friend ostream &operator<<(ostream& output, const MyString& str);
	friend istream &operator>>(istream& in, MyString& right);
public:

	MyString();
	MyString(const MyString& str);
	MyString(const MyString& str, size_t pos, size_t len = msize); 
	MyString(const char* s);
	~MyString();

	static const size_t msize = -1;

	MyString& append(const MyString& str);
	MyString substr(size_t pos, size_t len = msize) const;
	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize);
	MyString& erase(size_t pos, size_t len = msize);
	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const MyString& str, size_t pos = 0) const;

};

#endif