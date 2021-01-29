/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-26 21:46:54
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-26 16:49:05
 * @FilePath: /practice/algorithm/dp/knapsack/subsetSum.cc
 */

/*
 子集和问题(同样是0-1, 物体个数只有一个): W容量的背包，一系列物体，使得包包装的重量最大, 求最大能装多重
 (子集: 原始集合的子集, 元素要么出现一次，要么出现0次)
*/
//note: 与0-1knapsack问题的区别是:  0-1背包求最大价值，而subsetSum求可以装下的最大重量

#include<iostream>
#include<vector>
using namespace std;

//not better
int knapsack0_1(const vector<int>& weight, const vector<int>& value, int N){
  int len=weight.size();
  vector<vector<int>> dp(len,vector<int>(N+1,0));//与v2区别:此处的i为下标

  //init: i=0时,
  for(int j=0;j<N;++j){
    if(weight[0]<=j){
      dp[0][j]=value[0];
    }else{
      dp[0][j]=0;
    }
  }
  for(int i=1;i<len;++i){
    for(int j=0;j<=N;++j){
      if(weight[i]<=j){
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
      }else{//note: vital here
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[len-1][N];
}

//better one
int knapsack0_1_v2(const vector<int>& weight, const vector<int>& value, int N){
  int len=weight.size();
  vector<vector<int>> dp(len+1,vector<int>(N+1,0));//dp[i][j]: 只考虑前i个物体,且容积为j时的最大价值数
  //init: i或w 为0时， dp[][]为0
  for(int i=1;i<=len;++i){//i-th个物体
    for(int j=1;j<=N;++j){
      if(weight[i]<=j){
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
      }else{//note: vital here
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[len][N];
}

int subsetSum(const vector<int>& weight, int N){
  int len=weight.size();
  vector<vector<int>> dp(len+1,vector<int>(N+1,0));//dp[i][j]: 只考虑前i个物体,且容积为j时的最大价值数
  //i或w 为0时， dp[][]为0
  for(int i=1;i<=len;++i){//i-th个物体
    for(int j=1;j<=N;++j){
      if(weight[i]<=j){
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight[i]]+weight[i]);//与knapsack0-1区别: +weight[i]
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[len][N];
}

int main(){
  vector<int> weight={1, 2, 4, 5,8};
  vector<int> value={1, 2, 4, 5,8};
  int totalWeight=10;
  int res=subsetSum(weight, totalWeight);
  int res=knapsack0_1(weight, value, totalWeight);
  return 0;
}