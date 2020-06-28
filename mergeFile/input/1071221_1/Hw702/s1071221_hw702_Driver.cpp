#include <iostream>
#include <iomanip> 
#include <vector>
#include <string>
#include <stdexcept>
#include "s1071221_MyArray_hw702.h"
using namespace std;

int main()
{
	cout << "My ID is s1071221" << endl << endl;
	cout << "------------簡單輸出測試------------" << endl;
	MyString str1("to be question"), str2(" or not to be"), str3("good"), str4("idea"), str5;
	cout << "str1 = " << str1 << endl;
	cout << "to be question" << endl;
	cout << "str2 = " << str2 << endl;
	cout << " or not to be" << endl;
	cout << "str3 = " << str3 << endl;
	cout << "good" << endl;
	cout << "str4 = " << str4 << endl;
	cout << "idea" << endl;
	cout << "------------append()------------" << endl;
	cout << "str1.append(str2)" << endl;
	str1.append(str2);
	cout << "str1 = " << str1 << endl;
	cout << "answer:to be question or not to be" << endl;
	cout << endl;
	cout << "------------substr()------------" << endl;
	cout << "str5 = str1.substr(6, 8)" << endl;
	str5 = str1.substr(6, 8);
	cout << "str1 = " << str1 << endl;
	cout << "str5 = " << str5 << endl;
	cout << endl;
	cout << "------------insert()------------" << endl;
	cout << "str3.insert(6, str4)" << endl;
	str3.insert(4, str4);
	cout << "str3 = " << str3 << endl;
	MyString str6(" idea");
	cout << "str6 = " << str6 << endl;
	cout << "str3.insert(4, str6, 0, 5)" << endl;
	str3.insert(4, str6, 0, 5);
	cout << "str3 = " << str3 << endl;
	cout << endl;
	cout << "------------erase()------------" << endl;
	cout << "str3.erase(2, 3)" << endl;
	str3.erase(1, 2);
	cout << "str3 = " << str3 << endl;

	cout << endl;
	cout << "------------find() find_first_of()------------" << endl;
	MyString str7("It is always morning somewhere in the world");
	cout << "str7 = " << str7 << endl;
	MyString str8("in");
	cout << "str8 = " << str8 << endl;
	cout << "str7.find(str8, 0) = " << str7.find(str8, 0) << endl;//找到字串相同回傳第一個的size
	cout << "str7.find_first_of(str8, 0) = " << str7.find_first_of(str8, 0) << endl;
	cout << endl;
	cout << "------------輸入測試------------" << endl;
	MyString str9;
	cin >> str9;
	cout << "str9 = " << str9 << endl;
	cout << "str7.find(str9, 0) = " << str7.find(str9, 0) << endl;
	cout << "str7.find_first_of(str9, 0) = " << str7.find_first_of(str9, 0) << endl;

}
