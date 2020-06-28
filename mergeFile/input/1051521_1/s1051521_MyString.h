#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include "s1051521_MyArray.h"
using namespace std;

class MyString : public MyArray
{
	friend ostream &operator<<(ostream& output, const MyString& str);

public:
	MyString();
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString(const MyString &str);
	// Constructs a copy of "str". (copy constructor)

	MyString(const MyString &str, size_t pos, size_t len = msize); // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char *s);
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	~MyString();
	// Destroys the string object.

	static const size_t msize = 999;
	//Note: maximum size.

	MyString& append(const MyString &str);
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos = 0, size_t len = msize) const;
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString &str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen);
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t subpos, size_t sublen);
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString &str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString &str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.


	MyString operator+ (const MyString& rhs) const;
	MyString operator+ (const char*   rhs) const;
	friend MyString operator+ (const char*   lhs, const MyString& rhs);

	MyString& operator= (const MyString& str);
	MyString& operator= (const char* s);
}; // end class MyString

#endif