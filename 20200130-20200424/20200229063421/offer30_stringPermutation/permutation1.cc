 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 23:14:37
 ///
 
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>&s){
	if(s[0]+s[1]+s[2]+s[3]==s[4]+s[5]+s[6]+s[7]\
		&&s[0]+s[2]+s[4]+s[6]==s[2-1]+s[4-1]+s[6-1]+s[8-1]\
		&&s[1-1]+s[2-1]+s[5-1]+s[6-1]==s[3-1]+s[4-1]+s[7-1]+s[8-1])
		return true;
	else 
		return false;
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
// 正方体八顶点
	vector<vector<int>> v;

//	string s("abc");
//	string s("a");
	vector<int> s={1,2,3,4,5,6,7,8};
	for(auto e:s)
		cout<<e<<" ";
	cout<<endl;
	cout<<endl;

	stringPermutation(v,s);
	
	for(auto &s:v){
		for(auto e:s)
			cout<<e<<" ";
		cout<<endl;
	}


	return 0;
}
