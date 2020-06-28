#ifndef s1062041_MyString_H
#define s1062041_MyString_H
#include <iostream>
#include <string>
#include <vector>
#include "s1062041_MyArray.h"
using namespace std;

template<typename T>
class MyString : public MyArray<T>
{
	//friend ostream &operator<<(ostream& output, const MyString& str);

public:
	MyString(); 
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString( const MyString<T> &str ); 
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

	const MyString& operator=(const MyString&);

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

template<typename T>
MyString<T>::MyString():MyArray<T>(10) {
	
}

template<typename T>
MyString<T>::MyString(const char *s):MyArray<T>(strlen(s)) {
	for (int i = 0; i < strlen(s); i++) {
		MyArray<T>::resize(1, s[i]);
	}
}

template<typename T>
MyString<T>::MyString(const MyString<T>& str):MyArray<T>(str) {
	
}

template<typename T>
MyString<T>::MyString(const MyString& str, size_t pos, size_t len):MyArray<T>(10){
	
	for (int j = pos; j < pos + len; j++) {
		MyArray<T>::resize(1, str.data[j]);
	}

}

template<typename T>
MyString<T>::~MyString() {
	
}

template<typename T>
const MyString<T>& MyString<T>::operator=(const MyString<T>& right) {

	if (&right != this) {
		if (MyArray<T>::getCapacity() != right.getCapacity()) {
			delete[] MyArray<T>::data;
			MyArray<T>::capacity = right.getCapacity();
			MyArray<T>::size = right.getSize();
			MyArray<T>::data = new T[MyArray<T>::capacity];
		}
		MyArray<T>::capacity = right.getCapacity();
		MyArray<T>::size = right.getSize();
		for (int i = 0; i < right.getSize(); i++) {
			MyArray<T>::data[i] = right.data[i];
		}
	}

	return *this;
}

template<typename T>
MyString<T>& MyString<T>::append(const MyString<T>& str) {

	for (int i = 0; i < str.getSize(); i++) {
		MyArray<T>::resize(1, str.data[i]);
	}

	return *this;
}

template<typename T>
MyString<T> MyString<T>::substr(size_t pos, size_t len) const {
	
	MyString temp(*this, pos, len);
	
	return temp;
	
}

template<typename T>
MyString<T>& MyString<T>::insert(size_t pos, const MyString<T>& str) {
	if (pos == MyArray<T>::getSize()) {
		for (int i = 0; i < str.getSize(); i++) {
			MyArray<T>::resize(1, str.data[i]);
		}
	}
	else {
		//先儲存要插入的後面的部分
		vector<T> tmp;
		unsigned int remainpos = pos;
		for (int i = remainpos; i < MyArray<T>::getSize(); i++) {
			tmp.push_back(MyArray<T>::data[i]);
		}
		
		//再從pos開始先全部刪除
		int count = 0;
		for (int i = pos; i < MyArray<T>::getSize(); i++, count++) {
			MyArray<T>::data[i] = NULL;
		}
		MyArray<T>::size -= count;

		//把要插入的部分儲存回去
		for (int i = 0; i < str.getSize(); i++) {
			MyArray<T>::resize(1, str.data[i]);
		}

		//最後把剩下的部分儲存回去
		for (int i = 0; i < tmp.size(); i++) {
			MyArray<T>::resize(1, tmp[i]);
		}

	}

	return *this;
}

template<typename T>
MyString<T>& MyString<T>::insert(size_t pos, const MyString<T>& str, size_t subpos, size_t sublen) {

	MyString sub(str, subpos, sublen);
	MyString<T>::insert(pos, sub);

	return *this;
}


template<typename T>
MyString<T>& MyString<T>::erase(size_t pos, size_t len) {

	//先儲存要刪除的後面的部分
	vector<T> tmp;
	unsigned int remainpos = len + pos;
	for (int i = remainpos; i < MyArray<T>::getSize(); i++) {
		tmp.push_back(MyArray<T>::data[i]);
	}

	//從pos開始全部刪除
	int count = 0;
	for (int i = pos; i < MyArray<T>::getSize(); i++, count++) {
		MyArray<T>::data[i] = NULL;
	}
	MyArray<T>::size -= count;

	//把剩下的部分儲存回去
	for (int i = 0; i < tmp.size(); i++) {
		MyArray<T>::resize(1, tmp[i]);
	}

	//更改capacity
	while (MyArray<T>::getSize() + 10 < MyArray<T>::getCapacity()) {
		MyArray<T>::reserve(MyArray<T>::getCapacity() / 2);
	}


	return *this;
}

template<typename T>
size_t MyString<T>::find(const MyString<T>& str, size_t pos) const {
	
	size_t ans = msize;
	bool isDiff;

	for (int i = pos; i < MyArray<T>::getSize(); i++) {
		//先比對第一個字
		if (str.data[0] == MyArray<T>::data[i]) {
			//如果第一個字相同的話
			isDiff = false;
			for (int j = 0; j < str.getSize(); j++) {
				//再連續比對整個詞
				if (MyArray<T>::data[i + j] != str.data[j]) {
					isDiff = true;
				}
			}
			//看看有沒有找到
			if (!isDiff) {
				ans = i;
			}
		}
		
	}
	return ans;

}

template<typename T>
size_t MyString<T>::find_first_of(const MyString<T>& str, size_t pos) const {
	 
	size_t ans = msize;
	
	for (int i = 0; i < str.getSize(); i++) {
		//str每個都要比對
		for (int j = pos; j < MyArray<T>::getSize(); j++) {
			if (str.data[i] == MyArray<T>::data[j]) {
				//如果比對到相同的字
				if (j < ans) {
					//比較有沒有比較小
					ans = j;
				}
			}
		}
	}

	return ans;

}