/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:54:55
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-03 04:27:45
 * @FilePath: /practice/sort/forward_list/bubblesort_forwardlist.cc
 */
#include "myforward_list.hpp"
bool bubble(Node* head,Node* sortedHead){
  Node dummy;
  dummy._next=head;
  Node* prev=&dummy;
  Node* cur=head;
  Node* next=head->_next;
  while()
}
Node* bubblesort(Node* head){
  if(!head) return NULL;
  Node sorted;
  Node* sortedHead=&sorted;
  Node* cur=head;
  while(cur!=NULL){
      bool flag=bubble(head,sortedHead);
      if(!flag) break;
      cur=cur->_next;
  }
  return sorted._next;
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