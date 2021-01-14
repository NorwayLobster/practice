#include "string.h"
#include <cstring>
String::String():
_pstr(NULL)//very vital
{
	cout<<"String()"<<endl;
}

String::String(const char *p):
_pstr(new char[strlen(p)+1]())
{
	strcpy(_pstr,p);
	cout<<"String(const char *p)"<<endl;
}

String::String(const String &s):
_pstr(new char[strlen(s._pstr)+1]())
{
	strcpy(_pstr,s._pstr);
	cout<<"String(const String &s)"<<endl;
}

String & String::operator=(const String & rhs)// 三部曲： 1， 自复制，2.深拷贝，3回收原空间
{
//error	~String();
	if(this!=&rhs){//防止自复制
		this->~String();
		_pstr=new char[strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
		cout<<"String operator=(const String &s)"<<endl;
	}
	return *this;
}

String::~String(){
	delete [] _pstr;
	_pstr=NULL;
	cout<<"~String()"<<endl;
}

void String::print(){
	cout<<"String:"<<_pstr<<endl;
}
