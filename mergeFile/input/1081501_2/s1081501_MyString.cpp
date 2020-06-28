#include"s1081501_MyString.h"
#include<iostream>
#include<string>
using namespace std;
istream& operator>>(istream& input, MyString& str)
{
	string s;
	int i = 0;
	getline(input,s);
	str.resize(s.length(),'\0');
	for (int i = 0; i < s.length(); i++)
	{
		str[i] = s[i];
	}
	
	return input;
}
ostream& operator<<(ostream& output, const MyString& str)
{
	for (int i = 0; i < str.getSize(); i++)
	{
		output << str[i];
	}
	return output;
}
MyString::MyString():MyArray()
{

}
MyString::MyString(const MyString& str)
{
	*this = str;
}
MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	int count = 0;
	if (len == msize)
	{
		len = str.getSize() - pos;
	}
	resize(len, '\0');
	int j = str.getSize();
	int k = 0;
	for (int i = pos; i < str.getSize(); i++)
	{
		this->operator[](k) = str[i];
		count++;
		k++;
		if (len == count)
		{
			break;
		}
	}
}
MyString::MyString(const char* s)
{
	int size=0;
	int i = 0;
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	resize(size, '\0');
	for (int j = 0; j < size; j++)
	{
		this->operator[](j) = s[j];
	}
}
MyString::~MyString()
{
	
}
MyString& MyString::append(const MyString& str)
{
	*this += str;
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
	if (len == msize)
	{
		len = getSize() - pos;
	}
	return MyString(*this, pos, len);
}
MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString str1(*this, 0, pos);
	MyString str2(*this, pos);
	str1 += str;
	str1 += str2;
	*this = str1;
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublens)
{
	MyString str3(str, subpos, sublens);
	MyString str1(*this, 0, pos);
	MyString str2(*this, pos);
	str1 += str3;
	str1 += str2;
	*this = str1;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == msize)
	{
		len = getSize() - pos;
	}
	MyString str1(*this, 0, pos);
	MyString str2(*this, pos + len);
	str1 += str2;
	*this = str1;
	return *this;
}
size_t MyString::find(const MyString& str, size_t pos) const
{
	MyString str1(*this);
	MyString str2(str);
	int k = str2.getSize();
	for (int i = pos; i < str1.getSize(); i++)
	{
		int count = 0;
		for (int j = 0; j < str2.getSize(); j++)
		{

			if (str1[i + j] == str2[j])
			{
				count++;
			}

		}
		if (count == k)
		{
			return i;
		}
	}
	return msize;
}
size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	MyString str1(*this);
	MyString str2(str);
	for (int i = pos; i < str1.getSize(); i++)
	{
		for (int j = 0; j < str2.getSize(); j++)
		{
			if (str1[i] == str2[j])
			{
				return i;
			}
		}
	}
	return msize;
}
