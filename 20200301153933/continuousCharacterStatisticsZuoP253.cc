 ///
 /// @file    continuousCharacterStatistics.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-01 17:14:32
 ///
 
#include <bits/stdc++.h>
using namespace std;
void func(string&s,string&res){
	size_t len=s.size();
	cout<<"len:"<<len<<endl;
	size_t left=0;
	size_t right=0;
	while(right<len){
		if(s[left]==s[right]){
			++right;
		}else{
			res.push_back(s[left]);
			res.push_back('_');
			res+=to_string(right-left);
			res.push_back('_');
			left=right;
			++right;
		}
	}
	res.push_back(s[left]);
	res.push_back('_');
	res+=to_string(right-left);
}
int err_no=0;
char func1(string&s,int index){
	size_t len=s.size();
	if(0==len){
		err_no=-1;	
		return 0;
	}
	cout<<"len:"<<len<<endl;
	size_t right=0;
	char a;
	int total=0;
	while(right<len){
		a=s[right];
		int num=0;
		++right;//
		++right;//到达数字
		while(right<len && s[right]>='0' && s[right]<='9'){
			num=num*10+(s[right]-'0');
			++right;
		}
			++right;//到达字母
		cout<<num<<endl;
		total+=num;
		if(total>=index)
		{
			cout<<"total:"<<total<<endl;
			cout<<"err_no:"<<err_no<<",total:"<<total<<endl;
			return a;
		}
	}
	err_no=-1;	
	cout<<"err_no:"<<err_no<<",total:"<<total<<endl;
	return a;
			
}
int main(){
	string str("aaaaaaabccc111111123abcabc");	
	string res;
	func(str,res);

	cout<<"res:"<<res<<endl;
	cout<<"char:"<<func1(res,18)<<endl;
	cout<<"err_no:"<<err_no<<endl;
	return 0;
}
