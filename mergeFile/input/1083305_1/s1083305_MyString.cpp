#include"MyString_hw702.h"
#include<string>
MyString::MyString()
	:MyArray()
{
}

MyString::MyString(const MyString& str)
	:MyArray(str)
{
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
	:MyArray(len,'\0')
{
	for (int i = pos; i < len + pos; i++) {
		at(i - pos) = str.at(i);
	}
}

MyString::MyString(const char* s)
{
	int p = 0;
	while (1) {
		if (s[p] == '\0')
			break;
		p++;
	 }
	this->resize(p, '\0');
	for (int i = 0; i < this->getSize(); i++) {
		at(i) = s[i];
	}
}

MyString::~MyString()
{
}

MyString& MyString::append(const MyString& str)
{
	MyString tmp = *this;
	int a = getSize() + str.getSize() + 1;
	resize(a, '\0');
	for (int i = 0; i < a; i++) {
		if (i < tmp.getSize())
			at(i) = tmp.at(i);
		else if (i == tmp.getSize())
			at(i) = ' ';
		else
			at(i) = str.at(i - tmp.getSize() - 1);
	}
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	int a = len;
	if (len + pos - 1 > getSize())
		a = getSize() - pos;
	MyString ans(*this,pos,a);
	return ans;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	MyString tmp(*this,pos,getSize() - pos);
	resize(str.getSize() + getSize(), '\0');
	for (int i = pos; i < pos + str.getSize() + tmp.getSize(); i++) {
		if (i - pos < str.getSize())
			at(i) = str.at(i - pos);
		else
			at(i) = tmp.at(i - pos - str.getSize());
	}
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString tmp = str.substr(subpos, sublen);
	insert(pos, tmp);
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len < getSize()) {
		MyString tmp2(*this, pos + len, getSize() - pos - len);
		resize(getSize() - len, '\0');
		for (int i = pos; i < getSize(); i++) {
			at(i) = tmp2.at(i - pos);
		}
	}
	else {
		resize(pos, '\0');
	}
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const
{
	string a, b;
	for (int i = 0; i < getSize(); i++) {
		a += at(i);
	}
	for (int i = pos; i < str.getSize(); i++) {
		b += str.at(i);
	}
	int ans = -1;
	for (int i = 0; i < a.length(); i++) {
		int j = 0;
		while (a[i + j] == b[j] && b[j] != '\0') {
			if (j == b.length() - 1)
				ans = i;
			j++;
		}
	}
	if (ans == -1) {
		return msize;
	}
	return ans;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	string a, b;
	for (int i = 0; i < getSize(); i++) {
		a += at(i);
	}
	for (int i = pos; i < str.getSize(); i++) {
		b += str.at(i);
	}
	int ans = -1;
	for (int i = 0; i < a.length(); i++) {
		int j = 0;
		for(int j = 0; j < b.length(); j++)
			if(a[i] == b[j])
				return i;
	}
	return msize;
}

ostream& operator<<(ostream& output, const MyString& str)
{
	for (int i = 0; i < str.getSize(); i++) {
		cout << str.at(i);
		//if (i != str.getSize())
		//	cout << ' ';
	}
	return output;
}
istream& operator>>(istream& input,  MyString& str)
{
	char* s = new char[100000];
	input >> s;
	int count = 0;
	while (s[count] != '\0')
		count++;
	str.resize(count, ' ');
	for (int i = 0; i < count; i++)
		str.at(i) = s[i];
	return input;
}