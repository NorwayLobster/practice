/*
 * @Author: your name
 * @Date: 2020-12-01 20:18:47
 * @LastEditTime: 2020-12-02 15:00:58
 * @LastEditors: ChengWang
 * @Description: In User Settings Edit
 * @FilePath: /practice/sort/forward_list/sort.cc
 */

#include "myforward_list.hpp"

Node* prev(myForwardList& fl,Node*p){
  Node *head=fl.getListHead();
  Node *cur=head;
  while(cur!=NULL){
    if(cur->_next==p){
      return cur;
    }
    cur=cur->_next;
  }
  return NULL;
}

Node* next(myForwardList& fl,Node*p){
  return p->_next;
}


void myswap(myForwardList& fl,Node*p1,Node*p2){
   Node* pre1=prev(fl,p1);
   Node* pre2=prev(fl,p2);
   Node*tmp;
   tmp=p2->_next;
   p2->_next=p1->_next;
   p1->_next=tmp;

   pre1->_next=p2;
   pre2->_next=p1;
}


Node * partition(myForwardList& fl, Node*left,Node*right){//time complexity????
  Node* p_pivot=left; 
  Node* pBoundary=left;
  // for(auto p=left+1;p<=right;p=p->_next){
  for(auto p=left->_next;p<=right;p=p->_next){//怎么比较p和right在链表中的先后关系
    if(p->_val < p_pivot->_val){
      pBoundary=pBoundary->_next;//to be improved
      myswap(fl,pBoundary,p);
    }
  }

  pBoundary=pBoundary->_next;
  myswap(fl,left,pBoundary);
  return pBoundary;
}

void quicksort(myForwardList& fl,Node*left,Node*right){
  cout<<"left :"<<left<<endl;
  cout<<"right:"<<right<<endl;
  if(left==right||left==right->_next) return ;//left 相等或right在left的前面
  // if(left>=right) return ;
  Node *p_pivot=partition(fl,left,right);
  quicksort(fl,left,prev(fl,p_pivot));
  quicksort(fl,next(fl,p_pivot),right);
}

int main(){
  myForwardList fl; 
  fl.push_front(-1);
  // fl.pop_front();
  for(int i=0;i<10;i++){
    if(i==5){
      fl.push_front(100);
      continue;
    }
    if(i==8){
      fl.push_front(800);
      continue;
    }
    fl.push_front(i);
  }
  fl.print();
  cout<<"size:"<<fl.size()<<endl;

  Node* last;
  Node* cur=fl.getListHead();
  while(cur->_next!=NULL){
    cur=cur->_next; 
  }
  last=cur;
  quicksort(fl,fl.getListHead()->_next,last);
  fl.print();
}
