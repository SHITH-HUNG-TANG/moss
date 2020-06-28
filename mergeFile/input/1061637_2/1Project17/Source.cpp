#include"s1061637_Mystring.h"
#include"s1061637_MyArray.h"
#include"s1061637_ BigNUMV2.h"
int main()
{
	MyArray	<char>non;
	MyArray	<char>rr(2, 'r');
	MyArray<char>aaa(3,'a');
	MyArray<char>bbb(aaa);
	
	/*cout <<aaa<<endl;
	cout <<bbb << endl;
	cout << "aaa=bbb" << (aaa == bbb) << endl;
	cout << "aaa=bbb" << (aaa != bbb) << endl;
	cout << "asd=bbb" << (non == bbb) << endl;
	cout << aaa + non << endl;
	cout << aaa + rr << endl;
	cout << (non += aaa) << endl;

	cout << (rr) << endl;
	cout << (aaa += rr) << endl;
	//cout << aaa << endl;
	cout << aaa[2] << endl;*/
	//cout << aaa.at(50) << endl
	/*MyArray	<char>dddd(4, 'd');
	cout << dddd.getSize()<<endl;
	cout << dddd.getCapacity() << endl;
	dddd.resize(9, 'e');
	cout << dddd<<endl;
	cout << dddd.getSize() << endl;
	cout << dddd.getCapacity() << endl;
	dddd.reserve(20);
	cout << dddd.getCapacity() << endl;;
	cout << dddd.getSize() << endl;
	dddd.shrink_to_fit();
	cout << "shrink_to_fit" << dddd.getCapacity() << endl;
	cout << dddd << endl;
	dddd.clear();
	cout << dddd << dddd.getSize()<< dddd.isEmpty();*/


	MyString xxxx("xxxx");
	
	MyString asdddw("asdddw");
	//cout << asdddw<< asdddw.getSize()<<asdddw.getCapacity()<<endl;
	/*MyString asdddw2(asdddw);
	MyString sd(asdddw, 2, 2); 
	cout << sd<<endl;
	MyString asdddw3(asdddw, 1,50);
	cout << asdddw3 << endl;
	cout << asdddw3.append(MyString("ppps"))<<endl;
	cout << asdddw3.substr(4,10)<<endl;
	cout << asdddw3.substr(3, 5) << endl;*/
	//cout<<asdddw.insert(3, xxxx)<<endl;
	
	/*MyString idk("abcdefg");
	cout << idk.insert(2, MyString("hijklm"), 3, -1)<<endl;
	cout << idk.erase(3, 4)<<endl;
	cout << idk.erase(3, 999)<<endl;*/
	MyString idk("aboxoxcox");
	//cout << idk.find(MyString("oxo"),1)<<endl;
	//cout << idk.find(MyString("oxo"), 4) << endl;
	//cout << idk.find(MyString("oxo"), 6) << endl;
	MyString abcdefggg("abcdefggg");
	int x = 1;
	while ((x = abcdefggg.find_first_of(MyString("aceg"), x)) != abcdefggg.msize)
	{
		cout << x << endl;
		x = x + 1;
	}
	BigNUM mybig, mybig2(9993345), mybig3(mybig2);
	cout << mybig3+ mybig2;
	return 0;
}