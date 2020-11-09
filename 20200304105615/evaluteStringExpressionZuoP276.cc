 ///
 /// @file    evaluteStringExpressionZuoP276.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-04 12:23:35
 //complete Wed Mar  4 17:20:25 CST 2020
 // 5h
 // Wed Mar  4 19:26:17 CST 2020
 // 1.中缀--> 后缀(逆波兰) 
 // 2.求值
 // 2h 
 
#include <bits/stdc++.h>
using namespace std;
pair<int,int> evaluteStringExpressionWithParentheses(const string&s,int start){
	int len=s.size();	
	deque<int> numDeque;
	deque<int> operatorDeque;
	pair<int,int> ret_pair;
	int num=0;
	int i=start;
	while(i<len && s[i]!=')'){
		if(start==i && '-'==s[i]){
			num=0;
			i++;//vital
			while(i<len && s[i]!=')' && s[i]>='0' && s[i]<='9'){
				num=num*10+(-1)*(s[i]-'0');
				i++;
			}
			numDeque.push_back(num);
		}else if(s[i]>='0' && s[i]<='9'){
			num=0;
			while(i<len && s[i]!=')' && s[i]>='0' && s[i]<='9'){
				num=num*10+s[i]-'0';
				i++;
			}
			if(!operatorDeque.empty()&&(operatorDeque.back()=='*'||operatorDeque.back()=='/')){
				if('*'==operatorDeque.back()){
					num=numDeque.back()*num;	
				}else{
					num=numDeque.back()/num;	
				}
				operatorDeque.pop_back();
				numDeque.pop_back();
			}
			numDeque.push_back(num);
		}else if(s[i]=='+'||s[i]=='-'){
			operatorDeque.push_back(s[i]);
			i++;
		}else if(s[i]=='*'||s[i]=='/'){
			operatorDeque.push_back(s[i]);
			i++;
		}else if(s[i]=='('){
			ret_pair=evaluteStringExpressionWithParentheses(s,i+1);
			num=ret_pair.first;
			if(!operatorDeque.empty()&&(operatorDeque.back()=='*'||operatorDeque.back()=='/')){
				if('*'==operatorDeque.back()){
					num=numDeque.back()*num;	
				}else{
					num=numDeque.back()/num;	
				}
				operatorDeque.pop_back();
				numDeque.pop_back();
			}
			numDeque.push_back(num);
			i=ret_pair.second+1;
		}
	}
	while(numDeque.size()>1){
		int tmp1=numDeque.front();
		numDeque.pop_front();
		if(operatorDeque.front()=='-'){
			tmp1=tmp1-numDeque.front();
		}else{
			tmp1=numDeque.front()+tmp1;
		}
		operatorDeque.pop_front();
		numDeque.pop_front();
		numDeque.push_front(tmp1);
	}
	return make_pair(numDeque.back(),i);
}

void infixToSuffix(const string&s,vector<string>&suffixExpression){
	int len=s.size();
	stack<int> tmp; //+ - * / (
	int i=0;
	int num;
	while(i<len){
		if(0==i && '-'==s[i]){
			num=0;
			i++;//vital
			while(i<len && s[i]>='0' && s[i]<='9'){
				num=num*10+(-1)*(s[i]-'0');
				i++;
			}
			suffixExpression.push_back(to_string(num));
		}else if('('==s[i]){
			tmp.push(s[i]);
			++i;
			if(i<len&&'-'==s[i]){
				num=0;
				++i;//vital 跳过-
				while(i<len && s[i]>='0' && s[i]<='9'){
					num=num*10+(-1)*(s[i]-'0');
					i++;
				}
				suffixExpression.push_back(to_string(num));
			}
		}else if(')'==s[i]){
			++i;
			while(!tmp.empty()&&'('!=tmp.top()){
				string s;
				s.push_back(tmp.top());
				suffixExpression.push_back(s);

				tmp.pop();
			}
			tmp.pop();// ( pop
		}else if(s[i]>='0' && s[i]<='9'){
			num=0;
			while(i<len && s[i]>='0' && s[i]<='9'){
				num=num*10+s[i]-'0';
				i++;
			}
			cout<<"num:"<<num<<endl;
			suffixExpression.push_back(to_string(num));
		}else if(s[i]=='*'||s[i]=='/'){
			tmp.push(s[i]);
			i++;
		}else if(s[i]=='+'||s[i]=='-'){
			while(!tmp.empty()&&'('!=tmp.top()){//运算优先级比s[i]高的，如* /, 包括先进去的+ - 
				//	if('+'==tmp.top()||'-'==tmp.top()||'*'==tmp.top()||'/'==tmp.top()){
//				suffixExpression.push_back(tmp.top());
				string s;
				s.push_back(tmp.top());
//				suffixExpression.push_back(to_string(tmp.top()));
				suffixExpression.push_back(s);
				tmp.pop();
			}
			tmp.push(s[i]);
			i++;
		}
	}
	while(!tmp.empty()){
//		suffixExpression.push_back(tmp.top());
		string s;
		s.push_back(tmp.top());
		suffixExpression.push_back(s);
//		suffixExpression.push_back(to_string(tmp.top()));
		tmp.pop();
	}
}
bool isOperator(const string&s){
		if("+"==s||"-"==s||"*"==s||"/"==s){
			return true;
		}
		return false;
}

int evaluteSuffixExpression(const vector<string> &s){
	int len=s.size();
	stack<int> tmp;
	int i=0;
	while(i<len){
		if(isOperator(s[i])){
			int right=tmp.top();tmp.pop();
			int left=tmp.top();tmp.pop();
			if("+"==s[i])
				tmp.push(left+right);
			else if("-"==s[i])
				tmp.push(left-right);
			else if("*"==s[i])
				tmp.push(left*right);
			else 
				tmp.push(left/right);
		}else{
				tmp.push(atoi(s[i].c_str()));
		}

		++i;
	}
	return tmp.top();
}
int main(){
	// note: expression 合法，且 中间过程不溢出
	string s("-10+(10+10*100/(-2)/(-1)-10)-(10-1+1*1/1)");
	pair<int,int> ret_pair;
//1.
	ret_pair=evaluteStringExpressionWithParentheses(s,0);
	cout<<"ret:"<<ret_pair.first<<endl;

//	string s1("(10-1+1*1/1)-1");
	string s1("-2000*(-910+600/(-30)-5000)+400");
	vector<string> d;
	infixToSuffix(s1,d);
//2.
	ret_pair=evaluteStringExpressionWithParentheses(s1,0);
	cout<<"ret:"<<ret_pair.first<<endl;

	cout<<int('+')<<endl;
	cout<<int('-')<<endl;
	cout<<int('*')<<endl;
	cout<<int('/')<<endl;
	for(auto e:d)
		cout<<e<<" ";
	cout<<endl;
//3.
	int b=evaluteSuffixExpression(d);
	cout<<"b:"<<b<<endl;

	return 0;
}
