 ///
 /// @file    offer58_reverseString.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 04:59:12
 ///
 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void myreverse(char * str){
	char * pLeft=str;
	char *pRight=str+strlen(str)-1;
	char tmp;
	while(pLeft<pRight){
		tmp=*pLeft;
//		cout<<"tmp:"<<tmp<<endl;
		*pLeft=*pRight;
		*pRight=tmp;
		++pLeft;
		--pRight;
	}
}
int reverseLeftN(char *str,int n){
	if(NULL==str)
		return -1;
	if(n<0||n>strlen(str))
		return -1;
	if(0==n||n==strlen(str))
		return 0;
	char *pLeft=str;
	char *pRight=str+n;
	char tmp=*pRight;
	*pRight='\0';
	myreverse(str);
	*pRight=tmp;
	myreverse(pRight);
	myreverse(str);
	return 0;
}
int reverseSentence(char *str){
	if(NULL==str)
		return -1;
	char * pLeft=str;
	char * pRight=str;
	while('\0'!=*pRight){
		while('\0'!=*pRight && ' '!=*pRight){
			++pRight;
		}
		if('\0'==*pRight)
			break;
		*pRight='\0';	
		myreverse(pLeft);
		*pRight=' ';	
		while('\0'!=*pRight && ' '==*pRight){
			++pRight;
		}
		pLeft=pRight;
	}
	myreverse(pLeft);
	myreverse(str);
	return 0;
}
int main(){
	char a[]="   hello    world.   ni hao  cheng wang! ";
	char b[]="abcdefg";
//	myreverse(a);
	reverseSentence(a);
	cout<<a<<endl;
	int n;
	cin>>n;
	reverseLeftN(b,n);
	cout<<b<<endl;
	return 0;
}
