/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 07:46:46
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-03 04:06:11
 * @FilePath: /practice/sort/forward_list/insertionsort_forwardlist.cc
 */

#include "myforward_list.hpp"

void findRightPosAndInsertion(Node* sortedHead, Node* p){
  Node* cur=sortedHead->_next;
  Node* prev=sortedHead;

  while(cur!=NULL){
    if(p->_val < cur->_val){//第一个p->_val小于的元素前面插入
      p->_next=cur;
      prev->_next=p;
      return ;
    }
    prev=cur;
    cur=cur->_next;
  }
  //p作为soted的最后一个node
  p->_next=NULL;
  prev->_next=p;
}

Node* insertionsort(Node* head){    
  if(!head) return NULL;
  if(!head->_next) return head;
  Node* cur=head->_next;//start from the 2nd node

  Node sorted;//sentiment node
  Node* sortedHead=&sorted;
  sortedHead->_next=head;//first node is natrually sorted
  sortedHead->_next->_next=NULL;//sorted is a independent list;

  while(cur!=NULL){
    Node* next=cur->_next;
    findRightPosAndInsertion(sortedHead,cur);//符合插入位置的最后一个，保持stable性质
    cur=next;
  }
  return  sorted._next;
}

void printList(Node* newhead){
  Node* cur=newhead;
  while(cur!=NULL){
    cout<<cur->_val<<","<<cur<<";";
    cur=cur->_next;
  }
  cout<<endl;
}

int main(){
  myForwardList fl;
  fl.push_front(-1);
  fl.push_front(-10);
  fl.push_front(10);
  // fl.pop_front();
  for(int i=0;i<10;i=i+2){ fl.push_front(i); }//降序排列

  fl.print();
  cout<<"size:"<<fl.size()<<endl;
  cout<<endl;


  Node* newhead = insertionsort(fl.getListHead()->_next);
  printList(newhead);

  return 0;
}