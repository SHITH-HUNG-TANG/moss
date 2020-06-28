#include "s1081420_MyString.h"



MyString::MyString(const MyString &str, size_t pos, size_t len ) {
	if (len == msize)len = str.getSize();
	this->resize(len);
	for (int i = pos; i < len; i++) (*this)[i - pos] = str[i];
}


MyString::MyString(const char *s) {
	/*string num = s;
	for (int i = 0; i < num.size(); i++)(*this)[i] = num[i];*/
	int num = 0;
	while (s[num] != '\0') {
		this->resize(this->getSize() + 1);
		(*this)[num] = s[num];
		num++;
	}
}

//template <typename T>
//MyString<T>::~MyString() {
//	size = 0;
//	capacity = 0;
//	delete[]data;
//	data = nullptr;
//}


MyString& MyString::append(const MyString &str) {
	int value = this->getSize();
	this->resize(value + str.getSize());
	for (int i = value; i < this->getSize(); i++)(*this)[i] = str[i - value];
	return *this;
}


MyString MyString::substr(size_t pos, size_t len ) const {
	MyString sub;
	if (len == msize)len = this->getSize();
	sub.resize(len);
	for (int i = pos; i < len + pos; i++) sub[i - pos] = (*this)[i];
	return sub;
}


MyString& MyString::insert(size_t pos, const MyString &str) {
	MyString sub;
	sub = this->substr(pos, this->getSize()-pos);
	/*sub.resize(this->getSize() - pos);
	for (i = pos; i < this->getSize() - pos; i++) sub[i - pos] = [i];*/
	this->resize(pos + str.getSize());
	for (int i = pos; i < str.getSize() + pos; i++)(*this)[i] = str[i - pos];
	this->append(sub);
	return *this;
}


MyString& MyString::insert(size_t pos, const MyString &str, size_t subpos, size_t sublen ) {
	MyString str_sub;
	str_sub = str.substr(subpos, sublen);
	this->insert(pos, str_sub);
	return *this;
}


MyString& MyString::erase(size_t pos, size_t len ) {
	MyString sub;
	sub = this->substr(pos + len, this->getSize()-(pos+len));
	this->resize(pos);
	this->append(sub);
	return *this;
}

int MyString::find(const MyString &str, size_t pos) const {
	int balance = msize;
	for (int i = pos; i < this->getSize(); i++) {
		if ((*this)[i] == str[0]&&balance==msize) {
			for (int j = i; j < str.getSize()+i; j++) {
				if ((*this)[j] == str[j - i]) {
					if (j-i != str.getSize() - 1)continue;
					else {
						balance = i;
						break;
					}
				}
				else break;
			}
		}
	}
	return balance;
}//完整字串


int MyString::find_first_of(const MyString& str, size_t pos) const {
	int tmp = msize;
	MyString arr;
	for (int i = 0; i < str.getSize(); i++) {
		arr.resize(1, str[i]);
		if (i == 0)tmp = str.find(arr, 0);
		else {
			if (tmp > str.find(arr))tmp = str.find(arr);
		}
	}
	return tmp;
	
}//找最早出現字串其中之一的字母

//template class  MyString<char*>;
//template class  MyString<int>;
//template class  MyString<char>;
//template class  MyString<string>;