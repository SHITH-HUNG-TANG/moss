#ifndef PG2CVector_H
#define PG2CVector_H
#include <iostream>
#include <vector>
using namespace std;

class MyArray
{
	friend ostream &operator<<(ostream& output, const MyArray& vec);

public:

	MyArray();
	MyArray(const MyArray &vec);
	~MyArray();

	char* begin();
	char* end();

	size_t getSize() const;
	void resize(size_t n, char c = '\0');
	size_t getCapacity() const;
	void reserve(size_t n = 0);
	void shrink_to_fit();
	void clear();
	bool empty() const;
	char& front();
	char& back();
	void push_back(char c);
	void pop_back();
	char& operator[] (size_t pos);
	char operator[] (size_t pos) const;
	bool operator==(const MyArray &str) const;
	bool operator!=(const MyArray &str) const;

private:
	size_t size;
	size_t capacity;
	char *sPtr;
};

#endif // !MyArray