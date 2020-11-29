 ///
 /// @file    test.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-05 15:45:48
 ///
 
#include <bits/stdc++.h>
using namespace std;
//floyd way, from down to up and percolate Down
void percolateDown(vector<int> &v,int parentIndex,int len){
	int childIndex=2*parentIndex+1;
	while(childIndex<len){
		if(childIndex+1<len&&v[childIndex+1]>v[childIndex]){//pick a bigger child if it exists   
			childIndex++;
		}
		if(v[parentIndex]>=v[childIndex]){
			break;
		}
		swap(v[childIndex],v[parentIndex]);
		parentIndex=childIndex;
		childIndex=childIndex*2+1;
	}
}
//build a max 2 heap
void my_make_heap(vector<int>&v){
	for(int i=v.size()/2+1;i>=0;i--){
		percolateDown(v,i,v.size());
	}
}
//sort it
void my_sort_heap(vector<int>&v){
	for(int i=v.size()-1;i>0;--i){//n-1 pop()
//	for(int i=v.size()-1;i>-1;--i){
		swap(v[i],v[0]);
		percolateDown(v,0,i);//adjust to i-1, len=i
//		percolateDown(v,0,i+1);
	}
}

//time complexity: O(nlogn), space complexity: O(1), not stable
int main(){
//	vector<int> v={23,32,23,432,0,1,0,4,8};
	vector<int> v={0,1,0,4,8};
//way1:stl	stable_sort(v.begin(),v.end());
//way2:heap sort	
//	make_heap(v.begin(),v.end());	
//	sort_heap(v.begin(),v.end());
	my_make_heap(v);
	my_sort_heap(v);

	for(auto e:v)
		cout<<e<<',';
	cout<<endl;
	return 0;
}


