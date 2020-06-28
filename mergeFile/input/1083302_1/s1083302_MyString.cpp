#include "s1083302_MyString.h"
using namespace std;

MyString::MyString()
	:MyArray<char>(10,' ')
{
	resize(0, ' ');
}

MyString::MyString(const MyString& str)
	:MyArray<char>(str)
{
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
	:MyArray(10)
{
	if (len == msize)
		len = str.getSize() - pos;
	resize(len, '0');
	for (int i = 0;i < getSize();i++)
	{
		at(i) = str.at(i + pos);
	}
}

MyString::MyString(const char* s)
	:MyArray(10,'0')
{
	int i = 0, j = 0;
	int count = 0;
	while (*(s + i) != '\0')
	{
		count++;
		i++;
	}
	resize(count, '0');
	while (*(s + j) != '\0')
	{
		at(j) = *(s + j);
		j++;
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
		len = getSize() - pos;
	MyString temp;
	temp.resize(len, '0');
	for (int i = 0;i < temp.getSize();i++)
	{
		temp.at(i) = at(i + pos);
	}
	return temp;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString temp;
	temp.resize((getSize() + str.getSize()),'0');
	for (int i = 0;i < pos;i++)
		temp.at(i) = at(i);
	for (int i = 0;i < str.getSize();i++)
		temp.at(i + pos) = str.at(i);
	for (int i = pos + str.getSize();i < temp.getSize();i++)
		temp.at(i) = at(pos + (i - (pos + str.getSize())));
	*this = temp;
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	if (sublen == msize)
		sublen = str.getSize() - subpos;
	MyString temp;
	temp = str.substr(subpos, sublen);
	insert(pos, temp);
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == msize)
	{
		len = getSize() - pos;
		for (int i = pos;i < getSize();i++)
		{
			at(i) = ' ';
		}
		resize(getSize() - len, ' ');
	}
	else
	{
		MyString temp;
		temp.resize(getSize() - len, ' ');
		for (int i = 0;i < pos;i++)
			temp.at(i) = at(i);
		for (int i = pos;i < temp.getSize();i++)
			temp.at(i) = at(i + len);
		*this = temp;
	}
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	int check = 0;
	for (size_t i = 0;i < getSize()-(str.getSize() - pos);i++)
	{
		int x = 0;
		for (int j = 0;j < str.getSize() - pos;j++)
		{
			if (at(i + x) != str.at(j+pos))
				check = 1;
			x++;
		}
		if (check == 0)
			return i;
		check = 0;
	}
	return msize;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	int ans = -1;
	for (int i = 0;i < getSize();i++)
	{
		int find = 0;
		for (int j = pos;j < str.getSize();j++)
		{
			if (at(i) == str.at(j))
			{
				find = i; 
				if (ans == -1)
					ans = find;
			}
		}
		if (ans > find&& find != 0)
			ans = find;
	}
	return ans;
}

istream& operator>>(istream& input, MyString& right)
{
	string in;
	input >> in;
	int len = in.length();
	char* ptr = new char[len + 1];
	ptr[len] = '\0';
	in.copy(ptr, len, 0);
	MyString temp(ptr);
	right = temp;
	delete[] ptr;
	return input;
}
