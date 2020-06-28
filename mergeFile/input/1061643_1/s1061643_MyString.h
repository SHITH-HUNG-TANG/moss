#ifndef MyString_H
#define MyString_H
#include <iostream>
#include "s1061643_MyArray.h"
using namespace std;

class MyString : public MyArray<char>
{
	friend ostream &operator<<(ostream& output, const MyString& str)
	{
		for (int i = 0; i < str.getSize(); i++)
			output << str[i];

		output << endl;

		return output;
	};
	friend istream& operator>>(istream& input, MyString& str)
	{
		string inputStr;
		getline(input, inputStr);

		for (int i = 0; i < inputStr.size(); i++)
			str.resize(str.getSize() + 1, inputStr[i]);

		return input;
	};

public:
	MyString() : MyArray(){};
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString(const MyString &str): MyArray(str){};
	// Constructs a copy of "str". (copy constructor)

	MyString(const MyString &str, size_t pos, size_t len = msize)
	{
		reserve(str.getCapacity());
		for (int i = 0; i < len; i++)
			resize(i + 1, str[pos + i]);
	}; // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char *s)
	{
		string str = s;
		while (getCapacity() <= str.size())
			reserve(getCapacity() * 2);
		for (int i = 0; i < str.size(); i++)
			resize(i + 1, str[i]);
	};
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	~MyString(){};
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append(const MyString &str)
	{
		while (getSize() + str.getSize() >= getCapacity())
			reserve(getCapacity() * 2);
		for (int i = 0; i < str.getSize(); i++)
			resize(getSize() + 1, str[i]);
		return *this;
	};
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const
	{
		MyString temp;
		while (temp.getCapacity() <= len)
			temp.reserve(temp.getCapacity() * 2);
		for (int i = 0; i < len; i++)
			temp.resize(i + 1, (*this)[pos + i]);
		return temp;
	};
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString &str)
	{
		MyString sub;
		for (int i = pos; i < getSize(); i++)
			sub.resize(sub.getSize() + 1, (*this)[i]);
		resize(pos, '\0');
		while (getCapacity() <= getSize() + str.getSize())
			reserve(getCapacity() * 2);
		for (int i = 0; i < str.getSize(); i++)
			resize(getSize() + 1, str[i]);
		for (int i = 0; i < sub.getSize(); i++)
			resize(getSize() + 1, sub[i]);
		return *this;
	};
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen = msize)
	{
		MyString sub;
		for (int i = pos; i < getSize(); i++)
			sub.resize(sub.getSize() + 1, (*this)[i]);
		resize(pos, '\0');
		while (getCapacity() <= getSize() + str.getSize())
			reserve(getCapacity() * 2);
		for (int i = 0; i < sublen; i++)
			resize(getSize() + 1, str[subpos + i]);
		for (int i = 0; i < sub.getSize(); i++)
			resize(getSize() + 1, sub[i]);
		return *this;
	};
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize)
	{
		MyString save;
		for (int i = pos + len; i < getSize(); i++)
			save.resize(save.getSize() + 1, (*this)[i]);
		resize(pos, '\0');
		for (int i = 0; i < save.getSize(); i++)
			resize(getSize() + 1, save[i]);
		return *this;
	};
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString &str, size_t pos = 0) const
	{
		for (int i = pos; i < getSize(); i++)
		{
			if ((*this)[i] == str[0])
			{
				MyString temp;
				for (int j = 0; j < str.getSize(); j++)
					temp.resize(temp.getSize() + 1, (*this)[j + i]);
				if (temp == str)
					return i;
			}
		}
		return msize;
	};
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString &str, size_t pos = 0) const
	{
		for (int i = pos; i < getSize(); i++)
		{
			for (int j = 0; j < str.getSize(); j++)
				if ((*this)[i] == str[j])
					return i;
		}
		return msize;
	};
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif