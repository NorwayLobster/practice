 ///
 /// @file    longestValidParenthesesSubstring.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 22:33:24
 /// complete: Tue Mar  3 23:26:24 CST 2020
 //1h
#include <bits/stdc++.h>
using namespace std;
int longestValidParenthesesSubstring(const string&s){
	int len=s.size();
	vector<int> dp(len,0);
	int preIndex=0;
	dp[0]=0;
	int res=INT_MIN;
	for(int i=0;i<len;++i){
		if(')'==s[i]){
			preIndex=i-dp[i-1]-1;
			if(preIndex>=0&&'('==s[preIndex]){
				dp[i]=dp[i-1]+2+(preIndex>0?dp[preIndex-1]:0);
			}
		}
		res=max(res,dp[i]);
	}
//	return *max_element(dp.begin(),dp.end());
	return  res;
}

int main(){
	string s("()(((()))))");
	cout<<"num:"<<longestValidParenthesesSubstring(s)<<endl;
	return 0;
}
