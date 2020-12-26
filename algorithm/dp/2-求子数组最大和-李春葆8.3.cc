/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-26 09:44:46
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-26 09:55:51
 * @FilePath: /practice/algorithm/dp/2-求子数组最大和-李春葆8.3.cc
 */

#include <iostream>
#include <vector>
using namespace std;

//time, O(n), space, O(n)
int maximumSubarraySum(vector<int>& arr){
  int len=arr.size();
  vector<int> dp(len+1,0);
  dp[0]=0;
  for(int i=1;i<=len;i++){
    dp[i]=max(dp[i-1]+arr[i-1],arr[i-1]);
  }
  return *max_element(dp.begin(),dp.end());
}

int main(){
  vector<int> arr={0,-2,11,-4,13,-5,-2};
  cout<<"res:"<<maximumSubarraySum(arr)<<endl;
  return 0;
}