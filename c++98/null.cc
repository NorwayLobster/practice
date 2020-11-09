///
 /// @file    null.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-28 23:33:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::string;
//using std::bool;
int main(void)
{
//	bool*p=NULL;
//	char *p="hello";
	string s="hello";
	int a=10;
	//const char *p=NULL;
	cout<<"&s=\n"<<&s<<endl;
	cout<<"&a=\n"<<&a<<endl;
	cout<<"hello"<<endl;
	return 0;
}
