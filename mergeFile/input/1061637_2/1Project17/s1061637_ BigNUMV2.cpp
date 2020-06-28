#include "s1061637_ BigNUMV2.h"
#include<iomanip>
BigNUM::BigNUM():MyArray(3)
{
	this->size = 1;
	data[0] = 0;
}
BigNUM::BigNUM(long long int input) : MyArray(3)
{
	
	if (input < 0)
	{
		plus = false;
		input = input * -1;
	}
	if(input==0)
		data_increase(0);
	else
	{
		for (size_t i = 0; input > 0; i++)
		{
			data_increase(0);
			data[i] += input % 1000000;//6位數
			input = input / 1000000;
			
		}
	}
	
}
BigNUM::BigNUM(int root, int pow) :MyArray(3)
{
	if (pow == 1)
		data_increase(root);
	else
	{
		BigNUM temp(1);
		BigNUM ROOT(root);
		for (int i = 0; i < pow; i++)
		{
			temp = temp * ROOT;

		}
		
		BigNUM::operator=(temp);

	}
}
BigNUM::BigNUM(const BigNUM& input) :MyArray(3)
{
	BigNUM::operator=(input);
}

const BigNUM& BigNUM::operator=(const BigNUM& input)
{
	
	this->MyArray::operator=(input);
	this->plus = input.plus;
	return *this;
}
BigNUM BigNUM::operator+(long long int input)//有進位!!
{
	return *this + BigNUM(input);
}
BigNUM BigNUM::operator+(const BigNUM& right)
{
	if (this->plus == right.plus)
	{
		BigNUM temp(0);
		if (this->value(right))
		{
			temp.BigNUM::operator=(*this);
		}
		else
		{
			temp.BigNUM::operator=(right);
		}
		for (size_t i=0; i<this->size &&i<right.size ;i++)
		{
			
				temp.data_increase(0);

			if(this->value(right))
				temp.data[i] += right.data[i];
			else
				temp.data[i] += this->data[i];
			temp.carry(i);
		}
		temp.shrink();
		return temp;
	}
	else if (this->plus)
	{
		if (this->value(right))//左大政幼小副
		{
			BigNUM temp(right);
			temp.plus = true;
			temp= *this - temp;
			temp.shrink();
			return temp;
		}
		else//左小政幼大副
		{
			BigNUM temp(right);
			temp.plus = true;
			temp = temp - *this;
			temp.plus = false;
			temp.shrink();
			return temp;
		}
	}
	else//左腹又正
	{
		if (this->value(right))
		{
			BigNUM temp(*this);
			temp.plus = true;
			temp = temp - right;
			temp.plus = false;
			temp.shrink();
			return temp;
		}
		else
		{
			BigNUM temp(*this);
			BigNUM temp2(right);
			temp.plus = true;
			temp= temp2 - temp;
			temp.shrink();
			return temp;
			 
		}

	}
		
		
}
void BigNUM::carry(int i)
{
	if (this->data[i] >= 1000000)
	{
		if(i<=size-1)
			this->data_increase(0);
		this->data[i + 1] += this->data[i] / 1000000;
		this->data[i] = (this->data[i] % 1000000);
	}
}
BigNUM BigNUM::operator-(const long long int& input)
{
	return *this - BigNUM(input);
}
BigNUM BigNUM::operator-(const BigNUM& right)
{
	if (this->plus != right.plus)
	{
		BigNUM temp(right);
		temp.plus = !right.plus;
		return (*this + temp);
	}

    if (this->value(right))
		{
			BigNUM temp(*this);
			for (size_t i = 0; i < temp.size; i++)
			{
				if (right.size - 1 >= i)
				{
					if (temp.data[i] < right.data[i])
						temp.borrow(i);
					temp.data[i] -= right.data[i];
				}
				else
					break;
			}
			
			temp.shrink();
			return temp;
		}
		else//+  左小又大
		{
			BigNUM temp(right);
			temp.plus = !right.plus;
			for (size_t i = 0; i < temp.size; i++)
			{
				if (this->size - 1 >= i)
				{
					if (temp.data[i] < this->data[i])
						temp.borrow(i);
					temp.data[i] -= this->data[i];
				}
			}
			
			temp.shrink();
			return temp;
		}
	
	
}
BigNUM BigNUM::operator*(const BigNUM& right) {
	BigNUM ANS(0);
	if (right.plus != this->plus)
	{
		ANS.plus = false;
	}
	ANS.reserve(this->size+ right.size);
	for(size_t i=0;i< (this->size);i++)
		for (size_t j = 0;j< (right.size); j++)
		{
			if(i+j>ANS.size-1)
				ANS.data_increase(0);
			ANS.data[i + j] += this->data[i] * right.data[j];
			ANS.carry(i + j);
		}

	ANS.shrink();
	return ANS;
}
/*bool BigNUM::dataisfull(size_t input) 
{
	size_t need = input + 1;
	if (this->size < need)
		return 1;
	else
		return 0;
}*/
void BigNUM::data_increase(int input)
{
	resize(size + 1,0);
	data[size - 1] = input;
}
//
bool BigNUM::value(const BigNUM& right)
{
	if (this->size> right.size)
		return 1;
	else if (this->size < right.size)
		return 0;
	if (this->data[this->size - 1] > right.data[this->size - 1])
		return 1;
	else
		return 0;
}
void BigNUM::borrow(size_t i)
{
	if (this->data[i + 1])
	{
		this->data[i + 1] -= 1;
		this->data[i] += 1000000;
	}
	else
	{
		this->data[i + 1] = 999999;
		borrow(i + 1);
	}
}
 ostream& operator<<(ostream& os, const BigNUM &big)
{
	 if (!big.plus)
		 os << '-';
	 for (int i = big.size - 1; i >= 0; i--)
		 if (i != big.size - 1)
		 {
			 os << ',';
			 os<< setw(3) << setfill('0') << big.data[i] / 1000;
		     os<<',';
			 os<<setw(3) << setfill('0') << big.data[i] %1000;
		 }
		 else 
		 {
			 if (big.data[i] > 999)
				 os << big.data[i] / 1000 << "," << setw(3) << setfill('0') << big.data[i] % 1000;
			 else
				 os << big.data[i];
		 }

			

		 
	 return os;
}
  BigNUM operator+(const int& left, const BigNUM& right)
  {
	  return BigNUM(left) + right;
  }
  BigNUM operator*(const int& left, const BigNUM& right)
  {
	  return BigNUM(left) * right;
  }
  BigNUM operator-(const int& left, const BigNUM& right)
  {
	  return BigNUM(left) - right;
  }
  BigNUM BigNUM::operator-()
  {
	  BigNUM temp(*this);
	  temp.plus = !temp.plus;
	  return temp;
  }
  void BigNUM::shrink()
  {

	  for (size_t i = this->size - 1; i > 0; i--)//i最少留一格
	  {
		  
		  if (this->data[i] == 0)
			  --size;
		  else
			  return;
	  }
	 
	  if (data[0] == 0)
		  this->plus = true;
  }
  /* istream& operator>>(ostream&, const string& input)
   {
	   int i = 0;
	   BigNUM temp;
	   if (input.size() % 6)
	   { 
		   substr(i, input.size() % 6);
		   i = input.size() % 6 - 1;
	   }

   }*/
  
  
