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
	j+=1;
	while(j<=i){
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

Node * delteMiddleNode(Node*head1){
	if(nullptr==head1) return head1;
	if(nullptr==head1->_next) return head1;
	if(nullptr==head1->_next->_next) 
	{
		Node*tmp=head1->_next;
		delete head1;
		return  tmp;
	}
	//step1 
	Node*cur=head1->_next->_next;
	Node*pre=head1;//小弟晚走一步
	while(nullptr!=cur&&nullptr!=cur->_next &&cur->_next->_next){//抠边界, 到达末节点即停
		//大哥走两步实心节点，小弟才往前走一步
		cout<<"cur->_val:"<<cur->_val<<endl;
		cout<<"pre->_val:"<<pre->_val<<endl;
		cur=cur->_next;
		if(nullptr==cur)
			break;
		cur=cur->_next;//成功走两步
		pre=pre->_next;
	}
	cout<<pre->_val<<endl;
	cout<<pre->_next->_val<<endl;
	Node *tmp=pre->_next;
	pre->_next=pre->_next->_next;
	delete tmp;
	tmp=nullptr;
	return head1;
}

// a/b处节点
Node * delteNode(Node*head1,int a, int b){
	if(nullptr==head1) return head1;
	if(nullptr==head1->_next) return head1;
	if(nullptr==head1->_next->_next) 
	{
		Node*tmp=head1->_next;
		delete head1;
		return  tmp;
	}
	Node*cur=head1;
	int n=0;
	while(nullptr!=cur){
			cur=cur->_next;
			++n;
	}
	cout<<"n:"<<n<<endl;
	//step1 
	int k=ceil(double(a)/double(b) * double(n));//删除第k
	cout<<"k:"<<k<<endl;
	if(k==0) return  head1;
	if(k==1){
		Node *tmp=head1->_next;
		delete head1;
		head1=nullptr;
		return  tmp;
	}

	cur=head1;
	//走到第k-1
	for(int i=0;i<k-1-1;++i){//走k-2 step
		cur=cur->_next;
	}
	Node *tmp=cur->_next;
	cur->_next=cur->_next->_next;
	delete tmp;
	tmp=nullptr;
	return head1;
}

//way1:双指针找中心
// 
//奇数：都相同
//
//偶数取下中: 
//通常写法: while(nullptr!=cur1&&nullptr!=cur1->_next){//抠边界, 到达末节点即停
//
//偶数取上中: //特别注意: 大哥走两步实心节点，小弟才往前走一步
//	while(nullptr!=cur1&&nullptr!=cur1->_next&&nullptr!=cur1->_next->_next){//抠边界, 到达末节点即停
//
//way2:安全保险 遍历求lenth，求到达上中心或下中心，需要走几步，
Node * findMiddleNode(Node*head1){
	if(nullptr==head1) return head1;
	if(nullptr==head1->_next) return head1;
	if(nullptr==head1->_next->_next) 
	{
		Node*tmp=head1->_next;
		delete head1;
		return  tmp;
	}
	//step1 
	Node*cur1=head1;
	Node*cur2=head1;//小弟
//error: while(nullptr!=cur1&&nullptr!=cur1->_next){//抠边界, 到达末节点即停
	while(nullptr!=cur1&&nullptr!=cur1->_next&&nullptr!=cur1->_next->_next){//抠边界, 到达末节点即停
		//大哥走两步实心节点，小弟才往前走一步
		cout<<"cur1->_val:"<<cur1->_val<<endl;
		cout<<"cur2->_val:"<<cur2->_val<<endl;
		cur1=cur1->_next;
		cur1=cur1->_next;
		cur2=cur2->_next;//成功走两步
	}
	return cur2;
}

int main(){
	Node*head;
//	buildList(&head,99,1);
	buildList(&head,5,1);
//	buildList(&head,11,1);
	printList(head);
	Node *ret;
//	ret=delteMiddleNode(head);
//	ret=findMiddleNode(head);
	ret=delteNode(head,2,6);
	cout<<"middle:"<<ret->_val<<endl;
	printList(ret);
	return 0;

}
