///
/// @file    zuoP412.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-24 18:24:44
///
//not debug and test
#include<bits/stdc++.h>
using namespace std;
#if 0 //error:
void handle(vector<int>&v){
	int len=v.size();
	if(len<3) return ;
	int j=2;
	//   for(int i=1;i<=(len+1)>>1;++i){
	for(int i=1;i<len;++i){
		if(v[i]<=v[i-1]){
			int j=i+1;
			while(j<len&&v[j]<=v[i-1]){
				j++;
			}
			if(j==len) break;
			swap(v[i],v[j]);
		}
	}
}
#endif
void handle(vector<int>&v){
	int len=v.size();
	if(len<3) return ;
	int i=0;
	//   for(int i=1;i<=(len+1)>>1;++i){
	for(int j=1;j<len;++j){
		if(v[i]!=v[j]){
			swap(v[++i],v[j]);
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	vector<int> v;
	int tmp;
	for(int i=0;i<N;++i){
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	handle(v);
}
