 ///
 /// @file    offer22PrintKthNodeReversely.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-04 23:45:24
 ///
 
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int _val;
	Node * _next;
};
Node * findKthToTail(Node * head,unsigned int k){
	if(NULL==head) return NULL;
	if(k==0) return NULL;
	Node* cur=head;
	Node* pK=head;
#if 1
	for(unsigned int i=0;i<k-1&&NULL!=cur;++i){
		cur=cur->_next;
	}
	while(NULL!=cur->_next){//next node is NULL, over
//error:	while(NULL!=cur){
		cur=cur->_next;
		pK=pK->_next;
	}
#endif


// 极易容易错。
#if 0
	unsigned int i=0;
	while(NULL!=cur){
		cur=cur->_next;
//error:		++i;
		if(i>=k){//fllow the kth step to start 
			pK=pK->_next;
		}
		++i;//correct, k-1 step complete
	}
#endif
	return pK;
}
void buildList(Node**head,int i){
	*head=(Node*)calloc(1,sizeof(Node));
	(*head)->_val=i;
	cout<<"i:"<<i<<endl;
	Node*pre=*head;
	Node*pnew=NULL;
	while(--i){
//		pnew = (Node*)calloc(1,sizeof(Node));
		pnew=new Node;
//		pnew=new Node();
//		pnew=new Node[1]();
		pnew->_val=i;
//		cout<<"i:"<<i<<endl;
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
Node * findMiddleToTail(Node * head){
	if(nullptr==head) return nullptr;
	Node*p1=head;
	Node*p2=head;
	while(nullptr!=p2->_next){
		p1=p1->_next;
		p2=p2->_next;
		if(nullptr==p2->_next)
			return p1;
		p2=p2->_next;
//		cout<<"p1->_val:"<<p1->_val<<endl;
	}
	return p1;
}


int main(){
	Node*head;
	int num=1;
//	int num=40;
//	int num=39;
	buildList(&head,num);

//	Node *ret=findKthToTail(head,0);
	Node *ret=findMiddleToTail(head);
//	Node *ret=findMiddleToTail(nullptr);
//	Node *ret=findMiddleToTail(head);
	if(nullptr==ret) {
		cout<<"ret:nullptr"<<endl;
		return 0;
	}
	cout<<ret->_val<<endl;
	clearList(&head);
	return 0;
}
