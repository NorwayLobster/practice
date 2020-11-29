//
//  Queue.hpp
//  两个stack实现queue
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stack>
#include <queue>
using std::queue;
using std::stack;
class Queue{
public:
    Queue(){}
    void Push(int element);
    void Pop();
    int Front();
    int Back();
private:
    void transfer(stack<int> &A,stack<int> &B);
private:
    stack<int> s1;
    stack<int> s2;
};

#endif /* Queue_hpp */
