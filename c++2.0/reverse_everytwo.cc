 ///
 /// @file    reverse_everytwo.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-12 21:16:35
 ///
 
#include <bits/stdc++.h>
using namespace std;

struct Node{
	Node(char ele)
	:_ele(ele)
	 ,_next(NULL)
	{cout<<"Node(char)"<<endl;};
	~Node()
	{cout<<"~Node()"<<endl;};
	char _ele;
	Node * _next;
};
Node *reverse_everytwo(Node *phead){
	if(!phead) return NULL;
	Node head(-1);
	head._next=phead;
	Node *pre=&head;
	Node *p=head._next;
	Node *suc=NULL;
	while(NULL!=p&&NULL!=p->_next){
		suc=p->_next->_next;		
		pre->_next=p->_next;
		p->_next->_next=p;
		p->_next=suc;

		pre=p;
		p=suc;
	}
	return head._next;
}
void buildList(Node &head,int num){
	Node *p=&head;
	for(int i=0;i<num;i++){
		Node *pnew=new Node((char)(i+65));
		p->_next=pnew;
		cout<<p->_ele<<endl;
		p=p->_next;
	}
}
void print(Node *p){
	while(NULL!=p){
		cout<<p->_ele<<',';
		p=p->_next;
	}
	cout<<endl;
}
void destroy(Node *p){
	while(NULL!=p){
		Node *next=p->_next;
		delete p;
		p=next;
	}
}
int main(){
	int num=11;
//	int num=10;
	Node head(-1);
	buildList(head,num);
	print(head._next);

	Node * p=reverse_everytwo(head._next);
	print(p);
	destroy(p);
}
