 ///
 /// @file    listPartitionZuoP52.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-15 00:20:06
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
		pnew->_val=i;
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

void printList(Node*head){
	if(NULL==head) return ;
	while(NULL!=head){
		cout<<head->_val<<" ";
		head=head->_next;
	}
	cout<<endl;
}
	
int listPartition(Node**head,int val){ 
	if(*head==NULL)  return -1;
	Node less;//3个临时哨兵
	Node equal;
	Node more;
	Node * cur=*head;
	Node * curLess=&less;
	Node * curEqual=&equal;
	Node * curMore=&more;
	while(NULL!=cur){
		if(cur->_val>val){
			curMore->_next=cur;	
			curMore=curMore->_next;
		}else if(cur->_val<val){
			curLess->_next=cur;	
			curLess=curLess->_next;
		}else{
			curEqual->_next=cur;	
			curEqual=curEqual->_next;
		}
		cur=cur->_next;
	}
	if(equal._next!=NULL){
		curLess->_next=equal._next;
		curEqual->_next=more._next;
	}else{
		curLess->_next=more._next;
	}
	curMore->_next=NULL;//vital
	*head=less._next;
	return 0;
}
int main(){
	Node*head;
	int num=14;
	buildList(&head,num);
	printList(head);

	cout<<"after"<<endl;
	listPartition(&head,5);
	printList(head);

	clearList(&head);
	return 0;
}

