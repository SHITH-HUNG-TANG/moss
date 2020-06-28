#include<iostream>
#include"s1081543_MyString.h"
#include<string>


ostream& operator<<(ostream& output, const MyString& str)//ok
{
	for (int i = 0; i < str.getSize(); i++)
	{
		output << str[i];
	}
	return output;
}

istream& operator>>(istream& input,  MyString& str)
{
	string s;

	getline(input, s);

	str.resize(s.size(), '\0');

	while (str.getSize() > str.getCapacity())
	{
		str.reserve(str.getCapacity() * 2);
	}

	for (int i = 0; i < str.getSize(); i++)
	{
		str[i] = s[i];
	}
	
	return input;
}

MyString::MyString():MyArray()//ok
{
	
}

MyString::MyString(const MyString& str) //ok
{
	resize(str.getSize(),'\0');

	reserve(str.getSize());

	for (int i = 0; i < getSize(); i++)
	{
		this->operator[](i) = str[i];
	}
	
}


MyString::MyString(const MyString& str, size_t pos, size_t len )//ok
{
	if (len == 4294967295)
	{
		len = str.getSize() - pos;
	}
	resize(len, '\0');
	reserve(10);
	while (getSize() > getCapacity())
	{
		reserve(getCapacity() * 2);
	}

	for (int i = pos, j = 0; j < len; i++, j++)
	{
		this->operator[](j) = str[i];
	}
}


MyString::MyString(const char* s)//ok
{
	int size = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		size++;
	}

	resize(size, '\0');
	while (getSize() > getCapacity())
	{
		reserve(getCapacity() * 2);
	}

	for (int i = 0; i < size; i++)
	{
		this->operator[](i) = s[i];
	}
	
}


MyString::~MyString()//ok
{

}


MyString& MyString::append(const MyString& str)//ok
{
	/*int start = getSize();
	resize(getSize() + str.getSize(), '\0');
	while (getSize() > getCapacity())
	{
		reserve(getCapacity() * 2);
	}

	for (int i = start, j = 0; i < getSize(); i++, j++)
	{
		this->operator[](i) = str[j];
	}*/

	*this += str;

	return *this;
}


MyString MyString::substr(size_t pos, size_t len ) const//ok
{
	if (len == 4294967295)
	{
		len = getSize() - pos;
	}

	MyString temp(*this, pos, len);

	return temp;	
}


MyString& MyString::insert(size_t pos, const MyString& str)//ok
{
	MyString temp(*this, 0, pos);

	MyString temp2(*this, pos);

	MyString temp3;

	temp3.append(temp);
	temp3.append(str);
	temp3.append(temp2);

	*this = temp3;

	return *this;
}


MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)//ok
{
	MyString temp(*this, 0, pos);

	MyString temp2(*this, pos);

	MyString temp3(str, subpos, sublen);

	MyString temp4;

	temp4.append(temp);
	temp4.append(temp3);
	temp4.append(temp2);

	*this = temp4;

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len )
{
	MyString temp3;
	if (len == 4294967295)
	{
		MyString temp(*this, 0, pos);
		temp3.append(temp);
	}

	else
	{
		MyString temp(*this, 0, pos);

		MyString temp2(*this, pos + len);

		temp3.append(temp);

		temp3.append(temp2);
	}

	*this = temp3;

	return *this;
}


size_t MyString::find(const MyString& str, size_t pos) const
{

	for (int i = pos; i < getSize(); i++)
	{
		int check = 0;
		if (this->operator[](i) == str[0])
		{
			check++;
			for (int j = 1; j < str.getSize(); j++)
			{
				if (this->operator[](i + j) == str[j])
				{
					check++;
				}
				else
				{
					break;
				}
			}
		}
		if (check == str.getSize())
		{
			return i;
		}
	}

	return msize;
}


size_t MyString::find_first_of(const MyString& str, size_t pos ) const
{
	for (int i = pos; i < getSize(); i++)
	{
		for (int j = 0; j < str.getSize(); j++)
		{
			if (this->operator[](i) == str[j])
			{
				return i;
			}
		}
	}

	return msize;
}
