/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:54:55
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-02 12:28:54
 * @FilePath: /practice/sort/forward_list/main.cc
 */
#include "myforward_list.hpp"
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
  return 0;
  Node *Last;
  Node* cur=fl._pListHead;
  while(cur->_next!=NULL){
    cur=cur->_next; 
  }
  last=cur;
  quicksort(fl,fl._pListHead->_next,last);
  fl.print();
}
