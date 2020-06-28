#include <iostream>
#include <stdexcept>
#include <string>
#include "s1060925_MyArray.h"

using namespace std;
template <typename T>
inline MyArray<T>::MyArray(int Capacity)
{
    capacity = Capacity;
    size = 0;
    data = new T[capacity];
}
template <typename T>
inline MyArray<T>::MyArray(int Size, T value)
{
    capacity = 10;
    size = Size;
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = value;
    }
}
template <typename T>
inline MyArray<T>::MyArray(const MyArray &right)
{
    size = right.size;
    capacity = right.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = right.data[i];
    }
}
template <typename T>
inline MyArray<T>::~MyArray()
{
    delete[] data;
}
template <typename T>
const MyArray<T> &MyArray<T>::operator=(const MyArray<T> &right)
{
    delete[] data;
    size = right.size;
    capacity = right.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = right.data[i];
    }
    return *this;
}
template <typename T>
inline bool MyArray<T>::operator==(const MyArray<T> &right) const
{
    MyArray left(*this);
    if (left.size != right.size)
    {
        return false;
    }
    else
    {
        int equal = 0;
        for (int i = 0; i < left.size; i++)
        {
            if (left.data[i] != right.data[i])
            {
                equal++;
                break;
            }
        }
        if (equal > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
template <typename T>
inline bool MyArray<T>::operator!=(const MyArray<T> &right) const
{
    return !(*this == right);
}
template <typename T>
inline MyArray<T> MyArray<T>::operator+(const MyArray<T> &right) const
{
    MyArray<T> left(*this);
    MyArray<T> result;
    result.size = left.getSize() + right.getSize();
    while (result.getCapacity() <= result.getSize())
    {
        result.reserve(result.getCapacity() * 2);
    }

    for (int i = 0; i < left.getSize(); i++)
    {
        result.data[i] = left.data[i];
    }

    for (int i = left.getSize(); i < result.getSize(); i++)
    {
        result.data[i] = right.data[i - left.getSize()];
    }
    return result;
}
template <typename T>
inline MyArray<T> &MyArray<T>::operator+=(const MyArray<T> &right)
{
    //size += right.getSize();
    while (getCapacity() <= getSize())
    {
        reserve(getCapacity() * 2);
    }
    for (int i = getSize(); i < getSize() + right.getSize(); i++)
    {
        data[i] = right.data[i - getSize()];
    }
    size += right.getSize();
    return *this;
}
template <typename T>
inline void MyArray<T>::resize(size_t n, T item)
{
    if (n > size)
    {

        for (int i = size; i < n; i++)
        {
            data[i] = item;
        }
        size = n;
    }
    else if (n < size)
    {
        for (int i = n; i < capacity; i++)
        {
            data[i] = '\0';
        }
        size = n;
    }
}
template <typename T>
inline void MyArray<T>::reserve(size_t n)
{
    if (n > capacity)
    {
        int *copy = new int[size];
        for (int i = 0; i < size; i++)
        {
            copy[i] = data[i];
        }
        delete[] data;
        data = new T[n];
        for (int i = 0; i < size; i++)
        {
            data[i] = copy[i];
        }
        delete[] copy;
        capacity = n;
    }
}
template <typename T>
inline int MyArray<T>::getSize() const
{
    return size;
}
template <typename T>
inline int MyArray<T>::getCapacity() const
{
    return capacity;
}
template <typename T>
inline void MyArray<T>::shrink_to_fit()
{
    capacity = size;
    MyArray<T> result(*this);
    delete[] data;
    size = result.getSize();
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = result.data[i];
    }
}
template <typename T>
inline void MyArray<T>::clear()
{
    for (int i = 0; i < capacity; i++)
    {
        data[i] = '\0';
    }
}
template <typename T>
inline bool MyArray<T>::isEmpty()
{
    MyArray left(*this);
    int check = 1;
    for (int i = 0; i < left.capacity; i++)
    {
        if (data[i] != '\0')
        {
            return false;
        }
    }
    return true;
}
template <typename T>
inline T MyArray<T>::at(int index) const
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("out_of_range");
    }
    return data[index];
}
template <typename T>
inline T &MyArray<T>::at(int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("out of range error");
    }
    return data[index];
}
template <typename T>
inline T &MyArray<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        cerr << "\nError: Index " << index << " out of range" << endl;
        exit(1);
    }
    return arr[index];
}
template <typename T>
inline T MyArray<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        cerr << "\nError: Index " << index << " out of range" << endl;
        exit(1);
    }
    return arr[index];
}