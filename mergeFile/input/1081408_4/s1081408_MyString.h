#ifndef s1081408_MyString_H
#define s1081408_MyString_H
#include <iostream>
#include<cstdint>
#include<string>
#include"s1081408_MyArray.h"
using namespace std;

class MyString : public MyArray<char>{
	//friend ostream &operator<<(ostream& output, const MyString& str);
public:
	MyString();
	MyString(const MyString &str);
	MyString(const MyString &str, size_t pos, size_t len = msize); // (substring constructor)
	MyString(const char *s);
	~MyString();

	static const size_t msize = -1;
	MyString& append(const MyString &str);
	MyString substr(size_t pos, size_t len = msize) const;
	MyString& insert(size_t pos, const MyString &str);
    MyString& insert(size_t pos, const MyString &str, size_t subpos, size_t sublen = msize);
	MyString& erase(size_t pos, size_t len = msize);
	int find(const MyString &str, size_t pos = 0) const;
	int find_first_of(const MyString &str, size_t pos = 0) const;
	void setdata(string &);
}; 

#endif

ostream &operator<<(ostream& output, const MyString& str) 
{
	for (int i = 0; i < str.getSize(); i++) {
		output << str.at(i);
	}
	return output;
}

istream &operator>>(istream& input, MyString& str)
{
	string str1;
	getline(input,str1);
	str.resize(str1.length(), NULL);
	str.setdata(str1);
	return input;
}

MyString::MyString()
	:MyArray::MyArray()
{}


MyString::MyString(const MyString& str) 
	:MyArray::MyArray(str)
{}

MyString::MyString(const MyString &str, size_t pos, size_t len) {
	if (len == -1)resize(str.size - pos,NULL);
	else resize(len,NULL);
	for (int i = 0, j = pos; i < size; i++, j++)data[i] = str.data[j];
}

MyString::MyString(const char* s) {
	int charsize=0;
	for (int i = 0;; i++) {
		if (s[i] != '\0')charsize++;
		else if (s[i] == '\0')break;
	}
	resize(charsize, NULL);
	for (int i = 0; i < size; i++)data[i] = s[i];
}

MyString::~MyString() {}

MyString& MyString::append(const MyString &str) {
	resize(size + str.size,'\0');
	for (int i = size - str.size,j=0; i < size; i++,j++)data[i] = str.data[j];
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const {
	MyString t;
	if (len == -1) t.resize (size - pos,NULL);
	else t.resize(len,NULL);
	for (int i = 0, j = pos; j < size; i++, j++)t.data[i] = data[j];
	return t;
}

MyString& MyString::insert(size_t pos, const MyString &str) {
	int a = size;
	resize(size + str.size, NULL);
	char* buf = new char[a-pos]();
	for (int i = 0, j = pos; i < a; i++,j++)buf[i] = data[j];
	for (int i = pos,j=0; i < pos + str.size; i++,j++)data[i] = str.data[j];
	for (int j = 0, i = pos + str.size; i < size; i++, j++)data[i] = buf[j];
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen) {
	int a = size;
	resize(size + sublen, NULL);
	char* buf = new char[a - pos]();
	char* subbuf = new char[sublen]();
	for (int i = 0, j = pos; i < a; i++, j++)buf[i] = data[j];
	for (int i = subpos, j = 0, length = 0; length<sublen; i++, j++,length++)subbuf[j] = str.data[i];
	for (int i = pos, j = 0; i < pos + sublen; i++, j++)data[i] = subbuf[j];
	for (int j = 0, i = pos + sublen; i < size; i++, j++)data[i] = buf[j];
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len) {
	int a = size;
	resize(size - len, NULL);
	char* buf = new char[a-len-pos]();
	for (int i = 0, j = pos+len; i < a; i++, j++)buf[i] = data[j];
	for (int i = pos, j = 0; i < size; i++, j++)data[i] = buf[j];
	return *this;
}

int MyString::find(const MyString &str, size_t pos) const {
	for (int j = 0; j < size - str.size; j++) {
		int mark = 0;
		for (int i = 0; i < str.size; i++) {
			if (data[j + i] == str.data[i]) {
				mark++;
				if (mark == str.size - 1) { return j; }
			}
			else break;
		}
		if (j == size - str.size - 1 && mark < str.size - 1) 
		    return msize;
	}
}

int MyString::find_first_of(const MyString &str, size_t pos) const {
	bool *found = new bool[str.size]();
	int* position = new int[str.size]();
	for (int i = 0; i < str.size; i++) {
		for (int j = 0; j < size; j++) {
			if (str.data[i]==data[j]) {
				position[i]=j;
				found[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < str.size; i++) {
		if (i < str.size - 1 && found[i]==false)continue;
		else if (i < str.size -1 &&  found[i]==true)break;
		else if (i == str.size - 1 && found[i]==false)return msize;
	}//全部都沒有
	for (int i = 0; i < str.size; i++) {
		if (i < str.size - 1 && found == false)continue;
		else if (i < str.size - 1 && found[i] == true)break;
		else if (i == str.size - 1 && found[i] == true)return position[str.size-1];
	}
	int min;
	for (int i = 0; i < str.size; i++) {
		if (found[i] == true) {
			min = position[i];
			break;
		}
	}
	for (int x = 0; x < str.size - 1;x++) {
		int y = x + 1;
		if (min > position[y] && found[y]==true)
			min = position[y];
	}
	return min;
}

void MyString::setdata(string & a) {
	for (int i = 0; i < a.length(); i++)data[i] = a[i];
}

