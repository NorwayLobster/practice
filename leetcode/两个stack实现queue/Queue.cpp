//
//  Queue.cpp
//  两个stack实现queue
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include "Queue.hpp"

void Queue::transfer(stack<int> &A,stack<int> &B){//从A中搬动B中
    while(!A.empty()){
        B.push(A.top());
        A.pop();
    }
}
void Queue::Push(int element){
    s1.push(element);
    
}
int Queue::Back(){
    assert(!s2.empty()||!s1.empty());
    if(!s1.empty()){
        return s1.top();
    }
    transfer(s2, s1);
    /*
     while(!s2.empty()){
     s1.push(s2.top());
     s2.pop();
     }
     */
    return s1.top();
    
}
int Queue::Front(){
    assert(!s2.empty()||!s1.empty());
    if(!s2.empty()){
        return s2.top();
    }
    
    transfer(s1, s2);
    /*
     while(!s1.empty()){
     s2.push(s1.top());
     s1.pop();
     }
     */
    return s2.top();
}

void Queue::Pop(){
    assert(!s2.empty()||!s1.empty());
    if(!s2.empty()){
        s2.pop();
        return ;
    }
    transfer(s1, s2);
    /*
     while(!s1.empty()){
     s2.push(s1.top());
     s1.pop();
     }
     */
    s2.pop();
    
}
