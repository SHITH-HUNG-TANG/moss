#ifndef PG2MyString_H
#define PG2MyString_H
#include"s1081421_MyArray.h"
#include<vector>
#include<iostream>
#include <exception>
#include<stdexcept>
using namespace std;
class MyString :public MyArray<char> {
	friend istream &operator>>(istream &input, MyString &right) {

		char *tmp = new char[10000]();
		input >> tmp;
		/*for (int i = 0; tmp[i] != '\0'; i++)
			if (tmp[i] == '\0')
				right.resize(i,' ');*/
		int i = 0;
		while (tmp[i] != '\0')
			i++;
		right.resize(i, ' ');
		for (int i = 0; i < right.getSize(); i++) {
			right.at(i) = tmp[i];
		}
		return cin;
	}
public:
	MyString();
	MyString(const MyString&str);
	MyString(const MyString&str, int pos, int msize);
	MyString(const char *s);
	~MyString();
	static const int msize = -1;
	MyString& append(const MyString&);
	MyString substr(int po, int len = msize)const;
	MyString& insert(int po, const MyString&);
	MyString& insert(int po, const MyString&, int subpos, int sublen);
	MyString& erase(int po, int len);
	int find(const MyString&, int pos = 0)const;
	int find_first_of(const MyString&, int pos = 0)const;
private:
};
MyString::MyString() :MyArray<char>() {
}
MyString::MyString(const MyString& right) : MyArray<char>(right) {

}
MyString::MyString(const MyString&str, int pos, int len) : MyArray<char>(10) {
	*this = str.substr(pos, len);
}
MyString::MyString(const char *s) 
:MyArray(10)
{
	int x = 0;
	while (1) {
		if (s[x] == '\0')
			break;
		x++;
	}
	int len = x;
	resize(len, ' ');
	for (int i = 0; i < len; i++) {
		at(i) = s[i];
	}
}
MyString::~MyString() {

}
MyString&MyString:: append(const MyString& right) {
	*this += right;
	return *this;
}

MyString MyString::substr(int po, int len)const {
	if (len + po  > getSize()) {
		len = getSize() - po;
	}
	MyString temp;
	temp.resize(len, ' ');
	for (int i = 0; i < len; i++) {
		temp.at(i) = at(po + i);
	}
	return temp;
}
MyString& MyString::insert(int po, const MyString&right) {
	MyString temp=this->substr( po, getSize() - po);
	erase(po, getSize() - po);
	*this += right;
	*this += temp;
	return *this;
}
MyString& MyString::insert(int po, const MyString&right, int po2, int ed) {
	if (ed > right.getSize()-1) {
		ed = right.getSize() -1;
	}
	MyString temp = this->substr(po, getSize() - po);
	erase(po, getSize() - po);
	MyString temp2 = right.substr(po2, ed - po2+1);
	*this += temp2;
	*this += temp;
	return *this;
}
MyString& MyString::erase(int po, int len) {
	if (len + po > getSize()) {
		len = getSize() - po;
	}
	MyString temp=this->substr(po+len,getSize()-po-len);
	MyString temp2 = *this;
	temp2.resize(getSize() - len,' ');
	for (int i = 0; i < po; i++) {
		temp2.at(i) = at(i);
	}
	for (int i = po; i < temp2.getSize(); i++) {
		temp2.at(i) = temp.at(i - po);
	}
	return *this=temp2;
}
int MyString::find(const MyString&right, int pos )const {
	bool ans = 0;
	int check = 0;
	int posing=0;
	for (int i = 0; i+pos < getSize(); i++) {
		int j = i;
		int k = 0;
		while (at(i + pos) == right.at(k)) {
			if (check == right.getSize()-1) {
				ans = 1;
				posing = i + pos - right.getSize() + 1;
				break;
			}
			check++;
			i++;
			k++;
		}
		i = j;
		check = 0;
	}
	if (ans == 1)
		return posing;
	else
		return msize;

}
int MyString::find_first_of(const MyString&right, int pos)const {
	int ans = msize;
	for (int i = pos; i < getSize(); i++) {
		for (int j = 0; j < right.getSize(); j++) {
			if (at(i) == right.at(j)) {
				ans = i;
				break;
			}
		}
		if (ans != msize)
			break;
	}
	return ans;
}
#endif
