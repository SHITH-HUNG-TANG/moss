#ifndef PG2MyString_H
#define PG2MyString_H
#include "s1081429_MyArray_hw701.h"
#include<string>
#include<iostream>
using namespace std;
class MyString :public MyArray<char>//???
{
	//friend ostream &operator<<(ostream& output, const MyString& str);
	friend istream& operator>>(istream&input, MyString&right);
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
MyString::MyString() :MyArray<char>()
{

}
MyString::MyString(const MyString &str) : MyArray(str)
{

}
MyString::MyString(const MyString &str, size_t pos, size_t len)  // (substring constructor)
{
	*this = str.substr(pos, len);
}
MyString::MyString(const char *s)
{
	int i = 0;
	for (i;s[i] != '\0';i++)
	{
		this->resize(i + 1, 0);
		this->operator[](i) = s[i];
	}
	
}

MyString::~MyString()
{

}
MyString& MyString::append(const MyString &str)
{
	*this += str;
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	MyString temp;
	if (this->getSize() < pos + len - 1)
		temp.resize(this->getSize() - pos, 0);
	else
		temp.resize(len, 0);

		for (int i = pos , j = 0;i < pos + temp.getSize();i++, j++) {
			temp[j] = this->operator[](i);
		}
	return temp;
}

MyString& MyString::insert(size_t pos, const MyString &str)
{
	MyString temp;
	temp = *this;
	temp.resize(this->getSize() + str.getSize(),0);
	for (int i = 0;i < this->getSize()-pos;i++)
	{
		temp[pos + str.getSize() + i] = this->operator[](pos + i);
	}
	for (int i = 0;i <str.getSize() ;i++)
	{
		temp[pos + i] = str[i];
	}
	*this = temp;
	return *this;
}


MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen )
{
	MyString temp;
	temp = *this;
	if (subpos + sublen  > str.getSize()) {
		temp.resize(this->getSize() + (str.getSize() -subpos), 0);
		sublen = str.getSize() - subpos;
	}
	else
	temp.resize(this->getSize() + sublen, 0);
	for (int i = 0;i < this->getSize() - pos;i++)
	{
		temp[pos + sublen + i] = this->operator[](pos + i);
	}
	for (int i = 0;i < sublen ;i++)
	{
		temp[pos + i] = str[subpos + i];
	}
	*this = temp;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len )
{
	MyString temp;
	temp = *this;
	if (this->getSize() < pos + len )
		temp.resize(this->getSize()-(this->getSize()  - pos ), 0);
	else
		temp.resize(this->getSize() - len, 0);
	for (int i = this->getSize() - 1, j = this->getSize() - len - 1, times = this->getSize() - (pos + len);times > 0;i--, j--, times--) {
			temp[j] = this->operator[](i);
	}
	*this = temp;
	return *this;
}

size_t MyString::find(const MyString &str, size_t pos )const
{
	for (int i = pos,j=0;i < this->getSize();i++)
	{
		int itmp = i;
		j = 0;
		while (this->operator[](itmp) == str[j])
		{
				itmp++;
				j++;
			if (itmp == i + str.getSize())
				return i;
		}
		
	}
	return msize;
}

size_t MyString::find_first_of(const MyString &str, size_t pos ) const
{
	for (int i = pos, j = 0;i < this->getSize();i++)
	{
		int itmp = i;
		j = 0;
		while (j<str.getSize())
		{
			if (this->operator[](itmp) != str[j])
				j++;
			else
				return itmp;
		}
		itmp++;

	}
	return msize;
}
istream& operator>>(istream&input, MyString&right)
{
	string a;
	cin >> a;
	right.resize(a.length(),0);
	for(int i=0;i<a.length();i++)
	{
		right[i] = a[i];
	}
	return input;
}