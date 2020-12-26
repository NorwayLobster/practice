/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-25 22:56:44
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-26 09:27:06
 * @FilePath: /practice/algorithm/dp/1-求解整数n的拆分问题-李春葆8.2.cc
 */

#include <iostream>
#include <vector>
using namespace std;
// n>k, f(n,k)=f(n-k,k)+f(n,k-1)
// n=k, f(n,k)=f(n-n,n)+f(n,n-1)=f(0,n)+f(n,n-1)=1+f(n,n-1)
// n<k, f(n,k)=f(n,n)
// 1==n || 1==k, f(n,k)=1

//time, O(n), time: O(n*n)
int split(vector<vector<int>>& dp, int i, int j){
  if(dp[i][j]>0){
    return dp[i][j];
  }

  if(1==i || 1==j){
    dp[i][j]=1;
  }else if(j<i){
    dp[i][j]=split(dp,i-j,j)+split(dp,i,j-1);
  }else if(j==i){
    dp[i][j]=1+split(dp,i,j-1);
  }else{//j>i
    dp[i][j]=split(dp,i,i);
  }

  return dp[i][j];
}

//time, O(n), time: O(n*n)
int split(int n, int k){
  vector<vector<int>> dp(n+1,vector<int>(k+1,1));
  for(int i=1; i<=n;++i){
    for(int j=1; j<=k; ++j){
      if(1==i || 1==j){
        dp[i][j]=1;
      }else if(j<i){
        dp[i][j]=dp[i-j][j]+dp[i][j-1];
      }else if(j==i){
        dp[i][j]=1+dp[i][j-1];
      }else{//j>i
        dp[i][j]=dp[i][i];
      }
    }
  }
  return dp[n][k];
}
int main(){
  int n=10;
  int k=11;
  vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
  cout<<"res:"<<split(n,k)<<endl;
  cout<<"n=5,k=5,res:"<<split(5,5)<<endl;
  cout<<"n=5,k=5,res:"<<split(dp,5,5)<<endl;
  return 0;
}