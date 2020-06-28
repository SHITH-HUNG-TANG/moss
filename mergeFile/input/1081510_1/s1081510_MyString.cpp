#include<iostream>
#include"s1081510_MyString.h"

MyString::MyString()
	:MyArray(10)
{

}

MyString ::MyString(const MyString &str)
{
	size = str.size;
	capacity = str.capacity;
	data = new char[capacity];
	for (int i = 0; i < size; i++)
		data[i] = str.data[i];
}

MyString ::MyString(const MyString &str, size_t pos, size_t len )
	:MyArray(10)
{
	while (len > size)
		resize(len, '\0');
	int j = 0;
	for (int i = pos; i < pos + len; i++)
	{
		data[j] = str.data[i];
		j++;
	}
}

MyString ::MyString(const char *s)
	:MyArray(10)
{
	int i = 0;
	while (s[i] != NULL)
	{
		resize(i+1, s[i]);
		i++;
	}
}

MyString::~MyString()
{

}

MyString &MyString ::append(const MyString &str)
{
	/*MyString str2(" ");
	*this += str2;*/
	*this += str;
	return *this ;
}

MyString MyString ::substr(size_t pos, size_t len ) const
{
	MyString substr(*this, pos, len);
	return substr;
}

MyString &MyString ::insert(size_t pos, const MyString &str)
{
	resize(size + str.size + 1,'\0');
	int j = size-str.size-1;
	for (int i = size-1 ; i >=pos+str.size; i--)
	{
		data[i] = data[j];
			j--;
	}
	int k = 0;
	for (int i = pos; i < pos + str.size; i++)
	{
		data[i] = str.data[k];
			k++;
	}
	return *this;
}

MyString &MyString ::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen )
{
	resize(size + sublen + 1, '\0');
	int j = size-sublen-1;
	for (int i = size-1; i >=pos+sublen; i--)
	{
		data[i] = data[j];
		j--;
	}
	int k = subpos;
	for (int i = pos; i < pos + sublen; i++)
	{
		data[i] = str.data[k];
		k++;
	}
	return *this;
}

MyString &MyString::erase(size_t pos, size_t len )
{
	int k = pos + len;
	for (int i = pos; i < size - len; i++)
	{
		data[i] = data[k];
		k++;
	}
	resize(size - len, '\0');
	return *this;
}

static const size_t msize = -1;

size_t MyString::find(const MyString &str, size_t pos ) const
{
	for (int i = pos; i < size; i++)
	{
		if (data[i] == str.data[0])
		{
			int k = i + 1, sum = 0;
			for (int j = 1; j < str.size; j++)
			{
				if (data[k] != str.data[j])
					break;
				else
					sum++;
				k++;
			}
			if (sum == str.size - 1)
				return i;
		}
	}
	
	return msize;
}

size_t MyString::find_first_of(const MyString &str, size_t pos ) const
{
	for (int i = pos; i < size; i++)
	{
		for (int j = 0; j < str.size; j++)
		{
			if (data[i] == str.data[j])
				return i;
		}
	}
	return msize;
}
