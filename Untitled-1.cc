#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
   子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列

输入：nums = [1,10,9,2,5,3,4,7,101,18] 
dp[0]=1
dp[1]=1
dp[4]= max(dp[j])=2
输出：4 
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//dp[i]: 以为i-th 元素结尾的, 最长子序列的长度
//dp[i]= max(dp[j]+1) if(nums[i-1]>nums[j]), 0<=j<i
// 
*/
class Solution {
public:
//time, O(N*N), space, O(N)
     int lengthOfLIS(vector<int>& nums) {
         int len=nums.size();
         vector<int> dp(len+1,0);
         //step0:init
         dp[0]=0;
         for(int i=1;i<=len;++i){
             dp[i]=1;//init
             for(int j=1;j<i;++j){
                 if(nums[i-1]>nums[j-1]){
                    dp[i]=max(dp[i],dp[j]+1);
                 }
             }
         }
        //  return dp[len]; fucking error
         return *max_element(dp.begin(),dp.end());
    }
};

int main(){
    cout<<"hello world"<<endl;
    vector<int> a{1,10,9,2,5,3,4,7,101,18};
    // a.push_back(1);
    // a.push_back(10);
    Solution s;
   int res=s.lengthOfLIS(a);
   cout<<"res:"<<res<<endl;
    return 0;
}
