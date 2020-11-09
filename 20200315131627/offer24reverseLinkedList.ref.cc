 ///
 /// @file    offer24reverseLinkedList.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-05 16:37:44
 ///complete: Thu Mar  5 17:00:39 CST 2020
// 23min
//recursive: Thu Mar  5 17:16:59 CST 2020
//16min
//reverse double linked list: Sun Mar  8 17:04:52 CST 2020
//
//Sun Mar  8 17:33:03 CST 2020
//30min
//
//reversePart
//Sun Mar  8 17:33:03 CST 2020
//Sun Mar  8 18:48:17 CST 2020
//70min
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int _val;
	Node * _next;
};
struct NodeDouble{
	int _val;
	NodeDouble * _next;
	NodeDouble * _pre;
};

//todo test
NodeDouble * reverseDoubleLinkedList(NodeDouble*head){
	if(nullptr==head) return nullptr;	
	if(nullptr==head->_next) return head;	
	NodeDouble * cur=head;
	NodeDouble * next=nullptr;
	NodeDouble * pre=nullptr;
	while(nullptr!=cur){
		next=cur->_next;
		cur->_next=cur->_pre;//pre
		cur->_pre=next;
		pre=cur;
		cur=next;
	}
	return pre;

}

//todo test
NodeDouble * reverseDoubleLinkedList_v2(NodeDouble*head){
	if(nullptr==head) return nullptr;	
	if(nullptr==head->_next) return head;	
	NodeDouble * cur=head;
//	NodeDouble * next=nullptr;
	NodeDouble * pre=nullptr;
	while(nullptr!=cur){
	
		//next=cur->_next;
		swap(cur->_next,cur->_pre);
		pre=cur;
		cur=cur->_pre; //cur=next;
	}
	return pre;
}
//recursive 
//to do
NodeDouble * reverseDoubleLinkedList_v3(NodeDouble*head){
	return head;
}

//iterative:
Node * reversePartLinkedList(Node*head,int from, int to){
	if(nullptr==head) return nullptr;
	if(nullptr==head->_next) return head;
	if(to<=from) return head;
	if(from<1) return head;
	Node * cur=head;
	int N=0;
	while(nullptr!=cur){
		cur=cur->_next;
		++N;
	}
	if(to>N) return head;


	Node * leftHeadPre=head;//from==2
	Node * rightHead=nullptr;
	Node * rightHeadNext=nullptr;

	cur=head;
	int stepToFromBefore=from-1-1;
	int stepToTo=to-1;
	int i=0;
	while(nullptr!=cur){
		cur=cur->_next;
		++i;
		if(i==stepToFromBefore){ 
			leftHeadPre=cur; 
		}
		if(i==stepToTo){ 
			rightHead=cur;
			rightHeadNext=cur->_next;
			break;
		}
	}
	cout<<endl;
	cout<<"_val:"<<rightHead->_val<<",ptr:"<<rightHead<<",_next:"<<rightHead->_next<<endl;


	if(from==1){
		cur=head;
		cout<<"_val:"<<head->_val<<",ptr:"<<head<<",_next:"<<head->_next<<endl;
	}else{
		cur=leftHeadPre->_next;
		cout<<"_val:"<<leftHeadPre->_val<<",ptr:"<<leftHeadPre<<",_next:"<<leftHeadPre->_next<<endl;
	}

	Node * pre=rightHead->_next;
	Node * next;
	
//	while(nullptr!=cur){
	while(rightHeadNext!=cur){
		next=cur->_next;
		cur->_next=pre;
		pre=cur;
		cur=next;
//		if(cur==rightHeadNext)//大坑，rightHead的_next先被更改了
//			break;
	}

	if(from==1) {
		head=rightHead;//head=pre;
	}else{
		leftHeadPre->_next=rightHead;// leftHeadPre->_next=pre;
	}

	return head;
}

//iterative:
Node * reverseLinkedList(Node*head){
	if(nullptr==head) return nullptr;
	if(nullptr==head->_next) return head;
	Node * pre=nullptr;
	Node * cur=head;
	Node * next;
	while(nullptr!=cur){
		next=cur->_next;
		cur->_next=pre;
		pre=cur;
		cur=next;
	}
	return pre;
}
//recursive
Node * reverseLinkedList_v2(Node *pre, Node*cur){
	if(nullptr==cur) return pre;
	Node * ret;
	ret=reverseLinkedList_v2(cur, cur->_next);
	cur->_next=pre;
	return  ret;
}

void buildList(Node**head,int i){
	*head=(Node*)calloc(1,sizeof(Node));
	(*head)->_val=i;
	cout<<"i:"<<i<<endl;
	cout<<"i:"<<i<<",ptr:"<<*head<<endl;
	Node*pre=*head;
	Node*pnew=pre;
	while(--i){
//		pnew = (Node*)calloc(1,sizeof(Node));
		pnew=new Node;
//		pnew=new Node();
//		pnew=new Node[1]();
		pnew->_val=i;
		cout<<"i:"<<i<<",ptr:"<<pnew<<endl;
		pre->_next=pnew;
		pre=pnew;
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

int main(){
	Node*head;
	buildList(&head,10);
	printList(head);
	
	Node *newHead;
//	newHead=reverseLinkedList(head);
//	newHead=reverseLinkedList(nullptr);
//
//	newHead=reverseLinkedList_v2(nullptr,head);

//	newHead=reversePartLinkedList(head,1,10);
//	newHead=reversePartLinkedList(head,2,11);
//	newHead=reversePartLinkedList(head,2,1);
//	newHead=reversePartLinkedList(head,2,5);
	newHead=reversePartLinkedList(nullptr,2,5);

//	newHead=reverseLinkedList_v2(nullptr,nullptr);
	printList(newHead);

	return 0;
}
