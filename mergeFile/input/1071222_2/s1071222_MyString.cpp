#include "s1071222_MyString.h"
#include<string>
#include<iostream>
using namespace std;

istream& operator>> (istream& input, MyString& right)
{
	string x;
	//cin >> x;
	getline(cin, x);
	char* ans = new char[x.size() + 1];
	for (int i = 0; i < x.size(); i++)
		ans[i] = x[i];
	ans[x.size()] = '\0';
	right = MyString::MyString(ans);
	return input;
}

ostream& operator<< (ostream& output, const MyString& right)
{
	for (int i = 0; i < right.size; i++)
	{
		output << right.data[i] << " ";
	}
	return output;
}

MyString::MyString():MyArray()
{
	;
}

MyString::MyString(const MyString& right):MyArray(right)
{
	;
}


MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	if (len > str.size - pos + 1)//¶W¹L½d³ò
	{
		this->resize(str.size - pos + 1);
		for (int i = 0; i < str.size - pos + 1;i++)
		{
			this->data[i] = str.data[pos - 1 +i];
		}
	}
	else
	{
		this->resize(len);
		for (int i = 0; i < len; i++)
		{
			this->data[i] = str.data[pos - 1 + i];
		}
	}
}

MyString::MyString(const char* s)
{
	int newSize = 0;
	while(s[newSize] != '\0')
			newSize++;
	this->resize(newSize);
	for (int i = 0; i < newSize; i++)
		this->data[i] = s[i];
}

MyString::~MyString()
{
}

MyString& MyString::append(const MyString& str)
{
	this->operator+=(str);
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString ans;
	if (len > this->size - pos + 1)//¶W¹L½d³ò
	{
		ans.resize(this->size - pos +1);
		for (int i = 0; i < this->size - pos; i++)
		{
			ans.data[i] = this->data[i + pos];
		}
	}
	else
	{
		ans.resize(len);
		for (int i = 0; i < len; i++)
		{
			ans.data[i] = this->data[i + pos];
		}
	}
	return ans;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString x(*this);
	this->resize(this->size + str.size);
	for (int i = 0; i < pos ; i++)
		this->data[i] = x.data[i];
	for (int i = 0; i < str.size; i++)
		this->data[pos + i] = str.data[i];
	for (int i = pos; i < x.size; i++)
		this->data[i+str.size] = x.data[i];

	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString x(*this);
	this->resize(this->size + sublen);
	for (int i = 0; i < pos; i++)
		this->data[i] = x.data[i];
	for (int i = 0; i <= sublen; i++)
		this->data[pos + i] = str.data[subpos + i];
	for (int i = pos; i < x.size; i++)
		this->data[i + sublen] = x.data[i];

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len > this->size - pos)//¶W¹L½d³ò
	{
		for (int i = 0; i < this->size - pos; i++)
		{
			this->data[i + pos] = ' ';
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			this->data[i + pos] = ' ';
		}
	}
	return *this;
}

int MyString::find(const MyString& str, size_t pos) const
{
	bool decide = false;
	for (int i = pos; i < this->size; i++)
	{
		if (this->data[i] == str.data[0])
		{
			for (int k = 0; k < str.size; k++)
			{
				if (str.data[k] != this->data[i + k])
				{
					decide = false;
					break;
				}
				else
					decide = true;
			}
		}
		if (decide == true)
			return i - pos;
	}
		return MyString::msize;
}

int MyString::find_first_of(const MyString& str, size_t pos) const
{
	bool decide = false;
	for (int i = pos; i < this->size; i++)
	{
		for (int k = 0; k < str.size; k++)
		{
			if (str.data[k] == this->data[i])
				decide = true;
		}
		if (decide == true)
			return i;
	}
	return MyString::msize;
}
