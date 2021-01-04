 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-09-12 16:49:59
 ///
 
#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;

class cat{
public:
	string name; 
public:
	cat(string n){
		name=n;
	}
		
};

using namespace std;

int main(){
	cat c("chengwang");
	cout<<c.name<<endl;
	return 0;
}
