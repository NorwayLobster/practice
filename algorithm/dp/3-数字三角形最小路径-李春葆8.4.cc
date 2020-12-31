/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-26 10:13:39
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-31 18:37:51
 * @FilePath: /practice/algorithm/dp/3-数字三角形最小路径-李春葆8.4.cc
 */
#include <iostream>
#include <vector>
int triangleMaxPathSum(vector<vector<int>>& arr){
  int height=arr.size();
  int width=arr[0].size();
  vector<vector<int>> dp(height+1,vector<int>(width,0));
//time, O(mn), space, O(mn) 
//TODO
//time, O(mn), space, O(2*width) : 滚动数组
//time, O(mn), space, O(width) :upper, upper_left

}
int main(){
  
  return 0;
}