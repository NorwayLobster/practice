// 给定一个单链表，每 k （1 <= k <= 链表长度 ）个节点一组进行翻转，请你返回翻转后的链表。如
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]
struct ListNode{
    ListNode()
    :next(nullptr)
    ,val(0)
    {}
    ListNode *next;
    int val;
};
ListNode* reverseKList(ListNode*head){
    if(nullptr==head) return head;
    if(k<=0) return head;
    int len=0;
    //k is valid
    ListNode* cur=head;
    ListNode* nodeBeforeBegin=nullptr;
    ListNode* begin=nullptr;
    ListNode* tail=nullptr;
    ListNode* nodeAfterTail=nullptr;
    ListNode dummy;
    nodeBeforeBegin=&dummy;
    while(nullptr!=cur){
        begin=cur;
        bool notGetK=false;
        for(int i=0;i<k-1;++i){
                if(nullptr==cur){
                    notGetK=true;
                    break;
                }
                cur=cur->next;
        }
        if(notGetK){
            break;
        }
        tail=cur;
        nodeAfterTail=cur->next;
        ListNode* newBegin=reverseList(begin,tail);
        nodeBeforeBegin->next=newBegin;
        //next step
        cur=nodeAfterTail;
        nodeBeforeBegin=begin;    
    }
    tail->next=cur;
    //mantain last left list
    return dummy.next;
}

ListNode* reverseList(ListNode* head, ListNode* tail){
    ListNode* cur=head;
    ListNode dummy;
    ListNode* next=nullptr;
    ListNode* prev=&dummy;
    while(tail!=cur){
        next=cur->next;
        //
        cur->next=prev;//指向前一个节点
        prev=cur;
        cur=next;
    }
   tail->next=prev;
   return dummy.next;
}