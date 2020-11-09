 ///
 /// @file    str.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 01:19:19
 ///
 
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;
int main(){
	cout<<	sizeof("hell");
	cout<<endl;	
	int a=0;
	sscanf("","%d",&a);
	printf("a:%d\n",a);

	return 0;
}
