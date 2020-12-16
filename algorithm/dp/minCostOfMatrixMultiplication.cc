/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-15 18:07:21
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-16 15:48:37
 * @FilePath: /practice/algorithm/dp/minCostOfMatrixMultiplication.cc
 */
#include <iostream>
#include <vector>
using namespace std;
void minCostOfMatrixMultiplication(vector<vector<int>>& dp, vector<vector<int>>& split, const vector<int>&p){
  //init 0
  int len=(int)p.size();
  int n=len-1;//n个矩阵
  for(int r=2;r<len;r++){//r 链长// r==1, no computation cost
    for(int left=0;left<len;left++){//left boundary
      int right=left+r-1;//right boundary
      dp[left][right]=dp[left][left]+dp[left+1][right]+p[left]*p[left+1]*p[right];//init: 以left为分割点 //  A: height*width //  dp[left][left]: p[left]*p[left+1] //  dp[left+1][right]: p[left+1]*p[right];
      split[left][right]=left;//init
      for(int k=left+1;k<right;k++){//corner case: split point k, k-th matrix在左边链，所以k最大为right-1; k从left或left+1皆可以
          int tmp=dp[left][k]+dp[k+1][right]+p[left]*p[k]*p[right];//数学归纳法, 转移方程
          if(tmp<dp[left][right]){
            dp[left][right]=tmp;//update
            split[left][right]=k;
          }
      }
    }
  }
}
void traceback(const vector<vector<int>>& split, int left, int right){
  if(left>=right) return;//empty interval
  if(left<split[left][right]){ cout<<'('; }
  traceback(split, left, split[left][right]);
  if(left<split[left][right]){ cout<<')'; }

  if(split[left][right]+1<right){ cout<<'('; }
  traceback(split, split[left][right]+1,right);
  if(split[left][right]+1<right){ cout<<')'; }
}
int main(){
  vector<int> p={30,35,15,5,10,20,25};
  int len=p.size();
  vector<vector<int>> m(len, vector<int>(len,0));
  vector<vector<int>> s(len, vector<int>(len,0));
  minCostOfMatrixMultiplication(m,s,p);
  cout<<"min cost:"<<m[0][len-1]<<endl;
  traceback(s,0,len-1);
  return 0;
}