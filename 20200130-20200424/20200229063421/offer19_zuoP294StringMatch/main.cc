 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 20:13:53
 ///
 
#include <bits/stdc++.h>
using namespace std;
int err_no=0;
bool isValid(const char *str, const char *pattern){
	if(NULL==str||NULL==pattern){
		err_no=-1;
		return false;	
	}
	while('\0'!=*str){
		if('*'==*str||'.'==*str)
			return false;
		++str;
	}
	const char * pLeft=pattern;	
	while('\0'!=*pattern){
		if('*'==*pattern){
			if('\0'!=*(pattern+1)&&'*'==*(pattern+1)){
				return false;
			}
			if(pLeft==pattern)
				return false;
		}
		++pattern;
	}
	return true;
}
bool __stringMatch(const char* str,const char *pattern){
	if('\0'==*str){
		if('\0'!=*pattern)
			return false;
		else 
			return true;
	}
	if('\0'==*pattern)
		return false;


	if('\0'!=*pattern && (*str==*pattern||'.'==*pattern) &&'\0'!=*(pattern+1) && '*'==*(pattern+1)){
		return __stringMatch(str+1,pattern)/*表示>1*/ ||__stringMatch(str,pattern+2)/*表示等于0*/||__stringMatch(str+1,pattern+2);//*表示等于1
	}else if('\0'!=*pattern && ('.'==*pattern ||*str==*pattern)){
		return __stringMatch(str+1,pattern+1);//
	} else if('\0'!=*(pattern+1) && '*'==*(pattern+1)){
		return __stringMatch(str,pattern+2);	//*表示等于0
	}else 
		return false;

}
bool stringMatch(const char* str,const char *pattern){
	if(!isValid(str,pattern)){
		err_no=-1;
		return false;	
	}
	if(0==strlen(str)||0==strlen(pattern)){
		if(0==strlen(str)&&0==strlen(pattern))
			return true;
		else
			return false;
	}
	return __stringMatch(str,pattern);	
}

int main(){
	const char *str="heeeellfafasdo wodrdall";
	const char *pattern="he*ll.*o wo.rda*l*";
//	const char *str="";
//  const char *pattern="";
	cout<<"bool:"<<stringMatch(str,pattern)<<endl;
	cout<<"err_no:"<<err_no<<endl;
	return 0;
}
