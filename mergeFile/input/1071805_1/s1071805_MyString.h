#ifndef S1071805_MYSTRING_H
#define S1071805_MYSTRING_H
#include "s1071805_MyArray.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyString : public MyArray<char>
{
	friend ostream &operator<<(ostream& output, const MyString& str);
	friend istream &operator>>(istream& input, MyString& str);

public:
	MyString(); 
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString( const MyString &str ); 
	// Constructs a copy of "str". (copy constructor)

	MyString( const MyString &str, size_t pos, size_t len = msize ); // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString( const char *s ); 
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	~MyString(); 
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append( const MyString &str ); 
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const;
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert( size_t pos, const MyString &str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert( size_t pos, const MyString &str, size_t subpos, size_t sublen = msize );
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase( size_t pos, size_t len = msize ); 
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find( const MyString &str, size_t pos = 0 ) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of( const MyString &str, size_t pos = 0 ) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif

ostream& operator<<(ostream& output, const MyString& str) 
{
	for (int i = 0; i < str.size; i++)
	{
		output << str[i];
	}
	return output;
}

istream& operator>>(istream& input, MyString& str)
{
	char buffer[1024];
	input >> buffer;

	if (str.data) 
	{
		delete str.data;
		str.data = NULL;
	}

	str.data = new char[strlen(buffer) + 1];
	strcpy_s(str.data, strlen(buffer) + 1, buffer);

	return input;
	//char ch;
	//unsigned int i = 0;
	//while (1)
	//{
	//	input >> noskipws;//noskipws => no skip whitespace(空白)
	//		//noskipws 不是不忽略輸入前的空格, 而是 不忽略 任意地方的空格
	//	input >> ch;
	//	if (ch == '\n')
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		str.data[i] = ch;
	//		i++;
	//	}
	//}
	//str.data[i] = '\0';
	//return input;
}

MyString::MyString() 
	:MyArray<char>()
{

}

MyString::MyString(const MyString& str) 
	:MyArray(str)
{
	
}

MyString::MyString(const MyString& str, size_t pos, size_t len) // (substring constructor)
{
	resize(str.size - len, 0);

	for (int i = 0; i < len; i++)
	{
		data[i] = str.data[i + str.size - len - 1];
	}
}
// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
// (or until the end of str, if either str is too short or if len is string::msize).

MyString::MyString(const char* s)
{
	if (s == NULL)
	{
		this->data = new char[1];
		*(this->data) = '\0';
	}
	else
	{
		int i = 0;
		while (data[i] != '\0')
		{
			data[i] = s[i];
			i++;
		}
		data[i] = '\0';

		size = strlen(s);
		if (size < 10)
			capacity = 10;
		else
			capacity = size * 2;
		data = new char[capacity];

		strcpy_s(data, strlen(s) + 1, s);
	}
}

MyString::~MyString()
{

}

MyString& MyString::append(const MyString& str)
{
	int tempsize = size;
	size += str.size;
	resize(size, 0);

	for (int i = 0; i < str.size; i++)
	{
		data[i + tempsize] = str.data[i];
	}

	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString temp;
	temp.resize(len, 0);

	for (int i = 0; i < len; i++)
	{
		temp.data[i] = data[i + pos];
	}

	return temp;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString temp;
	temp.resize(size + str.size, 0);
	
	for (int i = 0; i < pos; i++)
	{
		temp.data[i] = data[i];
	}

	for (int i = 0; i < str.size; i++)
	{
		temp.data[i + pos] = str.data[i];
	}

	for (int i = pos + str.size; i < temp.size; i++)
	{
		temp.data[i] = data[i - str.size];
	}
	
	resize(temp.size,0);
	capacity = temp.capacity;
	delete[] data;
	data = new char[capacity];

	for (int i = 0; i < size; i++)
		data[i] = temp.data[i];

	return *this;
	
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString a;
	a = str.substr(subpos, sublen);
	
	MyString temp;
	temp.resize(size + a.size, 0);

	for (int i = 0; i < pos; i++)
	{
		temp.data[i] = data[i];
	}

	for (int i = 0; i < a.size; i++)
	{
		temp.data[i + pos] = a.data[i];
	}

	for (int i = pos + a.size; i < temp.size; i++)
	{
		temp.data[i] = data[i - a.size];
	}
	
	resize(temp.size, 0);
	capacity = temp.capacity;
	delete[] data;
	data = new char[capacity];

	for (int i = 0; i < size; i++)
		data[i] = temp.data[i];

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{	
	
	int tempsize = size;
	size = size - len;

	for (int i = 0; i < pos; i++)
	{
		data[i] = data[i];
	}

	for (int i = pos + len; i < tempsize; i++)
	{
		data[i - len] = data[i];
	}

	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	int k;
	for (int i = 0; i < size - str.size; i++)
	{
		k = 0;
		for (int j = 0; j < str.size; j++)
		{
			if (data[i + j] == str.data[j])
				k = k + 1;
		}
		
		if (k == str.size)
		{
			return i;
		}
	}
	return msize;
}


size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < str.size; j++)
		{
			if (data[i + j] == str.data[j])
				return i + j;
		}
	}
	return msize;
}
