//program 20.6.2.cpp unordered_map示例
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
     unordered_map<string,int> turingWinner; //图灵奖获奖名单
	turingWinner.insert(make_pair("Dijkstra",1972));
	turingWinner.insert(make_pair("Scott",1976));
	turingWinner.insert(make_pair("Wilkes",1967));
	turingWinner.insert(make_pair("Hamming",1968));
     turingWinner["Ritchie"] = 1983;
	string name;
	cin >> name; //输入姓名
	unordered_map<string,int>::iterator p = turingWinner.find(name);//据姓名查获奖时间
	if( p != turingWinner.end())
		cout << p->second;
	else
		cout << "Not Found" << endl;
	return 0;
}

