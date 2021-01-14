//
//  main.cpp
//  a_Multiply_b
//
//  Created by ChengWang on 3/23/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cmath>

double power_v1(int a, int n);
using  namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<power(2,5)<<endl;
    cout<<2<<endl;
    cout<<power_v1(2,5)<<endl;
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
