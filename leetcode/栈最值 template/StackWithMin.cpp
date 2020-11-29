//
//  StackWithMin.cpp
//  栈最值
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
#include "StackWithMin.hpp"

template<typename T>
void StackWithMin<T>::Push(T element){
    S.push(element);
    if(MinS.empty()||element<=MinS.top())
        MinS.push(element);
    if(MaxS.empty()||element>=MaxS.top())
        MaxS.push(element);
}
template<typename T>
void StackWithMin<T>::Pop(){
    assert(!S.empty());
    if(S.top()==MinS.top())
        MinS.pop();
    if(S.top()==MaxS.top())
        MaxS.pop();
    S.pop();
}

template<typename T>
T StackWithMin<T>::Top(){
    assert(!S.empty());
    return S.top();
}

template<typename T>
T StackWithMin<T>::Min(){
    assert(!S.empty());
    return MinS.top();
}
template<typename T>
T StackWithMin<T>::Max(){
    assert(!S.empty());
    return MaxS.top();
}
