 ///
 /// @file    manacher.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 09:39:35
 ///
 
#include <bits/stdc++.h>
using namespace std;
void generateManacherString(string &manacherString,string &s){
	int index=0;

	for(int i=0;i<manacherString.size();++i){
		manacherString[i]=i&0x1?s[index++]:'#';	
		cout<<manacherString<<endl;
	}
}
int manacher(string &s){
	string manacherString;
//	manacherString.reserve(len*2+1);
	manacherString.resize(s.size()*2+1);
	cout<<"size:"<<manacherString.size()<<endl;
	generateManacherString(manacherString,s);
	int len=manacherString.size();
	int curMidIndex=-1;
	vector<int> Radius(len,0);
	int curMostRightBoundary=-1;//manacherString[curMostRightBoundary]本身不是回文子串一部分
	int maxRadius=0;
	for(int i=0;i<len;++i){
		cout<<"i:"<<i<<endl;
		Radius[i]=i<curMostRightBoundary?min(curMostRightBoundary-i,Radius[2*curMidIndex-i]):1;
		while(i+Radius[i]<len&&i-Radius[i]>-1){
			if(manacherString[i+Radius[i]]==manacherString[i-Radius[i]]){
				Radius[i]++;
				cout<<"radius[i]"<<Radius[i]<<endl;
			}else{
				break;
			}
		}
		if(i+Radius[i]>curMostRightBoundary){//相等是更新curMidIndex与否? no,保留Radius大的
			curMostRightBoundary=i+Radius[i];//
			curMidIndex=i;
		}
		maxRadius=max(maxRadius,Radius[i]);
	}
	return maxRadius-1;//
}
int main(){
//	string s("abcbab");
	string s("123");
//	string s("abc1234321ab");
//	string s("abcabcabcabc");
	cout<<"maxRadius:"<<manacher(s)<<endl;
	return 0;

}
