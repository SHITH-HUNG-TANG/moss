#include "s1081420_MyString.h"
#include<iostream>
using namespace std;

int main(int argc, const char *argv[]) {
	cout << "I'm s1081420\n\n";




	MyString v;
	cout << "Test operator >> and << \n";
	cin >> v;
	cout << v << "\n\n";


	MyString arr1, arr2("Hellow"), arr3("to day is a nice day"), arr4("to day is a nice day", 5, 8), arr5("to day is a nice day", 6);
	cout << "Test  constructor:MyArray<char>arr1\n";
	cout << arr1;
	cout << "arr1_size=" << arr1.getSize() << "\narr1_capacity" << arr1.getCapacity() << "\n\n";
	cout << "Test  constructor:MyArray<char>arr2(str)\n";
	cout << arr2;
	cout << "arr2_size=" << arr2.getSize() << "\narr2_capacity" << arr2.getCapacity() << "\n\n";
	cout << arr3;
	cout << "arr3_size=" << arr3.getSize() << "\narr3_capacity" << arr3.getCapacity() << "\n\n";

	MyString arr6, arr7, arr8, arr9;
	arr6.resize(5, 'A');
	arr7.resize(3, 'B');
	arr8.resize(10, 'C');
	cout << arr6 << endl;
	cout << arr7 << endl;
	cout << arr8 << endl;

	cout << "Test append \n" << "arr6 : " << arr6 << "\narr7 : " << arr7 << "\n" << "arr6.append(arr7) : ";
	arr6.append(arr7);
	cout << arr6<<"\n\n";

	cout << "Test substr \n" << "arr9 : " << arr9 << "\narr6 : " << arr6<<"\narr9=arr6.substr(3,3) : ";
	arr9 = arr6.substr(3, 3);
	cout << arr9 << "\n\n";

	cout << "Test insert \n" << "arr6 : " << arr6 << "\narr7 : " << arr7 << "\n" << "arr6.insert(2,arr7) : ";
	arr6.insert(2, arr7);
	cout << arr6 << "\n\n";

	cout << "Test insert \n" << "arr9 : " << arr9 << "\narr8 : " << arr8 << "\n" << "arr9.insert(2,arr8,3,5) : ";
	arr9.insert(2, arr8, 3, 5);
	cout << arr9 << "\n\n";

	cout << "Test erase \n" << "arr9 : " << arr9 << "\narr9.erase(1,3) : ";
	arr9.erase(1,3);
	cout << arr9 << "\n\n";

	cout << "Test find \n";
	MyString arr10("x to be or not to be, that is cool question"), arr11("cool"), arr12("cxxl");
	cout << arr10.find(arr11) << "\n" << arr10.find(arr12) << "\n" << arr10.find_first_of(arr12) << "\n\n";




	system("pause");
	return 0;
}