#include <iostream>
#include <ostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <exception>

#include"s1083331_MyString.h"
#include"s1083331_MyArray.h"

MyString::MyString(int newcapacity):MyArray(newcapacity)
{
}

MyString::MyString(const MyString& str) : MyArray(str)
{
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	int newsize = len;

	resize(newsize, '\0');

	for (int i = 0; i < newsize; i++)
	{
		this->operator[](i) = str[pos + i];
	}
}

MyString::MyString(const char* str)
{
	int newsize = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		newsize++;
	}

	resize(newsize, '\0');

	for (int i = 0; i < newsize; i++)
	{
		this->operator[](i) = str[i];
	}
}

MyString::~MyString()
{
}

MyString& MyString::append(const MyString& str)
{
	int newsize = getSize() + str.getSize() + 1;
	int size1 = getSize();

	MyString ans(*this);

	ans.resize(newsize, '\0');

	ans[size1] = ' ';

	for (int i = 0; i < str.getSize(); i++)
	{
		ans[i + size1 + 1] = str[i];
	}

	*this = ans;

	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString ans;
	int num = 0;
	
	if (pos > getSize() - 1)
	{
		ans.resize(0);
	}
	else if (len + pos > getSize())
	{
		ans.resize(getSize() - pos, '\0');
		num = getSize() - pos;
	}
	else
	{
		ans.resize(len, '\0');
		num = len;
	}
	
	for (int i = 0; i < num; i++)
	{
		ans[i] = this->operator[](i + pos);
	}

	return ans;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString ans;

	int newsize = getSize() + str.getSize();

	ans.resize(newsize, '\0');

	int i = 0;
	for (; i < pos; i++)
	{
		ans[i] = this->operator[](i);
	}

	for (int l = 0; l < str.getSize(); l++)
	{
		ans[l + i] = str[l];
	}

	for (int j = i; j < getSize(); j++)
	{
		ans[j + str.getSize()] = this->operator[](j);
	}

	*this = ans;

	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString ans;
	
	int newsublen;
	if (sublen >= str.getSize())
	{
		newsublen = str.getSize() - 1;
	}
	else
	{
		newsublen = sublen;
	}

	int strsize = newsublen - subpos + 1;
	int newsize = getSize() + strsize;

	ans.resize(newsize, '\0');

	int i = 0;
	for (; i < pos; i++)
	{
		ans[i] = this->operator[](i);
	}

	for (int l = 0; l < strsize; l++)
	{
		ans[l + i] = str[l + subpos];
	}

	for (int j = i; j < getSize(); j++)
	{
		ans[j + strsize] = this->operator[](j);
	}

	*this = ans;

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	MyString ans;

	int num = 0;
	if (pos > getSize() - 1)
	{
		ans.resize(len, '\0');
		num = len;

		int j = 0;
		for (int i = 0; i < num; i++)
		{
			ans[j] = this->operator[](i);
			j++;
		}

		for (int i = pos + len; i < getSize(); i++)
		{
			ans[j] = this->operator[](i);
			j++;
		}

		*this = ans;

		return *this;
	}
	else if (len + pos > getSize())
	{
		ans.resize(pos, '\0');
		num = pos;

		int j = 0;
		for (int i = 0; i < num; i++)
		{
			ans[j] = this->operator[](i);
			j++;
		}

		for (int i = pos + len; i < getSize(); i++)
		{
			ans[j] = this->operator[](i);
			j++;
		}

		*this = ans;

		return *this;
	}
	else
	{
		ans.resize(getSize() - len, '\0');

		int j = 0;
		for (int i = 0; i < pos; i++)
		{
			ans[j] = this->operator[](i);
			j++;
		}

		for (int i = pos + len; i < getSize(); i++)
		{
			ans[j] = this->operator[](i);
			j++;
		}

		*this = ans;

		return *this;
	}
}

int MyString::find(const MyString& str, size_t pos) const
{
	int size2 = 0;

	MyString smallstr(str);

	for (int i = pos; i < getSize(); i++)
	{
		if (this->operator[](i) == smallstr[0])
		{
			size2++;
			size2 += recursive(*this, i + 1, smallstr, 1);

			if (size2 == smallstr.getSize())
			{
				return i;
			}

			size2 = 0;
		}
	}

	return msize;
}

int MyString::recursive(const MyString& str1, size_t pos1, const MyString& str2, size_t pos2) const
{
	if (pos2 == str2.getSize())
	{
		return 0;
	}
	else
	{
		if (str1[pos1] == str2[pos2])
		{
			return 1 + recursive(str1, pos1 + 1, str2, pos2 + 1);
		}
		else
		{
			return 0 + recursive(str1, pos1 + 1, str2, pos2 + 1);
		}
	}
}

int MyString::find_first_of(const MyString& str, size_t pos) const
{
	MyString smallstr(str);

	for (int i = pos; i < getSize(); i++)
	{
		for (int j = 0; j < smallstr.getSize(); j++)
		{
			if (this->operator[](i) == smallstr[j])
			{
				return i;
			}
		}
	}

	return msize;
}

MyString& MyString::operator=(const MyString& num)
{
	resize(num.getSize(), 0);

	for (int i = 0; i < getSize(); i++)
	{
		this -> operator[](i) = num[i];
	}

	return *this;
}


