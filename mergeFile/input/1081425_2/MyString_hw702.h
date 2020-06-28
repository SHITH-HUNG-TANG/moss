#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include "MyArray_hw701.h"
using namespace std;

class MyString : public MyArray<char>
{
	friend ostream& operator<<(ostream& output, const MyString& str);
	friend istream& operator>>(istream& ism,MyString& str);

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

ostream &operator<<(ostream& os, const MyString& str){
	for(int i = 0 ; i < str.getSize();i++){
		cout<<str[i];
	}
	return os;
}

istream& operator>>(istream& is,MyString& str){
	str.clear();
	char c = is.get();
	while(c != '\n' && c != ' '){
		str.resize(str.getSize() + 1);
		str[str.getSize() - 1] = c;
		c = is.get();
	}
	return is;
}

MyString::MyString():MyArray(10){
}

MyString::MyString(const MyString &str){
	*this = str;
}

MyString::MyString(const MyString &str, size_t pos, size_t len ){
	if(len == msize){
		len = str.getSize() - pos;
	}
	resize(len);
	for(size_t i = 0 ; i < len;i++){
		(*this)[i] = str[i + pos];
	}
}

MyString::MyString(const char *s){
	int cnt = 0;
	while(s[cnt] != '\0'){
		resize(getSize() + 1);
		(*this)[getSize() - 1] = s[cnt++];
	}
}

MyString::~MyString(){
}

MyString& MyString::append(const MyString &str){
	*this += str;
	return *this;
}

MyString MyString::substr(size_t pos,size_t len)const{
	return MyString(*this,pos,len);
}

MyString& MyString::insert(size_t pos,const MyString& str){
	this->resize(str.getSize() + this->getSize());
	for(int i = this->getSize() - 1 ; i > pos;i--){
		(*this)[i] = (*this)[i - str.getSize()]; 
	}
	for(int i = pos ; i < str.getSize() + pos ; i++){
		(*this)[i] = str[i - pos];
	}
	return *this;
}

MyString& MyString::insert(size_t pos,const MyString& str,size_t subpos,size_t sublen){
	return this->insert(pos,str.substr(subpos,sublen));
}

MyString& MyString::erase(size_t pos,size_t len){
	if(len == msize || pos + len >= this->getSize()){
		this->resize(pos);
		return *this;
	}
	for(int i = pos ; i < pos + len;i++){
		(*this)[i] = (*this)[i + len];
	}
	this->resize(this->getSize() - len);

	return *this;
}

size_t MyString::find(const MyString& str,size_t pos) const{
	for(int i = pos ; i < this->getSize();i++){
		if((*this)[i] == str[0]){
			bool find = true;
			for(int j = 0 ; j < str.getSize();j++){
				if((*this)[i +j] != str[j] || i + j >= this->getSize()){
					find = false;
					break;
				}
			}
			if(find){
				return i;
			}
		}

	}
	return msize;
}

size_t MyString::find_first_of(const MyString& str,size_t pos) const{
	for(int i = 0; i < this->getSize() ;i++){
		bool find = false;
		for(int j = 0 ; j < str.getSize();j++){
			if((*this)[i] == str[j]){
				find = true;
				break;
			}
		}
		if(find){
			return i;
		}
	}
	return msize;
}