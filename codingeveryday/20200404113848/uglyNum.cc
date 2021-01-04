///
/// @file    uglyNum.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-04 11:39:00
///

#include <bits/stdc++.h>
using namespace std;
int myMin(int a,int b,int c){
	int d=min(a,b);
	return min(d,c);
}
#if 0
bool isUgly(int i){
	while(i%2==0)
		i/=2;
	while(i%3==0)
		i/=3;
	while(0==i%5)
		i/=5;
	if(1==i) return true;
	return false;
}
#endif
#if 1
//fatal error: logically wrong
bool isUgly(int i){
	int a1=i/2;//非整除时破坏了因子
	int a2=i%2;
	if(0!=a2) return false;
	if(1==a1) return true;

	int b1=a1/3;
	int b2=a1%3;
	if(0!=b2) return false;
	if(1==b1) return true;

	int c1=b1/5;
	int c2=b1%5;
	if(0!=c2) return false;
	if(1==c1) return true;
	return false;
}
#endif

class Solution {
	public:
#if 1
		int GetUglyNumber_Solution(int index) {
			if(1==index) return 1;
			int cnt(1),i(2);//vital:开始状态
			while(cnt<index){
					cout<<"i:"<<i<<",cnt:"<<cnt<<endl;
					//while(1){
					//            if(cnt>=index)
					//                break;
					if(isUgly(i))
						cnt++;
					++i;
			}
				return i-1;
		}
#endif
#if 1
			int GetUglyNumber_Solution1(int index) {
				if(index<7) return index;

				vector<int> uglyNum(index+1,0);        
				int t2(4),t3(3),t5(2);
				int M(0);//M2(2*uglyNum[t2]),M3(3*uglyNum[t3]),M5(5*uglyNum[t5]);
				int cnt(7);//下一个求uglyNum[7]
				for(int i=1;i<7;++i)
					uglyNum[i]=i;
				while(cnt<=index){
					M=myMin(uglyNum[t2]*2,uglyNum[t3]*3,uglyNum[t5]*5);
					uglyNum[cnt++]=M;
					while(uglyNum[t2]*2<=M)
						t2++;
					while(uglyNum[t3]*3<=M)
						t3++;
					while(uglyNum[t5]*5<=M)
						t5++;
				}
				return uglyNum[index];
			}
#endif
		};

int main(){
	Solution  s;
			cout<<s.GetUglyNumber_Solution(150)<<endl;
			cout<<s.GetUglyNumber_Solution1(150)<<endl;
			return 0;
		}
