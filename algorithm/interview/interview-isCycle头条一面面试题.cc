/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-11 13:26:48
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-11 13:27:11
 * @FilePath: /practice/algorithm/sort/list/isCycle头条一面面试题.cc
 */
#include <iostream>
using namespace std;
struct ListNode{
    ListNode* next;
    int val;
    ListNode(int _val)
       :next(nullptr)
        ,val(_val)
       {}
};
ListNode* buildList(){
    ListNode dummy(-1);
    ListNode* cur=&dummy;
    
    ListNode* pnew=new ListNode(1);
    cur->next=pnew;
    cur=cur->next;
    
    ListNode* tmp;
    pnew=new ListNode(2);
    tmp=pnew;
    cur->next=pnew;
    cur=cur->next;
    
    pnew=new ListNode(3);
    cur->next=pnew;
    cur=cur->next;
    
    cur->next=tmp;
    return dummy.next;
}
bool isCycle(ListNode* head){
    if(nullptr==head) return false;
    ListNode* fast=head;
    ListNode* slow= head;
    while(nullptr!=fast && nullptr!=fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
    ListNode* head=buildList();
    bool flag=isCycle(head);
    cout<<"flag:"<<flag<<endl;
    return 0;
}