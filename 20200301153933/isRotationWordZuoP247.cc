 ///
 /// @file    isRotationWord.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 15:40:17
 ///
 
#include <bits/stdc++.h>
using namespace std;

//time: O(N)
//space: O(N)
bool isRotationWord(string &s1,string &s2){
	//way1.BF s1左移1-n位，然后找有无s2
	//way2.
	string str=s2+s2;
	const char * p= strstr(str.c_str(),s1.c_str());
	if(NULL==p){
		return false;
	}
		return true;
}
int main(){
//	string s1("cdab");
//	string s2("abcd");
	string s1("1ab2");
	string s2("ab12");
//	string s1("2ab1");
//	string s2("ab12");
	cout<<"bool:"<<isRotationWord(s1,s2);
	cout<<endl;
	return 0;
}
