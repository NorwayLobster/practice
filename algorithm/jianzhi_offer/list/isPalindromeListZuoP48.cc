 ///
 /// @file    isPalindromeList.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-08 23:48:43
 ///
 
#include <bits/stdc++.h>
using namespace std;

bool isPalindromeList(forward_list<int> &sigleList){
	cout<<"empty():"<<sigleList.empty()<<endl;
	if(sigleList.empty()) return false;	
//	int N=0;
//	for(auto ite=sigleList.begin();ite!=sigleList.end();++ite){ ++N; }
//	cout<<"N:"<<N<<endl;

//way1: stack, 装前半段， 与后半段比较	
	
//way2: 逆向后半段
	int len=distance(sigleList.begin(),sigleList.end());	
	cout<<"len:"<<len<<endl;
	auto iteRightHalfStart=sigleList.begin();
	int i=0;
	cout<<ceil(len*1.0/2)<<endl;
	cout<<endl;
	while(i<ceil(len*1.0/2)){
		iteRightHalfStart++;
		++i;
	}
	forward_list<int> sigleListRightHalf(iteRightHalfStart,sigleList.end());
	sigleListRightHalf.reverse();
	auto ite=sigleListRightHalf.begin();
	auto ite1=sigleList.begin();
	while(sigleListRightHalf.end()!=ite){
		if(*ite!=*ite1)
			break;
		ite++;
		ite1++;
	}

	if(sigleListRightHalf.end()!=ite)
		return false;
//error:	for(auto ite1=sigleList.begin(),ite2=sigleList.end();ite1!=ite2;++ite1,--ite2;){ //前向迭代器

	return true;
}
int main(){
	cout<<(5>>1)<<endl;
	cout<<ceil(5.0/2)<<endl;
	cout<<ceil(5/2)<<endl;
	cout<<(4>>1)<<endl;
//	forward_list<int> sigleList(10,0);
	forward_list<int> sigleList;
	int i=0;
	sigleList.push_front(i++);
	sigleList.push_front(i++);
	sigleList.push_front(i++);
	cout<<"i:"<<i<<endl;
	sigleList.push_front(i--);

	sigleList.push_front(i--);
	sigleList.push_front(i--);
	sigleList.push_front(i--);

	sigleList.push_front(i--);
	sigleList.pop_front();
//	sigleList.insert_after(sigleList.end(),100);
//	sigleList.erase_after(sigleList.end(),100);
	
	for(auto &e:sigleList)
		cout<<"e:"<<e<<endl;

	cout<<"isPalindromeList or not:"<<isPalindromeList(sigleList)<<endl;

	cout<<"complete"<<endl;
	return 0;
}
