#include<iostream>
#include<vector>
#include <stdexcept> 
#include "s1061460_MyString.h"
//ref: https://defuse.ca/big-number-calculator.htm
//you may modified this example to test your program in various condition and input numbers

using namespace std;

int main(int argc, char* argv[]) {
	cout << "---------Test MyString---------" << endl;
	MyString<char> s2 = "HELLOWORLD", s3 = " DRIVER", s5 = "YA", s6 = "MYARRAY", s4(s6), s7 = "MYSTRING";
	cout << "s2 = HELLOWORLD, s3 =  DRIVER, s5 = YA, s6 = MYARRAY, s4(s6), s7 = MYSTRING" << endl;
	cout << "s2 = " << s2 << endl;
	cout << endl;
	cout << "---------Test substr---------" << endl;
	cout << "s3.substr(2, 2) = " << s3.substr(2, 2) << endl;
	cout << endl;
	cout << "---------Test append---------" << endl;
	cout << "s2.append(s3) = " << s2.append(s3) << endl;
	cout << endl;
	cout << "---------Test insert---------" << endl;
	cout << "s2.insert(2, s3) = " << s2.insert(2, s3) << endl;
	cout << "s3.insert(2, s2, 1, 2) = " << s3.insert(2, s2, 1, 2) << endl;
	cout << endl;
	cout << "---------Test erase---------" << endl;
	cout << "s6.erase(2, 4) = " << s6.erase(2, 4) << endl;
	cout << endl;
	cout << "---------Test find/find_first_of---------" << endl;
	try {
		cout << "s5 = " << s5 << endl;
		cout << "s4 = " << s4 << endl;
		cout << "s5.find(s4, 0) = " << s5.find(s4, 0) << endl;
		cout << "s7.find_first_of(s6, 0) = " << s7.find_first_of(s6, 0) << endl;
		cout << "s2 = " << s2 << endl;
		cout << "s3 = " << s3 << endl;
		cout << "s3.find_first_of(s2, 2) = " << s3.find_first_of(s2, 2) << endl;
		cout << "s4.find_first_of(s2, 8) = " << s4.find_first_of(s2, 8) << endl;
	}
	catch (out_of_range & e) {
		std::cerr << e.what() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
