/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-31 14:49:46
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-31 14:50:42
 * @FilePath: /practice/algorithm/interview/isCycle声网.cc
 */
// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <unordered_map>
//该题题意条件描述不清楚：重复数值为同一节点？？？？？？？？？？？？？？？
using namespace std;
int main(){
    int a;
    unordered_map<int, int> hash;
    while(cin>>a){
        cout<<a<<endl;
        hash[a]++;
        if(hash[a]>1){
            cout << "true" << endl;
            break;
        }
    }
    cout << "false" << endl;
    return 0;
}