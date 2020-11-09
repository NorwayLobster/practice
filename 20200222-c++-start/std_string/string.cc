 ///
 /// @file    string.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 01:29:49
 ///
 
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::basic_string;
using std::string;

int main(){
//1.
	basic_string<char> a="hello";
//2.
	string b= "world"+a;
//3.
	basic_string<char> c=a.append("hello");
	cout<<"c:"<<c<<endl;
//3. .substr()
	basic_string<char> d= c.substr(0,3);
	cout<<"d:"<<d<<endl;
//
//3. .data() 等于 .c_str()
	cout<<"pointer:"<<(void*)d.c_str()<<endl;
//	cout<<"pointer:"<<static_cast<void*>(d.c_str())<<endl;
//	cout<<"pointer:"<<reinterpret_cast<void*>(d.c_str())<<endl;
	cout<<"d:"<<d.c_str()<<endl;
	cout<<"d[0]:"<<d.c_str()[0]<<endl;
//	d.c_str()[0]='d'; error
	cout<<"d:"<<d.data()<<endl;
	cout<<"sizeof(d):"<<sizeof(d)<<endl;

	return 0;
}
	


