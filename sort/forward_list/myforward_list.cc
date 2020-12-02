/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:15:48
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-02 10:58:18
 * @FilePath: /practice/sort/forward_list/myforward_list.cc
 */

#include "myforward_list.hpp"

myForwardList::myForwardList()
:_pListHead(NULL)
{
  cout<<"myForwardList::myForwardList()"<<endl;
}

myForwardList::~myForwardList(){
  cout<<"myForwardList::~myForwardList()"<<endl;
	Node*next=_pListHead->_next;
	Node*cur=NULL;
	while(NULL!=next){
		cur=next;
		next=next->_next;
//		free(cur);
		delete  cur;
//		delete [] cur;
		cur=NULL;
	}
  _pListHead=NULL;
}
void myForwardList::push_front(int element){
  Node* pnew=new Node(element);
  pnew->_next=_pListHead->_next;
  _pListHead->_next=pnew;
}
void myForwardList::print(){
  Node *head=_pListHead->_next;
	if(NULL==head) return ;
	while(NULL!=head){
		cout<<head->_val<<" ";
		head=head->_next;
	}
	cout<<endl;
}