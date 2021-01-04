//
//  main.cpp
//  power(a,n)
//
//  Created by ChengWang on 3/23/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
double power_v1(int a, int n);
double power_v2(int a, int n);
double power_v3(int a, int n);
double power_v4(int a, int n);
double power_v5(int a, int n);

int main(int argc, const char * argv[]) {
        // insert code here...
    std::cout << "Hello, World!\n";
    for(int i=0;i<21;++i){
        cout<<pow(2,i)<<endl;
//        cout<<power_v1(2,i)<<endl;
//        cout<<power_v2(2,i)<<endl;
//        cout<<power_v3(2,i)<<endl;
        cout<<power_v4(2,i)<<endl;
        cout<<power_v5(2,i)<<endl;
    }
    return 0;
}

double power_v1(int a, int n){
    if(0==n)
        return 1;
    if(1==n)
        return a;
    double res=1;
    if(n%2==1){
        res= power_v1(a,(n-1)/2);
        res=res*res*a;
    }
    else{
        res= power_v1(a,n/2);
        res=res*res;
    }
    return res;
}



double power_v2(int a, int n){
    if(0==n)
        return 1;
    if(1==n)
        return a;
    double res= power_v1(a,n/2);
    if(n&1){//奇数
        res=res*res*a;
    }
    else{
        res=res*res;
    }
    return res;
}

double power_v3(int a, int n){
    if(0==n)//
        return 1;
    double res= power_v1(a,n/2);
    res = n&1 ? res*res*a:res*res;
    return res;
}

double power_v4(int a, int n){
//double power_v4(int a, int n){
    if(n<0)
        return 1.0/power_v4(a,-n);
    if(0==n)//
        return 1;
    double res= power_v1(a,n/2);
    res = n&1 ? res*res*a:res*res;
    return res;
}




//迭代
//利用二进制位展开

double power_v5(int a, int n){
    int res=1;
    int tmp=a;
    while(n){
        if(n&1)
            res*=tmp;
        n>>=1;
        tmp = tmp*tmp;
    }
    return res;
}
