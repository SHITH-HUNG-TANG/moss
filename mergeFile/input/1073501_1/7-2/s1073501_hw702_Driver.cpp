#include"s1073501_MyString.h"
#include"s1073501_MyArray.h"
#include"s1073501_MyArray.cpp"
#include<iostream>
using namespace std;

int main() {
	MyString n1("aaaa");
	MyString n2("bbbbbbb");
	MyString n3("abcd");
	MyString n4("hapcc fo");
	
	cout<<"n1:"<< n1;
	n1.append(n2);
	cout << "n1:" << n1;
	cout << "n2:" << n2;
	cout << "n3:" << n3;
	n3.erase(0, 2);
	cout<<"n3:" << n3;
	cout<<"n4:" << n4; //n4("hapcc fo");
	n3 = n4.substr(3, 4);
	cout << "n3:" << n3;
	MyString n5 = "abcd", n6 = "the ";
	n5.insert(1, n6);
	cout << "n5:" <<n5;
	MyString n7 = "to be the question", n8 = "or not to be";
	cout << "n8:" << n8;
	cout << "n7:" << n7;
	n7.insert(6, n8, 3, 4);
	cout << "n7 insert n8:" << n7;
	/*MyString STR ("that is cool question");
	cout << STR.find("cool");*/
	//cout<<STR.find_first_of("cXXl");

}
