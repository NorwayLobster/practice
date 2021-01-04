//
//  main.cpp
//  9 printf()
//
//  Created by ChengWang on 1/23/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char ch='c';
    string str="chengwang";
    char arr[6]="cheng";
    
    short int aa=123;
    int a=15;
    long int l=10000;
    long long int ll=233424234;
    
    unsigned short int unaa=12;
    unsigned int una=123;
    unsigned long int unl=123;
    unsigned long long int unll=123;
    
    float flt=12.2;
    double dbl=123.34;
    


    printf("字符为 %c \n", ch);
    printf("字符的ASCII码 %d \n", ch);
    
    printf("字符串为%s \n" , str.c_str());
    printf("字符数组为%s \n" , arr);
    
    printf("short整数为 %d\n" ,aa );
    printf("整数为 %d\n" ,a );
    printf("长整数为 %ld\n",l);
    printf("long long为 %lld\n",ll);
    
    printf("\n");
    printf("unsigned short整数为 %d\n" ,unaa );
    printf("unsigned 整数为 %d\n" ,una );
    printf("unsigned 长整数为 %lu\n",unl);
    printf("unsigned long long为 %llu\n",unll);
    printf("unsigned long long为 %lld\n",unll);
    
    printf("\n");
    
    printf("浮点数为 %f \n", flt);
    printf("双精度值为 %lf \n", dbl);
    
    printf("八进制值为 %o \n", a);
    printf("十六进制值为 %x \n", a);
    
    printf("指针 %p\n",arr);
    
  

    return 0;
}
