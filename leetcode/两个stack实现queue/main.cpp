//
//  main.cpp
//  两个stack实现queue
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

//#include "Queue.cpp"//加上会报错：ld: 5 duplicate symbols for architecture x86_64
#include "Queue.hpp"
#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

//Queue：先进先出

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Queue Q;
    queue<int> q;
//    Q.Pop();
    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    Q.Push(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<Q.Front()<<endl;
    cout<<q.front()<<endl;
    cout<<Q.Back()<<endl;
    cout<<q.back()<<endl;
    Q.Pop();
    q.pop();
    cout<<Q.Front()<<endl;
    cout<<q.front()<<endl;
    Q.Pop();
    q.pop();
    cout<<Q.Front()<<endl;
    cout<<q.front()<<endl;
    Q.Push(6);
    q.push(6);
    Q.Pop();
    q.pop();
    cout<<Q.Front()<<endl;
    cout<<q.front()<<endl;
    cout<<Q.Back()<<endl;
    cout<<q.back()<<endl;
    Q.Pop();
    q.pop();


    Q.Pop();
    q.pop();
    
   //此时Q为空
//    Q.Pop();
//    cout<<Q.Front()<<endl;
//    cout<<q.front()<<endl;
    return 0;
}
