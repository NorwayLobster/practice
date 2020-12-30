/*
 * @Author: your name
 * @Date: 2020-12-01 20:18:47
 * @LastEditTime: 2020-12-02 15:00:58
 * @LastEditors: ChengWang
 * @Description: In User Settings Edit
 * @FilePath: /practice/sort/forward_list/sort.cc
 */

#include "myforward_list.hpp"
#include <algorithm>


Node* prev(myForwardList& fl,Node*p){
  Node *head=fl.getListHead();
  Node *cur=head;
  while(cur!=NULL){
    // cout<<"cur:"<<cur<<endl;
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


void myswap(myForwardList& fl,Node*& p1,Node*& p2){
  if(p1==p2) return ;
   Node* pre1=prev(fl,p1);
   Node* pre2=prev(fl,p2);
   Node*tmp;
   tmp=p2->_next;
   p2->_next=p1->_next;
   p1->_next=tmp;

   pre1->_next=p2;
   pre2->_next=p1;
   std::swap(p1,p2);//very important
}


Node * partition(myForwardList& fl, Node*left,Node*right){//time complexity????
  Node* p_pivot=left; 
  Node* pBoundary=left;
  // for(auto p=left+1;p<=right;p=p->_next){
  // for(auto p=left->_next;p<=right;p=p->_next){//怎么比较p和right在链表中的先后关系

  //bug: dead loop, why???????????
  for(auto p=left->_next;p!=right->_next;p=p->_next){//怎么比较p和right在链表中的先后关系
    if(p->_val < p_pivot->_val){
      pBoundary=pBoundary->_next;//to be improved
      myswap(fl,pBoundary,p);//p已经指到pBoundary的位置了
      // std::swap(pBoundary,p);
    }
  }

  pBoundary=pBoundary->_next;
  myswap(fl,left,pBoundary);
  // std::swap(pBoundary,left);
  return pBoundary;
}

// int listPartition(Node**head,int val){ 
Node * partition_v1(myForwardList& fl, Node*left,Node*right){//time complexity????
  // fl.print();
  Node* p_pivot;
  Node* newHead;
  Node* newTail;
  Node* prev_left=prev(fl,left);
  Node* next_right=next(fl,right);
  cout<<"next_righ:"<<next_right<<endl;
  int val=left->_val;//pivot
	// if(*head==NULL)  return -1;
	Node less;//3个临时哨兵
	Node equal;
	Node more;
	// Node * cur=*head;
	// Node * cur=fl.getListHead()->_next;
	Node * cur=left;
	Node * curLess=&less;
	Node * curEqual=&equal;
	Node * curMore=&more;
	// while(NULL!=cur){
	while(right->_next!=cur){
		if(cur->_val>val){
			curMore->_next=cur;	
			curMore=curMore->_next;
		}else if(cur->_val<val){
			curLess->_next=cur;	
			curLess=curLess->_next;
		}else{
			curEqual->_next=cur;	
			curEqual=curEqual->_next;
		}
		cur=cur->_next;
	}
  
  p_pivot=equal._next;

	if(less._next!=NULL && more._next!=NULL){
    newHead=less._next;
    newTail=curMore;

		curLess->_next=equal._next;
		curEqual->_next=more._next;
  } else if(less._next==NULL && more._next==NULL){
    newHead=equal._next;
    newTail=curEqual;
  } else if(less._next==NULL){
    newHead=equal._next;
    newTail=curMore;

		curEqual->_next=more._next;
  }else{ // if(more._next==NULL){
    cout<<"hello"<<endl;
    newHead=less._next;
    newTail=curEqual;

		curLess->_next=equal._next;
  }

	prev_left->_next=newHead;
  newTail->_next=next_right;

  // fl.print();
  return p_pivot; 
}
void quicksort(myForwardList& fl,Node*left,Node*right){
  cout<<"left :"<<left<<endl;
  cout<<"right:"<<right<<endl;
  if(left==right||left==right->_next) return ;//left 相等或right在left的前面
  // if(left>=right) return ;
  // Node *p_pivot=partition(fl,left,right);
  Node *p_pivot=partition_v1(fl,left,right);
  cout<<"p_pivot:"<<p_pivot<<endl;
  // fl.print();
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
  cout<<"last val:"<<last->_val<<","<<last<<endl;
  Node* p2=prev(fl,last);
  cout<<"prev(last):"<<p2<<endl;
  Node *p1=next(fl,prev(fl,last));
  cout<<"last:"<<p1<<endl;
  // return 0;
  quicksort(fl,fl.getListHead()->_next,last);
  // fl.print();
}
