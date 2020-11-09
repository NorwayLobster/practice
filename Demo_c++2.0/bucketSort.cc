 ///
 /// @file    bucketSort.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-05 16:57:48
 ///
 
#include <bits/stdc++.h>
using namespace std;
//elements distribution: 0~9
void bucketsort(vector<int>&v){
	int len=v.size();
	if(!len) return ;
	vector<int> v_of_buckets(len,0);
	for(int i=0;i<(int)v.size();++i){
		v_of_buckets[v[i]]++;
	}
#ifdef debug
	for(auto e:v_of_buckets)
		cout<<e<<',';
	cout<<endl;
#endif

	int j=0;//index
	for(int i=0;i<(int)v_of_buckets.size();++i){
		while(v_of_buckets[i]--){
			v[j++]=i;
		}
	}
}

//time complexity: O(n), space complexity: O(n), stable
int main(){
	vector<int> v={9,3,3,2,4,2,0,1,0,4,8};
//	vector<int> v={0,1,0,4,8};
//way1:stl	stable_sort(v.begin(),v.end());
//way2:bucket sort	
	for(auto e:v)
		cout<<e<<',';
	cout<<endl;

	bucketsort(v);

	for(auto e:v)
		cout<<e<<',';
	cout<<endl;
	return 0;
}


