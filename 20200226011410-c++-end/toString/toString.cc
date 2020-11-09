 ///
 /// @file    toString.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-26 17:32:54
 ///
 
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
template<typename T>
string any2string(T t){
//	char a='a';
//	int b='a';
//	int a=10;
//	string str=std::to_string(b);
//	cout<<str<<endl;
	stringstream ss;
//	ss<<a;
//	ss.clear();
	ss<<t;
//	cout<<ss.str()<<endl;
	return ss.str();
}

int main(){
	cout<<"hello"<<endl;
	cout<<any2string('a')<<endl;
	cout<<"hello"<<endl;
	return 0;
}
