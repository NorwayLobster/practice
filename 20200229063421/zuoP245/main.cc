 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 04:37:20
 ///
 
#include <bits/stdc++.h>
using namespace std;
void moveKToLeft(char *s,int k,int i){//可以再优化
	while('\0'!=*s){
		s[i-k]=*s;
		++s;
	}
	*(s-k)='\0';
}
void func(char *s,int k){
	int i=0;
	while('\0'!=*s){
		if('0'==s[i]){
			int num=0;
			while('\0'!=*s&&'0'==*s){
				++num;
				++s;
			}
			if(k==num){
				moveKToLeft(s,k,i);	
			}
		}else{
			++s;
		}
	}
}
int main(){
//	char s[]="A000b";
//	char s[]="A0-00b";
	char s[]="A0000b000";
	int k=3;
	func(s,k);
	cout<<"s:"<<s<<endl;
	return 0;

}
