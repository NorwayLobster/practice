/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-27 11:32:02
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-27 11:34:38
 * @FilePath: /practice/algorithm/dp/knapsack/changeMaking.cc
 */
//找零钱:  面值arr[i]的纸币，个数不限， 需要把N元换成零钱, 
// Unbounded Knapsack: 区别是找零钱必须要把包装满.

// Q1: 求最少的硬币个数的找零钱的方案
// Q2: 求所有找零钱可行方案的总数,
// Q3: 求所有找零钱可行方案的具体方案
//time complexity: O(N*b*(j/weight[i]))
void changeMaking_Q1(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
    for(int i=1;i<=n;i++){//只考虑前i个物品
      cout<<"i:"<<i<<endl;
      for(int j=0;j<=b;j++){//总重限制为j
        cout<<"j:"<<j<<endl;
        dp[i][j]=INT_MAX;
        for(int k=0;k*weight[i]<=j;++k){
        // for(int k=0;k<=j/weight[i];++k){
          dp[i][j]=min(dp[i][j], k+dp[i-1][j-k*weight[i]]);//note: 前i-1个物品，在j重量的情况下，最少的硬币个数
          // int tmp=k+dp[i-1][j-k*weight[i]];//note: 前i-1个物品，在j重量的情况下，最少的硬币个数
          // if(tmp<dp[i][j]){
          //   dp[i][j]=tmp;
          //   info[i][j]=k;//k个i-th item
          // }
        }
      }
    }
}
//time complexity optimization: O(N*b)
void knapsack_v1_Q1(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
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



void changeMaking_Q2(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
    for(int i=1;i<=n;i++){//只考虑前i个物品
      cout<<"i:"<<i<<endl;
      for(int j=0;j<=b;j++){//总重限制为j
        cout<<"j:"<<j<<endl;
        int sum=0;
        // dp[i][j]=0;
        for(int k=0;k*weight[i]<=j;++k){
        // for(int k=0;k<=j/weight[i];++k){
          sum+=dp[i-1][j-k*weight[i]];//note: 前i-1个物品，在j重量的情况下，最少的硬币个数
        }
        dp[i][j]=sum;
      }
    }
}
//time complexity optimization: O(N*b)
void knapsack_v1_Q2(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
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



void changeMaking_Q3(vector<vector<int>>& dp, vector<vector<int>>& info,vector<int>& value, vector<int>&weight,int n, int b){
}