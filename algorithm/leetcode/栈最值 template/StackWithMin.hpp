//
//  StackWithMin.hpp
//  栈最值
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
#ifndef StackWithMin_hpp
#define StackWithMin_hpp
#include <stack>
using std::stack;
template<typename T>
class StackWithMin{
public:
    StackWithMin(){}
    ~StackWithMin(){}
    void Push(T element);
    void Pop();
    T Top();
    T Min();
    T Max();
private:
    stack<T> S;
    stack<T> MinS;
    stack<T> MaxS;
};
#endif
