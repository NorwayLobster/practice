 ///
 /// @file    offerFindEntryNodeInLinkedListLoop.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-05 15:33:04
 /// complete: Thu Mar  5 16:13:27 CST 2020
 //corner case: Thu Mar  5 16:36:09 CST 2020
// 40min 
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int _val;
	Node * _next;
};
int lengthOfLoop(Node * head){
	if(nullptr==head)
		return 0;
	Node *slow=head;
	Node *fast=head;
	bool first=true;
	int i=0;
	while(fast!=slow||first){
		first=false;
		fast=fast->_next;
		slow=slow->_next;
		fast=fast->_next;
		i++;
	}
	return i;
}
Node * findMeetingNodeInLoop(Node *head){
	if(nullptr==head)
		return nullptr;
	Node *slow=head;
	Node *fast=head;
	bool first=true;
	while(nullptr!=fast->_next&&(fast!=slow||first)){
		first=false;
		fast=fast->_next;
		slow=slow->_next;
		if(nullptr==fast->_next)
			break;
		fast=fast->_next;
		cout<<"fast:"<<fast->_val<<",fast ptr:"<<fast<<endl;
		cout<<"slow:"<<slow->_val<<",slow ptr:"<<slow<<endl;
	}
	if(nullptr==fast->_next)
		return nullptr;
	cout<<"i:"<<fast->_val<<",fast ptr:"<<fast<<endl;
	cout<<"i:"<<slow->_val<<",slow ptr:"<<slow<<endl;
	return slow;
}
Node * offerFindEntryNodeInLinkedListLoop(int lengthOfLoop,Node *head){
	if(nullptr==head)
		return nullptr;
	if(0==lengthOfLoop) return nullptr;
	Node *cur=head;
	for(int i=0;i<lengthOfLoop;++i){
		cur=cur->_next;
	}
	Node *slow=head;
	Node *fast=cur;
	while(fast!=slow){
		fast=fast->_next;
		slow=slow->_next;
	}

	return slow; 
}

void buildList(Node**head,int i){
	*head=(Node*)calloc(1,sizeof(Node));
	(*head)->_val=i;
	cout<<"i:"<<i<<endl;
	cout<<"i:"<<i<<",ptr:"<<*head<<endl;
	Node*pre=*head;
	Node*pnew=pre;
	Node *bak=pre;
	while(--i){
//		pnew = (Node*)calloc(1,sizeof(Node));
		pnew=new Node;
//		pnew=new Node();
//		pnew=new Node[1]();
		pnew->_val=i;
		if(i==1){//loop
			bak=pnew;
		}
		cout<<"i:"<<i<<",ptr:"<<pnew<<endl;
		pre->_next=pnew;
		pre=pnew;
	}
	cout<<"pnew:"<<bak->_val<<",pnew ptr:"<<pnew<<endl;
	pnew->_next=bak;
	cout<<"bak:"<<bak->_val<<",bak ptr:"<<bak<<endl;
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
	int num=1;//corner case: one node and it also is a loop
//	int num=40;
//	int num=39;
	buildList(&head,num);

	Node *ret;
//	Node *ret=offerFindEntryNodeInLinkedListLoop();
	Node *meetingNode;
//	Node *meetingNode=findMeetingNodeInLoop(nullptr);
	meetingNode=findMeetingNodeInLoop(head);
	if(nullptr==meetingNode) {
		cout<<"ret:nullptr"<<endl;
	//	return 0;
	}else{
		cout<<meetingNode->_val<<",meetingNode ptr:"<<meetingNode<<endl;
	}
	int len=lengthOfLoop(meetingNode);
	cout<<len<<endl;
	ret=offerFindEntryNodeInLinkedListLoop(len,head);
	if(nullptr!=ret) {
		cout<<ret->_val<<",ptr:"<<ret<<endl;
	}
//	clearList(&head);
	return 0;
}
