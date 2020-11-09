///
/// @file    zuoMaxSbuarraySum.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-24 20:27:43
///

#include<bits/stdc++.h>
using namespace std;
int handle(vector<int>&v){
	int prefixSumMin=INT_MAX;
	int subarraySumMax=INT_MIN;
	int prefixSum=0;
	int len=v.size();
	for(int i=0;i<len;++i){
		prefixSum=prefixSum+v[i];
		subarraySumMax=max(prefixSum-prefixSumMin,subarraySumMax);
		prefixSumMin=min(prefixSum,prefixSumMin);         
	}
	cout<<subarraySumMax<<endl;
	return 0;
}
int main(){
//	int N;
//	scanf("%d",&N);
//	int tmp;

	vector<int> v= {-2,2,-3,4,-1,2,1,-5,3};
#if 0
	for(int i=0;i<N;++i){
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
#endif
	handle(v);
	return 0;
}
