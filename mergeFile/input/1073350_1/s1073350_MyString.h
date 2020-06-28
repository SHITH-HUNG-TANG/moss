#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include<string>
#include<math.h>
using namespace std;

template< typename T >
class MyArray {	//modify this class into a template class
	template<typename T>
	friend ostream& operator<<(ostream&, const MyArray<T>&);
public:
	MyArray(int Capacity = 10);
	MyArray(int Size, T value);
	MyArray(T*, int);
	MyArray(const MyArray&);
	~MyArray();
	const MyArray& operator=(const MyArray&);
	bool operator==(const MyArray&) const;
	bool operator!=(const MyArray&) const;
	MyArray operator+(const MyArray&) const;	//new
	MyArray& operator+=(const MyArray&);	//new
	T& operator[](int);
	T operator[](int) const;
	T& at(int) /*throw(out_of_range)*/;		//new
	T at(int) const /*throw(out_of_range)*/; 	//new

	int getSize() const;
	int getCapacity() const;
	void resize(size_t size, T item);
	void reserve(size_t size);
	void shrink_to_fit();	//new
	void clear();			//new
	bool isEmpty();			//new

private:
	int size;
	int capacity;
	T* data;
};
#endif // !MyArray

template<typename T>
class MyString: public MyArray<T>
{
	template<typename T>
	friend ostream &operator<<(ostream& output, const MyString<T>& str);
	template<typename T>
	friend istream& operator>>(istream& input,MyString<T>& str);

public:
	MyString();
	// Constructs an empty string, with a length of zero characters. 
	// *default capacity = 10

	MyString(const MyString& str);
	// Constructs a copy of "str". (copy constructor)

	MyString(const MyString& str, size_t pos, size_t len = msize); // (substring constructor)
	// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
	// (or until the end of str, if either str is too short or if len is string::msize).

	MyString(const char* s);
	// Copies the array of character (C-string) pointed by s.
	// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
	// The sequence is copied as the new value for the string.

	~MyString();
	// Destroys the string object.

	static const size_t msize = -1;
	//Note: maximum size. You may use SIZE_MAX at <cstdint>, too.

	MyString& append(const MyString& str);
	// Appends a str on the tail of current MyString. 
	// *Return the reference of itself

	MyString substr(size_t pos, size_t len = msize) const;
	// The substring is the portion of the object that starts at character position pos and spans len characters 
	// (or until the end of the string, whichever comes first).
	// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

	MyString& insert(size_t pos, const MyString& str);
	// Inserts a copy of a str at "pos".
	// example: str = "to be question", str2 = "the "
	// str.insert(6,str2); 
	// = to be (the )question = to be the question
	// *Return the reference of itself

	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = msize);
	// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
	// begins at the character position subpos and spans sublen characters (or until the end of str).
	// example: str = "to be the question", str3 = "or not to be"
	// str.insert(6,str3,3,4); // to be (not )the question
	// *Return the reference of itself

	MyString& erase(size_t pos, size_t len = msize);
	// Erases the portion of the string value that begins at the character position pos and spans len characters 
	// (or until the end of the string, if either the content is too short or if len is string::msize.)
	// *Return the reference of itself

	size_t find(const MyString& str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first occurrence of the string str.
	// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.

	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	// Searches the portion of the string value that begins at the character position "pos" until the end of the string
	// for the first character that matches *any* of the characters of the string str.
	// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.

	//You may add several helper functions or operators here
	//...
}; // end class MyString

template<typename T>
MyArray< T >::MyArray(int Capacity)
	:capacity(Capacity), size(0)
{
	data = new T[capacity];
}
template<typename T>
MyArray<T>::MyArray(T* x, int Size)
	: capacity(10)
{
	while (Size > capacity)
		reserve(2 * capacity);
	data = new T[capacity];
	for (int i = 0;i < Size;i++)
	{
		data[i] = *x;
		x++;
	}
	size = Size;
}
template<typename T>
MyArray<T>::MyArray(int Size, T value)
	:capacity(10)
{
	while (Size > capacity)
		reserve(2 * capacity);
	data = new T[capacity];
	for (int i = 0;i < Size;i++)
		data[i] = value;
	size = Size;
}

