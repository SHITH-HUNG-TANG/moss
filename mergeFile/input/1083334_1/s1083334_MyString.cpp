#include"s1083334_MyString.h"
#include<string>

MyString::MyString()
	:MyArray()
{

}
MyString::MyString(const MyString &str)
	:MyArray(str.getCapacity())
{
	resize(str.getSize());
	for (int i = 0; i < getSize(); i++) {
		(*this)[i] = str[i];
	}
}
MyString::MyString(const MyString &str, size_t pos, size_t len)
	:MyArray()
{
	int x = 0;
	if (len == msize) {
		resize(str.getSize() - pos);
		for (int i = pos; i < str.getSize(); i++) {
			(*this)[x++] = str[i];
		}
	}
	else {
		resize(len);
		while (len--) {
			(*this)[x++] = str[pos++];
		}
	}
}
MyString::MyString(const char *s) 
	:MyArray()
{
	resize(strlen(s));
	for (int i = 0; i < getSize(); i++) {
		(*this)[i] = s[i];
	}
}
MyString::~MyString() {

}
MyString& MyString::append(const MyString &str) {
	int s = getSize();
	resize(getSize() + str.getSize());
	for (int i = s; i < getSize(); i++) {
		(*this)[i] = str[i - s];
	}
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const {
	MyString temp;
	int x = 0;
	if (len == msize) {
		temp.resize(getSize() - pos);
		for (int i = pos; i < getSize(); i++) {
			temp[x++] = (*this)[i];
		}
	}
	else {
		temp.resize(len);
		while (len--) {
			temp[x++] = (*this)[pos++];
		}
	}
	return temp;
}
MyString& MyString::insert(size_t pos, const MyString &str) {	
	*this=substr(0, pos).append(str).append(substr(pos, getSize() - pos));
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen) {
	*this = substr(0, pos).append(str.substr(subpos, sublen)).append(substr(pos, getSize() - pos));
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len) {
	int length = (len == msize) ? getSize() - pos : len;
	*this = substr(0, pos).append(substr(pos + len, getSize() - length - pos));
	return *this;
}
size_t MyString::find(const MyString &str, size_t pos) const {
	for (int i = pos; i < getSize(); i++) {
		if ((*this)[i] == str[0]) {
			if ((substr(i, str.getSize()) == str)) {
				return i;
			}
		}
	}
	return msize;
}
size_t MyString::find_first_of(const MyString &str, size_t pos) const {
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < str.getSize(); j++) {
			if ((*this)[i] == str[j]) {
				return i;
			}
		}
	}
	return msize;
}
ostream &operator<<(ostream& output, const MyString& str) {
	for (int i = 0; i < str.getSize(); i++) {
		output << str[i];
	}
	return output;
}

istream &operator>>(istream& input, MyString& str) {
	string s;
	getline(input, s);
	str.resize(s.length());
	for (int i = 0; i < s.length(); i++) {
		str[i] = s[i];
	}
	return input;
}
