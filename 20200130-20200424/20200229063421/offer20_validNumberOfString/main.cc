 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 21:42:41
 ///
 
#include <bits/stdc++.h>
using namespace std;
int err_no=0;
bool scanfUnsignedInteger(const char **p){
	int i=0;
	while('\0'!=**p&&**p<='9'&&**p>='0'){
		++*p;
		++i;
	}
	cout<<"p:"<<*p<<endl;
	return  i;
}
bool scanfInteger(const char **p){
	if('+'==**p||'-'==**p)
		++*p;
	cout<<"p:"<<*p<<endl;
	return scanfUnsignedInteger(p);

}
bool isNumeric(const char*p){
	if(NULL==p){
		err_no=-1;
		return false;
	}
	if(0==strlen(p)){
		return false;
	}

	bool numeric=scanfInteger(&p);	//12.--->12.0 合法  
	if('.'==*p){
		++p;
		numeric=scanfUnsignedInteger(&p)||numeric;
	}
	if('e'==*p||'E'==*p){
		++p;
		numeric=scanfInteger(&p)&&numeric;//23e 非法  e12非法
	}

	return numeric&&'\0'==*p;//23e5.3 非法
}

int main(){
//	const char * p="123.4";	//yes
//	const char * p="-123.4e+12.3";	//no
//	const char * p="-123.4e+12";	//yes
//	const char * p="+123.e-12";	//yes
//	const char * p=".123e-12";	//yes
//	const char * p=".123E-12";	//yes
//	const char * p="+1.123E+12";	//yes
//	const char * p="";	//no
//	const char * p="+1.123E";	//no
//	const char * p="e+12";	//no
//	const char * p="123E4";	//yes
	const char * p="123";	//yes
	cout<<"bool:"<<isNumeric(p)<<endl;
	return 0;
}