template<typename T>
MyArray<T>::MyArray(const MyArray<T>& right)
{
	size = right.size;
	capacity = right.capacity;
	data = new T[capacity]{};
	for (int i = 0;i < size;i++)
		data[i] = right.data[i];
}

template<typename T>
MyArray<T>::~MyArray()
{
	delete[]data;
}

template<typename T>
int MyArray<T>::getSize() const
{
	return size;
}
template<typename T>
int MyArray<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
void MyArray<T>::resize(size_t Size, T item)
{
	while (Size > capacity)
		reserve(2 * capacity);
	if (Size > size)
		for (int i = size;i < Size;i++)
			data[i] = item;
	/*else if (Size < size)
	{
		T* temp = data;
		delete[]data;
		data = new T[Size];
		for (int i = 0;i < Size;i++)
			data[i] = temp[i];
	}*/
	size = Size;
}
template<typename T>
void MyArray<T>::reserve(size_t n)
{
	if (n > capacity)
	{
		T* tmp = new T[n]{};
		for (int i = 0;i < size;i++)
			tmp[i] = data[i];
		delete[]data;
		data = tmp;
		capacity = n;
	}
}
template<typename T>
T& MyArray<T>::operator[](int n)
{
	return data[n];
}
template<typename T>
T MyArray<T>::operator[](int n) const
{
	return data[n];
}

template<typename T>
const MyArray<T>& MyArray<T>::operator=(const MyArray<T>& right)
{
	size = right.size;
	capacity = right.capacity;
	delete[]data;
	data = new T[capacity]{};
	for (int i = 0;i < size;i++)
		data[i] = right.data[i];
	return *this;
}
template<typename T>
bool MyArray<T>::operator==(const MyArray<T>& right) const
{
	if (size != right.size)
		return false;
	for (int i = 0;i < size;i++)
		if (data[i] != right.data[i])
			return false;
	return true;
}
template<typename T>
bool MyArray<T>::operator!=(const MyArray<T>& right) const
{
	return !(*this == right);
}
template<typename T>
void MyArray<T>::shrink_to_fit()
{
	capacity = size;
}
template<typename T>
void MyArray<T>::clear()
{
	size = 0;
	capacity = 10;
	data = new T[capacity];
}
template<typename T>
bool MyArray<T>::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
template<typename T>
MyArray<T> MyArray<T>::operator+(const MyArray<T>& right) const
{
	MyArray<T> buffer(*this);
	MyArray<T> buffer1(*this);
	int buffersize = buffer.size + right.size;
	int buffersize1 = buffer.size;
	int j = 0;
	buffer.resize(buffersize, 0);
	for (int i = 0;i < buffer.size;i++)
		buffer[i] = buffer1[i];
	for (int i = buffersize1;j < right.size;i++)
	{
		buffer.data[i] = right.data[j];
		j++;
	}
	return buffer;

}
template<typename T>
MyArray<T>& MyArray<T>::operator+=(const MyArray<T>& right)
{
	MyArray<T> buffer(*this);	
	*this = buffer + right;
	return *this;
}
template<typename T>
T& MyArray<T>::at(int number)// throw(out_of_range)
{
	if (number<0 || number>size)
		throw out_of_range("MyArray<T>::at() is out of range\n");
	return data[number];
}
template<typename T>
T MyArray<T>::at(int number) const//const throw(out_of_range)
{
	if (number<0 || number>size)
		throw out_of_range("MyArray<T>::at() is out of range\n");
	return data[number];
}

