//
//  main.cpp
//  Fobonaci
//
//  Created by ChengWang on 3/6/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//int f(int n);
//int f(int , int ); //参数声明引用
int f_v1(int , int & );
int f_v2(int n, unordered_map<int , int>& hash);
long long int f_v2(int n, unordered_map<int , long long int>& hash);
long long int f_v3(int n, long long & pre);
long long int f_v4(long long n);
long long int f_v5(long long n);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Fibonacci!\n";
    
    int count=0;
//    unordered_map<int, int> hash;
    unordered_map<int, long long int> hash;
//    cout<<f_v1(55, count);
    cout<<endl;
    cout<<"v2:"<<f_v2(55, hash);
    cout<<endl;
//    cout<<count;
    cout<<endl;
    for(int i =0;i<25;++i){
        count=0;
        cout<<f_v1(i,count)<<' ';
    }
    cout<<endl;
    
#if 1
    for(int i =0;i<25;++i){
        hash.clear();
//        cout<<f_v2(i,hash)<<' ';
        
//        long long pre;
//        cout<<f_v3(i,pre)<<' ';
        
        cout<<f_v5(i)<<' ';
    }
    cout<<endl;
#endif
    
    return 0;
    
}

int f_v1(int n, int & count){
    ++count;
    if(n==0)
        return 0;
    if(1==n)
        return 1;
    return f_v1(n-1, count)+f_v1(n-2, count);
}


//记忆策略 + 递归
//int f_v2(int n, unordered_map<int , int> & hash){
long long int f_v2(int n, unordered_map<int , long long int> & hash){
    
    if(n==0){
        return 0;
    }
    if(1==n)
        return 1;
    if(0==hash[n])
        return hash[n]=f_v2(n-1, hash) + f_v2(n-2, hash);
    else
//    if(0!=hash[n])
        return hash[n];
//    return f_v2(n-1, hash)+f_v2(n-2, hash);
}

//不易于记忆
//记忆策略+线性递归版 from 邓俊辉p25
long long int f_v3(int n, long long & pre){
    if(n==0) {pre = 1; return 0;}//令f(-1)=1; f(0）=0
    long long _pre;
    pre = f_v3(n-1,_pre);
    return pre+_pre;
}
    

//动态规划： //迭代 + 记忆策略
long long int f_v5(long long n){
    int a[n+1];
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=n;++i)
        a[i]=a[i-1]+a[i-2];
    return a[n];
}

//动态规划：优化，空间复杂度为O(1)
long long int f_v4(long long n){
    int g=0, f=1;//令f(-1)=1; f(0）=0
    while(n--){
        //        g=g+f;//左g表当前f(n), 右g表f(n-1),f表f(n-2),f
        g+=f;
        f=g-f;//f表f(n-1),即原来的右g
    }
    return g;
}
