 ///
 /// @file    bruteForce.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-02 01:27:26
 ///
 
#include <bits/stdc++.h>
using namespace std;
const char * bf(const char*str,const char *pattern){
	const char *pLeft;
	const char *pLeftPattern;
	while('\0'!=*str){
		if(*str==*pattern){
			pLeft=str;
			pLeftPattern=pattern;
			while('\0'!=*str && '\0'!=*pattern && *str==*pattern){
				++str;
				++pattern;
			}
			if('\0'==*pattern){
				return pLeft;
			}else{
				str=pLeft;	
				pattern=pLeftPattern;
			}
		}
		++str;
	}
	return (const char*)-1;
}
//dengjunhui v1
int bf_v1(const char*str,const char *pattern){
	size_t len1=strlen(str),i=0;
	size_t len2=strlen(pattern),j=0;
	while(i<len1 && j<len2){
		if(str[i]==pattern[j]){
				++i;
				++j;
		}else{
			i=i-j+1;
			j=0;
		}
	}
	return i-j;// i-j=len1 fail ,  i-j<=len1-len2, success
}
//dengjunhui v2
int bf_v2(const char*str,const char *pattern){
	size_t len1=strlen(str),i=0;
	size_t len2=strlen(pattern),j=0;
	for(;i<len1-len2+1;++i){
		for(;j<len2;++j){
			if(str[i+j]!=pattern[j]){
				break;
			}
		}
		if(j>=len2) break;
	}
	return i;// i=len1 fail ,  i<=len1-len2, success
}
int main() {
	const char *str="abfcde";
	const char *pattern="cde";
	cout<<"start:"<<bf(str,pattern);
	cout<<endl;
	cout<<"start:"<<bf_v1(str,pattern);
	cout<<"start:"<<bf_v2(str,pattern);
	cout<<endl;
	return 0;
}
