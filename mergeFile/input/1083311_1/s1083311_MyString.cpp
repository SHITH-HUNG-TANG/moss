#include "s1083311_MyString.h"

MyString::MyString()
	:MyArray(10)
{	

}

MyString::MyString(const MyString& copy)
	:MyArray(copy)
{
	
}

MyString::MyString(const MyString& str, size_t pos, size_t len) //要裁的 , 起點 , 長度
	:MyArray(10)
{	
	if (len == -1)
		len = str.getSize() - pos;
	this->resize(len , char());
	for (int i = pos; i < pos + len; i++)
		this->operator[](i - pos) = str[i]; //at(i - pos) = str.at(i);
		
}

MyString::MyString(const char* s)
	:MyArray(10)
{	
	this->resize(strlen(s), char());
	for (int i = 0; i < strlen(s); i++)
		this->operator[](i) = *(s + i);

}


MyString& MyString::append(const MyString& str)
{	
	this->operator+=(str);
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{	
	if (len == -1)
		len = this->getSize() - pos;
	MyString str;
	str.resize(len , char());
	for (int i = pos; i < pos + len; i++)
		str.operator[](i - pos) = this->operator[](i); //str.at(i - pos) = at(i);
	return str;

}

MyString& MyString::insert(size_t pos, const MyString& str)
{	
	this->resize(this->getSize() + str.getSize(), char()); 
	
	/*MyString temp;
	temp.resize(str.getSize(), char());
	temp = str.substr(subpos, sublen);*/

	//str7.resize(4, 'g');
	//str8.resize(5, 'T');
	//str8.insert(3, str7);
	//T T T g g g g T T
	for (int i = this->getSize() - 1; i >= pos + str.getSize(); i--)
		this->operator[](i) = this->operator[](i - str.getSize());

	for (int i = pos; i < pos + str.getSize(); i++)
		this->operator[](i) = str.operator[](i - pos);


	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{	
	if (sublen == -1)
		sublen = str.getSize() - subpos;
	this->resize(this->getSize() + sublen, char()); //size = 9
	//str7.resize(10, 'g');
	//str8.resize(5, 'T');
	//str8.insert(3, str7, 1, 4);
	//T T T g g g g T T
	MyString temp;
	temp.resize(sublen, char());
	temp = str.substr(subpos, sublen);
	for (int i = this->getSize() - 1; i >= pos + sublen ; i--)
		this->operator[](i) = this->operator[](i - sublen);
	
	for (int i = pos; i < pos + sublen; i++)
		this->operator[](i) = temp.operator[](i - pos);
	
	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{	
	if (len == -1)
		len = this->getSize() - pos;
	for (int i = pos; i < this->getSize() - len; i++) 
		this->operator[](i) = this->operator[](i + len);
	
	this->resize(this->getSize() - len, char());
	return *this;
	
}

size_t MyString::find(const MyString& str, size_t pos) const
{	
	bool find;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (this->operator[](i) == str[pos])
		{
			find = true;
			for (int j = pos, temp = i; j < str.getSize(); j++, temp++)
			{
				if (temp >= this->getSize())
					return msize;
				else if (this->operator[](temp) != str[j])
					find = false;
			}
			if (find)
				return i;
		}		
	}
	return msize;
	
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	
	bool find = false;
	for (int i = 0; i < this->getSize(); i++)
	{
		for (int j = pos; j < str.getSize(); j++)
		{
			if (this->operator[](i) == str.operator[](j)) 
			{	
				find = true;
				return i;
			}
		}
	}
	if (find == 0)
		return msize;
	
}

istream& operator>>(istream& input, MyString& right)
{
	string str;
	cin >> str;
	int length = str.length();
	char* ptr = new char[length + 1]; //including null
	str.copy(ptr, length, 0);
	ptr[length] = '\0';
	right = MyString(ptr);
	return input;
}

MyString::~MyString()
{
}


