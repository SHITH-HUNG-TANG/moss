#include<iostream>
using namespace std;

#include "s1083320_MyString.h"

template< class T >MyString<T>::MyString() : MyArray<T>()
{
	this->reserve(10);
}

template< class T >MyString<T>::~MyString(){
}

template< class T >MyString<T>::MyString(const MyString& copy) : MyArray(copy)
{

}

template< class T >MyString<T>::MyString(const MyString& copy, size_t pos, size_t msize)
{
	this->clear();
	for (int i = 0; i < msize; ++i)
	{
		this->push_back(copy.at(pos + i));
	}
}

template< class T >MyString<T>::MyString(const char *s)
{
	int i = 0;
	while (1) {
		if (s[i] == '\0') break;
		i++;
	}
	this->resize(i);
	for (int j = 0; j < this->getSize(); ++j) set(j, s[j]);
}

template< class T >MyString<T>& MyString<T>::append(const MyString& right)
{
	MyString a;
	for (int i = 0; i < this->getSize(); ++i)
	{
		a.push_back(this->at(i));
	}
	for (int j = 0; j < right.getSize(); ++j)
	{
		a.push_back(right.at(j));
	}
	this->resize(a.getSize());
	for (int k = 0; k < this->getSize(); ++k)
	{
		this->set(k, a.at(k));
	}
	return *this;
}

template< class T >MyString<T> MyString<T>::substr(size_t pos, size_t len) const {
	MyString ans;
	for (int i = 0; i < len; ++i) ans.push_back(this->at(i + pos));
	return ans;
}

template< class T >MyString<T>& MyString<T>::insert(size_t pos, const MyString &str) {
	MyArray ans;
	for (int i = 0; i <= pos; ++i) ans.push_back(this->at(i));
	for (int j = 0; j < str.getSize(); ++j) ans.push_back(str.at(j));
	for (int k = pos+1; k < this->getSize(); ++k) ans.push_back(this->at(k));
	this->clear();
	for (int a = 0; a < ans.getSize(); ++a) this->push_back(ans.at(a));
	return *this;
}

template< class T >MyString<T>&	MyString<T>::erase(size_t pos, size_t len) {
	MyArray ans;
	for (int i = 0; i <= pos; ++i) ans.push_back(this->at(i));
	for (int k = len; k < this->getSize(); ++k) ans.push_back(this->at(k));
	this->resize(ans.getSize());
	for (int a = 0; a < ans.getSize(); ++a) this->set(a, ans.at(a));
	return *this;
}

template< class T >MyString<T>& MyString<T>::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen )
{
	MyString ans(*this), copy(str.substr(subpos, sublen));
	ans.insert(pos, copy);
	this->clear();
	for (int a = 0; a < ans.getSize(); ++a) this->push_back(ans.at(a));
	return *this;
}

template< class T >size_t MyString<T>::find(const MyString &str, size_t pos) const
{
	for (int i = pos; i < str.getSize(); ++i)
	{
		for (int j = 0; j < this->getSize(); ++j)
		{
			if (this->at(j) != str.at(i+j)) break;
			else if (this->at(j) == str.at(i+j) && j == this->getSize()-1) return i;
		}
	}
	return msize;
}

template< class T >size_t MyString<T>::find_first_of(const MyString &str, size_t pos) const {
	for (int i = 0; i < this->getSize(); ++i)
	{
		for (int j = pos; j < str.getSize(); ++j)
		{
			if (this->at(i) == str.at(j)) return j;
		}
	}
	return msize;
}

template class MyString<char>;