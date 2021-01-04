//
//  main.cpp
//  8 typedef #define等
//
//  Created by ChengWang on 1/23/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <cstdio>
#include <iostream>
#define PI 3.14
typedef struct Student_tag{
    int age;
    Student_tag *  s;
    int grade;
} Student, * pStuent;

typedef struct Node_tag{
    int val;
    Node_tag*next;
} Node,*pNode;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    printf("%f\n",PI);
    
    
    return 0;
}
