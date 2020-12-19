/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-16 12:45:08
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-19 02:24:31
 * @FilePath: /practice/algorithm/dp/knapsackUnlimitedItems.cc
 */

#include <iostream>
#include <vector>
using namespace std;
using itemNo=int;
using Weight=int;

//完全背包: 优化
//time complexity optimization: O(N*b)
void knapsack_v1(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
  //init
    dp[1][b]=b/weight[1]*value[1];//只考虑前1个物品

    for(int i=1;i<=n;i++){//只考虑前i个物品
      for(int j=0;j<=b;j++){//总重限制为j
        if(j-weight[i]<0){
          dp[i][j]=dp[i-1][j];
          info[i][j]=info[i-1][j];
        }else{
          dp[i][j]=max(dp[i-1][j],value[i]+dp[i][j-weight[i]]);
          info[i][j]=dp[i-1][j]>value[i]+dp[i][j-weight[i]] ? info[i-1][j]: i;
        }
      }
    }
}


//完全背包
//time complexity: O(N*b*(j/weight[i]))
void knapsack(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
    for(int i=1;i<=n;i++){//只考虑前i个物品
      cout<<"i:"<<i<<endl;
      for(int j=0;j<=b;j++){//总重限制为j
        cout<<"j:"<<j<<endl;
        // dp[i][j]=0;
        for(int k=0;k*weight[i]<=j;++k){
        // for(int k=0;k<=j/weight[i];++k){
          int tmp=k*value[i]+dp[i-1][j-k*weight[i]];//note: 前i-1个物品的最大值
          if(tmp>dp[i][j]){
            dp[i][j]=tmp;
            info[i][j]=k;//k个i-th item
          }
        }
      }
    }
}

void trace(vector<vector<int>>& info){

}

int main(){
  // vector<int> value={1,3,5,9}; fatal error
  vector<int> value={0,1,3,5,9};//index 0 is a placeholder
  vector<int> weight={0,2,3,4,7};
  itemNo n=4;
  Weight b=10;
  vector<vector<int>> dp(n+1,vector<int>(b+1,0));
  vector<vector<int>> info(n+1,vector<int>(b+1,0));
  // knapsack(dp,info,value,weight,n,b);
  knapsack_v1(dp,info,value,weight,n,b);
  for(auto v: dp){
    for(auto e: v){
      cout<<e<<" ";
    }
    cout<<endl;
  }
  trace(info);
  return 0;
}