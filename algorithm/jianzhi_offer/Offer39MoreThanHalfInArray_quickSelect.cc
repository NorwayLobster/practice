 ///
 /// @file    Offer39MoreThanHalfInArray.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-23 23:13:01
 ///
 
#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int left,int right){
	if(left==right) return left;
	int boundaryIndex=left;
	int pivot=v[left];
	for(int cur=left+1;cur<=right;++cur){
		if(v[cur]<pivot){
			boundaryIndex++;
			swap(v[boundaryIndex],v[cur]);
		}
	}
	swap(v[boundaryIndex],v[left]);
	return boundaryIndex;
}

int quickSelectionKth(vector<int>&v,int k){
	int left=0;
	int len=v.size();
	if(k>len) return -1;
	k=k-1;
	cout<<"len:"<<len<<endl;
	int right=len-1;
		
	while(left<=right){
		int pivotIndex=partition(v,left,right);
		if(pivotIndex<k){
			left=pivotIndex+1;
		}else if(pivotIndex>k){
			right=pivotIndex-1;
		}else{
			return v[pivotIndex];
		}
	}
	return -1;
}
int main(){
	vector<int> v={1,32,432,42,43,1,1,1,1,1};
//	vector<int> v={1,32,432,42,43};
	int len=v.size();
	int middle;
	if(len&0x1)
		middle=v.size()/2+1;
	else
		middle=v.size()/2;
	cout<<"middle:"<<middle<<endl;
	int retval=quickSelectionKth(v,middle);
	cout<<"ret:"<<retval<<endl;
	for(auto e:v){
		cout<<e<<" ";
	}
	cout<<endl;
	return 0;
}
