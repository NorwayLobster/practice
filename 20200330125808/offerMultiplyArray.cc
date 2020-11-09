///
/// @file    offerMultiplyArray.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-31 00:19:17
///

#include <bits/stdc++.h>
using namespace std;
vector<int> multiply(const vector<int>& A) {
	vector<int> res;
	if(0==A.size()) return res;
	if(1==A.size()) return vector<int>(1,1);
	int len=A.size();
	vector<int> left(len,1);
	vector<int> right(len,1);
	int i=1;
	while(i<len){
		left[i]=left[i-1]*A[i-1];
		i++;
	}
	i=len-2;
	while(i>-1){
		right[i]=left[i+1]*A[i+1];
		i--;
	}
	for(int i=0;i<len;++i){
		res.push_back(left[i]*right[i]);
	}
	return res;
}
int main(){
	vector<int> v={1,2,3,4,5};
	vector<int> res=multiply(v);
	for(auto e:res)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}
