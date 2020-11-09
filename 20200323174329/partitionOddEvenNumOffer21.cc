 ///
 /// @file    partitionOddEvenNumOffer21.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-23 22:25:42
 ///complete: Mon Mar 23 22:59:49 CST 2020

#include <bits/stdc++.h>
using namespace std;
bool compare(int cur){
	return cur&0x1;
}

int partition(vector<int> &v){
	int len=v.size();
	if(0==len) return -1;
	int left=0;
	int right=len-1;
//	int pivot=v[left];
	int boundaryIndex=left;
	for(int cur=left;cur<=right;++cur){
		cout<<"cur:"<<v[cur]<<endl;
		cout<<"bool:"<<(cur&0x1)<<endl;
//		cout<<"odd:"<<compare(cur)<<endl;
#if 1
		if(compare(v[cur])){//left: odd
			cout<<"odd:"<<v[cur]<<endl;
			swap(v[boundaryIndex],v[cur]);
			boundaryIndex++;	
		}
#endif
	}
	return boundaryIndex;
}

int main(){
//	vector<int> v={1,23,4,5,5,66,6,6};
//	vector<int> v={1,23,4,5,5};
//	vector<int> v={1,23,5,5};
	vector<int> v;
	for(auto e:v)
		cout<<e<<' ';
	cout<<endl;

	int a=partition(v);
	cout<<"boundaryIndex:"<<a<<endl;
	for(auto e:v)
		cout<<e<<' ';
	cout<<endl;
	return 0;
}
