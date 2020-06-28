#pragma once
#ifndef s1081420_MyArray_H
#define s1081420_MyArray_H

#include <string>
#include<iostream>
using namespace std;

template<typename T>
class MyArray {	//modify this class into a template class
	//template<typename T>
	friend ostream& operator<< (ostream& out, const MyArray<T>& right) {
		for (int i = 0; i < right.getSize(); i++) out << right[i] << " ";
		out << endl;
		return out;
	}//輸出物件，中間含空格


	//friend istream& operator>>(istream&, MyArray&);
	public:
		MyArray(int Capacity = 10);//預設空間為capacity=10,size=0//每次空間格不夠時變成當下2倍大
		MyArray(size_t Size, T value);//ex.(3,5)陣列內容為3個5，value 的 type 要用template
		//Bouns->
		MyArray(T value[], int Size);//傳入一個陣列讓陣列的內容放入Array(this)裡
		//Bouns<-
		MyArray(const MyArray<T> & right);//copy constructor
		~MyArray();
		const MyArray<T>& operator=(const MyArray<T>&);//assigment operator
		bool operator==(const MyArray<T>&) const;
		bool operator!=(const MyArray<T>&) const;
		MyArray<T> operator+(const MyArray<T>&) const;	//NEW回傳新的容器，並且原本的兩者本身值不變
		MyArray<T>& operator+=(const MyArray<T>&) ;		//NEW回傳原容器修改過的結果
		T& operator[](int);//可修改
		T operator[](int) const;//僅傳值
		T& at(int);		//new。可修改，有範圍檢查之內容存取(exception)
		T at(int) const;	//new。僅傳值，有範圍檢查之內容存取(exception)

		int getSize() const { return size; };
		int getCapacity() const { return capacity; };
		void resize(size_t size, T item='\0');
		void reserve(size_t size);//將capacity直接變成所傳入的變數
		void shrink_to_fit();	//new。將capacity縮等於size
		void clear();			//new。清除array內容
		bool isEmpty();			//new。檢查是否為空
		/*class out_of_range : public logic_error {
		public:
			explicit out_of_range(const string& what_arg);
			explicit out_of_range(const char* what_arg);
		};*/

	private:
		int size = 0;
		int capacity = 10;
		T* data = nullptr;
};



//#include "s1081420_MyArray.cpp"
#endif // !s1081420_MyArray

