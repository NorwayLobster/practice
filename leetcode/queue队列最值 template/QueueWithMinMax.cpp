//
//  QueueWithMinMax.cpp
//  queue队列最值
//
//  Created by ChengWang on 12/23/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
#include "QueueWithMinMax.hpp"
template<typename T> void QueueWithMinMax<T>::Push(T element){
    if(Q.empty()){
        MinDeQ.push_front(element);
        MaxDeQ.push_front(element);
    }
    else{
        while(!MinDeQ.empty()&&element<MinDeQ.back()){
            MinDeQ.pop_back();//等于的 留在里面
        }
        MinDeQ.push_back(element);
        while(!MaxDeQ.empty()&&element>MinDeQ.back()){
            MaxDeQ.pop_back();
        }
        MaxDeQ.push_back(element);
        
    }
        Q.push(element);
}
template<typename T> void QueueWithMinMax<T>::Pop(){
    assert(!Q.empty());
    if(Q.front()==MinDeQ.front())
        MinDeQ.pop_front();
    if(Q.front()==MaxDeQ.front())
        MaxDeQ.pop_front();
    Q.pop();
}

template<typename T> T QueueWithMinMax<T>::Front(){
    return Q.front();
}
template<typename T> T QueueWithMinMax<T>::Back(){
    return Q.back();
}
template<typename T> T QueueWithMinMax<T>::Max(){
    return MaxDeQ.front();
}
template<typename T> T QueueWithMinMax<T>::Min(){
    return MinDeQ.front();
}
