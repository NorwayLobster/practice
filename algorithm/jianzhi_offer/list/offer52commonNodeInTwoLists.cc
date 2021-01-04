 ///
 /// @file    offer52commonNodeInTwoLists.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-05 20:17:31
 ///complete:Thu Mar  5 20:39:21 CST 2020
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
Node* firstCommonNodeInTwoLists_v2(Node*head1,Node*head2){
	if(nullptr==head1) return nullptr;
	if(nullptr==head2) return nullptr;
	Node*cur1=head1;
	Node*cur2=head2;
	int i=0;
	int len1,len2;
	while(nullptr!=cur2){
		cur2=cur2->_next;
		++i;
	}
	len1=i;
	i=0;
	while(nullptr!=cur1){
		cur1=cur1->_next;
		++i;
	}
	len2=i;
	cout<<"len1:"<<len1<<",len2:"<<len2<<endl;
//do not forget
	cur1=head1;
	cur2=head2;

	for(int i=0;i<(len1>len2?len1-len2:len2-len1);++i){
		if(len1>len2)
			cur1=cur1->_next;
		else
			cur2=cur2->_next;
	}
	while(nullptr!=cur1&&nullptr!=cur2){
			if(cur1==cur2) return cur1;
			cur1=cur1->_next;
			cur2=cur2->_next;
	}
	return nullptr;
}
Node* firstCommonNodeInTwoLists(Node*head1,Node*head2){
	if(nullptr==head1) return nullptr;
	if(nullptr==head2) return nullptr;
	Node*cur1=head1;
	Node*cur2=head2;
	unordered_map<Node*,int> hash;
	while(nullptr!=cur1){
		hash[cur1]=1;
		cur1=cur1->_next;
	}
	while(nullptr!=cur2){
		if(hash.end()!=hash.find(cur2)){
			if(hash[cur2]>0){
				cout<<"cur2:"<<cur2<<endl;
				return cur2;
			}
			
		}
		cur2=cur2->_next;
	}
	return nullptr;
}
int main(){
	Node*head;
	Node*head1;
	buildList(&head,1,0);
//	buildList(&head1,10,1);
	Node *ret;
//	ret=firstCommonNodeInTwoLists(head,head1);
//	ret=firstCommonNodeInTwoLists_v2(head,head1);
	ret=firstCommonNodeInTwoLists_v2(head,head);
//	ret=firstCommonNodeInTwoLists(head,head);
//	ret=firstCommonNodeInTwoLists_v2(nullptr,head1);
	if(nullptr==ret){
		cout<<"ret:nullptr"<<endl;
		return 0;
	}
	cout<<"ret:"<<ret->_val<<",ptr:"<<ret->_next<<endl;
	return 0;

}
