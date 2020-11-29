/*
 * @Author: your name
 * @Date: 2020-05-05 17:55:15
 * @LastEditTime: 2020-11-29 22:09:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /practice/sort/vector/mergeSort 分治思想 stl中的merge()/mergesort叽里呱啦.cc
 */
 ///
 /// @file    mergesort.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-05 16:40:10
 ///
 
#include <vector>
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

void my_copy(const vector<int>&src,vector<int>&dest,int left1,int right1,int left2){
	while(left1<right1){
		dest[left2++]=src[left1++];
	}
}
void my_merge(vector<int>&v,int left1,int right1,int left2,int right2){
	vector<int> buf(right2-left1+1,0);//space complexity, O(M)
//	vector<int> buf(right1-left1+right2-left2+2,0);
	int index=0;
	int originalLeft1=left1;
	while(left1<=right1&&left2<=right2){
		if(v[left1]<v[left2])	
			buf[index++]=v[left1++];
		else 
			buf[index++]=v[left2++];
	}
	
#if 0
	cout<<endl<<endl;
	for(int i=left1;i<=right2;++i)
		cout<<v[i]<<',';
	cout<<endl;
	for(int j=0;j<=index;++j)
		cout<<buf[j]<<',';
	cout<<endl;


	for(int i=left1;i<=right2;++i)
		cout<<v[i]<<',';
	cout<<endl<<endl;
#endif
	while(left1<=right1){ buf[index++]=v[left1++]; }
	while(left2<=right2){ buf[index++]=v[left2++]; }
//fatal error:	
	// my_copy(buf,v,0,buf.size(),left1);//left1 is error
	my_copy(buf,v,0,buf.size(),originalLeft1);
}


void mergesort(vector<int>&v,int leftIndex, int rightIndex){
	if(leftIndex==rightIndex) return ;//one element, sorted naturally
	 int mid=leftIndex+(rightIndex-leftIndex)/2;
	//  int mid=leftIndex+((rightIndex-leftIndex)>>1)/2;//不实用
	 mergesort(v,leftIndex,mid);
	 mergesort(v,mid+1,rightIndex);
//	 std::merge(v,...)
	 my_merge(v,leftIndex,mid,mid+1,rightIndex);
}

//time complexity: O(nlogn), space complexity: O(n), stable
int main(){
	vector<int> v={23,32,23,432,0,1,0,4,8};
//	vector<int> v={0,1,0,4,8};
//way1:stl	stable_sort(v.begin(),v.end());
//way2:merge sort	
	mergesort(v,0,v.size()-1);
	for(auto e:v)
		cout<<e<<',';
	cout<<endl;
	return 0;
}


