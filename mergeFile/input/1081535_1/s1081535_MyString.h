#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include<string>
#include "s1081535_MyArray.h"
using namespace std;


class MyString : public MyArray<char>
{
	//輸入運算子重載
	friend istream& operator >> (istream &input, MyString &x)
	{
		string s;
		input >> s;
		for (int i = 0; i < s.length(); i++)
		{
			x.push_back(s[i]);
		}

		return input;
	}


	//friend ostream &operator<<(ostream& output, const MyString& str);

public:

	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10
	MyString()
		:MyArray(10)
	{
	}

	// Constructs a copy of "str". (copy constructor)
	MyString(const MyString &str)
		:MyArray(str)
	{
	}

	// (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).
	MyString(const MyString &str, size_t pos, size_t len = msize)
		:MyArray(10)
	{
		if (pos < str.getSize() & len != -1)
		{
			for (int i = pos; i < pos + len; i++)
			{
				push_back(str.data[i]);
			}
		}
	}

	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.
	MyString(const char *s)
		:MyArray(10)
	{
		int i = 0;
		while (s[i] != NULL)
		{
			push_back(s[i]);
			i++;
		}
	}

	// Destroys the string object.
	~MyString()
	{
	}

	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.
	static const size_t msize = -1;

	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself
	MyString& append(const MyString &str)
	{
		*this += str;
		return *this;
	}

	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
	MyString substr(size_t pos, size_t len = msize) const
	{
		try
		{
			at(pos);
			MyString newstr;
			if (pos < getSize() & len != -1 & len <= getSize() - pos)
			{

				for (int i = pos; i < pos + len; i++)
				{
					newstr.push_back(data[i]);
				}
			}
			return newstr;
		}
		catch (const out_of_range&orr)
		{
			MyString newstr(orr.what());
			return newstr;
		}
	}

	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself
	MyString& insert(size_t pos, const MyString &str)
	{
		if (pos < getSize())
		{
			MyString newstr;
			for (int i = getSize() - 1; i >= pos; i--)
			{
				newstr.push_back(data[i]);
				pop_back();
			}
			for (int i = 0; i < str.getSize(); i++)
			{
				push_back(str.data[i]);
			}
			for (int i = newstr.getSize() - 1; i >= 0; i--)
			{
				push_back(newstr.data[i]);
			}
			return *this;
		}
		else
		{
			cout << "out_of_range：";
			return *this;
		}

	}

	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself
	MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen = msize)
	{
		if (pos<getSize()&&subpos<str.getSize()&&sublen != -1 && sublen < str.getSize() - subpos)
		{
			MyString newstr;
			for (int i = getSize() - 1; i >= pos; i--)
			{
				newstr.push_back(data[i]);
				pop_back();
			}
			for (int i = subpos; i < subpos + sublen; i++)
			{
				push_back(str.data[i]);
			}
			for (int i = newstr.getSize() - 1; i >= 0; i--)
			{
				push_back(newstr.data[i]);
			}
			return *this;
		}
		else
		{
			if (pos < getSize()|| subpos < str.getSize()) cout << "out_of_range：";
			else cout << "length_over_string：";
			return *this;
		}
	}

	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself
	MyString& erase(size_t pos, size_t len = msize)
	{
		if (pos<getSize()&&len != -1 && len < getSize() - pos)
		{
			MyString newstr;
			for (int i = pos + len; i < getSize(); i++)
			{
				newstr.push_back(data[i]);
			}
			for (int i = 0; i < getSize() - pos; len++)
			{
				pop_back();
			}
			for (int i = 0; i < newstr.getSize(); i++)
			{
				push_back(newstr.data[i]);
			}
			return *this;
		}
		else
		{
			if (pos < getSize()) cout << "out_of_range：";
			else cout << "length_over_string：";
			return *this;
		}
	}



	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.
	size_t find(const MyString &str, size_t pos = 0) const
	{
		int newmsize = -1;
		for (int i = pos; i < getSize(); i++)
		{
			int k = 0;
			for (int j = 0; j < str.getSize(); j++)
			{
				if (data[i + j] == str.data[j])k++;
			}
			if (k == str.getSize())
			{
				newmsize = i;
				break;
			}
		}
		return newmsize;
	}

	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
	size_t find_first_of(const MyString &str, size_t pos = 0) const
	{

		int newmsize = -1;
		for (int i = pos; i < getSize(); i++)
		{
			for (int j = 0; j < str.getSize(); j++) 
			{
				if (data[i] == str.data[j])
				{
					newmsize = i;
					break;
				}
			}
			if (newmsize != -1)break;
		}
		return newmsize;
	}

	
	
	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif