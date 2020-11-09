 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 02:14:53
 ///
 
#include <bits/stdc++.h>
using namespace std;
int translateNumToString(vector<int> v,string &s,int k){

	if(v[k]>0) return v[k];
	if(k==0) return 1;
	int num=(s[k-1]-'0')*10+s[k]-'0';
	if(k==1){
		if(num<=25 && num>=10)
			return 2;
		else 
			return 1;
	}

	if(num<=25 && num>=10)
		v[k]=translateNumToString(v,s,k-1)+translateNumToString(v,s,k-2);
	else
		v[k]=translateNumToString(v,s,k-1);
	return v[k];
}

int main(){
	string s("2");//假设合法输入
//	string s("23032625");//假设合法输入
	vector<int> v(1024,-1);		
	int len=s.size();
	if(!s.size()) return -1;
	cout<<"num:"<<translateNumToString(v,s,len-1)<<endl;
	return 0;
}

