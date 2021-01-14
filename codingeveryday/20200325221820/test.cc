///
/// @file    test.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-25 22:18:59
///

#include <iostream>
using std::cout;
using std::endl;
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int K;
	cin>>K;

	forward_list<int> fl;
	int N=7;
	for(int i=N;i>0;--i){
		fl.push_front(i);
	}
	int i=0;
	auto it=fl.begin();
	auto it1=fl.begin();
	while(i<K){
		it++;
	}
	while(it!=fl.end()){
		it++;
		it1++;
	}
	cout<<*it1<<endl;
	return 0;
}
