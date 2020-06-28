#ifndef PG2MyString_H
#define PG2MyString_H
#include <iostream>
#include "s1060925_MyArray.h"
using namespace std;
class MyString : public MyArray<char>
{
public:
    MyString();
    MyString(const MyString &str);
    MyString(const MyString &str, size_t pos, size_t len = msize);
    MyString(const char *s);
    ~MyString();

    static const size_t msize = -1;
    MyString &append(const MyString &str);
    MyString substr(size_t pos, size_t len = msize) const;
    MyString &insert(size_t pos, const MyString &str);
    MyString &insert(size_t pos, const MyString &str, size_t subpos, size_t sublen = msize);
    MyString &erase(size_t pos, size_t len = msize);
    size_t find(const MyString &str, size_t pos = 0) const;
    size_t find_first_of(const MyString &str, size_t pos = 0) const;
};
MyString::MyString() : MyArray() {}
MyString::MyString(const MyString &str) : MyArray(str) {}
MyString::MyString(const MyString &str, size_t pos, size_t len)
{
    reserve(len + 1);
    for (int i = pos; i < pos + len; i++)
    {
        if (str[i] == '\0')
            break;
        if (size == capacity)
        {
            reserve(capacity * 2);
        }
        size++;
        data[size - 1] = str[i];
    }
}
MyString::MyString(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    //resize(i);
    for (int j = 0; j < i; j++)
    {
        if (size == capacity)
        {
            reserve(capacity * 2);
        }
        size++;
        data[size - 1] = s[j];
    }
}
MyString::~MyString() {}
MyString &MyString::append(const MyString &str)
{
    reserve(getSize() + str.getSize() + 1);
    for (int i = 0; i < str.getSize(); i++)
    {
        if (size == capacity)
        {
            reserve(capacity * 2);
        }
        size++;
        data[size - 1] = str[i];
    }
    return *this;
}
MyString MyString::substr(size_t pos, size_t len) const
{
    MyString store(*this, pos, len);
    return store;
}
MyString &MyString::insert(size_t pos, const MyString &str)
{
    MyString S(*this);
    MyString store(*this, pos, S.getSize() - pos);
    //cout << "st " << store << endl;
    for (int i = getSize(); i > pos; i--)
    {
        if ((size - 1) >= 0)
        {
            data[size - 1] = '\0';
            size--;
        }
    }
    for (int i = 0; i < str.getSize(); i++)
    {
        if (size == capacity)
            reserve(2 * capacity);
        size++;
        data[size - 1] = str[i];
    }
    for (int i = 0; i < store.getSize(); i++)
    {
        if (size == capacity)
            reserve(2 * capacity);
        size++;
        data[size - 1] = store[i];
    }
    return *this;
}
MyString &MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen)
{
    MyString store(str, subpos, sublen);
    insert(pos, store);
    return *this;
}
MyString &MyString::erase(size_t subpos, size_t sublen)
{
    MyString store(*this, subpos + sublen, getSize() - (subpos + sublen));
    for (int i = getSize(); i > subpos; i--)
    {
        if ((size - 1) >= 0)
        {
            data[size - 1] = '\0';
            size--;
        }
    }

    reserve(store.getSize() + 1);
    for (int i = 0; i < store.getSize(); i++)
    {
        if (size == capacity)
            reserve(2 * capacity);
        size++;
        data[size - 1] = store[i];
    }
    return *this;
}
size_t MyString::find(const MyString &str, size_t pos) const
{
    MyString store(*this);
    for (size_t i = pos; i < getSize(); i++)
    {
        int count = 0;
        if (str[0] == store[i])
        {
            for (size_t j = 0; j < str.getSize(); j++)
            {
                if (str[j] != store[i + j])
                    break;
                count++;
            }
            if (count == str.getSize())
                return i;
        }
    }
    return msize;
}
size_t MyString::find_first_of(const MyString &str, size_t pos) const
{
    MyString store(*this);
    for (size_t j = 0; j < getSize(); j++)
    {
        for (size_t i = pos; i < str.getSize(); i++)
        {
            if (store[j] == str[i])
            {
                return j;
            }
        }
    }
    return msize;
}
#endif