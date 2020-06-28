#include "s1071222_MyString.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "Student ID:1071222" << endl << endl;

	MyString str1;
	str1.resize(3, 'A');
	str1.resize(6, 'B');
	str1.resize(9, 'C');
	str1.resize(12, 'D');

	cout << "------代刚MyString(const MyString< T >& str, size_t pos, size_t len = msize)------" << endl;
	cout << "str1: " << str1 << endl;
	MyString str2(str1, 2, 4);
	cout << "str2: " << str2 << endl;
	MyString str3(str1, 2, 8);
	cout << "str3: " << str3 << endl;
	MyString str4(str1, 2, 12);
	cout << "str4: " << str4 << endl;
	cout << endl;

	cout << "------代刚MyString(const char* s)------" << endl;
	MyString str5 = "test 1";
	cout << "str5: " << str5 << endl;
	MyString str6 = "test 2";
	cout << "str6: " << str6 << endl;
	MyString str7 = "test 3";
	cout << "str7: " << str7 << endl;
	cout << endl;

	cout << "------代刚MyString< T >& append(const MyString< T >& str)------" << endl;
	MyString str8;
	cout << "str8: " << str8.append(str5) << endl;
	cout << "str8: " << str8.append(str6) << endl;
	cout << "str8: " << str8.append(str7) << endl;
	cout << endl;

	cout << "------代刚MyString< T > substr(size_t pos, size_t len = msize) const------" << endl;
	MyString str9 = "Sweat is the lubricant of success";
	MyString str10, str11, str12, str13, str14, str15, str16;
	str10 = str9.substr(0, 5);
	cout << "str10: " << str10 << endl;
	str11 = str9.substr(0, 8);
	cout << "str11: " << str11 << endl;
	str12 = str9.substr(0, 12);
	cout << "str12: " << str12 << endl;
	str13 = str9.substr(0, 22);
	cout << "str13: " << str13 << endl;
	str14 = str9.substr(0, 25);
	cout << "str14: " << str14 << endl;
	str15 = str9.substr(0, 33);
	cout << "str15: " << str15 << endl;
	str16 = str9.substr(5, 30);
	cout << "str16: " << str16 << endl;
	cout << endl;


	cout << "------代刚MyString< T >& insert(size_t pos, const MyString& str)------" << endl;
	MyString str17 = "to be question";
	MyString str18 = "test 1 ";
	MyString str19 = "test 2 ";
	MyString str20 = "test 3 ";
	cout << "str18 insert str17:" << str17.insert(0, str18) << endl;
	cout << "str19 insert str17:" << str17.insert(10, str19) << endl;
	cout << "str20 insert str17:" << str17.insert(20, str20) << endl;
	cout << endl;

	cout << "------代刚MyString< T >& insert(size_t pos, const MyString< T >& str, size_t subpos, size_t sublen = msize)------" << endl;
	MyString str21 = "Giving is a reward in itself";
	MyString str22 = "test 1 2 3 ";
	cout << "str22 insert str21:" << str21.insert(0, str22, 0, 7) << endl;
	cout << "str22 insert str21:" << str21.insert(14, str22, 0, 9) << endl;
	cout << "str22 insert str21:" << str21.insert(38, str22, 0, 11) << endl;
	cout << endl;

	cout << "------代刚MyString< T >& erase(size_t pos, size_t len = msize)------" << endl;
	MyString str23 = "test 1 ";
	MyString str24 = "test 1 2 3 ";
	cout << "str23: " << str23 << endl;
	str23.erase(2,3);
	cout << "str23: " << str23 << endl;
	cout << "str24: " << str24 << endl;
	str24.erase(5, 10);
	cout << "str24: " << str24 << endl;
	cout << endl;

	cout << "------代刚int find(const MyString< T >& str, size_t pos = 0) const------" << endl;
	MyString str25 = "Albert Einstein: Logic will get you from A to B. Imagination will take you everywhere";
	MyString str26 = "Imagination";
	MyString str27 = "Imaginationz";
	cout << "position: " << str25.find(str26, 0) << endl;
	cout << "position: " << str25.find(str26, 40) << endl;
	cout << "position: " << str25.find(str27, 0) << endl;
	cout << endl;

	cout << "------代刚int find_first_of(const MyString< T >& str, size_t pos = 0) const------" << endl;
	MyString str28 = "A manˇs best friends are his ten fingers";
	MyString str29 = "abcd";
	MyString str30 = "xyz";
	cout << "position: " << str28.find_first_of(str29, 0) << endl;
	cout << "position: " << str28.find_first_of(str30, 0) << endl;
	cout << endl;

	cout << "------代刚friend istream &operator>>(istream&, const MyString< T >&);------" << endl;
	MyString str31;
	cin >> str31;
	cout << str31 << endl;
}