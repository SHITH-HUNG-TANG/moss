#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include<exception>
#include<stdexcept>
#include<cstdint>
#include<stdlib.h>
#include<cstring>
#include "s1073501_MyArray.h"
using namespace std;

class MyString : public MyArray<char>{
	friend ostream &operator<<(ostream& out, const MyString& str){
		for (int i = 0; i < str.size; i++) 
			out << str.data[i];
		cout << endl;
		return out;
	};
public:
	MyString() : MyArray() {
		this->capacity = 10;
		this->size = 0;
		this->data = new char[capacity]{};
	}
	
// Constructs a copy of "str". (copy constructor)
	MyString(const MyString& str) {
		size = str.getSize();
		capacity = str.getCapacity();
		data = new char[capacity];

		memcpy(data, str.data, str.size + 1);
		/*for (int i = 0; i < str.getSize(); i++) {
			this->data[i] = str.data[i];
		}*/

		/*int len = strlen(str.data);
		data = new char[len + 1];
		strcpy(this->data, str.data);*/
	}
	// (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).
	MyString(const MyString& str, size_t pos, size_t len = msize):MyArray() {
		if(len==msize)
		this->size =pos - len;
		else {
			this->size = len - pos;
		}
		this->capacity = 10;
		while (this->size > this->capacity) {
			capacity *= 2;
		}
		this->data = new char[capacity]{ NULL };
		//for (int i = pos ; i < len; i++) {
		//	//for(int j=0; j<len; j++)
		//}
		if (len == msize) {
			for (int i = 0;i < this->size;i++) {
				this->data[i] = str.data[i];
			}
		}
		else {
			for (int i = pos, j = 0; i < len; i++, j++) {
				this->data[j] = str.data[i];
			}
		}
	}
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	MyString(const char* a): MyArray(){
		int len = strlen(a);
		/*for (int i = 0; i < strlen(a); i++) {
			data[i] = a.data[i];
		}*/

		data = new char[capacity];
		memcpy(data, a, len + 1);
		size = len;
	}
	~MyString() {
		data = NULL;
		delete[] data;
		size = 0;
		capacity = 0;
	}
	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append(const MyString& str) {
		MyString tmp = str;
		int s = this->size;
		tmp.size = s + str.size;
		tmp.resize(tmp.size, 0);
		this->capacity = str.getCapacity();

		//cout << "tmp size:" << tmp.size << endl;;

		for (int i = 0; i < this->size; i++) {
			tmp.data[i] = this->data[i];
		}
		for (int j = this->size; j < tmp.size; j++) {
			tmp.data[j] = str.data[j - size];	//Tmp.data[obj.size］=obj.data[0]
		}
		*this = tmp;
		return *this;
	}
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const {
		MyString tmp;
		tmp.resize(len,NULL);
		for (int i = pos;i < len + pos;i++) {
			tmp.data[i-pos] = this->data[i];
		}
		
		//tmp.size = len + pos;
		//tmp.resize(tmp.size, 0);
		//for (int i = 0; i < this->size; i++) {
		//	tmp.data[i] = this->data[i];
		//}
		//for (int j = this->size; j < tmp.size; j++) {
		//	tmp.data[j] = this->data[j - size];	//Tmp.data[obj.size］=obj.data[0]
		//}
		return tmp;
	}
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
	MyString& insert(size_t pos, const MyString& str) {
		size_t lengthDest = size;
		size_t lengthSource = str.size;
		MyString tmp(data);
		tmp.size = size + str.size;
		this->size = tmp.size;
		tmp.capacity = 10;
		while (this->size > this->capacity) {
			capacity *= 2;
		}
		tmp.capacity = capacity;
		data = new char[lengthSource + lengthDest + 1];
		for (int i = 0; i < pos; i++)
			data[i] = tmp.data[i];
		for (int i = pos, j = 0;i < str.size + pos; i++, j++)
			data[i] = str.data[j];
		for (int i = pos + str.size, j = 0;i < tmp.size;i++, j++) 
			data[i] = tmp.data[pos + j];
			return *this;
	}
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize) {
		MyString tmp ;
		tmp = str.substr(subpos, sublen);
		//cout << tmp << endl;
		this->insert(pos, tmp);
		return *this;
		//if (sublen == msize)
		//	tmp.size=this->size + (str.getSize()-subpos);
		//else {
		//	tmp.size = this->size + sublen;
		//}
		////this->capacity = 10;
		//while (tmp.size > tmp.capacity) {
		//	tmp.capacity *= 2;
		//}
		//tmp.data = new char[tmp.capacity]();
		////MyString tmp;
		////tmp.size = size + str.size;
		//////this->size = tmp.size;
		////tmp.capacity = 10;
		////while (tmp.size > tmp.capacity) {
		////	tmp.capacity *= 2;
		////}
		////tmp.capacity = capacity;
		//if (sublen == msize) {
		//	for (int i = 0;i < pos;i++) {
		//		tmp.data[i] = this->data[i];
		//	}
		//	for (int i = pos, j = subpos;i < (str.getSize() - subpos);i++, j++)tmp.data[i] = str.data[j];
		//	for (int i = pos + (str.getSize() - subpos),  j = pos;i < tmp.size;i++, j++)tmp.data[i] = this->data[j];
		//}
		//else {
		//	/*for (int i = 0;i < pos;i++)
		//		tmp.data[i] = this->data[i];//to be (6)
		//	for (int i = pos, j = subpos; i < pos + sublen; j++, i++) {
		//		if (j < subpos + sublen - 1)
		//			tmp.data[i] = str.data[j];//not
		//		
		//	}
		//	for (int i = pos + sublen, j = pos; i < size + sublen; j++, i++) {//這裡吃步道植ㄚㄚㄚ
		//		tmp.data[i] = this->data[j];
		//	}*/
		//	for (int i = 0;i < pos;i++)
		//		tmp.data[i] = this->data[i];
		//	for(int j=pos;j<pos+sublen;j++)
		//		tmp.data[j] = str.data[j];
		//	for(int i= pos + sublen;i<tmp.size;i++)
		//		tmp.data[i] = this->data[i];
		//}
		//*this = tmp;
		//return *this;
	}
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize) {
	if (pos >= size) {
		cout << "Index out of range." << endl;
		return *this;
	}
	if (pos == 0 && len == -1) {
		clear();
	}
	else if (pos + len > size) {
		*(data + pos) = '\0';
		size = pos + 1;
	}
	else {
		for (int i = 0; i < len; i++) {
			*(data + pos + i) = *(data + pos + len + i);
		}
		*(data + pos + len) = '\0';
		size -= len;
	}
	return *this;
}
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	/*size_t find(const MyString& str, size_t pos = 0) const {
		if (pos > str.size ){
			cout << "fail pos " << str.size << endl;
			return -1;
		}
		char ch = str.data[pos--];
		for (int i = pos;i < size;i++){
			if (ch == data[i])
				return i ;
		}
	}*/
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

/* size_t find_first_of(const MyString& str, size_t pos = 0) const {
	
}*/
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.


}; // end class MyStrin

#endif
