///
/// @file    string.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-28 22:25:16
///
#include <cstring>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
//5. 实现一个自定义的String类，保证main函数对正确执行
class String
{
	public:
		String()
		: _pstr(NULL)
		{
		cout<<"defualt constructor"<<endl;
		};
		
		String(const char *pstr)
		:_pstr(new char[strlen(pstr)+1]())
		//:_pstr(new [strlength(pstr)+1]i())
		{
			cout<<"normal constructor"<<endl;
			strcpy(_pstr,pstr);
		};
		
		String(const String & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1]())
		{
			cout<<"cpoy constructor"<<endl;
			strcpy(_pstr, rhs._pstr);
		};

		String & operator=(const String & rhs)
		{
			cout<<"overload operator ="<<endl;
			if(this!=&rhs)
			{
				delete [] _pstr;

				cout<<"inside overload operator ="<<endl;
				_pstr = new char[strlen(rhs._pstr)+1];	
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		};

		~String()
		{
			cout<<"NULL\n"<<_pstr<<endl;
			if(NULL!=_pstr)
			{
				cout<<"inside the deconstructor"<<endl;
				delete [] _pstr;
				_pstr=NULL;
			}
			cout<<"~String()"<<endl;
		};

		void print();

	private:
		char * _pstr;
		//char * _pstr=NULL;
};

void String::print()
{
	if(NULL!=_pstr)
	{
		cout<<_pstr<<endl;
	}
}

int main(void)
{
	String str1;
	str1.print();

//	cout<<"-----"<<endl;
//	
//	String str2 = "Hello,world";
//	str2.print();		
//	cout<<"-----"<<endl;
//	String str3("wangdao");
//	str3.print();	
//
//	cout<<"-----"<<endl;
//	String str4 = str3;
//	str4.print();
//
//	cout<<"-----"<<endl;
//	str4 = str2;
//	str4.print();
//
//
//	cout<<"-----"<<endl;
	return 0;
}
