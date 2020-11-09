///
/// @file    poke.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-04 14:42:49
///

#include <bits/stdc++.h>
using namespace std;
bool IsContinuous( vector<int> numbers ) {
	int len=numbers.size();
	if(0==len) return false;
	int kingNum(0);
	int gapNum(0);
	sort(numbers.begin(),numbers.end());
	int i=0;
	while(i<len&&0==numbers[i]){
		kingNum++;
		i++;
	}
	cout<<"kingNum:"<<kingNum<<endl;
	while(i<len){
		if(i>0&&numbers[i]==numbers[i-1]){
			return false;
		}
		if(i>0)
			gapNum+=numbers[i]-numbers[i-1]-1;
		i++;
	}
	cout<<"gapNum:"<<gapNum<<endl;

	if(kingNum==gapNum) return true;
	return false;
}
int main(){
	vector<int> v={0,3,2,6,4,5};
//	vector<int> v={0,0,1,2,5};
//	vector<int> v={1,2,3,4,5};
	bool flag=IsContinuous(v);
	cout<<"flag:"<<flag<<endl;
	return 0;
}
