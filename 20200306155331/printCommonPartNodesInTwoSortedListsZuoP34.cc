 ///
 /// @file    printCommonPartNodesInTwoLists.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-06 16:04:14
 ///
 
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

void printCommonPartNodesInTwoSortedLists(Node*head1,Node*head2){
	if(nullptr==head1) return ;
	if(nullptr==head2) return ;
	Node*cur1=head1;
	Node*cur2=head2;
	while(nullptr!=cur1&&nullptr!=cur2){
		if(cur1->_val<cur2->_val)
			cur1=cur1->_next;
		else if(cur1->_val>cur2->_val)
			cur2=cur2->_next;
		else{
			cout<<"_val:"<<cur1->_val<<",ptr:"<<cur1<<endl;
			cur1=cur1->_next;
			cur2=cur2->_next;
		}
	}
}
int main(){
	Node*head;
	Node*head1;
	buildList(&head,10,0);
	buildList(&head1,10,0);
	printCommonPartNodesInTwoSortedLists(head1,head);
	return 0;

}
