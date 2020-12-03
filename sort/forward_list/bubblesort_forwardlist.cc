/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:54:55
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-03 07:08:52
 * @FilePath: /practice/sort/forward_list/bubblesort_forwardlist.cc
 */
#include "myforward_list.hpp"

//have bug

bool bubble(Node* head,Node* sortedHead){
  Node dummy;
  dummy._next=head;

  Node* prev=&dummy;
  Node* cur=head;

  if(NULL==head->_next){//only one node left
  //头插法
    head->_next=sortedHead->_next;//sortedHead is a dummy 
    sortedHead->_next=head;
    return true; 
  }

  Node* next=head->_next;

  bool sorted;
  while(next!=NULL){
    sorted=true;
    if(cur->_val > next->_val){
      //cur 与 next 交换
      cur->_next=next->_next;
      next->_next=cur;
      prev->_next=next;

      prev=prev->_next;
      cur=prev->_next;
      next=cur->_next;
      sorted=false;
    }else{
      prev=cur;
      cur=next;
      next=next->_next;
    }
  }
  prev->_next=NULL;//seperate the last node

  //头插法
  cur->_next=sortedHead->_next;//
  sortedHead->_next=cur;
  return sorted;
}

Node* bubblesort(Node* head){
  if(!head) return NULL;
  Node sorted;
  Node* sortedHead=&sorted;
  
  // Node* cur=head;
  // while(cur!=NULL){//循环次数????
  while(1){//直到有序,break
      bool sortedflag=bubble(head,sortedHead);
      if(sortedflag) break;
      // cur=cur->_next;
  }
  return sorted._next;
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
  Node* newhead = bubblesort(fl.getListHead()->_next);
  printList(newhead);

  return 0;
}