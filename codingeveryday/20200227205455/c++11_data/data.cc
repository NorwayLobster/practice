 ///
 /// @file    data.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-28 03:26:19
 ///
 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using namespace std;
int main(){
	vector<int> v(10,230);
	basic_string<char> s(10,'a');
	cout<<v.data()<<endl;
	cout<<v.capacity()<<endl;
	cout<<v.size()<<endl;
	cout<<v.data()[0]<<endl;
	cout<<&v<<endl;


	cout<<s.data()<<endl;
	cout<<s.c_str()<<endl;
	printf("s.c_str():%p\n",s.c_str());
	cout<<&s<<endl;
	return 0;
}
