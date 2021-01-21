/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-21 10:44:45
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-21 10:45:27
 * @FilePath: /practice/algorithm/interview/JosephCicle华为一面.cc
 */
/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-21 09:28:31
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-21 16:46:22
 * @FilePath: /undefined/Users/ChengWang/Untitled-1.cc
 */

#include<iostream>
#include<vector>
using namespace std;
int main(){
  int len=100;
  int m=5;
  vector<bool> v(len,true);
  int i=0;
  vector<int> res;
  while(len-1==(int)res.size()){
   int j=0;
    while(j<5){
      if(v[i]==true){
        j++;
      }
      if(j==5){
        cout<<i+1<<",";
        res.push_back(i);
        v[i]=false;
      }
      ++i;
      i=i%len;
    }
  }
  cout<<endl;
  return 0;
}