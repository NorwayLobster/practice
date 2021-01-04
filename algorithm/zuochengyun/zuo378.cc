///
/// @file    zuo378.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-24 11:25:53
///
//not debug and test 
#include<bits/stdc++.h>
using namespace std;
int handle(vector<int>&v){
	int len=v.size();
	unordered_map<int,int> hash;
	int MaxLen=0;
	for(int i=0;i<len;++i){
		int min=INT_MAX;
		int max=INT_MIN;

		for(int j=i+1;j<len;++j){
			if(hash.end()!=hash.find(v[j]))
				break;
			if(v[j]<min) min=v[j];
			if(v[j]>max) max=v[j];
			hash[v[j]]=1;
			if(max-min==j-i&&j-i>MaxLen){
				MaxLen=j-i;
			}
		}
		hash.clear();
	}
	return MaxLen;
}
int main(){

	int N;
	scanf("%d",&N);
	vector<int> v(N);
	int tmp;
	for(int i=0;i<N;i++){
		scanf("%d",&tmp);
		v[i]=tmp;
	}
	return handle(v);
}
