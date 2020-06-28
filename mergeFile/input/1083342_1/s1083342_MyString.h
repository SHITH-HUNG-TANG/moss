#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include<string>
#include "s1083342_MyArray.h"
using namespace std;


//////////////////////�g�k���Pcpp�ɡA�n��
class MyString : public MyArray<char>
{
	friend istream& operator>>(istream& input, MyString& i)
	{
		string k;
		int p = 0;
		input >> k;
		while (p < k.length())
		{
			i.push_back(k[p]);
			p++;
		}
		return input;
	}

	/*friend ostream& operator<<(ostream& output, const MyString& i)
	{
		if (i.getSize() == 0)
		{
			cout << "nothing";
		}
		for (int j = 0;j < i.getSize();j++)
		{
			output << i.data[j];
		}
		return output;
	}*/

public:
	
	MyString() : MyArray<char>()
	{
	}
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10
	
	MyString(const MyString& str)
	{
		this->size = str.size;
		this->capacity = str.capacity;
		this->data = new char[str.capacity]();
		for (int j = 0;j < str.size;j++)
		{
			this->data[j] = str.data[j];
		}
	}
	// Constructs a copy of "str". (copy constructor)
	MyString(const MyString& str, size_t pos, size_t len = msize)
	{
		this->size = 0;
		this->capacity = 10;
		this->data = new char[this->capacity]();
		if(len!=-1&& pos < str.size)
		{
			for (int i = pos;i < pos + len;i++)
			{
				this->push_back(str.data[i]);
			}
		}
	}
	// (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).
	
	MyString(const char* s)
	{
		this->size = 0;
		this->capacity = 10;
		this->data = new char[this->capacity]();
		int i = 0;
		while (s[i] != NULL)
		{
			this->push_back(s[i]);
			i++;
		}
	}
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.
	
	~MyString()
	{
	}
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.
	
	MyString& append(const MyString& str)
	{
		//this->push_back(' ');
		for (int i = 0;i < str.size;i++)
		{
			this->push_back(str.data[i]);
		}
		return *this;
	}
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself
	
	MyString substr(size_t pos, size_t len = msize) const
	{
		try
		{ 
			this->at(pos);
			MyString g;
			if (len!= -1&&pos< this->size)
			{
				for (int i = pos;i < len+ pos;i++)
				{
					g.push_back(this->data[i]);
				}
			}
			return g;
		}
		catch (out_of_range & h)
		{
			cout << h.what() << endl;
			return *this;
		}
	}
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
	
	MyString& insert(size_t pos, const MyString& str)
	{
		try
		{
			this->at(pos);
			MyString h;
			int a = this->size;
			for (int i = pos;i < this->size;i++)  //����ɫ᭱�����s�_��
			{
				h.push_back(this->data[i]);
			}
			for (int i = pos;i < a;i++) //���ɫ᭱�R��
			{
				this->pop_back();
			}
			for (int i = 0;i < str.size;i++)  //��J�s���ƦC
			{
				this->push_back(str.data[i]);
			}
			for (int i = 0;i < h.size;i++) //��J�Ȧs��
			{
				this->push_back(h.data[i]);
			}
			return *this;
		}
		catch (out_of_range & f)
		{
			cout << f.what() << endl;
			return *this;
		}
	}
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself
	
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize)
	{
		try
		{ 
			this->at(pos);
		}
		catch (out_of_range & f)
		{
			cout << f.what() << endl;
			return *this;
		}
		try
		{
			str.at(subpos);
		}
		catch (out_of_range & f)
		{
			cout << f.what() << endl;
			return *this;
		}
		if (sublen != -1 && subpos < str.size&& pos<this->size&&sublen<=str.size-subpos)
		{
			this->insert(pos, str.substr(subpos, sublen));
		}
		return *this;
	}
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself
	
	MyString& erase(size_t pos, size_t len = msize)
	{
		try
		{
			this->at(pos);
			if (len != -1 && pos < this->size&&len<= this->size-pos)
			{
				MyString k;
				int d = this->size;
				for (int i = pos + len;i < this->size;i++) //��᭱���s�_��
				{
					k.push_back(this->data[i]);
				}
				for (int i = pos;i < d;i++)   //��᭱�����R��
				{
					this->pop_back();
				}
				for (int i = 0;i < k.size;i++)   //�A��᭱��^��
				{
					this->push_back(k.data[i]);
				}
			}
			return *this;
		}
		catch (out_of_range & f)
		{
			cout << f.what() << endl;
			return *this;
		}
	}
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself
	
	size_t find(const MyString& str, size_t pos = 0) const
	{
		int g = 0; //�Ĺs��
		int f = 0; //�P�_���X���@��
		int x = 0; //�ĴX��
		for (int i = pos;i < this->size;i++)
		{
			if (this->data[i] == str[g])
			{
				x = i;  //�ĴX��
				for (int h = 1;h < str.size;h++)
				{
					if (this->data[i + h] == str[h])
					{
						f++;
					}
				}
				if (f == str.size - 1)
				{
					return  x;
				}
			}
		}
		return msize;
	}
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.
	
	size_t find_first_of(const MyString& str, size_t pos = 0) const
	{
		for (int i = pos;i < this->size;i++)
		{
			for (int k = 0;k < str.size;k++)
			{
				if (this->data[i] == str.data[k])
				{
					return i;
				}
			}
		}
		return msize;
	}
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif
