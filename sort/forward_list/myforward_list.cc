/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:15:48
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-02 11:16:14
 * @FilePath: /practice/sort/forward_list/myforward_list.cc
 */

#include "myforward_list.hpp"

myForwardList::myForwardList()
:_ListHead()
,_pListHead(&_ListHead)
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
  cout<<"myForwardList::push_front()"<<endl;
  Node* pnew=new Node(element);
  pnew->_next=_pListHead->_next;
  _pListHead->_next=pnew;
}
void myForwardList::print(){
  cout<<"myForwardList::print()"<<endl;
  Node *head=_pListHead->_next;
	if(NULL==head) return ;
	while(NULL!=head){
		cout<<head->_val<<" ";
		head=head->_next;
	}
	cout<<endl;
}