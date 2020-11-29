 ///
 /// @file    max_element.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-26 12:10:41
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
int main(){

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	unordered_map<string,int> hash;
	hash["hello"]=3;
	hash["zello1"]=20;
	hash["hello3"]=3;
	auto it=max_element(v.begin(),v.end());
	unordered_map<string,int>::iterator it1=max_element(hash.begin(),hash.end(),[](const pair<string,int>&lhs,const pair<string,int>&rhs)->bool{return lhs.second<rhs.second;});
	cout<<"max:"<<it1->first<<","<<it1->second<<endl;
//	cout<<"max:"<<*it1<<endl;
	return 0;
}
