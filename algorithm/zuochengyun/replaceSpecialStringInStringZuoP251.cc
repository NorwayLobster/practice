 ///
 /// @file    replaceSpecialStringInStringZuoP251.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 16:11:06
 ///
 
#include <bits/stdc++.h>

using namespace std;
void func(string&str,string&from,string&to){

	size_t ret=str.find(from);
	if(string::npos!=ret)
		str.replace(ret,from.size(),to);
	while(string::npos!=(ret=str.find(from))){
		str.replace(ret,from.size(),"");
	}
}
int main(){
	string str("abc123abcabc");	
	string from("abc");	
	string to("456");	
	func(str,from,to);
	cout<<"str:"<<str<<endl;
	return 0;
}
