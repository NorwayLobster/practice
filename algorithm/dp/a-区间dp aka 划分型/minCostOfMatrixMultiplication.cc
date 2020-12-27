/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-15 18:07:21
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-16 08:43:44
 * @FilePath: /practice/algorithm/dp/minCostOfMatrixMultiplication.cc
 */
#include <iostream>
#include <vector>
using namespace std;
void minCostOfMatrixMultiplication(vector<vector<int>>& dp, vector<vector<int>>& split, const vector<int>&p){
  //init 0
  int len=(int)p.size();
  int n=len-1;//n个矩阵
  for(int r=2;r<=n;r++){//r 链长// r==1, no computation cost
    for(int left=0;left<=n-r;left++){//left boundary: left-th matrix, start from 0
      int right=left+r-1;//right boundary: right-th matrix, 
      dp[left][right]=0+dp[left+1][right]+p[left]*p[left+1]*p[right+1];//init: 以left为分割点 //  A: height*width //  dp[left][left]: p[left]*p[left+1] //  dp[left+1][right]: p[left+1]*p[right+1];
      split[left][right]=left;//init
      for(int k=left+1;k<right;k++){//corner case: split point k, k-th matrix在左边链，所以k最大为right-1; k从left或left+1皆可以
          int tmp=dp[left][k]+dp[k+1][right]+p[left]*p[k+1]*p[right+1];//数学归纳法, 转移方程
          //k-th matrix's width is p[k+1]
          //bugfix: int tmp=dp[left][k]+dp[k+1][right]+p[left]*p[k]*p[right+1];//数学归纳法, 转移方程
          if(tmp<dp[left][right]){
            dp[left][right]=tmp;//update
            split[left][right]=k;
          }
      }
    }
  }
}
void traceback(const vector<vector<int>>& split, int left, int right){
  // if(left>=right){
  if(left==right){
    cout<<"A"<<left;
    return;
  }//one matrix interval

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
  int n=len-1;//the no. of matrix
  cout<<"n:"<<n<<endl;
  vector<vector<int>> m(n, vector<int>(n,0));
  vector<vector<int>> s(n, vector<int>(n,0));
  minCostOfMatrixMultiplication(m,s,p);
  for(auto v:m){
    for(auto e:v){
      cout<<e<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  for(auto v:s){
    for(auto e:v){
      cout<<e<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  cout<<"min cost:"<<m[0][n-1]<<endl;
  traceback(s,0,n-1);
  return 0;
}