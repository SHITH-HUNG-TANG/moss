#include <iostream>
#include "MyString_hw702.h"

using namespace std;

int main(){
    cout<<"測試 MyString str1()"<<endl;
    MyString str1;
    cout<<"Capacity : "<<str1.getCapacity()<<endl;

    cout<<endl;
    cout<<"測試 MyString str2(\"0123456789\")"<<endl;
    MyString str2("0123456789");
    cout<<str2<<endl;

    cout<<endl;
    cout<<"測試 MyString str3(str2,3,3) (=\"345\")"<<endl;
    MyString str3(str2,3,3);
    cout<<str3<<endl;

    cout<<endl;
    cout<<"測試 MyString str4(str2)"<<endl;
    MyString str4(str2);
    cout<<str4<<endl;

    cout<<endl;
    cout<<"測試 str3.append(str4)"<<endl;
    cout<<str3.append(str4)<<endl;

    cout<<endl;
    cout<<"測試 str3.substr(2)"<<endl;
    cout<<str3.substr(2)<<endl;

    cout<<endl;
    cout<<"測試 str2.insert(4,str4)"<<endl;
    cout<<str2.insert(4,str4)<<endl;

    cout<<endl;
    cout<<"測試 str2.erase(2,10)"<<endl;
    cout<<str2.erase(2,10)<<endl;

    cout<<endl;
    cout<<"測試 str2.insert(4,str4,3,3)"<<endl;
    cout<<str2.insert(4,str4,3,3)<<endl;

    cout<<endl;
    cout<<"測試 str2.find(\"89345\")"<<endl;
    cout<<str2.find("89345");

    cout<<endl;
    cout<<"測試 str2.find_first_of(\"76\")"<<endl;
    cout<<str2.find_first_of("76")<<endl;
    return 0;
}