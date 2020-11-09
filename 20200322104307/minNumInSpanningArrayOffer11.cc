 ///
 /// @file    minNumInSpanningArrayOffer11.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-22 18:01:48
 ///
 
#include <bits/stdc++.h>
using namespace std;
int minNumInArray(int start,int end,vector<int>&v){
	int i=start;
	int MIN=v[start];
	while(i<end){
		if(v[i]<MIN){
			MIN=v[i];
		}
		i++;
	}
	return MIN;
}

int minNumInSpanningArray(vector<int>&v){

	int len=v.size();
	if(0==len){
		cout<<"invalid cin"<<endl;
		return -1;
	}
	int index1=0;
	int index2=len-1;
	int indexMid=index1;
	while(v[index1]>=v[index2]){
		if(1==index2-index1){
			indexMid=index2;
			break;
		}
		indexMid=(index1+index2)>>1;		
		if(v[indexMid]==v[index1]&&v[indexMid]==v[index2]){
			return minNumInArray(index1,index2,v);
		}

		if(v[indexMid]>=v[index1]){
			index1=indexMid;
		}else{
			index2=indexMid;
		}
	}
	return v[indexMid];

}

int main(){
//	vector<int> v={1,2,3,4,5};	
//	vector<int> v={2,3,4,5,-3,-2,-1,0};	//升序
//	vector<int> v={2,2,2,2,-3,-2,-1,2};	//升序
//	vector<int> v={1,2,2,2,2,2,-3,-2,-1,1};	//升序
	vector<int> v;
	cout<<"min:"<<minNumInSpanningArray(v)<<endl;
	return 0;
}
