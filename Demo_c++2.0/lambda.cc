 ///
 /// @file    lambda.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 15:07:52
 ///
 
#include <iostream>
#include <functional>
#include <vector>
using namespace std;
using std::cout;
using std::endl;
int test(int x){
	std::function<int(int,int)> f=[](int a,int b)->int{return a+b;};
	cout<<f(x,11)<<endl;
	return 0;

}
auto g_Lambda = [](int i, int j) { return i + j;}; 

int main()
{
	vector<int> v{11,22,5,2,1,4,3};
	sort(v.begin(),v.end());
	for(auto e:v)
		cout<<e<<",";

	cout<<endl;
	std::function<int(int, int)> f = g_Lambda;
	cout<<f(2,3)<<endl;

	auto f1=std::bind(test,10);	
	f1();
	return 0;
}
