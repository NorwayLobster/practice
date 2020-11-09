///
/// @file    minStack.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-26 13:42:56
///

//6
//push 3
//push 2
//push 1
//getMin
//pop
//getMin
#include<bits/stdc++.h>
using namespace std;
class MinStack{
	public:
		MinStack(){}
		~MinStack(){}
		void push(long long num){
			_s.push(num);
			if(_minS.empty())
				_minS.push(num);
			else
				_minS.push(min(_minS.top(),num));
		}
		void pop(){
			_minS.pop();
			_s.pop();
		}
		long long int getMin(){
			return _minS.top();
		}
	private:
		stack<long long int> _s;
		stack<long long int> _minS;
};
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	long long int N;
	cin>>N;
	cin.ignore();
//	cin.clear()
	string temp;
//	getline(cin,temp);
//  N=stoll(temp);
	long long int num;
	string str1;
	stringstream ss;
	MinStack minStack;
	for(long long int i=0;i<N;++i){
		getline(cin,temp);
//		cin>>temp;
		ss<<temp<<endl;
		ss>>str1>>num;
		cout<<"str1:"<<str1<<endl;
		cout<<"num:"<<num<<endl;
		if("push"==str1)
			minStack.push(num);
		else if("pop"==str1)
			minStack.pop();
		else if("getMin"==str1)
			cout<<minStack.getMin()<<endl;
		ss.clear();
	}
	return 0;
}
