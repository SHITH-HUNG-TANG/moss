#include "s1083308_MyArray.h"
#include "s1083308_MyString.h"
#include <iostream>
#include <string>
using namespace std;

MyString::MyString()
	:MyArray()
{
	
}

MyString::MyString(const MyString& str)
	:MyArray(str)
{
	
}

MyString::MyString(int Size, char value)
	:MyArray(Size , value)
{

}

MyString::~MyString()
{
	
}


MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	resize(len, 0);
	int k = 0;
	for (int i = pos; i < pos + len; i++)
	{
		this->operator[](k) = str[i];
		k++;
	}
}

MyString::MyString(const char* s)
{
	int lenth = 0;
	while (s[lenth] != '\0')
		lenth++;

	resize(lenth , '\0') ;

	for (int i = 0; i < lenth; i++)
	{
		this->operator[](i) = s[i];
	}
}

const MyString& MyString::operator=(const MyString& copy)
{
	resize(copy.getSize(), 0);

	for (int i = 0; i < getSize(); i++)
		this->operator[](i) = copy[i];

	return *this;
}

MyString MyString::operator+(const MyString& right)
{
	MyString a(*this);
	a += right;
	return a;
}//new

MyString& MyString:: operator+=(const MyString& right)
{
	int orisize = getSize();
	int newsize = getSize() + right.getSize();

	resize(newsize, 0);

	for (int i = 0; i < newsize; i++)
	{
		if (i >= orisize)
			this->operator[](i) = right[i - orisize];
	}

	return *this;
}//new

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString n2(*this, pos, len);
	return n2;
}

ostream& operator<<(ostream& out, const MyString & right)
{
	
	for (int i = 0; i < right.getSize(); i++)
	{
			out << right[i] ;
	}
	return out;
}

istream& operator>>(istream& in, MyString& right)
{
	string temp;
	in >> temp;
	right.resize(temp.length(), '\0');
	for (int i = 0; i < right.getSize(); i++)
	{
		right[i] = temp[i];
	}

	return in;
}

MyString& MyString::append(const MyString& str)
{
	int orisize = getSize();
	resize(getSize() + str.getSize() + 1 , '\0');
	int k = 0;
	for (int i = orisize ; i < getSize(); i++)
	{
		if (i == orisize)
			this->operator[](i) = ' ';
		else
		{
			this->operator[](i) = str[k];
			k++;
		}
	}
	
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString a1( str, subpos, sublen );
	MyString temp1;
	MyString temp2;
	temp1.resize(getSize() - sublen,0);
	temp2.resize( sublen , 0 );
	for (int i = 0; i < temp1.getSize(); i++)
	{
		temp1[i] = this->operator[](i);
	}
	for (int i = 0; i < temp2.getSize(); i++)
	{
		temp2[i] = this->operator[](i + sublen );
	}
	MyString sum;
	sum.resize( temp1.getSize() + temp2.getSize() + a1.getSize(), '\0');
	sum = temp1 + a1 + temp2;
	*this = sum;
	return *this;	
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	int orisize = getSize();
	resize( str.getSize() + getSize() , '\0' ) ;
	int newsize = getSize();
	for (int i = orisize-1 ; i >= pos; i--)
	{
		this->operator[](newsize - 1) = this->operator[](i);
		newsize--;
	}
	int k = 0;
	for (int i = pos ; i < pos + str.getSize() ; i++)
	{
		this->operator[](i) = str[k];
		k++;
	}
	return *this;

}

MyString& MyString::erase(size_t pos, size_t len)
{
	for (int i = pos; i < pos + len; i++)
	{
		this->operator[](i) = '\0';
	}
	int p = pos;
	if(pos + len != getSize())
	{ 
		for (int i = pos + len ; i < getSize() ; i++)
		{
			this->operator[](p) = this->operator[](i);
			p++;
		}
	}
	resize(getSize() - len, '\0');
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos ) const
{	
	if (str.getSize() > 1)
	{
		string ori;
		for (int i = 0; i < getSize(); i++)
		{
			ori += this->operator[](i);
		}
		string search;
		for (int i = 0; i < str.getSize(); i++)
		{
			search += str[i];
		}
		return ori.find(search);
	}
	else if (str.getSize() == 1)
	{
		return find_first_of(str, 0);
	}
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	for (int i = 0; i < getSize(); i++)
		for (int j = 0; j < str.getSize(); j++)
		{
			if (this->operator[](i) == str[j])
			{
				return i;
			}
		}

	return msize;
}


