 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 23:14:37
 ///
 
#include <bits/stdc++.h>
using namespace std;
void help(vector<string> & str_v,string &str,int depth, int len){
	if(depth==len){
		str_v.push_back(str);
		return ;
	}
	for(int i=depth;i<len;++i){
		swap(str[depth],str[i]);
		help(str_v,str,depth+1,len);
		swap(str[i],str[depth]);
	}
}
void stringPermutation(vector<string> & str_v,string &str){
	int len=str.size();
	if(0==len) return ;
	help(str_v,str,0,len);
	return ;

}
int main(){
	vector<string> v;

//	string s("abc");
//	string s("a");
	string s("");
	stringPermutation(v,s);
	for(auto &s:v){
		cout<<s<<endl;
	}
	return 0;
}
