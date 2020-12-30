/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 07:45:24
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-03 03:10:03
 * @FilePath: /practice/sort/forward_list/mergesort_forwardlist.cc
 */

/**
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "myforward_list.hpp"

Node *findMiddlePos(Node *head){
  if (!head)
    return head;
  Node* fast = head;
  Node* slow = head;

  while (nullptr != fast->_next && nullptr != fast->_next->_next)
  {
    fast = fast->_next->_next;
    slow = slow->_next;
  }
  //even:slow和slow->next之间平分节点，n/2,n/2 ;
  ///odd,slow位于正中心，left:n/2+1,right:n/2
  return slow;
}

//升序排序
Node *merge_v1(Node *p1, Node *p2){
  Node dummy(-1);
  Node *p = &dummy;
  while (nullptr != p1 && nullptr != p2)
  {
    if (p1->_val < p2->_val)//升序
    {
      p->_next = p1;

      p = p->_next;
      p1 = p1->_next;
    } else {
      p->_next = p2;

      p = p->_next;
      p2 = p2->_next;
    }
  }
  if (nullptr != p1){
    p->_next = p1;
  }else{// if (nullptr != p2)
    p->_next = p2;
  }
  // p->next=nullptr;
  return dummy._next;
}

//降序排序
Node* mymerge(Node* p1,Node* p2){
  Node merged;
  if(NULL==p1 && NULL==p2) return NULL;
  if(NULL==p1) return p2;
  if(NULL==p2) return p1;
  Node* cur1=p1;
  Node* cur2=p2;
  Node* cur3=&merged;
  while(cur2!=NULL && cur1!=NULL){
    if(cur1->_val > cur2->_val){//降序排序
        cur3->_next=cur1;

        cur3=cur3->_next;
        cur1=cur1->_next;
    }else{
        cur3->_next=cur2;

        cur3=cur3->_next;
        cur2=cur2->_next;
    }
  }
  if(cur1!=NULL){
    cur3-> _next=cur1;
  }
  if(cur2!=NULL){
    cur3-> _next=cur2;
  }
  return merged._next;
}

Node *mergesort(Node *head) {
  // O(n log n) time, merge sort
  // using constant space complexity
  if (!head || nullptr == head->_next)
    return head;

  auto iter = findMiddlePos(head); //fast and slow pointer

  //split
  // cout << "iter:" << iter->_val << endl;
  Node *middle= iter->_next;//不是正中
  iter->_next = nullptr;//split

  //devide and conquer, sort left, and sort right
  Node *new1 = mergesort(head);
  Node *new2 = mergesort(middle);
  //merge
  return merge_v1(new1, new2);
  // return head;
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
  myForwardList fl1;
  fl.push_front(-1);
  fl1.push_front(-2);
  // fl.pop_front();
  for(int i=0;i<10;i=i+2){ fl.push_front(i); }//降序排列
  for(int i=-1;i<10;i=i+2){ fl1.push_front(i); }//降序排列

  fl.print();
  fl1.print();
  cout<<"size:"<<fl.size()<<endl;
  cout<<"size:"<<fl1.size()<<endl;
  cout<<endl;

  Node* newhead=mymerge(fl.getListHead()->_next,fl1.getListHead()->_next);
  fl1.getListHead()->_next=NULL;//vital
  fl.getListHead()->_next=NULL;
  printList(newhead);

  Node* newhead1 = mergesort(newhead);
  // cout<<"size:"<<fl.size()<<endl;
  printList(newhead1);

  return 0;
}