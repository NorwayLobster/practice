//
//  main.cpp
//  4 比较器函数对象 比较运算符重载
//
//  Created by ChengWang on 1/23/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
int main(int argc, const char * argv[]) {
    // insert code here...
    Student s1;
    s1.age=10;
    s1.grade=10;
    s1.name="chengwang";
    pStuent p1= &s1;
    s1.s=p1;
    
    std::cout << "Hello, World!\n";
    vector<int> v1={1,2,34,56,12312,33,4,43,23};
    vector<int> v2={1,2,3,4,5,6,12,31,2,33,4,43,23};
    printVector(v1);
    printVector(v2);
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),cmp());
//    priority_queue<>(<#const priority_queue<_Tp, _Container, _Compare> &__q#>)
//    sort(v1.begin(),v1.end(),greater<int>());
//    sort(v1.begin(),v1.end(),less<int>());
//    sort(v2.begin(),v2.end());
    printVector(v1);
    printVector(v2);
    
    
    
    
    return 0;
}
void printVector(vector<int> &v){
    for(auto ele:v)
        printf("%d_",ele);
    printf("\n");
}
