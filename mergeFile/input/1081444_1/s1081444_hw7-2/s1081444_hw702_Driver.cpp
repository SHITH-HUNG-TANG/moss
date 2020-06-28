#include"s1081444_MyArray.h"
#include"s1081444_MyString.h"

#include<iostream>
using namespace std;

int main()
{
	cout << "I'm s1081444." << endl << endl;
	cout << "--------------- Test constructor ---------------" << endl;
	char A[] = "Good morning!";
	MyString s1(A);
	cout << "A[] = " << A << endl;
	cout << "s1(A) = " << s1 << endl;
	cout << "  ans = " << "Good morning!" << endl;

	MyString s2(s1);
	cout << "s2(s1) = " << s2 << endl;
	cout << "   ans = " << "Good morning!" << endl;

	MyString s3(s1, 5, 7);
	cout << "s3(s1, 5, 7) = " << s3 << endl;
	cout << "         ans = " << "morning" << endl;

	MyString s4(s1, 5);
	cout << "s4(s1, 5) = " << s4 << endl;
	cout << "      ans = " << "morning!" << endl;
	cout << "--------------- Test append ---------------" << endl;
	char B[] = "Happy ";
	MyString s5(B);
	cout << "B[] = " << B << endl;
	cout << "s5(B) = " << s5 << endl;
	char C[] = "birthday!";
	MyString s6(C);
	cout << "C[] = " << C << endl;
	cout << "s6(C) = " << s6 << endl;
	cout << "s5.append(s6) = " << s5.append(s6) << endl;
	cout << "          ans = " << "Happy birthday!" << endl;
	cout << "--------------- Test insert ---------------" << endl;
	char D[] = "Happy Year!!!";
	MyString s7(D);
	cout << "D[] = " << D << endl;
	cout << "s7(D) = " << s7 << endl;
	char E[] = "new ";
	MyString s8(E);
	cout << "E[] = " << E << endl;
	cout << "s8(E) = " << s8 << endl;
	cout << "s7.insert(6, s8) = " << s7.insert(6, s8) << endl;
	cout << "             ans = " << "Happy new Year!!!" << endl;

	char F[] = "A brand NEW car";
	MyString s9(F);
	cout << "F[] = " << F << endl;
	cout << "s9(F) = " << s9 << endl;
	cout << "s7 = " << s7 << endl;
	cout << "s7.insert(6, s9, 8, 3) = " << s7.insert(6, s9, 8, 4) << endl;
	cout << "                   ans = " << "Happy NEW new Year!!!" << endl;
	cout << "--------------- Test substr ---------------" << endl;
	char G[] = "Nice to meet you.";
	MyString s10(G);
	cout << "G[] = " << G << endl;
	cout << "s10(G) = " << s10 << endl;
	cout << "s10.substr(8, 4) = " << s10.substr(8, 4) << endl;
	cout << "             ans = " << "meet" << endl;
	cout << "--------------- Test erase ---------------" << endl;
	char H[] = "Have a nice nice nice day.";
	MyString s11(H);
	cout << "H[] = " << H << endl;
	cout << "s11(H) = " << s11 << endl;
	cout << "s11.erase(7, 10) = " << s11.erase(7, 10) << endl;
	cout << "             ans = " << "Have a nice day." << endl;
	cout << "--------------- Test find ---------------" << endl;
	char I[] = "You can say that again.";
	MyString s12(I);
	cout << "I[] = " << I << endl;
	cout << "s12(I) = " << s12 << endl;
	cout << "s12.find(\"that\") = ";
	if (s12.find("that") == -1)
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << s12.find("that") << endl;
	}
	cout << "             ans = " << "12" << endl;

	cout << "s12.find(\"treat\") = ";
	if (s12.find("treat") == -1)
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << s12.find("treat") << endl;
	}
	cout << "              ans = " << "Not found" << endl;
	cout << "--------------- Test find_first_of ---------------" << endl;
	char J[] = "This is cotton candy.";
	MyString s13(J);
	cout << "J[] = " << J << endl;
	cout << "s13(J) = " << s13 << endl;
	cout << "s13.find_first_of(\"that\") = ";
	if (s13.find_first_of("free") == -1)
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << s13.find_first_of("free") << endl;
	}
	cout << "                      ans = " << "Not found" << endl;

	cout << "s13.find_first_of(\"candy\") = ";
	if (s13.find_first_of("candy") == -1)
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << s13.find_first_of("candy") << endl;
	}
	cout << "                       ans = " << "8" << endl;
	cout << "--------------- Test operator<< ---------------" << endl;
	MyString s14;
	cin >> s14;
	cout << s14 << endl;
	system("pause");
	return 0;
}