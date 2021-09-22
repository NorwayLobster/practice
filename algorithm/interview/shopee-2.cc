#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    ListNode* next;
    int val;
    ListNode()
    :next(nullptr)
    ,val(0)
    {}
    ListNode(int val1)
    :next(nullptr)
    ,val(val1)
    {}
};
ListNode* reverseList(ListNode* start, ListNode* tail);
ListNode* reverseListMToN(ListNode* root,int m, int n){
    if(nullptr==root) return root;
    //m,n are valid
    ListNode dummy;
    dummy.next=root;
    ListNode* cur=&dummy;
    ListNode* nodeBeforeStart=nullptr;
    ListNode* nodeAfterTail=nullptr;
    //step0: find start, tail node
    for(int i=0;i<m-1;++i){//get to the node before start
        cur=cur->next;
    }
    nodeBeforeStart=cur;
    ListNode* start=cur->next;

    cur=&dummy;
    for(int i=0;i<n;++i){//get to the tail node
        cur=cur->next;
    }
    ListNode* tail=cur;
    nodeAfterTail=cur->next;
    //step1: reverse
    ListNode* newHead=reverseList(start, tail);
    //step2: splice the list
    nodeBeforeStart->next=newHead;
    start->next=nodeAfterTail;
    return dummy.next;
}
ListNode* reverseList(ListNode* start, ListNode* tail){
    ListNode* cur=start;
    ListNode* next=nullptr;
    ListNode* prev=nullptr;
    while(cur!=tail){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    tail->next=prev;
    return tail;
}
int main(){
    ListNode root(1);
    ListNode node1(2);
    ListNode node2(3);
    ListNode node3(4);
    root.next=&node1;
    root.next->next=&node2;
    root.next->next->next=&node3;
    ListNode* res=reverseListMToN(&root,1,2);
    ListNode* cur=res;
    while(cur!=nullptr){
        cout<<"cur:"<<cur->val<<endl;
        cur=cur->next;
    }
    return 0;
}