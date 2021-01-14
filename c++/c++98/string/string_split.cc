 ///
 /// @file    string_split.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-12-14 10:23:21
 ///
 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
void split(string& s, vector<string>& v){
	std::istringstream iss(s);
	string word;
	while(std::getline(iss,word,',')){
		v.push_back(word);
	}
    v[0].erase(v[0].begin());//delete '['
}
int main(){
	vector<string> res;
	string s("[hello,world]");
	s.pop_back();//pop ]
	split(s,res);
	for(auto e:res){
		cout<<e<<endl;
	}
	return 0;
}
