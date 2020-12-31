 ///
 /// @file    printListEndToStart.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-04 21:48:18
 ///
 
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int _val;
	Node * _next;
	~Node() {cout<<"~Node()"<<" _val:"<<_val<<endl;}
	Node()
		:_val(100)
		,_next(NULL) 
	{cout<<"Node()"<<endl;}
};
//iteration
void printListEndToStart(Node*phead){
	if(NULL==phead) return ;	
	Node *cur=phead;
	stack<Node*> s;
	while(NULL!=cur){
		s.push(cur);		
		cur=cur->_next;
	}
	while(!s.empty()){
		cout<<s.top()->_val<<endl;
		s.pop();
	}
}
//recursion
//
void printListEndToStart_v2(Node*phead){
	if(NULL==phead) return ;	
	printListEndToStart_v2(phead->_next);
	cout<<phead->_val<<endl;
}
void buildList(Node**head,int i){
	*head=(Node*)calloc(1,sizeof(Node));
//	(*head)->_val=i;
	cout<<"i:"<<i<<endl;
	Node*pre=*head;
	Node*pnew=NULL;
	while(--i){
//		pnew = (Node*)calloc(1,sizeof(Node));
		pnew=new Node;
//		pnew=new Node();
//		pnew=new Node[1]();
//		pnew->_val=i;
		cout<<"i:"<<i<<endl;
		pre->_next=pnew;
		pre=pre->_next;
	}
}
void clearList(Node**head){
	Node*next=*head;
	Node*cur=NULL;
	while(NULL!=next){
		cur=next;
		next=next->_next;
//		free(cur);
		delete  cur;
//		delete [] cur;
		cur=NULL;
	}
}
int main(){
	Node*head;
	int num=4;
	buildList(&head,num);
	printListEndToStart(head);
	cout<<endl;
	printListEndToStart_v2(head);
	clearList(&head);
	cout<<"finish"<<endl;
	return 0;
}
