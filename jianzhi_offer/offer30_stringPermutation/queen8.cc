 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 23:14:37
 ///
 
#include <bits/stdc++.h>
using namespace std;


///?????????????? 待改正
bool check(vector<int>&s){
	for(int i=0;i<s.size();++i){
		for(int j=i+1;j<s.size();++j){
			if(j+i==s[j]+s[i]||j-i==-s[j]+s[i])
				return false;
		}
	}
	return true;
}
void help(vector<vector<int>> & str_v,vector<int>&str,int depth, int len){
	if(depth==len){
		if(check(str))
			str_v.push_back(str);
		return ;
	}
	for(int i=depth;i<len;++i){
		swap(str[depth],str[i]);
		help(str_v,str,depth+1,len);
		swap(str[i],str[depth]);
	}
}
void stringPermutation(vector<vector<int>> & str_v,vector<int>&str){
	int len=str.size();
	if(0==len) return ;
	help(str_v,str,0,len);
	return ;
}
int main(){
// 8皇后
	vector<vector<int>> v;

//	string s("abc");
//	string s("a");
	vector<int> s={0,1,2,3,4,5,6,7};
	for(auto e:s)
		cout<<e<<" ";
	cout<<endl;
	cout<<endl;

	stringPermutation(v,s);
	cout<<"v.size:"<<v.size()<<endl;	
	for(auto &s:v){
		for(auto e:s)
			cout<<e<<" ";
		cout<<endl;
	}
	return 0;
}
