 ///
 /// @file    simpleExpress.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-08-17 20:53:24
 ///
 
#include <iostream>
using namespace std;
int main(){
	long long int a,b;
	char c;
	scanf("%lld %c %lld",&a,&c,&b);
	switch(c){
		case '+':cout<<a+b<<endl;break;
		case '-':cout<<a-b<<endl;break;
		case '*':cout<<a*b<<endl;break;
	}
	return 0;
}
