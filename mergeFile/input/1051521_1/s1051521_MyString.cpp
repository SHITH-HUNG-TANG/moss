#include <iostream>
#include "s1051521_MyString.h"
using namespace std;

MyString::MyString() {

}

MyString::MyString(const MyString &str) : MyArray(str) {

}

MyString::MyString(const MyString &str, size_t pos, size_t len) : MyArray() {
	char ch;
	reserve(len);
	for (int i = 0; i < len; i++) {
		ch = str[pos + i];
		push_back(ch);
	}
}

MyString::MyString(const char *s) : MyArray() {
	reserve(strlen(s));
	while (*s != '\0') {
		push_back(*s);
		s++;
	}
}

MyString::~MyString() {

}

MyString &MyString::append(const MyString &str) {
	reserve(getSize() + str.getSize());

	char words;
	for (int i = 0; i < str.getSize(); i++) {
		words = str[i];
		push_back(words);
	}
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const {
	MyString x;
	char ch;
	x.reserve(len);
	for (int i = 0; i < len; i++) {
		ch = (*this)[pos + i];
		x.push_back(ch);
	}
	return x;
}

MyString &MyString::insert(size_t pos, const MyString &str) {
	reserve(getSize() + str.getSize());
	char x;
	MyString newstring(*this);
	resize(pos);
	for (int i = 0; i < str.getSize(); i++) {
		x = str[i];
		push_back(x);
	}
	for (int i = 0; i < newstring.getSize() - pos; i++) {
		x = newstring[pos + i];
		push_back(x);
	}
	return *this;
}

MyString &MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen) {
	reserve(getSize() + sublen);
	char ch;
	MyString newstring(*this);
	resize(pos);
	for (int i = 0; i < sublen; i++) {
		ch = str[subpos + i];
		push_back(ch);
	}
	for (int i = 0; i < newstring.getSize() - pos; i++) {
		ch = newstring[pos + i];
		push_back(ch);
	}
	return *this;
}

MyString &MyString::erase(size_t subpos, size_t sublen) {
	char ch;
	MyString newstring(*this);
	resize(subpos);
	for (int i = 0; i < newstring.getSize() - subpos - sublen; i++) {
		ch = newstring[subpos + sublen + i];
		push_back(ch);
	}
	return *this;
}

size_t MyString::find(const MyString &str, size_t pos) const {
	bool flag;

	for (int i = pos; i < (getSize() - str.getSize() + 1); i++) {
		flag = true;
		for (int k = 0; k < str.getSize(); k++) {
			if (str[k] != (*this)[i + k]) {
				flag = false;
				break;
			}
		}
		if (flag)
			return i;
	}
	return msize;
}

size_t MyString::find_first_of(const MyString &str, size_t pos) const {
	bool flag;

	for (int i = pos; i < getSize(); i++) {
		flag = false;
		for (int k = 0; k < str.getSize(); k++) {
			if (str[k] == (*this)[i]) {
				flag = true;
				break;
			}
		}
		if (flag)
			return i;
	}
	return msize;
}

MyString MyString::operator+ (const MyString& rhs) const {
	MyString x(*this);
	x.append(rhs);
	return x;
}

MyString MyString::operator+ (const char* rhs) const {
	MyString x(rhs);
	MyString y(*this);
	y.append(x);
	return y;
}

MyString operator+ (const char*lhs, const MyString& rhs) {
	MyString x(lhs);
	x.append(rhs);
	return x;
}

MyString &MyString::operator= (const MyString& str) {
	//MyString x(str);
	//return x;

	clear();
	reserve(str.getSize());
	for (int i = 0; i < str.getSize(); i++) {
		push_back(str[i]);
	}
	return *this;
}

MyString &MyString::operator= (const char* s) {
	clear();
	reserve(strlen(s));
	while (*s != '\0') {
		push_back(*s);
		s++;
	}
	return *this;
}

ostream &operator<<(ostream& output, const MyString& str) {
	output << static_cast<const MyArray &>(str);
	return output;
}