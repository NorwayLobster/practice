 ///
 /// @file    minUnorderedSequence.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-16 12:01:43
 ///
 
#include <bits/stdc++.h>
using namespace std;
int minUnorderedSequence(vector<int> &v){
	int len=v.size();
	if(0==len) return -1;
	int Min=v[0];
	int Max=v[len-1];
	int noUnorderdIndexMin=-1;
	int noUnorderdIndexMax=-1;
	for(int i=0;i<len;++i){
		if(v[i]>Max){
			noUnorderdIndexMax=i;	
		}
		Max=max(Max,v[i]);
	}

	for(int i=len-1;i>-1;--i){
		if(v[i]<Min){
			noUnorderdIndexMin=i;	
		}
		Min=std::min(Min,v[i]);
	}
	if(noUnorderdIndexMax==-1) 
		return noUnorderdIndexMax;
	if(noUnorderdIndexMin==-1) 
		return noUnorderdIndexMin;
	return std::abs(noUnorderdIndexMax-noUnorderdIndexMin);
}
int main(){
	vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(2);
	v.push_back(28);
	for(auto e:v){
		cout<<e<<" ";
	}
	cout<<endl;
	cout<<"len:"<<minUnorderedSequence(v);
	cout<<endl;
	return 0;
}
