#include "s1081504_MyString.h"

MyString::MyString() : MyArray ()
{

}

MyString::MyString(const MyString& str) : MyArray(str)
{

}

MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	if (len != msize && str.getSize() - 1 >= pos)
	{
		resize(len);
		if (len > getCapacity())
		{
			while (getCapacity() < len)
				reserve(getCapacity() * 2);
		}
		for (int i = 0, j = pos; i < len; i++, j++)
		{
			this->operator[](i) = str[j];
		}
	}
	else
	{
		resize(str.getSize() - pos);
		if (getSize() > getCapacity())
		{
			while (getCapacity() < getSize())
				reserve(getCapacity() * 2);
		}
		for (int i = 0, j = pos; i < getSize(); i++, j++)
		{
			this->operator[](i) = str[j];
		}
	}
}

MyString::MyString(const char* s)
{
	int newSize(0), counter(0);
	while (s[counter] != '\0')
	{
		newSize++;
		counter++;
	}
	resize(newSize);
	if (newSize > getCapacity())
	{
		while (getCapacity() < newSize)
			reserve(getCapacity() * 2);
	}
	for (int i(0); i < newSize; i++)
	{
		this->operator[](i) = s[i];
	}
}

MyString::~MyString()
{

}

ostream& operator<<(ostream& out, const MyString& temp)
{
	for (int i(0); i < temp.getSize(); i++)
	{
		out << temp[i];
	}
	return out;
}

istream& operator>>(istream& in, MyString& temp)
{
	string s("");

	getline(in, s);

	temp.resize(s.size(), '\0');

	while (temp.getSize() > temp.getCapacity())
	{
		temp.reserve(temp.getCapacity() * 2);
	}

	for (int i = 0; i < temp.getSize(); i++)
	{
		temp[i] = s[i];
	}

	return in;
}



MyString& MyString::append(const MyString& str)
{
	*this += str;
	return *this;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	return MyString(*this, pos, len);
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	resize(getSize() + str.getSize());
	if (getSize() > getCapacity())
	{
		while (getCapacity() < getSize())
			reserve(getCapacity() * 2);
	}
	MyString temp(*this);
	for (int i = pos, j = pos + str.getSize(); i < pos + temp.getSize(); i++, j++)
	{
		this->operator[](j) = temp[i];
	}

	for (int i = pos, j = 0; j < str.getSize(); i++, j++)
	{
		this->operator[](i) = str[j];
	}

	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	MyString temp(str, subpos, sublen);
	resize(getSize() + temp.getSize());
	if (getSize() > getCapacity())
	{
		while (getCapacity() < getSize())
			reserve(getCapacity() * 2);
	}
	MyString temp2(*this);
	for (int i = pos, j = pos + temp.getSize(); i < pos + temp2.getSize(); i++, j++)
	{
		this->operator[](j) = temp2[i];
	}

	for (int i = pos, j = 0; j < temp.getSize(); i++, j++)
	{
		this->operator[](i) = temp[j];
	}

	return *this;
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len != msize && getSize() - 1 >= pos)
	{
		int tempSize(getSize());
		resize(getSize() - len);
		for (int i = pos; i < len; i++)
		{
			this->operator[](i) = '\0';
		}

		for (int i = pos + len, j = pos; i < tempSize; i++, j++)
		{
			this->operator[](j) = this->operator[](i);
		}

		return *this;
	}
	else
	{
		int tempSize(getSize());
		resize(pos);
		for (int i = pos; i < tempSize; i++)
		{
			this->operator[](i) = '\0';
		}

		return *this;
	}
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

size_t MyString::find_first_of(const MyString& str, size_t pos) const
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