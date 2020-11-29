//
//  main.cpp
//  栈最值
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include "StackWithMin.cpp"//与两个queue实现stack的加载头文件的方式不同？？？？？
//#include "StackWithMin.hpp"
#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    stack<int> s;
    StackWithMin<int> S;
    S.Push(4);
    S.Push(4);
    S.Push(5);
    S.Push(6);
    S.Push(61);
    S.Push(62);
    S.Push(63);
    cout<<S.Top()<<endl;
    cout<<S.Min()<<endl;
    cout<<S.Max()<<endl;
    S.Pop();
    S.Pop();
    cout<<endl;
    cout<<S.Top()<<endl;
    cout<<S.Min()<<endl;
    cout<<S.Max()<<endl;
    S.Pop();
    S.Push(163);
    S.Push(1);
    S.Push(2);
    cout<<endl;
    cout<<S.Top()<<endl;
    cout<<S.Min()<<endl;
    cout<<S.Max()<<endl;
    return 0;
}
