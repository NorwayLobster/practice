#include<bits/stdc++.h>
using namespace std;
class MinStack{
public:
    void push(int x){
        s.push(x);
        if(minS.empty()){
            minS.push(x);
        }else{
            int cur=minS.top();
            if(x<=cur){
                minS.push(x);
            }
        }
    }
    void pop(){
        int cur=s.top();
        s.pop();
        if(cur==minS.top()){
            minS.pop();
        }
    }
    int top(){
        return s.top();
    }
    int getMin(){
        return minS.top();
    }
private:
    stack<int> s;
    stack<int> minS;
};
int main(){
    MinStack ms;
    // ms.push(-2);
    // ms.push(0);
    // ms.push(-3);
    // cout<<"getMin:"<<ms.getMin()<<endl;
    // ms.pop();
    // cout<<"top:"<<ms.top()<<endl;
    // cout<<"getMin:"<<ms.getMin()<<endl;
    cout<<"------test2:-------"<<endl;
    ms.push(2);
    ms.push(2);
    cout<<"getMin:"<<ms.getMin()<<endl;//2
    ms.pop();
    cout<<"getMin:"<<ms.getMin()<<endl;//2
    ms.push(3);
    cout<<"top:"<<ms.top()<<endl;//3
    cout<<"getMin:"<<ms.getMin()<<endl;//2
    ms.push(1);
    cout<<"top:"<<ms.top()<<endl;//1
    cout<<"getMin:"<<ms.getMin()<<endl;//1
    return 0;
}