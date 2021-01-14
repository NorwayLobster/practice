///
/// @file    reverseString.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-03 12:53:10
///

#include <bits/stdc++.h>
using namespace std;
void myReverse(string &str,int left,int right){
	if(left>=right) return ;
	while(left<right){
		swap(str[left++],str[right--]);
	}
}
string ReverseSentence(string str) {
	if(0==str.size()) return str;
	cout<<"str:"<<str<<endl;
	int left(0),right(0);
	while(right<str.size()){
		if(' '==str[right]){
			myReverse(str,left,right-1);
			while(right<str.size()&&' '==str[right]){
				right++;
			}
			left=right;
		}
		right++;
	}
	if(right==str.size()&&' '!=str[right-1])
		myReverse(str,left,right-1);
	cout<<"str:"<<str<<endl;
	myReverse(str,0,str.size()-1);
	cout<<"str:"<<str<<endl;
	return str;
}
int main(){
	string str("  hello world");
	string newStr=ReverseSentence(str);
	cout<<newStr<<endl;
	return 0;
}
	
