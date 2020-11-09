///
/// @file    hash.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-01 00:19:28
///

#include <bits/stdc++.h>
using namespace std; 
int main()
{  
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	std::unordered_map<int,char> map = {{1,'a'},{1,'b'},{1,'d'},{2,'b'}};
	std::unordered_map<int,char> map1 = {{1,'b'},{1,'d'},{2,'b'}};
	if(map==map) cout<<"true"<<endl;
	if(map==map1) 
		cout<<"map1==map:true"<<endl;
	else 
		cout<<"map1==map:false"<<endl;
	cout<<"key:1,value:"<<map[1]<<endl;	
	cout<<"size:"<<map.size()<<endl;
	auto range = map.equal_range(1);
	for_each(map.begin(),map.end(),[](const pair<int,char> & p)->void{ std::cout << p.first << ' ' << p.second << '\n';});
	cout<<endl;
	for (auto it = range.first; it != range.second; ++it) {
		std::cout << it->first << ' ' << it->second << '\n';
	}
}
