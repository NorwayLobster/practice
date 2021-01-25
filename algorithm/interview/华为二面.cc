/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-22 15:41:53
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-22 09:37:21
 * @FilePath: /practice/algorithm/interview/华为二面.cc
 */
#include<iostream>
#include<vector>
using namespace std;
//王成
/*
直角三角形，边长a,b,c，周长等于N,求符合要求的所有的组合
*/
int main(){
  int p=100;
  // for(int x=1;x<p;++x){//O(p^2)
  //   for(int y=1;y<p;++y){
  //     if(x*x+y*y==(p-x-y)*(p-x-y)){
  //       cout<<x<<","<<y<<","<<p-x-y<<endl;
  //     }
  //   }
  // }
  //优化
  for(int x=1;x<p/2;++x){//O(p*p)
    for(int y=p/2-x;y<p && y>=0;++y){
      if(x*x+y*y==(p-x-y)*(p-x-y)){
        cout<<x<<","<<y<<","<<p-x-y<<endl;
      }
    }
  }
  return 0;
}
