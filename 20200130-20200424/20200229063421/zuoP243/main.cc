 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 04:02:17
 ///
 
#include <bits/stdc++.h>
using namespace std;
int err_no=0;
int func(string&s){
	int len=s.size();
	if(s.size()==0){
		err_no=-1;
		return 0;
	}
	int total=0;	
	int i=0;
	while(i<len){
		int minusNum=0;
		if('-'==s[i]){
			while(i<len&& s[i]=='-'){
				++minusNum;
				++i;
			}
		}
		if(s[i]>='0' && s[i]<='9'){
			int	minus=1;
			int sum=0;
			if(i>0 &&'-'==s[i-1]){
				minus=minusNum&0x1?-1:1;
			}
			while(i<len && s[i]>='0' &&s[i]<='9'){
				sum=sum*10+minus*(s[i]-'0');
				++i;
			}
			total+=sum;
		}else{
			++i;
		}
	}
	return total;
}
int main(){
//	string s1("a---1.23");
//	string s1("a-1BC--12");
//	string s1("a1Cd2e33");
	string s1("a-1b--2c--d6e");
	cout<<"num:"<<func(s1)<<endl;
	return 0;
}
