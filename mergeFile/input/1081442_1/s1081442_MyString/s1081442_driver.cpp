#include "s1081442_MyString.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main()
{
	cout << "---------------------------------MyArray-------------------------------------" << endl;
	cout << "Case 1 :MyArray (int capacity = 10)" << endl;
	MyArray<int>u;
	cout << "1 : Capacity : " << u.getCapacity() << "  " << "Size : " << u.getSize() << endl;
	cout << endl;
	cout << "Case 2 :MyArray(int Size, T value) & shrink_to_fit()" << endl;
	MyArray<char>t(5, 'a');
	MyArray<char>n0(10, 'b');
	MyArray<char>n4(15, 'c');
	MyArray<char>j3(15, 'd');
	MyArray<char>temp();
	cout << "1 :" << endl << "Capacity : " << t.getCapacity() << "  " << "Size : " << t.getSize() << endl;
	cout << t << endl;
	cout << "2 :" << endl << "Capacity : " << n0.getCapacity() << "  " << "Size : " << n0.getSize() << endl;
	cout << n0 << endl;
	cout << "3 :" << endl << "Capacity : " << n4.getCapacity() << "  " << "Size : " << n4.getSize() << endl;
	cout << n4 << endl;
	cout << "4 :" << endl << "Capacity : " << j3.getCapacity() << "  " << "Size : " << j3.getSize() << endl;
	cout << j3 << endl;
	cout << endl;
	cout << "Case 3 : Operator<<" << endl;
	cout << "1 =  " << t << endl;
	cout << "2 =  " << n0 << endl;
	cout << "3 = " << n4 << endl;
	cout << endl;
	cout << "Case 4 : Operator=" << endl;
	t = n0;
	cout << "1 = 2 " << endl << "1 = " << t << endl;
	n0 = n4;
	cout << "2 = 3 " << endl << "2 = " << n0 << endl;
	n4 = j3;
	cout << "3 = 4" << endl << "3 = " << n4 << endl;
	cout << endl;
	cout << "Case 5 : operator+ & shrink_to_fit()" << endl;

	cout << "1 :" << endl << "Capacity : " << t.getCapacity() + n0.getCapacity() << "  " << "Size : " << t.getSize() + n0.getSize() << endl;
	cout << "1 + 2 = " << endl << t + n0 << endl;
	cout << "2 :" << endl << "Capacity : " << n0.getCapacity() + n4.getCapacity() << "  " << "Size : " << n0.getSize() + n4.getSize() << endl;
	cout << "2 + 3 =" << endl << n0 + n4 << endl;
	cout << "3 :" << endl << "Capacity : " << t.getCapacity() + n4.getCapacity() << "  " << "Size : " << t.getSize() + n4.getSize() << endl;
	cout << "1 + 3 =" << endl << t + n4 << endl;
	cout << endl;
	cout << "Case 6 : operator+= & shrink_to_fit()" << endl;
	t += n0;
	cout << "1 :" << endl << "Capacity : " << t.getCapacity() << "  " << "Size : " << t.getSize() << endl;
	cout << "1 += 2 " << endl << t << endl;
	n0 += n4;
	cout << "2 :" << endl << "Capacity : " << n0.getCapacity() << "  " << "Size : " << n0.getSize() << endl;
	cout << "2 += 3" << endl << n0 << endl;
	n4 += t;
	cout << "3 :" << endl << "Capacity : " << n4.getCapacity() << "  " << "Size : " << n4.getSize() << endl;
	cout << " 3 += 1" << endl << n4 << endl;
	cout << endl;
	cout << "Case 7 :at() & Exception handling" << endl;
	cout << "1 :" << endl << "Capacity : " << t.getCapacity() << "  " << "Size : " << t.getSize() << endl;
	cout << t << endl;
	try
	{
		t.at(500) = { 2 };
	}
	catch (const outofrange& no)
	{
		cerr << "Out of Range error :" << no.what() << endl;
	}
	cout << "2 :" << endl << "Capacity : " << n0.getCapacity() << "  " << "Size : " << n0.getSize() << endl;
	cout << n0 << endl;
	try
	{
		n0.at(100) = { 55 };
	}
	catch (const outofrange& no)
	{
		cerr << "Out of Range error :" << no.what() << endl;
	}
	cout << "3 :" << endl << "Capacity : " << n4.getCapacity() << "  " << "Size : " << n4.getSize() << endl;
	cout << n4 << endl;
	try
	{
		n4.at(105) = { 5 };
	}
	catch (const outofrange& no)
	{
		cerr << "Out of Range error :" << no.what() << endl;
	}

	cout << endl;
	cout << "Case 8 : clear() & isEmpty()" << endl;
	t.clear();
	if (t.isEmpty())
		cout << "1 : " << endl << "Capacity = " << t.getCapacity() << endl << "Size = " << t.getSize() << endl;
	n0.clear();
	if (n0.isEmpty())
		cout << "2 : " << endl << "Capacity = " << n0.getCapacity() << endl << "Size = " << n0.getSize() << endl;
	n4.clear();
	if (n4.isEmpty())
		cout << "3 : " << endl << "Capacity = " << n4.getCapacity() << endl << "Size = " << n4.getSize() << endl;
	cout << endl;
	cout << "-------------------------------------------MyString-----------------------------------------------" << endl;
	const char* s = "abcdefghijk";
	const char* p = "1234567890";
	const char* q = "abcdef1234";
	cout << "S =" << s << endl;
	cout << "P = " << p << endl;
	cout << "Q = " << q << endl;
	cout << "----------------------------------------Case 1 : MyString()---------------------------------------" << endl;
	MyString g;
	cout <<"Capacity :"<< g.getCapacity()<<endl;
	cout << "Size :" << g.getSize() << endl;
	cout << "-----------------------------Case 2 : MyString(const MyString& str)-------------------------------" << endl;

	MyString s1(s);
	MyString p1(p);
	MyString q1(q);
	
	cout <<"MyString s1(S) = "<< s1<<endl;
	cout << "size = " << s1.getSize() << endl;
	cout << "capacity = " << s1.getCapacity() << endl<<endl;
	cout << "MyString p1(P) = " << p1 << endl;
	cout << "size = " << p1.getSize() << endl;
	cout << "capacity = " << p1.getCapacity() << endl<<endl;
	cout << "MyString q1(Q) = " << q1 << endl;
	cout << "size = " << q1.getSize() << endl;
	cout << "capacity = " << q1.getCapacity() << endl<<endl;
	cout << "-----------------Case 3 : MyString(const MyString& str, size_t pos, size_t len)------------------- "<< endl;
	MyString s2(s, 1, 2);
	MyString p2(p, 5, 3);
	MyString q2(q, 5);

	cout << "MyString s2(s, 1, 2) = " << s2<<endl;
	cout << "size = " << s2.getSize() << endl;
	cout << "capacity = " << s2.getCapacity() << endl<<endl;
	cout << "MyString p2(p, 5, 3) = " << p2<<endl;
	cout << "size = " << p2.getSize() << endl;
	cout << "capacity = " << p2.getCapacity() << endl<<endl;
	cout << "MyString q2(q, 5) = " << q2 << endl;
	cout << "size = " << q2.getSize() << endl;
	cout << "capacity = " << q2.getCapacity() << endl<<endl;
	cout << "-------------------------------Case 4 : MyString(const char* s)---------------------------------- " << endl;
	MyString s3("012456");
	MyString p3("abc");
	MyString q3("defgh12345678");
	cout << "MyString s3(\"012456\") = " << s3 << endl;
	cout << "size = " << s3.getSize() << endl;
	cout << "capacity = " << s3.getCapacity() << endl << endl;
	cout << "MyString p3(\"abc\") = " << p3 << endl;
	cout << "size = " << p3.getSize() << endl;
	cout << "capacity = " << p3.getCapacity() << endl << endl;
	cout << "MyString q3(\"defgh12345678\") = " << q3 << endl;
	cout << "size = " << q3.getSize() << endl;
	cout << "capacity = " << q3.getCapacity() << endl << endl;
	cout << "-----------------------------Case 5 : append(const MyString& str)------------------------------- " << endl;
	MyString s4(s);
	MyString p4(p);
	MyString q4(q);
	cout <<"s4 = " <<s4 << endl;
	cout << "s4.append(\"abc\") = " << s4.append("abc")<<endl;
	cout << "size = " << s4.getSize() << endl;
	cout << "capacity = " << s4.getCapacity() << endl << endl;
	cout << "p4 = " << p4 << endl;
	cout << "p4.append(\"abcdefg\") = " << p4.append("abcdefg") << endl;
	cout << "size = " << p4.getSize() << endl;
	cout << "capacity = " << p4.getCapacity() << endl << endl;
	cout << "q4 = " << q4 << endl;
	cout << "q4.append(\"abc12345\") = " << q4.append("abc12345") << endl;
	cout << "size = " << q4.getSize() << endl;
	cout << "capacity = " << q4.getCapacity() << endl << endl;
	cout << "-------------------------Case 6 : substr(size_t pos, size_t len) const--------------------------- " << endl;
	MyString s5(s);
	MyString p5(p);
	MyString q5(q);
	MyString s6=s5.substr(5,4);
	MyString p6= p5.substr(3);
	MyString q6=q5.substr(2, 7);
	cout << "s5 = " << s5 << endl;
	cout << "s6=s5.substr(5,4) = " << s6 << endl;
	cout << "size = " << s6.getSize() << endl;
	cout << "capacity = " << s6.getCapacity() << endl << endl;
	cout << "p5 = " <<p5 << endl;
	cout << "p6= p5.substr(3) = " << p6 << endl;
	cout << "size = " << p6.getSize() << endl;
	cout << "capacity = " << p6.getCapacity() << endl << endl;
	cout << "q5 = " << q5 << endl;
	cout << "q6=q5.substr(2, 7)  = " << q6 << endl;
	cout << "size = " << q6.getSize() << endl;
	cout << "capacity = " << q6.getCapacity() << endl << endl;
	
	cout << "----------------------Case 7 : insert(size_t pos, const MyString& str)-------------------------- " << endl;
	MyString s7(s);
	MyString p7(p);
	MyString q7(q);
	cout << "s7 = " << s7 << endl;
	cout << "s7.insert(3,\"abcdef\") = " << s7.insert(3, "abcdef") << endl;
	cout << "size = " << s7.getSize() << endl;
	cout << "capacity = " << s7.getCapacity() << endl << endl;	
	cout << "p7 = " << p7 << endl;
	cout << "p7.insert(10,\"huang\") = " << q7.insert(10, "huang") << endl;
	cout << "size = " << p7.getSize() << endl;
	cout << "capacity = " << p7.getCapacity() << endl << endl;
	cout << "q7 = " << q7 << endl;
	cout << "q7.insert(7,\"ooao\") = " << q7.insert(7, "ooao") << endl;
	cout << "size = " << q7.getSize() << endl;
	cout << "capacity = " << q7.getCapacity() << endl << endl;

	cout << "---------Case 8 : insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)--------- " << endl;

	MyString s8(s);
	MyString p8(p);
	MyString q8(q);
	cout << "s8 = " << s8 << endl;
	cout << "s8.insert(3,\"abcdef\",2,3) = " << s8.insert(3, "abcdef",2,3) << endl;
	cout << "size = " << s8.getSize() << endl;
	cout << "capacity = " << s8.getCapacity() << endl << endl;
	cout << "p8 = " << p8 << endl;
	cout << "p8.insert(5,\"ab0cdef0\",2) = " << p8.insert(5, "ab0cdef0",2) << endl;
	cout << "size = " << p8.getSize() << endl;
	cout << "capacity = " << p8.getCapacity() << endl << endl;
	cout << "q8 = " << q8 << endl;
	cout << "q8.insert(0,\"12345000\",4,1) = " << q8.insert(0, "12345000",4,1) << endl;
	cout << "size = " <<q8.getSize() << endl;
	cout << "capacity = " << q8.getCapacity() << endl << endl;

	cout << "--------------------------Case 9 : erase(size_t pos, size_t len)------------------------------ " << endl;
	MyString s9(s);
	MyString p9(p);
	MyString q9(q);
	cout << "s9 = " << s9 << endl;
	cout << "s9.erase(5,4) = " << s9.erase(5,4) << endl;
	cout << "size = " << s9.getSize() << endl;
	cout << "capacity = " << s9.getCapacity() << endl << endl;
	cout << "p9 = " << p9 << endl;
	cout << "p9.erase(5) = " << p9.erase(5) << endl;
	cout << "size = " << p9.getSize() << endl;
	cout << "capacity = " << p9.getCapacity() << endl << endl;
	cout << "q9 = " << q9 << endl;
	cout << "q9.erase(0,4) = " << q9.erase(0, 4) << endl;
	cout << "size = " << q9.getSize() << endl;
	cout << "capacity = " << q9.getCapacity() << endl << endl;
	cout << "------------------Case 10 : find(const MyString& str, size_t pos) const---------------------- " << endl;
	MyString s10(s);
	MyString p10(p);
	MyString q10(q);
	cout << "s10 = " << s10 << endl;
	cout << "s10.find(\"abc\") = " << s10.find("abc") << endl<<endl;

	cout << "p10 = " << p10 << endl;
	cout << "p10.find(\"def\",1) = " << p10.find("def",1) << endl<<endl;

	cout << "q10 = " << q10 << endl;
	cout << "q10.find(\"123\",1) = " <<	q10.find("123",1) << endl<<endl;

	cout << "--------------Case 11 :find_first_of(const MyString& str, size_t pos) const------------------ " << endl;
	MyString s11(s);
	MyString p11(p);
	MyString q11(q);
	cout << "s11 = " << s11 << endl;
	cout << "s11.find_first_of(\"abc\",2) = " << s11.find_first_of("abc",2) << endl<<endl;
	
	cout << "p11 = " << p11 << endl;
	cout << "p11.find_first_of(\"qpoiu\",4) = " << p11.find_first_of("qpoiu", 4) << endl<<endl;

	cout << "q11 = " << q11 << endl;
	cout << "q11.find_first_of(\"234\") = " << q11.find_first_of("234") << endl<<endl;
	cout << "--------------Case 12 :istream& operator>>(istream& input, MyString& str)------------------ " << endl;
	MyString change;
	cin >> change;
	return 0;
}