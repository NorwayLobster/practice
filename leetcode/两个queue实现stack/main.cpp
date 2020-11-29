//
//  main.cpp
//  两个queue实现stack
//
//  Created by ChengWang on 12/22/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include "Stack.hpp"
//#include "Stack.cpp"
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Stack S;
    stack<int> s;
    s.push(1);
    S.Push(1);
    cout<<S.Top()<<endl;
    cout<<s.top()<<endl;
    s.push(2);
    S.Push(2);
    S.Pop();
    s.pop();
    s.push(4);
    S.Push(4);
    cout<<S.Top()<<endl;
    cout<<s.top()<<endl;
    s.push(5);
    S.Push(5);
    cout<<S.Top()<<endl;
    cout<<s.top()<<endl;
    s.push(3);
    S.Push(3);
    cout<<S.Top()<<endl;
    cout<<s.top()<<endl;
    S.Pop();
    s.pop();
    s.push(6);
    S.Push(6);
    s.push(61);
    S.Push(61);
    S.Pop();
    s.pop();
    cout<<S.Top()<<endl;
    cout<<s.top()<<endl;
    return 0;
}
