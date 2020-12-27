/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-25 22:13:01
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-25 22:22:51
 * @FilePath: /practice/algorithm/dp/fibonacci.cc
 */

#include <iostream>
#include <vector>
using namespace std;
int fib(int n){
  if(1 ==n || 2 == n){
    return 1;
  }
  return fib(n-1)+fib(n-2);
}
int fib_dp(int n){//time, O(n), space, O(1)
  int pre=1;
  int prepre=1;
  int cur=0;
  for(int i=3;i<=n;i++){
      cur=pre+prepre;
      prepre=pre;
      pre=cur;
  }
  return cur;
}
int main(){
  int n=10;
  int res=fib(n);
  cout<<"res:"<<res<<endl;
  cout<<"dp:"<<fib_dp(n)<<endl;
  return 0;
}