/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-25 14:17:46
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-25 14:17:46
 * @FilePath: /practice/algorithm/interview/print多态执行问题-头条二面.cc
 */
#include <cstdio>
class A{
    public:
        A(){
            f();
        }
        virtual void f(){
            printf("A::f\n");
        }
};

class B:public A{
    public:
        virtual void f(){
            printf("B::f\n");
        }
};

int main(){
    B b;
    return 0;
}
