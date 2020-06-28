#include<iostream>
#include <string>
using namespace std;
#include "s1083329_MyString.h"
#include <exception>


ostream& operator<<(ostream& output, const MyString& ans)
{
	if (ans.isEmpty() == true)output << " is empty" << endl;
	for (int i = 0; i < ans.getSize(); i++) {
		output << ans[i];
		output << ", ";
	}
	return output;
}

istream& operator>>(istream& input,  MyString& ans)
{
	string a;
	input >> a;
	int al = a.length();
	ans.resize(al, 0);
	for (int i = 0; i < al; i++)
	{
		ans[i] = a[i];
	}
	return input;
}

MyString :: MyString(int Size, char value)
	:MyArray(Size,value)
{

}

MyString::MyString() :MyArray(){

}

MyString::MyString(const MyString& str):MyArray(str){

}

MyString::MyString(const MyString& str, size_t pos, size_t len) {
	if (pos + len > str.getSize())resize(str.getSize() - pos, 0);
	else resize(len, 0);
	int i = 0;
	for (int j = pos; j < pos+len; j++)
	{
		this -> operator[](i) = str[j];
		i++;
		if (i == getSize())break;
	}
}

MyString::MyString(const char* s) {
	int i = 0;
	while (s[i] != '\0')i++;
	resize(i , 0);
	for (int j = 0; j < i; j++) {
		this -> operator[](j) = s[j];
	}
}

MyString::~MyString() {

}

MyString& MyString::append(const MyString& str) {
	int temsize = getSize();
	int j = 0;
	resize(getSize() + str.getSize()+1,0);
	this -> operator[](temsize) = ' ';
	for (int i = temsize + 1; i < getSize(); i++)
	{
			this -> operator[](i) = str[j];
			j++;
	}
	return *this;
}

MyString MyString::substr(size_t pos, size_t len ) const {
	MyString a;
	if (pos + len > getSize())a.resize(getSize() - pos, 0);
	else a.resize(len, 0);
	//a.resize(len, 0);
	int j = 0;
	for (int i = pos; i <pos + len+1; i++)
	{
			a[j] = this -> operator[](i);
			j++;
			if (j == a.getSize())break;
	}
	//cout <<"a = "<< a << endl;
	return a;
}

MyString& MyString::insert(size_t pos, const MyString& str) {
	MyString a;
	a.resize(getSize() + str.getSize(), 0);
	int i = 0;
		for (int j = 0; j < pos; j++) {
			a[i] = this -> operator[](j);
			i++;
		}
		for (int k = 0; k < str.getSize(); k++)
		{
			a[i] = str[k];
			i++;
		}
		for (int n = pos; n < getSize(); n++)
		{
			a[i] = this -> operator[](n);
			i++;
		}		
		*this = a;
		return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen) {
	MyString a;
	if (subpos + sublen > str.getSize()) {
		a.resize(getSize() + str.getSize() - subpos, 0);
		sublen = str.getSize() - subpos;
	}
	else a.resize(getSize() +sublen, 0);
	//cout << a.getSize()<<endl;
	int i = 0;
	for (int j = 0; j < pos; j++) {
		a[i] = this -> operator[](j);
		i++;
	}
	for (int k = subpos; k <subpos+ sublen; k++)
	{
		a[i] = str[k];
		i++;
	}
	for (int n = pos ; n <= getSize(); n++)
	{
		a[i] = this -> operator[](n);
		i++;
		if (i == a.getSize())break;
	}
	*this = a;
	return a;
}

MyString& MyString::erase(size_t pos, size_t len) {
	MyString a;
	if (pos + len > getSize())a.resize(pos, 0);
	else a.resize(getSize() - len, 0);
	int i = 0;
	for (int j = 0; j < pos; j++) {
		a[i] = this -> operator[](j);
		i++;
	}
	for (int j = pos + len; j < getSize(); j++)
	{
		if (i == a.getSize())break;
		a[i] = this -> operator[](j);
		i++;
	}
	*this = a;
	return a;
}

int MyString::find(const MyString& str, size_t pos ) const {
	int check = 0,tem=0;
	for (int i = pos; i < getSize(); i++) {
		if (this -> operator[](i) == str[0]) {
			for (int j = 0; j < str.getSize(); j++)
			{
				if (this -> operator[](i) == str[j]) { check = 1; i++; }
				else
				{
					tem = j;
					check = 0;
					break;
				}
			}
			if (check == 1)return i - str.getSize();
			else  	i = i - tem;
		}
	}return msize;
}

int MyString::find_first_of(const MyString& str, size_t pos ) const {
	int check = 0, tem = 0;
	for (int i = pos; i < getSize(); i++) {
			for (int j = 0; j < str.getSize(); j++)
			{
				if (this -> operator[](i) == str[j]) { return i; }
			}
	}return msize;
}