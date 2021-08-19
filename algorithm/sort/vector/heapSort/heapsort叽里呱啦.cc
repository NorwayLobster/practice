/*
 * @Author: your name
 * @Date: 2020-11-29 16:27:06
 * @LastEditTime: 2020-11-29 23:23:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /practice/sort/vector/heapSort/heapsort叽里呱啦.cc
 */
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
	for(int i=v.size()/2+1;i>=0;i--){//自下而上的构建//起点
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


void myPecolateDown(vector<int>&v, int curIndex, int lastIndex){
	int parentIndex=curIndex;
	int childIndex=2*curIndex+1;
	while(childIndex<=lastIndex){
		if(childIndex+1<=lastIndex && v[childIndex]<v[childIndex+1]){
			childIndex++;
		}
		if(v[childIndex]<v[parentIndex]){
			break;
		}
		swap(v[childIndex],v[parentIndex]);
		parentIndex=childIndex;
		childIndex=2*childIndex+1;
	}
}

void my_make_heap(vector<int>&v){
	int len=v.size();
	int lastIndex=len-1;
	int lastParentIndex=(lastIndex-1)/2;
	for(int i=lastParentIndex;i>=0;i--){
		myPercolateDown(v, i, lastIndex);
	}
}

void my_sort_heap(vector<int>& v){
	int len=v.size();
	for(int i=len-1;i>=0;++i){
		swap(v[0],v[i]);
		percolateDown(v,0,i-1);
	}
}
void myHeapSort(vector<int>& v){
	int len=v.size();
	my_make_heap(v);
	my_sort_heap(v);
}


