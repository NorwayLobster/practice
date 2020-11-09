 ///
 /// @file    findKInSortedArray.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-15 20:58:21
 ///complete: Mar 15 21:06:49 CST 2020
 //8min
 //
#include <bits/stdc++.h>
using namespace std;
bool findKInSortedArray(vector<vector<int>> &v,int K){
	int len1=v.size();
	if(len1==0) return false;

	int len2;
	len2=v[0].size();
	int i=0;
	int j=len2-1;
	while(i<len1&&j>-1){
		if(v[i][j]>K){
			j--;
		}else if(v[i][j]<K){
			i++;
		}else{
			return true;
		}
	}
	return false;
}
int main(){
	vector<vector<int>> v(5,vector<int>(6,0));
	int len1=v.size();
	if(len1==0) return 0;
	int len2=v[0].size();
	int k=10;
	for(int i=0;i<len1;++i){
		for(int j=0;j<len2;++j){
			v[i][j]=k;
			cout<<v[i][j]<<" ";
			++k;
		}
		cout<<endl;
	}
	int K=35;
	cout<<"bool:"<<findKInSortedArray(v,K)<<endl;
	return 0;

}
