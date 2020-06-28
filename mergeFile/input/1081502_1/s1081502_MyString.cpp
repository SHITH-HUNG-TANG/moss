#include<iostream>
#include<cstdint>
#include<string>
#include"s1081502_MyString.h"
using namespace std;

MyString::MyString()
	:MyArray(){
}
MyString::MyString(const MyString& str)
	:MyArray(str){
}
MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	size_t newsize = 0;
	if (len == msize)
	{
		newsize = str.getSize() - pos;
	}
	else
	{
		newsize = len;
	}
	MyString newstr(str);
	resize(newsize);
	while (newsize > getCapacity())
	{
		reserve(getCapacity()*2);
	}
	for (int i = pos,j = 0; i < newsize + pos; i++, j++)
	{
		this->operator[](j) = newstr[i];
	}
}
MyString::MyString(const char* s)
{
	int newsize = 0;
	while (s[newsize] != '\0') {
		newsize++;
	}
	resize(newsize);
	while (newsize > getCapacity())
	{
		reserve(getCapacity() * 2);
	}
	for (int i = 0; i < newsize; i++)
	{
		this->operator[](i) = s[i];
	}
}
MyString::~MyString(){
}
MyString& MyString::append(const MyString& str)
{
	*this += str;
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
	MyString mystr(*this);
	MyString newstr;
	size_t newsize = 0;
	if (len == msize)
	{
		newsize = getSize() - pos;
	}
	else
	{
		newsize = len;
	}
	newstr.resize(newsize);
	for (int i = pos,j = 0; i < newsize + pos; i++, j++)
	{
		newstr[j] = mystr[i];
	}
	return newstr;
}
MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString mystr(*this);
	MyString newstr;
	int mysize = getSize();
	int frontsize = pos;
	int backsize = mysize - pos;
	int newsize = 0;
	newsize = str.getSize();
	newstr.resize(newsize + getSize());
	int position = 0;
	for (int i = 0; i < frontsize; i++)
	{
		newstr[i] = mystr[i];
		++position;
	}
	for (int i = 0; i < newsize; i++)
	{
		newstr[position] = str[i];
		++position;
	}
	for (int i = pos; i < backsize + pos ; i++)
	{
		newstr[position] = mystr[i];
		++position;
	}
	*this = newstr;
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString mystr(*this);
	MyString newstr;
	MyString tempstr;
	tempstr = str.substr(subpos, sublen);
	int mysize = getSize();
	int frontsize = pos;
	int backsize = mysize - pos;
	int newsize = 0;
	newsize = tempstr.getSize();
	newstr.resize(newsize + getSize());
	int position = 0;
	for (int i = 0; i < frontsize; i++)
	{
		newstr[i] = mystr[i];
		++position;
	}
	for (int i = 0; i < newsize; i++)
	{
		newstr[position] = tempstr[i];
		++position;
	}
	for (int i = pos; i < backsize + pos; i++)
	{
		newstr[position] = mystr[i];
		++position;
	}
	*this = newstr;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len)
{
	MyString mystr(*this);
	MyString newstr;
	int newsize = 0;
	if (len == msize)
	{
		newsize = pos;
		newstr.resize(newsize);
		for (int i = 0; i < pos; i++)
		{
			newstr[i] = mystr[i];
		}
	}
	else
	{
		newsize = getSize() - len;
		newstr.resize(newsize);
		int position = 0;
		for (int i = 0; i < pos; i++)
		{
			newstr[i] = mystr[i];
			++position;
		}
		for (int i = pos+len; i < getSize(); i++)
		{
			newstr[position] = mystr[i];
			++position;
		}
	}
	*this = newstr;
	return *this;
}
size_t MyString::find(const MyString& str, size_t pos) const
{
	MyString mystr(*this);
	int newsize = str.getSize();
	bool haveans = 0;
	int ans = 0;
	int position = 0;
	for (int i = pos; i < getSize(); i++)
	{
		position = i;
		if (str[0] == mystr[i] && haveans == 0)
		{
			for (int j = 0; j < newsize; j++)
			{
				if (j == newsize - 1 && str[j] == mystr[position])
				{
					ans = position - newsize + 1;
					haveans = 1;
				}
				if (str[j] != mystr[position])
				{
					break;
				}
				++position;
			}
		}
	}
	if (haveans == 0)
	{
		ans = msize;
	}
	return ans;
}
size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	MyString mystr(*this);
	int newsize = str.getSize();
	bool haveans = 0;
	int ans = 0;
	for (int i = pos; i < getSize(); i++)
	{
		if (haveans == 1)
		{
			break;
		}
		for (int j = 0; j < newsize; j++)
		{
			if (mystr[i] == str[j])
			{
				ans = i;
				haveans = 1;
			}
		}
	}
	if (haveans == 0)
	{
		ans = msize;
	}
	return ans;
}



