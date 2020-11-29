 ///
 /// @file    mergesort.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-05 16:40:10
 ///
 
#include <bits/stdc++.h>
using namespace std;

void my_copy(const vector<int>&src,vector<int>&dest,int left1,int right1,int left2){
	while(left1<=right1){
		dest[left2++]=src[left1++];
	}
}
void my_merge(vector<int>&v,int left1,int right1,int left2,int right2){
	vector<int> buf(right2-left1+1,0);
//	vector<int> buf(right1-left1+right2-left2+2,0);
	int index=0;
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
//	std::copy(buf.begin(),buf.begin()+index,v.begin()+left1);
//fatal error:	
	my_copy(buf,v,0,buf.size(),left1);
//	my_copy(buf.begin(),buf.end(),v.begin()+left1);
}


void mergesort(vector<int>&v,int leftIndex, int rightIndex){
	if(leftIndex>=rightIndex) return ;//one element, sorted naturally
	 int mid=leftIndex+((rightIndex-leftIndex)>>1)/2;
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


