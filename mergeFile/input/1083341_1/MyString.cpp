#include <iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include <limits.h>
#include "MyString.h"
using namespace std;

istream& operator>>(istream& input, MyString& str) {

	string temp;
	input >> temp;
	str.resize(temp.length(), '\0');
	for (int i = 0; i < str.getSize(); i++) {
		str[i] = temp[i];
	}
	return input;
}
MyString::MyString() 
	:MyArray()
{
}
MyString::MyString(const MyString& str)
	: MyArray(str)
{
}
MyString::MyString(const MyString& str, size_t pos, size_t len )
	:MyArray(len,'\0')
{

	for (int i = 0; i < len; i++) {
		operator[](i) = str.operator[](i+pos);
	}
}
MyString::MyString(const char* s)
{
	int n = 0;
	while (true) {
		if (s[n] == '\0')
			break;
		n++;
	}
	this->resize(n, '\0');
	for (int i = 0; i < n; i++) {
		operator[](i) = s[i];
	}
}
MyString::~MyString() 	
{
}
MyString& MyString::append(const MyString& str)
{
	MyString ans;
	int inheritancesize = getSize() + str.getSize();
	ans.resize(inheritancesize, '0');
	for (int i = 0; i < getSize(); i++) {
		ans.operator[](i) = operator[](i);
	}
	for (int i = getSize(); i < inheritancesize; i++) {
		ans.operator[](i) = str.operator[](i-getSize());
	}
	*this = ans;
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
	MyString ans;
	ans.resize(len, '0');
	int k = pos;
	for (int i = 0; i < len; i++) {
		ans.operator[](i) = operator[](k);
		k++;
	}
	return ans;
}
MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString ans;
	int inheritancesize = getSize() + str.getSize();
	ans.resize(inheritancesize, '0');

	for (int j = 0; j < pos; j++) {
		ans.operator[](j) = operator[](j);
	}
	int k = pos;
	for (int i = 0; i < str.getSize(); i++) {
		ans.operator[](k) = str.operator[](i);
		k++;
	}
	int z = pos;
	for (int x = pos + str.getSize(); x < inheritancesize; x++) {
		ans.operator[](x) = operator[](z);
		z++;
	}
	*this = ans;
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString ans;
	int inheritancesize = getSize() + sublen;
	ans.resize(inheritancesize, '0');
	
	for (int j = 0; j < pos; j++) {
		ans.operator[](j) = operator[](j);
	}
	int k = pos;
	int r = subpos;
	for (int i = 0; i < sublen; i++) {
		ans.operator[](k) = str.operator[](r);
		k++;
		r++;
		}
	int z = pos;
	for (int x = pos + sublen; x < inheritancesize; x++) {
		ans.operator[](x) = operator[](z);
		z++;
	}
	*this = ans;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len)
{
	MyString ans;
	int inheritancesize = getSize() - len;
	ans.resize(inheritancesize, '0');
	int j = 0;
	for (int i = 0; i < pos; i++) {
		ans.operator[](i) = operator[](i);
		j++;
	}
	for (int k = pos + len; k < getSize(); k++) {
		ans.operator[](j) = operator[](k);
		j++;
	}
	*this = ans;
	return *this;
}
size_t MyString::find(const MyString& str, size_t pos) const
{
	int test = 0;
	int inheritancesize = getSize() - str.getSize();
	char first = str.operator[](0);
	
	for (int i = 0; i < inheritancesize; i++) {
		test = 0;
		if (operator[](i) == first) {
			for (int k = 0; k < str.getSize(); k++) {
				if (operator[](i + k) == str.operator[](k)) {
					test = 1;
				}
			}
			if (test == 1) {
				return i;
			}
		}
	}
	return -1;
}
size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	int inheritancesize = getSize() - str.getSize();
	char first = str.operator[](0);

	for (int i = 0; i < inheritancesize; i++) {
		for (int k = 0; k < str.getSize(); k++) {
			if (operator[](i) == str.operator[](k)) {
				return i;
			}
		}
	}
	return -1;
}



