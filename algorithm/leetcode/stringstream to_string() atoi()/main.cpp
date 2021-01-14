//
//  main.cpp
//  stringstream to_string() itoa()
//
//  Created by ChengWang on 1/5/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using namespace std;
//1. aoti()的要点：1.非法输入的输出？非法输入的情况

//                2. 基本功能的实现
//c++字符串并一定不容易做题, 不一定容易操纵字符串


// 1.非法输入
// 2.边界条件
// 3.基础功能
// 4. 算法时间复杂度
// 5. 算法空间复杂度

//待完善
#if 0
int str2__int128(string & s, __int128 & retval, int & err_no, int depth){
    //1. 非法输入
    //2. 溢出
    //3.基本功能
    if(depth>2){
        err_no=-1;
        return -1;
    }
    if(0==s.size()){
        err_no=-1;
        return -1;
    }
    if('-'!=s[0]||'+'==s[0]){
        string tmp(s.begin()+1,s.end());
        internal(tmp,retval,err_no,2);
    }else if(invalid()){
        
    }
}
#endif

int globalNum=0;
int internal(const char * str,bool minus){
    long int total=0;
    int flag=minus?-1:1;
    while('\0'!=*str){
        if(*str>='0'&&*str<='9'){
            total=total*10+flag*(*str-'0');
            if(total>INT_MAX||total<INT_MIN){
                globalNum=-1;
                return 0;
            }
            ++str;
        }else{
            globalNum=-1;
            return 0;
        }
    }
    
    return (int)total;
}
int myatoi(const char *str){
    if(NULL==str||str[0]=='\0'){
        globalNum=-1;
        return 0;
    }
    bool minus=false;
    if(str[0]=='+'){
        ++str;
    }else if(str[0]=='-'){
        ++str;
        minus=true;
    }
    
    if('\0'==str[0]){
       globalNum=-1;
       return 0;
    }
    return internal(str, minus);
}
//note:stringstream的可以实现 数值和字符串的相互转化
//atoi() atol() atoll() 字符串转数值
//to_string() 数值转字符串
//注意：存在itoa() ltoa()等函数，但 他们不是标注c库函数
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    stringstream  ss;
    ss<<"hello word!"<<std::endl;
    string s,s1,s2;
    while(ss>>s){
        cout<<s<<endl;
    }
    ss.clear();
    s="1234555";
    ss<<s<<endl;
    int num;
    ss>>num;
    printf("%d\n",num);
    cout<<num<<endl;
    ss.clear();
    int a=12;
    ss<<a<<endl;
    ss>>s;
    printf("%s\n",s.c_str());
//    ss>>s1>>s2;
//    std::cout<<s1<<std::endl;
//    std::cout<<s2<<std::endl;
    string s_1=to_string(num);
    
    printf("%s\n",s_1.c_str());
    int num1=atoi(s.c_str());
    long num2=atol(s.c_str());
    long long num3=atoll(s.c_str());
    printf("%d\n",num1);
    printf("%ld\n",num2);
    printf("%lld\n",num3);
    

    cout<<"------------------"<<endl;
    cout<<"globalNum:"<<globalNum<<endl;
    string str;
    cin>>str;
    cout<<myatoi(str.c_str())<<endl;
    cout<<"globalNum:"<<globalNum<<endl;
    
    
    return 0;
}
