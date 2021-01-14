 ///
 /// @file    delteKthNodeReverselyInListAndDoubleList.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-06 17:18:43
 /// Fri Mar  6 17:52:39 CST 2020
 //34min
 
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int _val;
	Node * _next;
};
void buildList(Node**head,int i,int j){
	*head=(Node*)calloc(1,sizeof(Node));
	(*head)->_val=j;
	cout<<"i:"<<j<<",ptr:"<<*head<<endl;
	Node*pre=*head;
	Node*pnew=pre;
//	j+=2;
	while(j<i){
//		pnew = (Node*)calloc(1,sizeof(Node));
		pnew=new Node;
//		pnew=new Node();
//		pnew=new Node[1]();
		pnew->_val=j;
		cout<<"i:"<<j<<",ptr:"<<pnew<<endl;
		pre->_next=pnew;
		pre=pnew;
		j+=1;
//		j+=2;
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
	cout<<"starting"<<endl;
	while(nullptr!=head){
		cout<<"_val:"<<head->_val<<",ptr:"<<head<<",_next:"<<head->_next<<endl;
		head=head->_next;
	}
	cout<<"finished"<<endl;
}

Node * delteKthNodeReverselyInListAndDoubleList(Node*head1,int k){
//case0: 
	if(nullptr==head1) return nullptr;
//case1: 
	if(k<=0) return head1;
	Node*cur1=head1;
	int n=0;
	while(nullptr!=cur1){
		cur1=cur1->_next;
		n++;
	}
//case2: n<=k
	if(k>=n) return  nullptr;//回收空间与否？
//case2: n>k
	cur1=head1;

	Node*cur2=head1;
	for(int i=0;i<k;++i){//先走k步,
		cur1=cur1->_next;
	}
//抠边界
	while(nullptr!=cur1->_next){//
//	while(nullptr!=cur1){
		cur1=cur1->_next;
		cur2=cur2->_next;
	}//cur2走到倒数第k+1个节点
	Node *tmp=cur2->_next;//kth 节点
//若果是双向链表
	//cur2->_next->_next->_pre=cur2;
	cur2->_next=cur2->_next->_next;
	delete tmp;
	tmp=nullptr;
	return head1;
}

int main(){
	Node*head;
	buildList(&head,10,0);
	printList(head);
	Node *ret=delteKthNodeReverselyInListAndDoubleList(head,2);
	printList(ret);
	return 0;

}
