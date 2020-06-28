#include "s1083313_MyString.h"
#include<iostream>
using namespace std;
MyString::MyString()
	:MyArray(10, 'o')
{
}

MyString::MyString(const MyString& str)
	: MyArray(str)
{
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
	: MyArray(10, ' ')
{
	if (len == msize) {
		resize(str.getSize() - pos, ' ');

	}
	else
	{
		resize(len, ' ');
	}
	for (int i = 0; i < getSize(); i++)
	{
		at(i) = str.at(i + pos);

	}
}

MyString::MyString(const char* s)
	:MyArray(10, 'r')
{
	int a = 0;
	int b = 0;
	int count = 0;
	while (*(s + a) != '\0') { count++; a++; }
	resize(count, 'x');
	while (*(s + b) != '\0') { at(b) = *(s + b); b++; }
}

MyString::~MyString()
{

}

MyString& MyString::append(const MyString& str)
{
	MyString a;
	a.resize(this->getSize() + str.getSize(), 'a');
	for (int i = 0; i < getSize(); i++) { a.at(i) = at(i); }
	for (int i = getSize(); i < a.getSize(); i++) { a.at(i) = str.at(i - getSize()); }
	*this = a;
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString a;
	if (len == msize) {
		a.resize(getSize() - pos, ' ');

	}
	else
	{
		a.resize(len, ' ');
	}
	for (int i = 0; i < a.getSize(); i++)
	{
		a.at(i) = at(i + pos);

	}

	return a;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString a;
	a.resize(getSize() + str.getSize(), 'x');
	for (int i = 0; i < pos; i++) { a.at(i) = at(i); }
	for (int i = 0; i < str.getSize(); i++) { a.at(i + pos) = str.at(i); }
	for (int i = 0; i < a.getSize() - (pos+str.getSize()); i++) { a.at(pos + str.getSize() + i) = at(i + pos); }
	*this = a;
	return *this;
	// TODO: 於此處插入 return 陳述式
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	if (sublen == msize) { sublen = (str.getSize() - pos); }
	MyString a;
	a.resize(getSize() + sublen, 'x');
	for (int i = 0; i < pos; i++) { a.at(i) = at(i); }
	for (int i = 0; i < sublen; i++) { a.at(i + pos) = str.at(i + subpos); }
	for (int i = 0; i < a.getSize() - (pos+sublen); i++) { a.at(sublen + pos + i) = at(i + pos); }
	*this = a;
	return *this;

	// TODO: 於此處插入 return 陳述式
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == msize)
	{
		len = getSize() - pos;
		
		for (int i = pos; i < getSize(); i++) { at(i) = ' '; }
		resize(getSize() - len, 'x');
	}
	else
	{ 
		MyString a;

		a.resize(getSize() - len, 'x');
		for (int i = 0; i < pos; i++) { a.at(i) = at(i); }

		for (int i = 0; i < getSize() - (pos + len); i++) { a.at(pos + i) = at(i + (len+ pos)); }
		*this = a;
	
	}
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	int flag = 0,aaa=0;
	for (int i = 0; i < getSize() - (str.getSize()- pos);i++)
	{
		if (at(i)==str.at(pos))
		{
			flag = 0;
			int x = 1;
			for (int a = i + 1; a < ((str.getSize() - pos)+(i));a++) 
			{
				if (at(a) != str.at(pos + x)) { flag = 0; break; }
				else { flag = 1; aaa = i; }
				x++;
			}
			if (flag == 1) { return   aaa; }
		}		 
	}
return msize; 
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	if ((str.getSize() - pos) > getSize()) { return msize; }
	for (int i = 0; i < getSize();i++) 
	{
		for (int j = pos; j < str.getSize() - pos; j++)
		{
			if (at(i)==str.at(pos+j)) { return i; }
		}
	}

	return msize;
}

istream& operator>>(istream& input, MyString& a)
{
	string inp;
	input >> inp;
	//	for (int i = a.size - 1; i >= 0; i--)
	//		input >> a.data[i];
	int len = inp.length();
	char* ptr = new char[len + 1];
	inp.copy(ptr, len, 0);
	ptr[len] = '\0';

	MyString nnn(ptr);
	a = nnn;
	delete[] ptr;

	return input;
}