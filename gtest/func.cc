 ///
 /// @file    func.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-09-16 17:10:40
 ///
 
#include <iostream>
#include <cmath>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

bool is_prime(int num) {
    if (num < 2)
        return false;
    for(int i = 2; i <= sqrt(num) + 1; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int func_null(){
	int* p=NULL;
	*p=10;
	return 0;
}

int Abs(int x){ return x > 0 ? x : -x; }
