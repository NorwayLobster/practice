 ///
 /// @file    make_shared.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-11 22:25:52
 ///
 
#include <bits/stdc++.h>
using namespace std;
int main(){
	shared_ptr<string> pstr=make_shared<string>("hell-000000000fasdfasdddfj");
	const char *p="World";
	const char pArr[]="World";
	shared_ptr<string> pstr1=make_shared<string>(p);
	cout<<*pstr<<endl;
	cout<<*pstr1<<endl;

	cout<<endl;
//1.	
//char *p1=const_cast<char*>(p);
//error	strcpy(p1,"Hello");
//
//
//2.
//	const char *parr=pArr;
//	strcpy(parr,"Univ.");
	char *p2=const_cast<char*>(pArr);//pArr内存的只读属性
	strcpy(p2,"Hello");
	cout<<p2<<endl;
	return 0;
}
