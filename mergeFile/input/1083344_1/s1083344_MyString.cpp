#include <iostream>
#include "s1083344_MyString.h"

using namespace std;

MyString::MyString()
{
	capacity = 10;
	size = 0;
}

MyString::MyString(const MyString& str)
{
	resize(str.size);
	reserve(str.capacity);

	for (int i = 0; i < size; i++)
		elem[i] = str.at(i);
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	if (len != msize) {
		resize(len);
		for (int i = pos; i < pos + len; i++)
			elem[i - pos] = str[i];
	}
	else {
		resize(len - pos + 1);
		for (int i = pos; i < len; i++)
			elem[i - pos] = str[i];
	}
}

MyString::MyString(const char* s)
{
	resize(strlen(s));
	for (int i = 0; i < size; i++)
		elem[i] = s[i];
}

MyString& MyString::append(const MyString& str)
{
	*this += str;

	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString str2;

	if (len != msize) {
		str2.resize(len);
		for (int i = 0; i < len; i++)
			str2.elem[i] = elem[i + pos];
	}
	else {
		str2.resize(len - pos + 1);
		for (int i = pos; i < len; i++)
			str2.elem[i - pos] = elem[i];
	}
	return str2;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString temp;
	temp.resize(size + str.size);

	for (int i = 0; i < pos; i++)
		temp.elem[i] = elem[i];
	for (int i = pos; i < str.size + pos; i++)
		temp.elem[i] = str.elem[i - pos];
	for (int i = str.size + pos; i < temp.size; i++)
		temp.elem[i] = elem[i - str.size];

	*this = temp;

	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString str2 = substr(subpos, sublen);

	insert(pos, str2);

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == msize)
		resize(pos);
	else {
		MyString str2 = substr(pos + len);
		for (int i = 0; i < str2.size; i++)
			elem[i + pos] = str2.elem[i];

		resize(size - len);
	}
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	for (size_t i = pos; i < size; i++) {
		if (elem[i] == str.elem[0]) {
			int x = 0;
			for (size_t n = 0; n < str.size; n++) {
				if (elem[n + i] != str.elem[x])
					break;
				else x++;
			}
			if (x == str.size)
				return i;
		}
	}

	return -1;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	for (int i = pos; i < size; i++) {
		for (int n = 0; n < str.size; n++)
			if (elem[i] == str.elem[n])
				return i;
	}
	return -1;
}

