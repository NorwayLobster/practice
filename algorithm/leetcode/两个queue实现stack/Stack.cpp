//
//  Stack.cpp
//  两个queue实现stack
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
# include "Stack.hpp"
#include <cassert>

//Stack：先进后出
void Stack::Push(int element){
    if(!q1.empty())
        q1.push(element);
    else
        q2.push(element);
}

void Stack::Pop(){
    assert(!q1.empty()||!q2.empty());
    if(!q1.empty()){
        while(1!=q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }
    else{
        while(1!=q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
    }
}

int Stack::Top(){
    assert(!q1.empty()||!q2.empty());
    if(!q1.empty())
        return q1.back();
    else
        return q2.back();
}
