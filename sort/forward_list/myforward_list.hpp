/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 10:12:20
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-02 10:53:39
 * @FilePath: /practice/sort/forward_list/myforward_list.hpp
 */

#ifndef __myForward_List_Hpp__
#define __myForward_List_Hpp__
#include <iostream>
using std::cout;
using std::endl;

struct Node{
	int _val;
	Node * _next;
	~Node() {cout<<"~Node()"<<" _val:"<<_val<<endl;}
	Node()
		:_val(100)
		,_next(NULL) 
	{cout<<"Node()"<<endl;}
	Node(int ele)
		:_val(ele)
		,_next(NULL) 
	{cout<<"Node(int)"<<endl;}
};

class myForwardList{
  public:
//Member types: 成员类型
  // value_type
  // const_iterator
  // iterator
  // ...
    myForwardList();
    myForwardList(const myForwardList&);
    ~myForwardList();
    void push_front(int element);
    void pop_front();
    void print();
    void quicksort();
    // void insert_after();
    // void erase_after();
    size_t size();
    void clear();
  private:
  Node *_pListHead;
};

// class iterator{ };
#endif 

// void buildList(Node**head,int i){
// 	*head=(Node*)calloc(1,sizeof(Node));
// //	(*head)->_val=i;
// 	cout<<"i:"<<i<<endl;
// 	Node*pre=*head;
// 	Node*pnew=NULL;
// 	while(--i){
// //		pnew = (Node*)calloc(1,sizeof(Node));
// 		pnew=new Node;
// //		pnew=new Node();
// //		pnew=new Node[1]();
// 		pnew->_val=i;
// 		cout<<"i:"<<i<<endl;
// 		pre->_next=pnew;
// 		pre=pre->_next;
// 	}
// }


