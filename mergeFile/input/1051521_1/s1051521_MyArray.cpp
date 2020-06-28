#include <iostream>
#include <vector>
#include "s1051521_MyArray.h"
using namespace std;

MyArray::MyArray() {
	capacity = 10;
	size = 0;
	sPtr = (char*)malloc(capacity + 1);
	*sPtr = '\0';
}

MyArray::MyArray(const MyArray &vec) {
	capacity = vec.capacity;
	size = vec.size;
	sPtr = (char*)malloc(capacity + 1);
	for (int i = 0; i < size; i++) {
		*(sPtr + i) = *(vec.sPtr + i);
	}
	*(sPtr + size) = '\0';
}

MyArray::~MyArray() {
	free(sPtr);
}

char* MyArray::begin() {
	return sPtr;
}

char* MyArray::end() {
	return sPtr + (capacity - 1);
}

size_t MyArray::getSize()const {
	return size;
}

void MyArray::resize(size_t n, char c) {
	if (n < size) {
		for (int i = n; i < size; i++)
			*(sPtr + i) = '\0';
	}
	else {
		reserve(n);
		for (int i = size; i < n; i++)
			*(sPtr + i) = c;
	}
	size = n;
}

size_t MyArray::getCapacity() const {
	return capacity;
}

void MyArray::reserve(size_t n) {
	if (n > capacity) {
		char *temp;
		temp = (char*)malloc(n + 1);
		for (int i = 0; i <= size; i++) {//'\0' need to be copy
			*(temp + i) = *(sPtr + i);
		}
		free(sPtr);
		sPtr = temp;
		capacity = n;
	}
}

void MyArray::shrink_to_fit() {
	if (size < capacity) {
		char *temp1;
		temp1 = (char*)malloc(size + 1);
		for (int i = 0; i <= size; i++) {
			*(temp1 + i) = *(sPtr + i);
		}
		free(sPtr);
		sPtr = temp1;
		capacity = size;
	}
}

void MyArray::clear() {
	*sPtr = '\0';
	size = 0;
}

bool MyArray::empty() const {
	if (size == 0)
		return true;
	else
		return false;
}

char& MyArray::front() {
	return *sPtr;
}

char& MyArray::back() {
	return *(sPtr + (size - 1));
}

void MyArray::push_back(char c) {
	*(sPtr + size) = c;
	*(sPtr + (size + 1)) = '\0';
	size++;
}

void MyArray::pop_back() {
	*(sPtr + (size - 1)) = '\0';
	size--;
}

char& MyArray::operator[] (size_t pos) {
	return *(sPtr + pos);
}

char MyArray::operator[] (size_t pos) const {
	return *(sPtr + pos);
}

bool MyArray::operator==(const MyArray &str) const {
	if (size != str.size)
		return false;
	for (int i = 0; i < size; i++) {
		if (*(sPtr + i) != *(str.sPtr + i))
			return false;
	}
	return true;
}

bool MyArray::operator!=(const MyArray &str) const {
	if (size != str.size)
		return true;
	for (int i = 0; i < size; i++) {
		if (*(sPtr + i) != *(str.sPtr + i))
			return true;
	}
	return false;
}

ostream &operator<<(ostream& output, const MyArray& vec) {
	vec.sPtr[vec.getSize()] = '\0';
	output << vec.sPtr;
	return output;
}