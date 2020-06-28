#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include<string>
#include "s1071221_MyArray_hw701.h"
using namespace std;

class MyString :public MyArray<char>
{
	//friend ostream &operator<<(ostream& output, const MyString& str);
	friend ostream& operator<<(ostream& output, const MyString&str)
	{
		for (int i = 0; i < str.size; i++)
			output << str.data[i];
		return output;
	}
	friend istream& operator>>(istream& input, MyString& str)
	{
		string number;
		input >> number;
		str.size = number.size();
		for (int i = 0; i < str.size; i++)
		{
			str.data[i] = number[i];
		}
		return input;
	}
public:
	MyString();
	//篶硑才﹃箂才
	// *纐粄甧秖= 10

	MyString(const MyString& str);
	//篶硑¨ str〃捌セ 狡籹篶硑ㄧ计

	MyString(const MyString& str, size_t pos, size_t len = msize); // 才﹃篶硑ㄧ计
	//狡籹眖才竚¨ pos〃秨﹍阁禫¨ len〃才str场だ
	//┪str挡Ю狦strび祏┪len琌string :: msize

	MyString(const char* s);
	//狡籹s才C才﹃计舱
	// char * s琌null沧ゎ才皐 ┮Τ才*/
	//盢狡籹才﹃穝

	~MyString();
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append(const MyString& str);
	//讽玡MyStringЮ场str
	// *ōまノ

	MyString substr(size_t pos, size_t len = msize) const;
	//才﹃琌癸禜场だ眖才竚pos秨﹍阁禫len才
	//┪才﹃ソЮ非
	// *穝篶硑才﹃癸禜ㄤ﹍て赣癸禜才﹃捌セ

	MyString& insert(size_t pos, const MyString& str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize);
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize);
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString& str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString

#endif