 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 02:47:32
 ///
 
#include <bits/stdc++.h>
using namespace std;
#define N 26
int longestSubtringOfNoDoubleCharacter(string &,vector<int>&);
int main(){
	vector<int> map(N,-1);
	for(auto a:map){
		cout<<a<<' ';
	}

	string s("abadfadsgdfhwedgwergwer");
	longestSubtringOfNoDoubleCharacter(s,map);

}

int longestSubtringOfNoDoubleCharacter(string &s,vector<int> &map){
	int len=s.size();
	if(0==len)
		return 0;
	int pre=-1;//前面一个合法的左边界的下标
	int MaxLen=0;//
	int curLen=0;//以i为右边界的substring长度
	for(int i=0;i<s.size();++i){
		pre=max(pre,map[s[i]]);		
		curLen=i-pre;//元素个数,不包含pre本身
		MaxLen=max(MaxLen,curLen);
		map[s[i]]=i;
	}
	cout<<endl;
	cout<<"MaxLen:"<<MaxLen<<endl;
	return 0;
}
