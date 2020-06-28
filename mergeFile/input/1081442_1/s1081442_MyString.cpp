#include "s1081442_MyString.h"

MyString::MyString()
	:MyArray(10)
{
}

MyString::MyString(const MyString& str)
	: MyArray(str)
{
}

//abcdefg //pos = 3 //len = 4
MyString::MyString(const MyString& str, size_t pos, size_t len) //substr constructor
	:MyArray(10)
{	
	//判斷len是不是-1
	//	this = str的pos開始 , 長度是len
	if (len == -1)
	{
		len = str.getSize() - pos;
		this->resize(len, '\0');
		for (int i = 0; i < len; i++)
		{
			at(i) = str.at(i + pos);
		}
	
	}
	else
	{
		this->resize(len, '\0');
		for (int i = 0; i < len; i++)
		{
			at(i) = str.at(i + pos);
		}
	}

}

MyString::MyString(const char* s)
	:MyArray(10)
{	
	this->resize(strlen(s),'\0');
	for (int i = 0; i < strlen(s); i++)
	{
		at(i) = s[i];
	}
}

MyString::~MyString()
{
}

MyString& MyString::append(const MyString& str)
{	
	this->operator+=(str);
	this->resize(getSize(), '\0');
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{	
	//判斷len是不是-1
	MyString n;
	//n.at(i)
	//n = this裁掉的
	if (len == -1)
	{
		len = getSize() - pos;
		n.resize(len,'\0');
		for (int i = 0; i < len; i++)
		{
			n.at(i) = at(i + pos);
		}
		
	}
	else
	{
		n.resize(len, '\0');
		for (int i = 0; i < len; i++)
		{
			n.at(i) = at(i + pos);
		}
		
	}
	return n;
	
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	this->resize(getSize()+str.getSize(),'\0');
	for (int i = 0; i < pos; i++)
	{
		at(i) = at(i);
	}
	for (int i = getSize()-1; i >=pos+str.getSize() ; i--)
	{
		at(i) = at(i - str.getSize());
	}
	for (int i = pos; i < pos + str.getSize(); i++)
	{
		at(i) = str.at(i-pos);
	}
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	if (sublen == -1)
	{
		MyString a;
		sublen = str.getSize() - subpos;
		a.resize(sublen,'\0');
		this->resize(getSize() + sublen, '\0');
		for (int i = 0; i < sublen; i++)
		{
			a.at(i) = str.at(i + subpos);
		}
		for (int i = 0; i < pos; i++)
		{
			at(i) = at(i);
		}
		for (int i = getSize() - 1; i >= pos + sublen; i--)
		{
			at(i) = at(i - sublen);
		}
		for (int i = pos; i < pos + sublen; i++)
		{
			at(i) = a.at(i - pos);
		}
		return *this;
	}
	else
	{
		this->resize(getSize()+sublen, '\0');
		MyString b;
		b.resize(sublen, '\0');
		for (int i = 0; i < sublen; i++)
		{
			b.at(i) = str.at(i + subpos);
		}
		for (int i = 0; i < pos; i++)
		{
			at(i) = at(i);
		}
		for (int i = getSize() - 1; i >= pos + b.getSize(); i--)
		{
			at(i) = at(i - b.getSize());
		}
		for (int i = pos; i < pos + b.getSize(); i++)
		{
			at(i) = b.at(i - pos);
		}
		return *this;
	}
}


MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == -1)
	{
		this->resize(pos, '\0');
		for (int i = 0; i < pos; i++)
		{
			at(i) = at(i);
		}
		return*this;
	}
	else
	{
		for (int i = 0; i < pos; i++)
		{
			at(i) = at(i);
		}
		for (int i = pos; i < getSize()-len; i++)
		{
			at(i) = at(i + len);

		}
		this->resize(getSize()-len, '\0');
		return *this;
	}
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	MyString c;
	int w=0;
	c.resize(str.getSize() - pos, '\0');
	for (int i = 0; i < str.getSize()-pos; i++)
	{
		c.at(i) = str.at(i + pos);
	}
	for (int i = 0; i < getSize()-c.getSize(); i++)
	{
		if (at(i) == c.at(0))
		{
			for (int j = 0; j < c.getSize(); j++)
			{
				if (at(i + j) != c.at(j))
					break;
				else if (j == c.getSize() - 1 && at(i + j) == c.at(j))
				{
					return i;
					w++;
					break;
				}
					
			}
		}
		if (i == getSize() - c.getSize() - 1&&w==0)
		{
			return msize;
		}
	}
	
	
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	MyString d;
	int w = 0;
	d.resize(str.getSize() - pos, '\0');
	for (int i = 0; i < str.getSize() - pos; i++)
	{
		d.at(i) = str.at(i + pos);
	}
	for (int i = 0; i < getSize(); i++)
	{
		for (int j = 0; j < d.getSize(); j++)
		{
			if (at(i) == d.at(j))
			{
				return i;
				w++;
				break;
			}
		}
		
	}
	if ( w == 0)
		{
			return msize;
		}
}

istream& operator>>(istream& input, MyString& str)
{
	string n; 
	cin >> n;
	int length = n.length();
	char* ptr = new char[length + 1];
	n.copy(ptr, length, 0); //從n的0開始丟長度length的資料進去ptr
	ptr[length] = '\0';
	MyString s(ptr);
	str = s;
	return input;
}
