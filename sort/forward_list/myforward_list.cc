/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:15:48
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-02 12:24:58
 * @FilePath: /practice/sort/forward_list/myforward_list.cc
 */

#include "myforward_list.hpp"

myForwardList::myForwardList()
:_ListHead()
,_pListHead(&_ListHead)
,_size(0)
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
  _size++;
}

void myForwardList::pop_front(){
  cout<<"myForwardList::pop_front()"<<endl;
  Node * tmp=_pListHead->_next;
  if(!tmp) return ;
  _pListHead->_next=tmp->_next;
  delete tmp;
  _size--;
}

size_t myForwardList::size(){
  return _size;
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


Node * partition(myFowardList& fl, Node*left,Node*right){
  Node* p_pivot=left; 
  Node* pBoundary=left;
  for(auto p=left+1;p<=right;p++){
    if(p->_val<p_pivot->_val){
      pBoundary=pBoundary->next;//to be improved
      myswap(fl,pBoundary,p);
    }
  }

  pBoundary=pBoundary->next;
  myswap(fl,left,pBoundary);
  return pBoundary;
}
// g_head=
void myswap(myFowardList& fl,Node*p1,Node*p2){
   Node* pre1=prev(fl,p1);
   Node* pre2=prev(fl,p2);
   Node*tmp;
   tmp=p2->_next;
   p2->_next=p1->_next;
   p1->_next=tmp;

   pre1->_next=p2;
   pre2->_next=p1;
}

Node *prev(myFowardList& fl,Node*p){
  Node *head==fl._pListHead;
  Node *cur=head;
  while(cur!=NULL){
    if(cur->_next==p){
      return cur;
    }
    cur=cur-_next;
  }
  return NULL
}
Node *next(myFowardList& fl,Node*p){
  return p->_next;
}

void quicksort(myFowardList& fl,Node*left,Node*right){
  if(left>=right) return ;
  Node *p_pivot=partition(fl,left,right);
  quicksort(left,prev(fl,p_pivot));
  quicksort(next(fl,p_pivot),right);
}