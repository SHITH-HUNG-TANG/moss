#include"s1081414_MyArray.h"
#include"s1081414_MyString.h"
#include<iostream>

using namespace std;

MyString::MyString() :MyArray<char>() {

}

MyString::~MyString() {

}


MyString::MyString(const MyString& str) :MyArray(str) {

}


MyString::MyString(const MyString& str, size_t pos, size_t len) {


}

MyString::MyString(const char* s) {

	int length = 0;
	length = strlen(s);
	int y = capacity;
	while (length > y)
		y = y * 2;
	size = length;
	reserve(y);
	for (int i = 0;i < length;i++) {
		(*this)[i] = s[i];
	}


}

MyString& MyString::append(const MyString& str) {

	int x = size;
	int y = capacity;
	size = size + str.size;
	while (size > y) {
		y = y * 2;
	}
	reserve(y);

	for (int i = 0;i < str.size;i++) {
		ptr[i + x] = str.ptr[i];
	}
	return *this;
};


MyString MyString::substr(size_t pos, size_t len) const {
	MyString A;
	A.size = len;
	int x = A.capacity;
	while (A.size > A.capacity) {
		A.capacity = A.capacity * 2;
	}
	A.ptr = new char[A.capacity];


	for (int i = 0;i < len;i++) {
		A.ptr[i] = ptr[pos + i];
	}
	return A;
}


MyString& MyString::insert(size_t pos, const MyString& str) {

	int originalsize = size;
	size = size + str.size;
	int y = capacity;
	while (size > y) {
		y = y * 2;
	}
	reserve(y);

	char* temp = new char[capacity];
	for (int i = 0;i < pos;i++) {
		temp[i] = ptr[i];
	}
	for (int i = 0;i < str.size;i++) {
		temp[i + pos] = str.ptr[i];
	}
	for (int i = 0;i < originalsize - pos;i++) {
		temp[i + pos + str.size] = ptr[pos + i];
	}
	delete[] ptr;
	ptr = temp;
	

	return *this;
}


MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen) {

	int x = sublen - subpos+1;
	int originalsize = size;
	size = size + x;
	int y = capacity;
	while (size > y) {
		y = y * 2;
	}
	reserve(y);
	
	char* temp = new char[capacity];
	for (int i = 0;i < pos;i++) {
		temp[i] = ptr[i];
	}
	for (int i = 0;i < x;i++) {
		temp[i+pos] = str.ptr[subpos + i];
	}
	for (int i = 0;i < originalsize-pos;i++) {
		temp[i+pos+x] = ptr[pos+i];
	}
	delete[]ptr;
	ptr = temp;

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len) {

	for (int i = pos;i < len;i++) {
		ptr[i] = NULL;
	}
	return *this;
}
size_t MyString::find(const MyString& str, size_t pos) const {

	int sum = 0;
	for (int i = pos;i < size-str.size+1;i++) {
		for (int j = 0;j < str.size;j++) {
			if (ptr[i + j] == str.ptr[j])
			{
				sum++;
				if (sum == str.size)
					return i;
			}
			else
			{
				sum = 0;
				break;
			}
		}
	}
	return msize;
}
size_t MyString::find_first_of(const MyString& str, size_t pos) const {

	for (int i = pos;i < size - str.size + 1;i++) {
		for (int j = 0;j < str.size;j++) {
			if (ptr[i + j] == str.ptr[j])
			{
				return i+j;
			}

		}
	}
	return msize;

}
