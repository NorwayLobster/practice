 ///
 /// @file    partition.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-23 17:56:15
 ///
 
#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v){
	int left=0;
	int boundaryIndex=0;
	int len=v.size();
	int right=len-1;
	cout<<"len:"<<len<<endl;
	srand(time(NULL));
	int randIndex=left+std::rand()%(right-left);
//	int randIndex1=left+std::rand()*1.0/RAND_MAX*(right-left);
	cout<<"randIndex:"<<randIndex<<endl;
	swap(v[left],v[randIndex]);
//	cout<<"randIndex1:"<<randIndex1<<endl;
	int pivot=v[left];	
	for(int cur=left+1;cur<=right;cur++){
		if(v[cur]<pivot){
			++boundaryIndex;
			swap(v[boundaryIndex],v[cur]);
		}
	}
	swap(v[boundaryIndex],v[left]);
	return boundaryIndex;
}
int main(){
	vector<int> v={132,43,24,23,432,53,234,53};
	for(auto e:v)
		cout<<e<<' ';
	cout<<endl;

	int pivotIndex=Partition(v);
	cout<<"pivotIndex:"<<pivotIndex<<endl;
	cout<<"pivot:"<<v[pivotIndex]<<endl;
	for(auto e:v)
		cout<<e<<' ';
	cout<<endl;
	return 0;
}
