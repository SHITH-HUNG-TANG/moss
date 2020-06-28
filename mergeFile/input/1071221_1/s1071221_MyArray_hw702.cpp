#include"s1071221_MyArray_hw702.h"
#include<iostream>
#include<string>
using namespace std;

MyString::MyString():MyArray(10)
{
}
MyString::MyString(const MyString& str):MyArray(str)
{
}
MyString::MyString(const MyString& str, size_t pos, size_t len )//string t(s, 0, 5); //值為複製字串 s，從索引位置0開始，指定複製的長度5
{
	if (size < str.size)
	{
		size = str.size;
		for (int i = pos; i < len; i++)
		{
			data[i - pos] = str[i];
		}
	}
	else
	{
		for (int i = pos; i < len; i++)
		{
			data[i - pos] = str[i];
		}
	}
}
MyString::MyString(const char* s)
{
	if (NULL == s)
	{
		return;
	}
	size = strlen(s);
	data = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		data[i] = s[i];
	}
}
MyString::~MyString()
{
	//delete[]data;
}
MyString&MyString::append(const MyString& str)
{
	MyArray<char>::operator+=(str);
	return *this;
}
MyString MyString::substr(size_t pos, size_t len ) const
{
	MyString ans;
	ans.size = len;
	for (int i = 0; i < len; i++)
	{
		ans.data[i] = data[i + pos];
	}
	return ans;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	//STR2 cc f
	//insert str3 = “abcd”
	//STR2.Insert (3, str3, 1, 2);
	//將bc插入STR2的第三位

	MyString after;//asd fgh
	after.resize(size - pos, ' ');//7-3=4 asd 

	MyString sub;
	sub = str.substr(subpos, sublen);
	resize(size+ sub.size, ' ');//所需存放

	for (int i = 0; i < sub.size; i++)
	{
		data[i + pos] = sub[i];
	}
	return *this;
}
MyString&MyString::insert(size_t pos, const MyString& str)//example: str = "to be question", str2 = "the "
{
	MyString ans(*this);//to be question
	ans.size = size + str.size;//14+3
	//ans = new char[ans.size]();
	for (int i = pos; i < size; i++)//後退
	{
		ans.data[i + str.size] = ans.data[i];
	}
	for (int i = 0; i < str.size; i++)
	{
		ans.data[i+pos] = str.data[i];
	}
	return ans;
}
MyString& MyString::erase(size_t pos, size_t len)
{
	char* p_old = data;
	size -= len;
	data = new char[size + 1];
	for (size_t i = 0; i < pos; i++)
	{
		data[i] = p_old[i];
	}
	for (size_t i = pos; i < size; i++)
	{
		data[i] = p_old[i + len];
	}
	*(data + size) = ' ';
	return *this;
}
size_t MyString::find(const MyString& str, size_t pos ) const
{
	if (pos > size) 
	{
		return -1;
	}
	for (size_t i = pos; str.size + i <= size; ++i)
	{
		if (strncmp(data + i, str.data, str.size) == 0) 
		{
			return i;
		}
	}
	return -1;
}
size_t MyString::find_first_of(const MyString& str, size_t pos ) const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = pos; j < str.size; j++)
		{
			if (data[i] == str[j])
			{
				return i;
			}
		}
	}
	return -1;
}