 ///
 /// @file    resize_reverse.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 11:43:05
 ///
 
#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	string s;
	cout<<s.size()<<endl;
	s.reserve(10);
	cout<<s.size()<<endl;
	s.resize(10);
	cout<<s.size()<<endl;

	cout<<endl;
	cout<<v.size()<<endl;
	v.reserve(10);
	cout<<v.size()<<endl;
	v.resize(10);
	cout<<v.size()<<endl;
}
