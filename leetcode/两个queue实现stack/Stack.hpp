//
//  Stack.hpp
//  两个queue实现stack
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
#ifndef Stack_hpp
#define Stack_hpp
#include <queue>
using std::queue;
class Stack{
public:
    Stack(){}
    void Pop();
    int Top();
    void Push(int);
private:
    queue<int> q1;
    queue<int> q2;
};

#endif /*Stack_hpp*/
