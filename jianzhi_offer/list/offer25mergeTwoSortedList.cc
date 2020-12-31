 ///
 /// @file    offer25mergeTwoSortedList.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-05 17:19:25
 ///complete: Thu Mar  5 18:09:52 CST 2020
 //50min
 //Thu Mar  5 18:21:56 CST 2020
 //12min
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
	j+=2;
	while(j<i){
//		pnew = (Node*)calloc(1,sizeof(Node));
		pnew=new Node;
//		pnew=new Node();
//		pnew=new Node[1]();
		pnew->_val=j;
		cout<<"i:"<<j<<",ptr:"<<pnew<<endl;
		pre->_next=pnew;
		pre=pnew;
		j+=2;
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
//iterative
Node *mergeTwoSortedList(Node*head,Node*head2){
	if(nullptr==head) return head2;
	if(nullptr==head2) return head;
	Node*newHead;
	Node *newCur=nullptr;
	Node *cur1=head;
	Node *cur2=head2;
	if(cur1->_val<cur2->_val){
		newHead=cur1;
		cur1=cur1->_next;
	}else{
		newHead=cur2;
		cur2=cur2->_next;
	}
	newCur=newHead;	
	while(nullptr!=cur1&&nullptr!=cur2){
		if(cur1->_val<cur2->_val){
			newCur->_next=cur1;
			cout<<"newCur:"<<newCur->_next<<endl;
			newCur=newCur->_next;
			cur1=cur1->_next;
		}else{
			newCur->_next=cur2;
			cout<<"newCur:"<<newCur->_next<<endl;
			newCur=newCur->_next;
			cur2=cur2->_next;
		}
	}
	if(nullptr!=cur1){
		newCur->_next=cur1;
		cout<<"newCur:"<<newCur->_next<<endl;
	}

	if(nullptr!=cur2){
		newCur->_next=cur2;
		cout<<"newCur:"<<newCur->_next<<endl;
	}

	return newHead;
}
Node *mergeTwoSortedList_v2(Node*cur1,Node*cur2){
	if(nullptr==cur1) return cur2;
	if(nullptr==cur2) return cur1;
	Node *head;
	if(cur1->_val<cur2->_val){
		head=cur1;
		head->_next=mergeTwoSortedList_v2(cur1->_next,cur2);
	}else{
		head=cur2;
		head->_next=mergeTwoSortedList_v2(cur1,cur2->_next);
	}
	return head;
}

int main(){
	Node*head;
	Node*head2;
	buildList(&head,10,0);
	buildList(&head2,10,1);
	printList(head);
	printList(head2);
//	Node *newHead=mergeTwoSortedList(nullptr,nullptr);
//	Node *newHead=mergeTwoSortedList(nullptr,head2);
//	Node *newHead=mergeTwoSortedList(head2,head);
	Node *newHead=mergeTwoSortedList_v2(head2,head);
//	Node *newHead=mergeTwoSortedList(head,nullptr);
	printList(newHead);
	return 0;
}
