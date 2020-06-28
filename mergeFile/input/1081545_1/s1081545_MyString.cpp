//#define  _CRT_SECURE_NO_WARNINGS
#include "s1081545_MyString.h"
#include <string>

MyString::MyString()
{

}

MyString::MyString(const MyString& objStr)
{
	this->size = objStr.size;
	this->capacity = objStr.capacity;
	this->data = new char[this->capacity]{};
	for (int i = 0; i < this->size; i++)
		this->data[i] = objStr.data[i];
}

MyString::MyString(const MyString& objStr, size_t pos, size_t len)
{
	int curCapacity = this->capacity;
	while ((int)len >= curCapacity)
		curCapacity *= 2;
	this->reserve(curCapacity);
	for (unsigned int i = 0; i < len; i++)
		this->data[i] = objStr.data[pos + i];
	this->size = len;
}

MyString::MyString(const char *str)
{
	int len = strlen(str);
	int curCapacity = this->capacity;
	while (len >= curCapacity)
		curCapacity *= 2;
	this->reserve(curCapacity);
	for (int i = 0; i < len; i++)
		this->data[i] = str[i];
	this->size = len;
}

MyString::~MyString()
{

}

MyString& MyString::append(const MyString &objStr)
{
	*this += objStr;
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString ResString(*this);
	for (unsigned int i = 0; i < len; i++)
		ResString.data[i] = this->data[pos + i];
	ResString.size = len;
	return ResString;
}

MyString& MyString::insert(size_t pos, const MyString & objStr)
{
	int curCapacity = this->capacity;
	int oriSize = this->size;
	this->size += objStr.size;
	while (this->size >= curCapacity)
		curCapacity *= 2;
	this->reserve(curCapacity);
	for (unsigned int i = oriSize - 1; i >= pos; i--)
		this->data[objStr.size + i] = this->data[i];
	for (int i = 0; i < objStr.size; i++)
		this->data[pos + i] = objStr.data[i];
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString &objStr, size_t subpos, size_t sublen)
{
	int curCapacity = this->capacity;
	int oriSize = this->size;
	this->size += sublen;
	while (this->size >= curCapacity)
		curCapacity *= 2;
	this->reserve(curCapacity);
	for (unsigned int i = oriSize - 1; i >= pos; i--)
		this->data[sublen + i] = this->data[i];
	for (unsigned int i = 0; i < sublen; i++)
		this->data[pos + i] = objStr.data[i + subpos];
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	int oriSize = this->size;
	this->size -= len;
	for (unsigned int i = pos; i <(unsigned int)oriSize; i++)
		this->data[i] = this->data[len + i];
	this->data[this->size] = '\0';
	return *this;
}

size_t MyString::find(const MyString &objStr, size_t pos) const
{
	for (int st = pos; st < this->size - objStr.size; st++)
	{
		bool found = true;
		for (int i = 0; i < objStr.size; i++)
		{
			if (this->data[st + i] != objStr.data[i])
			{
				found = false;
				st += i;
				break;
			}
		}
		if (found)
			return (size_t)st;
	}
	return msize;
}

size_t MyString::find_first_of(const MyString &objStr, size_t pos) const
{
	for (int st = pos; st < this->size; st++)
	{
		for (int i = 0; i < objStr.size; i++)
		{
			if (this->data[st] == objStr.data[i])
				return (size_t)st;
		}
	}
	return msize;
}