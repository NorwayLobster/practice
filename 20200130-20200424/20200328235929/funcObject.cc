///
/// @file    funcObject.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-29 00:00:01
///
#include<bits/stdc++.h>
using namespace std;
//typedef bool (* func)(int,int);
using func=bool (*)(int,int);
bool myLess(int a,int b){
	string str1=to_string(a);
	string str2=to_string(b);
	string str3=str1+str2;
	string str4=str2+str1;
	return str3<str4;
}
int main(){
	func f=myLess;
	cout<<"bool:"<<f(23,231)<<endl;
	cout<<"bool:"<<f(23,234)<<endl;
	return 0;
}
