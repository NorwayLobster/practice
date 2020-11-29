//
//  QueueWithMinMax.hpp
//  queue队列最值
//
//  Created by ChengWang on 12/23/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#ifndef QueueWithMinMax_hpp
#define QueueWithMinMax_hpp

#include <deque>
#include <queue>
using std::deque;
using std::queue;
template<typename T> class QueueWithMinMax{
public:
    QueueWithMinMax(){}
    ~QueueWithMinMax(){}
    void Push(T);
    void Pop();
    T Back();
    T Front();
    T Min();
    T Max();
private:
    //比大小运算符
    
private:
    queue<T> Q;
    deque<T> MinDeQ;
    deque<T> MaxDeQ;
};

#endif /* QueueWithMinMax_hpp */
