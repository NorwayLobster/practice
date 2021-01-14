 ///
 /// @file    isValidParentheses.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 22:25:27
 /// 10min
 
#include <bits/stdc++.h>
using namespace std;
bool isValidParentheses(const string &s){
	int len=s.size();
	int left=0;
	int right=0;
	for(int i=0;i<len;++i){
		if('('!=s[i]&&')'!=s[i]) return false;
		if('('==s[i])
			left++;
		if(')'==s[i])
			right++;
		if(right>left) 
			return false;
	}
	return right==left;
}
int main(){
	string s("(((())))");
	cout<<"bool:"<<isValidParentheses(s)<<endl;
	return 0;
}
