 ///
 /// @file    combination.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 00:16:36
 ///
 
#include <bits/stdc++.h>
using namespace std;
void help(vector<string> &v,string str,int k,int len,int start,string &tmp){
	if(0==k){
		v.push_back(tmp);
		return;
	}
	for(int i=start;i<len;++i){
		tmp.push_back(str[i]);
		help(v,str,k-1,len,i+1,tmp);
		tmp.pop_back();
	}
} 
void mycombination(vector<string> &v, string &str){

	int len=str.size();
	if(0==len) return ;
	string tmp;
	for(int k=1;k<=len;++k){
		help(v,str,k,len,0,tmp);
	}
}
int main(){
	vector<string> v;
	string str("abc");
	mycombination(v,str);
	for(auto &s:v)
		cout<<s<<endl;
	return 0;
}
