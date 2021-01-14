 ///
 /// @file    strint.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-12 20:52:10
 ///
 
#include <bits/stdc++.h>
using namespace std;
int strint(char *p){
	int sum=0;
	if(!p) return sum;
	int len=(int)strlen(p);
	std::reverse(p,p+len);
#if Debug
	cout<<p<<endl;
#endif
	char *left=p;
	cout<<*p<<endl;
	cout<<*(p+len-1)<<endl;
	cout<<endl;
	int multiply=1;
	while('\0'!=*left){
		if(*left>='0'&&*left<='9'){
			sum+=(*left-'0')*multiply;	
			multiply*=16;
#if Debug
			cout<<*left-'0'<<endl;
			cout<<sum<<endl;
			cout<<multiply<<endl;
			cout<<endl;
#endif
		}else if(*left>='a'&&*left<='f'){
			sum+=(*left-'a'+10)*multiply;	
			multiply*=16;
			cout<<multiply<<endl;
		}else{
			cout<<"invalid input"<<endl;
			return -1;
		}
		left++;
	}
	return sum;
}

int main(){
//	char p[]="10";
	char p[]="10f";
//	char p[]="123456789";
	cout<<strint(p)<<endl;	
	
	return 0;
}
