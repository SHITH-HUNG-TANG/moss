#include"s1081444_MyString.h"

ostream& operator<<(ostream &output, const MyString &a)
{
	for (int i = 0; i < a.getSize(); ++i)
	{
		output << a[i];
	}
	return output;
}
istream& operator>>(istream &input, MyString &a)
{
	string s;
	getline(input, s);
	a.resize(s.size(), '\0');
	while (a.getSize() > a.getCapacity())
	{
		a.reserve(a.getCapacity() * 2);
	}
	for (int i = 0; i < a.getSize(); ++i)
	{
		a[i] = s[i];
	}
	return input;
}
MyString::MyString() :MyArray()
{

}
MyString::MyString(const MyString &str) : MyArray(str)
{

}
MyString::MyString(const MyString &str, size_t pos, size_t len)
{
	if (len == msize)
	{
		len = str.getSize() - pos;
	}
	resize(len,'\0');
	for (int i = 0, j = pos; i < getSize(); ++i, ++j)
	{
		this->operator[](i) = str[j];
	}
}
MyString::MyString(const char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
	{

	}
	resize(i, '\0');
	for (i = 0; s[i] != '\0'; ++i)
	{
		this->operator[](i) = s[i];
	}
}
MyString::~MyString()
{

}
static const size_t msize = -1;
MyString& MyString::append(const MyString &str)
{
	*this += str;
	return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
	if (len == msize)
	{
		len = getSize() - pos;
	}
	return MyString(*this, pos, len);
}
MyString& MyString::insert(size_t pos, const MyString &str)
{
	/*MyString temp1 = substr(0, pos);
	MyString temp2 = substr(pos, getSize());
	MyString result = temp1.append(str).append(temp2);
	return *this = result;*/
	resize(getSize() + str.getSize(), '\0');
	return *this = substr(0, pos).append(str).append(substr(pos, getSize()));
}
MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen )
{
	if (sublen==msize)
	{
		sublen = str.getSize() - subpos;
	}
	resize(getSize() + sublen, '\0');
	return *this= substr(0, pos).append(str.substr(subpos,sublen)).append(substr(pos, getSize()));
}
MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == msize)
	{
		len = getSize() - pos;
	}
	resize(getSize() - len, '\0');
	return *this = substr(0, pos).append(substr(pos + len, getSize()));
}
size_t MyString::find(const MyString &str, size_t pos) const
{
	bool found = false;
	int now = 0;
	for (int i = pos; i < getSize(); ++i)
	{
		if (this->operator[](i)==str[0])
		{
			now = i;
			for (int j = i,k=0; k < str.getSize(); ++j)
			{
				if (this->operator[](j) == str[k])
				{
					found = true;
				}
				else
				{
					found = false;
					break;
				}
				++k;
			}
			if (found)
			{
				break;
			}
		}
	}
	if (found)
	{
		return now;
	}
	else
	{
		return msize;
	}
}
size_t MyString::find_first_of(const MyString &str, size_t pos) const
{
	for (int i = pos; i < getSize(); ++i)
	{
		for (int j = 0; j < str.getSize(); ++j)
		{
			if (this->operator[](i) == str[j])
			{
				return i;
			}
		}
	}
	return msize;
}