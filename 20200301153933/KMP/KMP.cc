 ///
 /// @file    KMP.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-02 02:20:56
 ///
 
#include <bits/stdc++.h>
using namespace std;
void buildNext(vector<int> &next,const char*pattern){
	next[0]=-1;
	next[1]=0;
	int pos=2;		
	int cnt=0;//比较pos-1和cnt位置的元素，是为了求next[pos]
	while(pos<strlen(pattern)){
//		if(pattern[pos-1]==pattern[cnt]){//v1
		if(cnt>=0&&pattern[pos-1]==pattern[cnt]){//v2
			next[pos]=cnt+1; //比对成功，下一次需要验证pos+1和cnt+1,来求pos+1
			++pos;
			++cnt;
		}else if(cnt>0){
			cnt=(pattern[cnt]!=pattern[next[cnt]]?next[cnt]:next[next[cnt]]);//v2
//			cnt=next[cnt];//v1
		}else{//cnt==0
			next[pos]=0;
			++pos;
		}

	}
}
int kmp(const char *str,const char*pattern){
	int len1=strlen(str);
	int len2=strlen(pattern);
	vector<int> next(len2,0);
	buildNext(next,pattern);
	int i=0,j=0;
	while(i<len1&&j<len2){
		if(j<0||str[i]==pattern[j]){
			++i;
			++j;
		}else{
			j=next[j];
		}
	}
	return i-j;	
}
int main(){
	const char *str="akmanabcfadsabcpcdecdd";
	const char *pattern="cde";
	cout<<"start:"<<str+kmp(str,pattern)<<endl;
	cout<<endl;
	return 0;
}

