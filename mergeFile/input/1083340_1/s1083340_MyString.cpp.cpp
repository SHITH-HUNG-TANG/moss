#include <iostream>
#include <stdexcept>
#include <string>
#include"s1083440_MyString.h"
using namespace std;

ostream& operator<<(ostream& output, const MyString& str)
{
	for (int i = 0; i < str.size; i++)
		output << str.data[i] ;
	output << endl;
	return output;
}

istream& operator>>(istream& input, MyString& str)
{
	string ppp;
	input >> ppp;
	str.resize(ppp.size(), '\0');
	for (int i = 0; i < str.size; i++)
		str[i] = ppp[i];
	return input;
}

MyString::MyString():MyArray()
{
}

MyString::MyString(const MyString& str):MyArray(str)
{
}

const MyString &MyString::operator=(const MyString& str)
{
	size = str.size;
	capacity = str.capacity;
	delete[] data;
	data = new char[capacity]();

	for (int i = 0; i < size; i++)
		data[i] = str.data[i];
	return *this;
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	if (str.size <= (pos + 1))
	{
		throw out_of_range("check range");
	}
	else if ((str.size-pos) < len || len == msize)
	{
		for (int i = pos,k=0; i < str.size; i++,k++)
		{
			if ((size-pos) >= capacity)
				(*this).reserve(capacity * 2);
			data[k] = str.data[i];
			size++;
		}
	}
	else
	{
		for (int i = pos, k = 0; i < (len + pos); i++, k++)
		{
			if (size >= capacity)
				(*this).reserve(capacity * 2);
			data[k] = str.data[i];
			size++;
		}
	}
}

MyString::MyString(const char* s)
{
	data = new char[capacity]();
	size = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		data[i] = s[i];
		size++;
		if (size >= capacity)
			(*this).reserve(capacity * 2);
		i++;
	}
}

MyString::~MyString()
{
}

MyString &MyString::append(const MyString& str)
{
	(*this) += str;
	return *this;
}

MyString MyString::substr(size_t pos, size_t len ) const
{
	MyString ppp;
	if (size <= (pos + 1))
	{
		throw out_of_range("check range");
	}
	else if ((size - pos) < len || len==msize)
	{
		for (int i = pos,k=0; i < size; i++,k++)
		{
			ppp.size++;
			ppp.resize(ppp.size, '\0');
			ppp.data[k] = data[i];
		}
	}
	else
	{
		for (int i = pos, k = 0; i < (len + pos); i++, k++)
		{
			ppp.size++;
			ppp.resize(ppp.size, '\0');
			ppp.data[k] = data[i];
		}
	}
	return ppp;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString ppp;
	ppp.resize((str.size + size), '\0');
	for (int i = 0; i < pos; i++)
		ppp[i] = (*this)[i];
	for (int i = 0; i < str.size; i++)
		ppp[i+pos] = str[i];
	for (int i = pos; i < size; i++)
		ppp[i+str.size] = (*this)[i];
	(*this) = ppp;
	return (*this);
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString ppp;
	ppp=str.substr(subpos, sublen);
	MyString iii(*this);
	(*this)=iii.insert(pos, ppp);
	return (*this);
}

MyString& MyString::erase(size_t pos, size_t len)
{
	MyString ppp;
	if (size <= (pos + 1))
	{
		throw out_of_range("check range");
	}
	else if (len == msize || (size - pos) < len)
	{
		ppp.resize(size-(size - pos), '\0');
		for (int i = 0; i < pos; i++)
			ppp[i] = (*this)[i];
	}
	else
	{
		ppp.resize(size-len, '\0');
		for (int i = 0; i < pos; i++)
			ppp[i] = (*this)[i];
		for(int i=(pos+len-1);i<size;i++)
			ppp[i-len]=(*this)[i];
	}
	(*this) = ppp;
	return (*this);
}


int MyString::find(const MyString& str, size_t pos ) const
{
	int th = 0;
	signed int point1 = msize;
	for (int i = pos; i < size; i++)
	{
		if ((*this)[i] == str[0] && (size-i)>=str.size)
		{
			point1 = i;
			th++;
			for (int j = i + 1, k = 1; k < str.size; k++, j++)
			{
				if ((*this)[j] == str[k])
				{
					th++;
				}
				if ((*this)[j] != str[k])
				{
					th=0;
					point1 = msize;
					break;
				}
			}
		}
	}
	if (th == str.size)
		return point1;
	else
	{
		point1 = -1;
		return point1;
	}
}

int MyString::find_first_of(const MyString& str, size_t pos) const
{
	int point = msize;
	for (int i = pos; i < size; i++)
	{
		for (int j = 0; j < str.size; j++)
		{
			if ((*this)[i] == str[j])
			{
				point = i;
				return point;
			}
		}
	}
	return point;
}