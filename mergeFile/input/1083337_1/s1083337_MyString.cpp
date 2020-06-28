#include "s1083337_MyString.h"

MyString::MyString() {
	(*this).resize(1, '\0');
}

MyString::MyString(const MyString& str) {

	resize(str.getSize(), '\0');
	for (int i = 0; i < getSize(); i++) {
		(*this)[i] = str[i];
	}
}
MyString::MyString(const MyString& str, size_t pos, size_t len ) {
 
	(*this).resize(len, '\0');
	size_t x = pos + len;
	for (int i = 0 ; pos <  x ;  i++, pos++) {
		(*this)[i] = str[pos];
	}
}
MyString::MyString(const char* s) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	(*this).resize(len, '\0');
	for (int i = 0; i < len; i++) {
		(*this)[i] = s[i];
	}
}
MyString::~MyString() {
	(*this).resize(0, '\0');
}

MyString& MyString ::append(const MyString& str) {

	int w = (*this).getSize();
	if (w == 1) {
		w = 0 ;
	}
	(*this).resize((*this).getSize() + str.getSize() , '\0');
	for (int j = 0 ;  j < str.getSize(); j++, w++) {
		(*this)[w] = str[j];
	}
	return (*this);
}
MyString MyString :: substr (size_t pos, size_t len ) const {
		MyString temp;
		temp.resize(len, '\0');
		for (int i = pos, k = 0; i < (pos + len); i++, k++) {
			temp[k] = (*this)[i];
		}
		return temp;
}

MyString& MyString::insert(size_t pos, const MyString& str) {

	MyString after;
	after.resize((*this).getSize() - pos  , '\0');

	for (int i = pos , k = 0 ; k < after.getSize(); i++, k++) {			//存放後半部的字串
		after[k] = (*this)[i];
	}

	(*this).resize((*this).getSize() + str.getSize(), '\0');

	for (int i = pos , k = 0 ; k < str.getSize() ; i++, k++) {
		(*this)[i] = str[k];
	}
	for (int i = pos + str.getSize() , k = 0; k < after.getSize(); i++, k++) {
		(*this)[i] = after[k];
	}
	return (*this);
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen ) {

	
	MyString after;
	after.resize((*this).getSize() - pos, '\0');
	
	for (int i = pos, k = 0 ; k <after.getSize(); i++, k++) {			//存放後半部的字串
		after[k] = (*this)[i];
	}

	MyString sub;
	sub.resize(sublen, '\0');
	sub = str.substr(subpos, sublen);
	(*this).resize((*this).getSize() +sub.getSize(), '\0');

	for (int i = pos, k = 0; k < sub.getSize() ; i++, k++) {
		(*this)[i] = sub[k];
	}
	for (int i = pos +sublen , k = 0; k < after.getSize(); i++, k++) {
		(*this)[i] = after[k];
	}
	return (*this);
}
MyString& MyString::erase(size_t pos, size_t len ) {

	MyString temp;
	if (len > ((*this).getSize() - pos)) {
		temp.resize( pos , '\0');
	}
	else
	{
	temp.resize((*this).getSize() - len, '\0');
	}
	int r = 0;
	for (int i = 0; i < pos; i++,r++) {
		temp[r] = (*this)[i];
	}
	for (int i = pos + len; i < (*this).getSize(); i++,r++) {
		temp[r] = (*this)[i];
	}
	(*this) = temp;
	return (*this);
}
size_t MyString::find(const MyString& str, size_t pos ) const {

	int flag  ;
	int ans;
	for (int i = pos , x = 0 ; i < (*this).getSize(); i++) {
		x = 0 ;
		flag = 0;
		if ((*this)[i] == str[x]) {											//遇到頭一樣的時候
			ans = i ;															//ans 先放 位置 
			MyString temp;
			temp.resize(str.getSize(), '\0');
			temp = (*this).substr( i , str.getSize());
			for (int k = 0; k < str.getSize(); k++) {
				if (temp[k] != str[k]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				return ans;
			}
		}
	}
	return msize;
}

size_t MyString :: find_first_of(const MyString& str, size_t pos ) const {
	
	for (int i = pos; i < (*this).getSize(); i++) {
		for (int k = 0; k < str.getSize(); k++) {
			if ((*this)[i] == str[k]) {
				return i ;
			}
		}
	}
	return msize;
}
istream& operator>>(istream& input, MyString& value) {

	string str;
	input >> str;
	value.resize(str.size(), '\0');
	for (int i = 0; i < value.getSize(); i++) {
		value[i] = str[i];
	}
	return input;
}