template<class T >
ostream& operator<<(ostream& output, const MyArray<T>& hugeinteger)
{
	for (int i = 0;i < hugeinteger.size;i++)
		output << hugeinteger.data[i] << " ";
	return output;
}
template<typename T>
ostream& operator<<(ostream& output, const MyString<T>& str)
{
	for (int i = 0;i < str.getSize();i++)
		output << str[i];
	return output;
}
template<typename T>
istream& operator>>(istream& input,  MyString<T>& str)
{
	char a[1000];
	input.getline(a,1000);
	int j = 0;
	while (a[j] != '\0')
		j++;
	str.resize(j, 0);
	for (int i = 0;i < j;i++)
		str[i] = a[i];
	return input;
}
template<typename T>
MyString<T>::MyString()
	:MyArray<T>()
{
}
template<typename T>
MyString<T>::~MyString()
{
}
template<typename T>
MyString<T>::MyString(const MyString<T>& str)
	:MyArray<T>(str)
{
}
template<typename T>
MyString<T>::MyString(const MyString<T>& str, size_t pos, size_t len )
{
	MyString<T> buffer(*this);
	if (len == msize)
	{
		buffer.resize(str.getSize() - pos, 0);
		int j = 0;
		for (int i = pos;i < str.getSize();i++)
		{
			buffer[j] = str[i];
			j++;
		}
	}
	else
	{
		buffer.resize(len, 0);
		int j = 0;
		for (int i = pos;i < pos + len;i++)
		{
			buffer[j] = str[i];
			j++;
		}
	}
	MyArray<T>::operator=(buffer);
}
template<typename T>
MyString<T>::MyString(const char* s)
{
	MyString<T> buffer;
	int j = 0;
	for (j;s[j] != '\0';j++);
	buffer.resize(j, 0);
	for (int i = 0;i < j;i++)
		buffer[i] = s[i];
	MyArray<T>::operator=(buffer);
}
// Copies the array of character (C-string) pointed by s.
// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
// The sequence is copied as the new value for the string.x
template<typename T>
MyString<T>& MyString<T>::append(const MyString<T>& str)
{
	MyString<T> buffer(*this);
	int totalsize = buffer.getSize() + str.getSize();
	int buffersize = buffer.getSize();
	buffer.resize(totalsize, 0);
	int j = 0;
	for (int i = buffersize;i < totalsize;i++)
	{
		buffer[i] = str[j];
		j++;
	}
	*this=buffer;
	return *this;
}
// Appends a str on the tail of current MyString. 
// *Return the reference of itself
template<typename T>
MyString<T> MyString<T>::substr(size_t pos, size_t len) const
{
	MyString<T> buffer(*this);
	MyString<T> temp;
	if (pos + len - 1 >= buffer.getSize()||(len==msize))
	{
		temp.resize(buffer.getSize() - pos, 0);
		int j = 0;
		for (int i = pos;i < buffer.getSize();i++)
		{
			temp[j] = buffer[i];
			j++;
		}	
	}
	else
	{
		temp.resize(len, 0);
		int j = 0;
		for (int i = pos;i < pos + len;i++)
		{
			temp[j] = buffer[i];
			j++;
		}
	}
	return temp;
}
// The substring is the portion of the object that starts at character position pos and spans len characters 
// (or until the end of the string, whichever comes first).
// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
template<typename T>
MyString<T>& MyString<T>::insert(size_t pos, const MyString<T>& str)
{
	MyString<T> buffer(*this);
	if (pos >= buffer.getSize())
	{
		buffer.resize(pos + str.getSize() , ' ');
		int j = 0;
		for (int i = pos;i < pos + str.getSize();i++)
		{
			buffer[i] = str[j];
			j++;
		}
		*this = buffer;
		return *this;
	}
	else
	{
		MyString<T> temp;
		temp.resize(buffer.getSize() - pos, 0);
		int j = 0;
		for (int i = pos;i < buffer.getSize();i++)
		{
			temp[j] = buffer[i];
			j++;
		}
		buffer.resize(buffer.getSize() - (2 + pos), 0);
		buffer.append(str);
		buffer.append(temp);
		*this = buffer;
	}
	return *this;
}
// Inserts a copy of a str at "pos".
// example: str = "to be question", str2 = "the "
// str.insert(6,str2); 
// = to be (the )question = to be the question
// *Return the reference of itself
template<typename T>
MyString<T>& MyString<T>::insert(size_t pos, const MyString<T>& str, size_t subpos, size_t sublen)
{
	MyString<T> buffer(*this);
    if (pos >= buffer.getSize())
	{
		buffer.resize(pos + sublen, ' ');
		int j = subpos;
		for (int i = pos;i < pos +sublen;i++)
		{
			buffer[i] = str[j];
			j++;
		}
		*this = buffer;
		return *this;
	}
	else if (sublen == msize)
	{
		MyString<T> temp;
		temp.resize(buffer.getSize() - pos, 0);
		int j = 0;
		for (int i = pos;i < buffer.getSize();i++)
		{
			temp[j] = buffer[i];
			j++;
		}
		buffer.resize(pos + str.getSize()-1, 0);
		for (int i = pos, k = subpos; i < pos + str.getSize()-1;i++, k++)
			buffer[i] = str[k];
		buffer.append(temp);
		*this = buffer;
	}
	else
	{
		MyString<T> temp;
		temp.resize(buffer.getSize() - pos, 0);
		int j = 0;
		for (int i = pos;i < buffer.getSize();i++)
		{
			temp[j] = buffer[i];
			j++;
		}
		buffer.resize(pos + sublen, 0);
		for (int i = pos,k=subpos; i < pos + sublen;i++,k++)
			buffer[i] = str[k];
		buffer.append(temp);
		*this = buffer;
	}
	return *this;
}
// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
// begins at the character position subpos and spans sublen characters (or until the end of str).
// example: str = "to be the question", str3 = "or not to be"
// str.insert(6,str3,3,4); // to be (not )the question
// *Return the reference of itself
template<typename T>
MyString<T>& MyString<T>::erase(size_t pos, size_t len)
{
	MyString<T> buffer(*this);
	if (pos >= buffer.getSize())
		return *this;
	else if (pos + len - 1 >= buffer.getSize()||len==msize)
	{
		buffer.resize(buffer.getSize() - (buffer.getSize() - pos), 0);
		*this = buffer;
		return *this;
	}
	else
	{
		MyString<T> temp;
		temp.resize(buffer.getSize()-(pos+len), 0);
		int j = 0;
		for (int i = pos + len;i < buffer.getSize();i++)
		{
			temp[j] = buffer[i];
			j++;
		}
		buffer.resize(buffer.getSize() - (buffer.getSize() - pos), 0);
		buffer.append(temp);
		*this = buffer;
	}
	return *this;
}
// Erases the portion of the string value that begins at the character position pos and spans len characters 
// (or until the end of the string, if either the content is too short or if len is string::msize.)
// *Return the reference of itself
template<typename T>
size_t MyString<T>::find(const MyString<T>& str, size_t pos) const
{
	MyString<T> buffer(*this);
	size_t count=0;
	int judge1 = 1;
	for (int i = pos;i < buffer.getSize();i++)
	{
		bool judge = true;
		int j = 0;
		if (buffer[i] == str[j])
		{
			count = i;
			for (int k = i;k < i + str.getSize() && k < buffer.getSize();k++)
			{
				if (buffer[k] != str[j])
				{
					i = k;
					judge = false;
					break;
				}
				j++;
				if (j == str.getSize())
					break;
			}
		}
		if (judge&&j==str.getSize())
		{
			judge1 = 0;
			break;
		}
	}
	if (judge1 == 0)
		return count;
	else
		return msize;
}
// Searches the portion of the string value that begins at the character position "pos" until the end of the string
// for the first occurrence of the string str.
// Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.
template<typename T>
size_t MyString<T>::find_first_of(const MyString<T>& str, size_t pos ) const
{
	MyString<T> buffer(*this);
	int judge1 = 1;
	size_t count = 0;
	for (int i = pos;i < buffer.getSize();i++)
	{
		bool judge = false;
		count = i;
		for (int j = 0;j < str.getSize();j++)
		{
			if (buffer[i] == str[j])
			{
				judge = true;
				judge1 = 0;
				break;
			}
		}
		if (judge)
			break;
	}
	if (judge1 == 0)
		return count;
	else
		return msize;
}
// Searches the portion of the string value that begins at the character position "pos" until the end of the string
// for the first character that matches *any* of the characters of the string str.
// Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
