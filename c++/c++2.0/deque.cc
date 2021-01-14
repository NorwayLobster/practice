 ///
 /// @file    deque.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-12 19:37:47
 ///
 

#include <bits/stdc++.h>
using namespace std;
int main(){
	deque<int> q;	
	q.push_back(10);
	q.push_back(100);
	cout<<q[0]<<endl;
	cout<<q[1]<<endl;
	q[1]=1111;
	q[2]=100011;
	cout<<q[1]<<endl;
	cout<<q[2]<<endl;
	return 0;
}
