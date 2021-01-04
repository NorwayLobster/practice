 ///
 /// @file    decltype.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 14:30:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(){
	int x,y;
	x=10;
	y=1;
	decltype(x+y) c=x+y;
	cout<<c<<endl;
	return 0;
}
