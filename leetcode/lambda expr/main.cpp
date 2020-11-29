//
//  main.cpp
//  lambda expr
//
//  Created by ChengWang on 11/26/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v{12,23,4,53};
    for_each(v.begin(),v.end(),[&](int a){printf("%d_",a);});//捕获实时的值： 捕获引用
    printf("\n");
    auto f=[=](int a)->void{printf("%d_",a);};//捕获当前值：copy
    for_each(v.begin(),v.end(),f);
    printf("\n");
    return 0;
}
