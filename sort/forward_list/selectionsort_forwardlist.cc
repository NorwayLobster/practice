/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 07:46:56
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-03 04:10:44
 * @FilePath: /practice/sort/forward_list/selectionsort_forwardlist.cc
 */

#include "myforward_list.hpp"
Node* findMinNodePrevOne(Node*p){
  Node* min=p;
  Node* preNode=NULL;
  Node* cur=p->_next;
  Node* pre=p;
  while(cur!=NULL){
    if(cur->_val < min->_val){
      preNode=pre;
      min=cur;
    }
    pre=cur;
    cur=cur->_next;
  }
  return preNode;
}

// void selectionsort(myForwardList& fl){
Node* selectionsort(Node* head){
    // Node* dummy=fl.getListHead();
    Node sorted;
    Node* cur1=&sorted;
    // Node* cur=dummy->_next;
    Node* cur=head;
    Node* minPrevNode;
    Node* min;
    while(cur!=NULL){
      minPrevNode=findMinNodePrevOne(cur);//if cur is min, return null;
      if(NULL!=minPrevNode){
        min=minPrevNode->_next;
        minPrevNode->_next=min->_next;
        //stay cur
      }else{//cur is min one;
        min=cur;
        cur=cur->_next;
      }
      cur1->_next=min;
      cur1=cur1->_next;
    }
    // dummy->_next=sorted._next;
    return sorted._next;
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
  Node* newhead = selectionsort(fl.getListHead()->_next);
  return 0;
}