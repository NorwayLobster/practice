 ///
 /// @file    evaluteStringExpressionZuoP276.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-04 12:23:35
 ///
 
#include <bits/stdc++.h>
using namespace std;
int	evaluteStringExpressionWithoutParentheses(const string&s){
	int len=s.size();	
	int i=0;
	stack<int> numStack;
	stack<int> operatorStack;
	while(i<len){
		if(s[i]>='0' && s[i]<='9'){
			int num=0;
			while(i<len&&s[i]>='0' && s[i]<='9'){
				num=num*10+s[i]-'0';
				i++;
			}
			if(!operatorStack.empty()&&(operatorStack.top()=='*'||operatorStack.top()=='/')){
				if('*'==operatorStack.top()){
					num=numStack.top()*num;	
				}else{
					num=numStack.top()/num;	
				}
				operatorStack.pop();
				numStack.pop();
			}
			numStack.push(num);
		}else if(s[i]=='+'||s[i]=='-'){
			operatorStack.push(s[i]);
			i++;
		}else if(s[i]=='*'||s[i]=='/'){
			operatorStack.push(s[i]);
			i++;
		}
	}
	while(numStack.size()>1){
		int tmp1=numStack.top();
		numStack.pop();
		if(operatorStack.top()=='-'){
			tmp1=numStack.top()-tmp1;
		}else{
			tmp1=numStack.top()+tmp1;
		}
		operatorStack.pop();
		numStack.pop();
		numStack.push(tmp1);
	}
	return numStack.top();
}
int a=evaluteStringExpressionWithParentheses(s){
	int len=s.size();
	int i=0;
	string tmp;
	while(i<len){
		if(s[i]!='('){
				pre_pair=evaluteStringExpressionWithParentheses(s,i+1);
				++i;
		}
		}else if(s[i]!=')'){
			
			


}


int main(){
	string s("10+10*100/2/1-10");
	int a=evaluteStringExpressionZuoP276(s);
	cout<<"a:"<<a<<endl;
	return 0;
}
