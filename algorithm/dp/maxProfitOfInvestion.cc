/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-16 11:36:45
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-16 12:28:16
 * @FilePath: /practice/algorithm/dp/maxProfitOfInvestion.cc
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//n个项目,m万元
//time complexity: O(nm)
//space complexity: O(n*m*m)
void invest(int m, int n, vector<vector<int>>& f,vector<vector<int>>& dp, vector<vector<int>>& info){
  //dp[i][j]: 前i个项目投j万元产生的最大收益
  //init
  // dp[1][1]=

  for(int i=1;i<=n;i++){//n个项目,m万元
    for(int j=1;j<=m;j++){//前i项目共投j万元, 
      dp[i][j]=0;//init
      for(int k=0;k<=j;k++){//第i-th项目投k万元
        int tmp=f[i][k]+dp[i-1][j-k];//init
        if(tmp>dp[i][j]){
          info[i][j]=k;////前i项目共投j万元时，i-th项目投k万元,收益最大
          dp[i][j]=tmp;
        }
      }
    }
  }
  cout<<"max profit:"<<dp[n][m]<<endl;
}

void trace(vector<vector<int>>&info,int x, int k){
  if(k==0) return ;
  int tmp=info[k][x];
  trace(info,x-tmp,k-1);
  cout<<k<<"-th project:"<<tmp<<endl;
}

int main(){
  int x=5;//x万元
  int k=4;//k个项目
  vector<vector<int>> f(k+1,vector<int>(x+1,0));
  vector<vector<int>> dp(k+1,vector<int>(x+1,0));
  vector<vector<int>> info(k+1,vector<int>(x+1,0));
  f[1][1]=11;
  f[1][2]=12;
  f[1][3]=13;
  f[1][4]=14;
  f[1][5]=15;

  f[2][2]=5;
  f[2][3]=10;
  f[2][4]=15;
  f[2][5]=20;

  f[3][1]=2;
  f[3][2]=10;
  f[3][3]=30;
  f[3][4]=32;
  f[3][5]=40;
  

  f[4][1]=20;
  f[4][2]=21;
  f[4][3]=22;
  f[4][4]=23;
  f[4][5]=24;

  invest(x,k,f,dp,info);

  for(auto v:dp){
    for(auto e:v){
      cout<<e<<" ";
    }
    cout<<endl;
  }
  trace(info,x,k);
  cout<<endl;
  return 0;
}