 ///
 /// @file    twoStringMinDistanceInStringArrayZuoP266.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 20:11:48
 /// complete: Tue Mar  3 21:55:08 CST 2020
//1h 40min
#include <bits/stdc++.h>
using  namespace std;

int twoStringMinDistanceInStringArray(vector<string>&arr, const string &s1,const string&s2){
	if(s1==s2) return 0;
	int lastS1Index=-1;
	int lastS2Index=-1;
	int len=arr.size();
	int minDistance=INT_MAX;
	for(int i=0;i<len;++i){
		//cout<<arr[i]<<" ";
		if(s1==arr[i]){
			lastS1Index=i;
			minDistance=min(minDistance, lastS2Index==-1?INT_MAX:lastS1Index-lastS2Index);
		}
		if(s2==arr[i]){
			lastS2Index=i;
			minDistance=min(minDistance, lastS1Index==-1?INT_MAX:lastS2Index-lastS1Index);
		}
	}
	return minDistance==INT_MAX?-1:minDistance;
}


void buildMapofMap(unordered_map<string,unordered_map<string,int>>& _map,vector<string>& arr){
	for(int i=0;i<(int)arr.size();++i){
		for(int j=0;j<(int)arr.size();++j){
			if(arr[i]==arr[j]) continue;
			if(_map.end()!=_map.find(arr[i])){
				if(_map[arr[i]].end()!=_map[arr[i]].find(arr[j])){
					continue;
				}
			}
			if(_map.end()!=_map.find(arr[j])){
		//		unordered_map<string,int>::iterator iter;
				if(_map[arr[j]].end()!=_map[arr[i]].find(arr[i])){
					_map[arr[i]].insert(make_pair(arr[j],_map[arr[j]][arr[i]]));
//					_map.insert(make_pair(arr[i],make_pair(arr[j],_map[arr[j]][arr[i]])));
				}else{
					_map[arr[i]].insert(make_pair(arr[j],twoStringMinDistanceInStringArray(arr,arr[j],arr[i])));
				}
			}else{
					unordered_map<string,int> tmp;
					tmp.insert(make_pair(arr[j],twoStringMinDistanceInStringArray(arr,arr[j],arr[i])));
					_map.insert(make_pair(arr[i],std::move(tmp)));
//error:			_map.insert(unordered_map<string,int> (make_pair(arr[j],twoStringMinDistanceInStringArray(arr,arr[j],arr[i]))));
//error:			_map.insert(make_pair(arr[i],make_pair(arr[j],twoStringMinDistanceInStringArray(arr,arr[j],arr[i]))));
			}
		}
	}
}
int _search(unordered_map<string,unordered_map<string,int>>& _map, const string&s1,const string &s2){
			if(s2==s1) return  0;
			if(_map.end()!=_map.find(s1)){
				if(_map[s1].end()!=_map[s1].find(s2)){
					return _map[s1][s2];
				}
			}
			return -1;
}

int main(){
	vector<string> arr={"hello","2","world","1","4","2","3","1","hello","world","1","3"};
#if 0
1: _map = std::unordered_map with 6 elements = {
	   ["3"] = std::unordered_map with 0 elements, 
	   ["4"] = std::unordered_map with 1 elements = {["3"] = 2}, 
	   ["hello"] = std::unordered_map with 5 elements = {["2"] = 1, ["world"] = 1, ["1"] = 1, ["3"] = 2, ["4"] = 4}, 
	   ["2"] = std::unordered_map with 4 elements = {["3"] = 1, ["4"] = 1, ["1"] = 2, ["world"] = 1}, 
	   ["world"] = std::unordered_map with 3 elements = {["3"] = 2, ["4"] = 2, ["1"] = 1}, 
	   ["1"] = std::unordered_map with 2 elements = {["3"] = 1, ["4"] = 1}}
#endif
	unordered_map<string,unordered_map<string,int>> _map;
//	for(auto &s:arr)
//		cout<<s<<" ";
	cout<<endl;
//1.v1
	cout<<twoStringMinDistanceInStringArray(arr,"hello","3")<<endl;

//1.v2
	buildMapofMap(_map,arr);
	cout<<_map["hello"]["3"]<<endl;
	cout<<_search(_map,"hello","world")<<endl;
	cout<<twoStringMinDistanceInStringArray(arr,"hello","world")<<endl;
	cout<<_search(_map,"hello","hello")<<endl;
	cout<<twoStringMinDistanceInStringArray(arr,"hello","hello")<<endl;
	cout<<_search(_map,"1","2")<<endl;
	cout<<twoStringMinDistanceInStringArray(arr,"1","2")<<endl;

	cout<<endl;
	return 0;
}
