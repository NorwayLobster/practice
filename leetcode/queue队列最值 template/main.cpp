//
//  main.cpp
//  queue队列最值
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

//wrong:
#include "QueueWithMinMax.cpp"
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    QueueWithMinMax<int> Q;
    Q.Push(-1);
    Q.Push(1);
    Q.Push(2);
    cout<<Q.Front()<<endl;
    cout<<Q.Back()<<endl;
    cout<<endl;
    cout<<Q.Min()<<endl;
    cout<<Q.Max()<<endl;
    Q.Push(11);
    Q.Push(21);
    Q.Push(41);
    cout<<Q.Front()<<endl;
    cout<<Q.Back()<<endl;
    cout<<Q.Min()<<endl;
    cout<<Q.Max()<<endl;
    cout<<endl;
    Q.Pop();
    
    
    return 0;
}
