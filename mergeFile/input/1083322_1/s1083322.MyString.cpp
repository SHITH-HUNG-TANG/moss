#include<iostream>
#include"s1083322_MyString.h"
using namespace std;
template <class T>MyString<T>::MyString()
{}
template <class T>MyString<T>::MyString(const MyString<T> &copy) 
{
	this->setSize(copy.getSize());
	this->setCapacity(copy.getCapacity());
	for (int i = 0; i < this->getSize(); i++)
	{
		this->setData(i, copy[i]);
	}
}
template <class T>MyString<T>::MyString(const MyString &str, size_t pos, size_t len)
{
	this->setSize(len);
	if (len > this->getCapacity()) 
	{
		this->setCapacity(len); 
		this->reserve(this->getCapacity());
	}
	int index = 0;
	for (int i = pos; i < pos+len; i++)
	{
		this->setData(index, str[i]);
		index++;
	}
}
template <class T>MyString<T>::MyString(const char *s) 
{
	int i = 0;
	while (s[i] !='\0') 
	{
		this->setData(i, s[i]);
		i++;
	}
	this->setSize(i);
}
template <class T>MyString<T>::~MyString() 
{}

template <class T>MyString<T>& MyString<T>::append(const MyString &right) 
{
	if (this->getSize() + right.getSize() > this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		this->reserve(this->getCapacity());
	}
	int index = 0;
	for (int i = this->getSize(); i < this->getSize() + right.getSize(); i++)
	{
		this->setData(i, right[index]);
		index++;
	}
	this->setSize(this->getSize() + right.getSize());
	return *this;
}
template <class T>MyString<T> MyString<T>::substr(size_t pos, size_t len)const 
{
	MyString temp(*this,pos,len);
	return temp;
}
template <class T>MyString<T>& MyString<T>::insert(size_t pos, const MyString &right)
{
	MyString copy(*this);
	int index = 0;
	if (this->getSize() + right.getSize() > this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		this->reserve(this->getCapacity());
	}
	for (int i = pos; i < pos+right.getSize(); i++)
	{
		this->setData(i, right[index]);
		index++;
	}
	int position = pos;
	for (int i = pos + right.getSize(); i < this->getSize() + right.getSize(); i++)
	{
		this->setData(i, copy[position]);
		position++;
	}
	this->setSize(this->getSize() + right.getSize());
	return *this;
}
template <class T>MyString<T>& MyString<T>::insert(size_t pos, const MyString &right, size_t subpos, size_t sublen)
{
	MyString copy(*this);
	int index = subpos;
	if (this->getSize() + sublen > this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		this->reserve(this->getCapacity());
	}
	for (int i = pos; i < pos + sublen; i++)
	{
		this->setData(i, right[index]);
		index++;
	}
	int position = pos;
	for (int i = pos + sublen; i < this->getSize() + sublen; i++)
	{
		this->setData(i, copy[position]);
		position++;
	}
	this->setSize(this->getSize() + sublen);
	return *this;
}
template <class T>MyString<T>& MyString<T>::erase(size_t pos, size_t len) 
{
	if (len > this->getSize())
	{
		len = this->getSize();
	}
	for (int i = pos; i <= len; i++)
	{
		this->setData(i, '\0');
	}
	return *this;
}
template <class T>size_t MyString<T>::find(const MyString<T> &str, size_t pos) const 
{
	int findindex=0;
	bool same = 0;
	int index = 0;
	for (int i = pos; i < this->getSize(); i++)
	{
		if (this->getData(i) == str[0])
		{
			for (int j = i; index < str.getSize(); index++)
			{
				if (this->getData(j) != str[index])
				{
					same = 0;
					break;
				}
				j++;
				same = 1;
			}
			index = 0;
			if (same == 1)
			{
				findindex = i;
				break;
			}
		}
	}
	if (same == 1)
		return findindex;
	else
		return msize;
}
template <class T>size_t MyString<T>::find_first_of(const MyString &str, size_t pos) const 
{
	int findposit=this->getSize();
	for (int i = 0; i < str.getSize(); i++)
	{
		for (int j = pos; j < this->getSize(); j++) 
		{
			if (this->getData(j) == str[i])
			{
				if (j < findposit)
				{
					findposit=j;
				}
			}
		}
	}
	if (findposit < this->getSize())
		return findposit;
	else
		return msize;
}

template class MyString <int>;
template class MyString <char>;