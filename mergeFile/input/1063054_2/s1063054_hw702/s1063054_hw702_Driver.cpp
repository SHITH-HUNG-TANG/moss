#include<iostream>
#include "s1063054_MyString.h"
void print(const MyString &a){
	cout<<a<<endl;
}


using namespace std;
int main(){
	cout<<"s1063054"<<endl;
	//print() is a function that prints the content of MyString's object
	//printInfo() is a function that shows the size and capacity of MyString's object


	



/*

	MyString a;
	a.shrink_to_fit();
	cout<<a<<endl;
	a.printInfo();
	a.reserve(7);
	cout<<a<<endl;
	a.printInfo();


	MyString c(a,2,9);
	cout<<"========="<<endl;
	cout<<c<<endl;
	cout<<"========="<<endl;
	c.printInfo();

	MyString d(" fo");
	d.printInfo();
	cout<<"========="<<endl;
	cout<<a.append(d)<<endl;
	cout<<"========="<<endl;
	a.printInfo();
	cout<<"========="<<endl;
	MyString t;
	t = a.substr(3,4);
	cout<<t<<endl;
	cout<<"========="<<endl;
	a.printInfo();
	cout<<"========="<<endl;
	cout<<"========="<<endl;

*/

	MyString A("to be");
	A.printInfo();
	MyString B("the ");
	A.insert(6,B);
	cout<<A<<endl;
	A.printInfo();

	MyString C("to be the question");
	C.printInfo();
	MyString D("or not to be ");
	C.insert(6,D);
	cout<<C<<endl;
	C.printInfo();
	cout<<"fklflf"<<endl;
	MyString E("to be the question");
	E.printInfo();
	MyString F("or not to be ");
	E.insert(6,F,3,4);
	cout<<E<<endl;
	E.printInfo();

/*

	MyString E("ABCDEFGHIJKLM");
	E.printInfo();
	E.erase(2,89);
	cout<<E<<endl;
	E.printInfo();
	MyString F("to be or not to be, that is cool question");
	E.printInfo();
	cout<<F.find("cXXL")<<endl;

	MyString G("to be or not to be, that is Xool question");
	G.printInfo();
	cout<<F.find_first_of("cXXL");

	MyString g;
	cin>>g;
	cout<<g<<endl;
	g.printInfo();
*/

	
	return 0;
}
