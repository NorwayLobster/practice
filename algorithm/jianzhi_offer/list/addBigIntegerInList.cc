 ///
 /// @file    addIntegerInList.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-15 01:04:41
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
Node *addIntegerInList(Node**head1,Node**head2){ 
	if(*head1==NULL)  return NULL;
	if(*head2==NULL)  return NULL;
	*head1=reverseLinkedList(*head1);
	*head2=reverseLinkedList(*head2);
	cout<<"after reverse"<<endl;
	printList(*head1);
	printList(*head2);

	Node * cur1=*head1;
	Node * cur2=*head2;
	int carry=0;

	Node start;//哨兵机制，简化处理
	Node * cur3=&start;//哨兵机制，简化处理

	while(NULL!=cur1||NULL!=cur2){
		int n1=cur1==NULL?0:cur1->_val;
		int n2=cur2==NULL?0:cur2->_val;
		int n3=(n1+n2+carry)%10;
		carry=(n1+n2)/10;
		Node *pnew=(Node*)malloc(sizeof(Node));
		pnew->_val=n3;
		cur3->_next=pnew;
		cur3=cur3->_next;

		cur1=cur1->_next;
		cur2=cur2->_next;
	}
	if(0!=carry){
		Node *pnew=(Node*)malloc(sizeof(Node));
		pnew->_val=carry;
		cur3->_next=pnew;
		cur3=cur3->_next;
	}
	*head1=reverseLinkedList(*head1);
	*head2=reverseLinkedList(*head2);

	Node * head3=start._next;
	head3=reverseLinkedList(head3);

	return head3;
}
int main(){
	Node*head2;
	Node*head1;
	int num=14;
	buildList(&head1,num);
	buildList(&head2,num);
	printList(head1);
	printList(head2);

	Node *head3=addIntegerInList(&head1,&head2);
	printList(head3);
	cout<<endl;

	clearList(&head1);
	clearList(&head2);
	clearList(&head3);
	return 0;
}

