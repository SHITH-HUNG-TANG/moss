#include"s1061637_MyString.h"
#include<iostream>
#include <string>
using namespace std;
MyString::MyString() :MyArray(10) {}
MyString::MyString(const MyString &str)
{
	delete[]data;
	this->data = new char[str.capacity];
	capacity = str.capacity;
	for (size_t i = 0; i < str.size; i++)
		data[i] = str.data[i];
	size = str.size;
}
MyString::MyString(const MyString &str, size_t pos, size_t len)
{
	if (len-1+pos > str.size|| len==-1)
		len = str.size-pos+1;
	delete[]data;
	data = new char[str.capacity];
	capacity = str.capacity;
	size = len;
	for (size_t i = 0, start = pos-1; i <len; i++, start++)
	{
		data[i] = str.data[start];	
	}
	
}
MyString::MyString(const char *s)
{
	int inputsize = 0;
	for (size_t i = 0; s[i] != '\0'; i++)
		++inputsize;
	capacity = inputsize;
	size = inputsize;
	data = new char[inputsize];
	copy(s, s + inputsize, data);
}
MyString&  MyString::append(const MyString &str)
{
	
	MyArray::reserve(str.size+ MyArray::size);
	copy(str.data , str.data+ str.size   , data+size);

	size = str.size + MyArray::size;
	return *this;

}
MyString& MyString::insert(size_t pos, const MyString &str)
{
	MyArray::reserve(str.size + MyArray::size);
	int tempsize = size - pos;
	char* temp = new char[tempsize];
	copy(data + pos, data + size, temp);
	copy(str.data, str.data + str.size,data + pos);
	copy(temp, temp + tempsize, data + pos+ str.size);
	size = str.size + size;
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString&str, size_t subpos, size_t sublen)
{//全部都是陣列大小
	
	if (subpos+ sublen > str.size+1|| sublen==-1)
		sublen = str.size-subpos+1;
	if (size < pos || subpos> str.size)
	{
		throw(std::out_of_range("索引值超出陣列") );
	}
	else
	{ 
		MyArray::reserve(sublen + MyArray::size);
		int tempsize = size - pos;
		char* temp = new char[tempsize];
		copy(data + pos, data + size, temp);//複製後面
		copy(str.data+subpos-1, str.data + subpos-1+sublen,data+pos);//複製右邊
		copy(temp, temp + tempsize, data + pos + sublen);
		size = sublen + size;
		return *this;
	}
}
MyString & MyString::erase(size_t pos, size_t len)//pos是實際位置
{
	if (len-1+ pos > size || len ==	 -1)
		len = size - pos+1;
	MyString right;
	right.MyArray::reserve(this->size -pos + 1 - len );
	copy(data+pos - 1 + len, data+this->size, right.data);
	right.size = this->size - pos + 1 - len;

	MyString left;
	left.MyArray::reserve(pos-1);
	copy(data , data +pos,left.data);
	left.size = pos - 1;
	this->size = 0;
	this->append(left).append(right);

	return *this;
}
	

MyString  MyString::substr(size_t pos, size_t len) const
{
	return MyString (*this,pos, len);
}

//template <class T>
 /*istream &operator>>(istream & in, MyString& str)
{
	 string temp;
	 in >> temp;
	 str.reserve(temp.size());
	 for (size_t i = 0; i < temp.size(); i++)
	 {
		 str.data[i] = temp[i];
	 }
	 size = temp.size;

}*/
	

 size_t MyString::find(const MyString &str, size_t pos = 0) const   //aboxoxcox
 {
	 for (size_t i = pos - 1; i < this->size; i++)
	 {
		 for (size_t j = 0; j < str.size; j++)
		 {
			 if (this->data[i + j] != str.data[j])
				 break;
			 else
			 {
				 if (j == str.size - 1)
					 return i + 1;
			 }
		 }
	 }
	 return  MyString::msize;
 }
 size_t MyString::find_first_of(const MyString &str, size_t pos = 0) const
 {
	 
	 for (size_t i = pos - 1; i < this->size; i++)
	 {
		 for (size_t j = 0; j < str.size; j++)
		 {

			 if (str[j] == this->data[i])
			 {
				 
				 return  i + 1;
			 }
		 }
	 }
	 return  MyString::msize;
 }