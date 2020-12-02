/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-02 07:45:24
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-02 13:21:49
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


ListNode *sortList(ListNode *head) {
  // O(n log n) time, merge sort
  // using constant space complexity
  if (!head || nullptr == head->next)
    return head;
  auto iter = findMiddlePos(head); //fast and slow pointer
  //split
  cout << "iter:" << iter->val << endl;
  ListNode *slow = iter->next;
  iter->next = nullptr;

  //devide and conquer, sort left, and sort right
  ListNode *new1 = sortList(head);
  ListNode *new2 = sortList(slow);
  //merge
  return mergeList(new1, new2);
  // return head;
}

ListNode *findMiddlePos(ListNode *head)
{
  if (!head)
    return head;
  ListNode *fast = head, *slow = head;

  while (nullptr != fast->next && nullptr != fast->next->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  //even:slow和slow->next之间平分节点，n/2,n/2 ;
  ///odd,slow位于正中心，left:n/2+1,right:n/2
  return slow;
}

ListNode *mergeList(ListNode *p1, ListNode *p2){
  ListNode dummy(-1);
  ListNode *p = &dummy;
  while (nullptr != p1 && nullptr != p2)
  {
    if (p1->val < p2->val)
    {
      p->next = p1;
      p = p->next;
      p1 = p1->next;
    }
    else
    {
      p->next = p2;
      p = p->next;
      p2 = p2->next;
    }
  }
  if (nullptr != p1)
  {
    p->next = p1;
  }
  else if (nullptr != p2)
    p->next = p2;
  // p->next=nullptr;
  return dummy.next;
}


void merge(){

}