 ///
 /// @file    offer62JosephuseCircleZuoP44.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-08 19:11:40
 ///
 
#include <bits/stdc++.h>
using namespace std;
//way1: 循环链表
int JosephuseCircle(int n,int m){
	if(m<=0||n<=0) return -1;
	list<int> _list(n,0);
	int i=0;
	for(auto &e:_list)
		e=i++;
	auto cur=_list.begin();
	for(int i=0;i<n-1;++i){
		for(int j=0;j<m-1;++j){//抠边界
				cur++;
				if(cur==_list.end())
					cur=_list.begin();
		}
		cout<<"cur:"<<*cur<<endl;
		auto next=++cur;
		_list.erase(--cur);
		if(next==_list.end())
			next=_list.begin();
		cur=next;
	}
	return *cur;
}

//way2: 数组 , 抠边界繁琐
int JosephuseCircle_v2(int n,int m){
	vector<int> v(n,1);
	int len=v.size();
	int i=0;
	int k=0;
	for(int	j=0;j<len-1;++j){
		k=m;
		while(k-1){
			if(0==v[i]){
				i=(i+1)%len;
				continue;
			}
			i=(i+1)%len;
			k--;
		}
		while(0==v[i]){
			i=(i+1)%len;
		}
		v[i]=0;//抠边界，下一个开始
		cout<<i<<endl;
		i=(i+1)%len;
	}//
	for(int	j=0;j<len-1;++j){
		if(1==v[j])
			return j;
	}
	return 0;
}

int main(){
	int a=JosephuseCircle(500,30);	
	int b=JosephuseCircle_v2(500,30);	
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
	return 0;
}
