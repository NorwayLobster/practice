 ///
 /// @file    offer18DeleteListNode.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-04 23:17:40
 /// complete: Wed Mar  4 23:41:46 CST 2020

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int _val;
	Node * _next;
};
void deleteNode(Node ** head,Node *p){
	if(NULL==*head) return ;
	if(NULL==p) return ;
	if(*head==p){
		*head=p->_next;//如果头结点又是尾结点，同样适用
		free(p);
		p=NULL;
		return ;
	}

	Node *tmp=p->_next;
	if(NULL!=tmp){
		p->_val=p->_next->_val;
		p->_next=p->_next->_next;
		free(tmp);
		tmp=NULL;
	}else{
		tmp=*head;
		while(NULL!=tmp){
			if(tmp->_next==p)
				break;
			tmp=tmp->_next;
		}
		tmp->_next=NULL;
		free(p);//p为尾结点
		p=NULL;
		//无法置空 pre->_next=NULL 必须循环
	}
}

int main(){


	return 0;
}
