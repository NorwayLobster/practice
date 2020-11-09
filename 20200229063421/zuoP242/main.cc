 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 04:02:17
 ///
 
#include <bits/stdc++.h>
using namespace std;

bool func(string&s1,string &s2){
	if(s1.size()!=s2.size()) return false;
	vector<int> map(256,0);
	for(auto e:s1)
		++map[e];
	for(auto e:s2){
		--map[e];
	}
	for(auto e:map){
		if(0!=e)
			return false;
	}
	return true;
}
int main(){
	string s1("123");
	string s2("1323");
	cout<<"bool:"<<func(s1,s2)<<endl;
	return 0;
}
