#pragma once
#ifndef idk
#include<vector>
#include<iostream>
#include"s1061637_MyArray.h"
using namespace std;
class BigNUM:public MyArray<long long int>
{
public:
	BigNUM();
	BigNUM(long long int);
	BigNUM(int, int);
	BigNUM(const BigNUM&);
	BigNUM operator+(const BigNUM&);
	BigNUM operator+(long long int);
	BigNUM operator-(const BigNUM&);
	BigNUM operator-(const long long int&);
	BigNUM operator*(const BigNUM& right);
	bool value(const BigNUM&);
	friend ostream& operator<<(ostream& ,const BigNUM&);
	//friend istream& operator>>(ostream&, const string&);
	//friend void operator>>(const BigNUM, istream&);
	friend BigNUM operator+(const int&, const BigNUM&);
	friend BigNUM operator*(const int&, const BigNUM&);
	friend BigNUM operator-(const int&, const BigNUM&);
	const BigNUM& operator=(const BigNUM&);
	BigNUM operator-();
public:
	void borrow(size_t);
	//bool dataisfull(size_t);
	void data_increase(int input=0);
	bool plus = 1;
	void carry(int);
	void shrink();
};

#endif // !1

