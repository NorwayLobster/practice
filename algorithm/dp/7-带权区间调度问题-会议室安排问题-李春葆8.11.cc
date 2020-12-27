/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-26 21:54:21
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-27 15:24:17
 * @FilePath: /practice/algorithm/dp/7-带权区间调度问题-会议室安排问题-李春葆8.11.cc
 */

// p[i]=> i-th任务开始之前最后一个结束的任务的编号
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int solve(vector<pair<int,int>>& time){
  int len=time.size();
  vector<int> pretask(len,-1);//0-th task 的兼容任务结束时间最晚的任务的index是-1
  // pretask[0]=0;
  for(int i=1;i<len;++i){
    for(int j=i;j>=0;--j){
      if(time[j].second<=time[i].first){
        pretask[i]=j;
        break;
      }
    }
  }
  cout<<endl;
  for(int i=0;i<len;++i){
    cout<<"i="<<i<<":"<<pretask[i]<<endl;
  }
  sort(time.begin(),time.end(),[](const pair<int,int>& left, const pair<int,int>& right)->bool{return left.second<right.second;});
  // sort(starttime.begin(),starttime.end(),[&endtime](int )->bool{return });
  vector<int> dp(len,0);//前index任务及之前的最大权重, 
  dp[0]=time[0].second-time[0].first;//task的最大权重
  cout<<"dp[0]:"<<dp[0]<<endl;
  cout<<endl;
  for(int i=1;i<len;++i){
    if(pretask[i]<0){
      dp[i]=max(dp[i-1],time[i].second-time[i].first);
    }else{
      dp[i]=max(dp[i-1],dp[pretask[i]]+time[i].second-time[i].first);
      // cout<<"index:"<<i-1<<",pre:"<<pretask[i-1]<<",dp[pre]:"<<dp[pretask[i-1]+1]<<",res:"<<dp[i]<<endl;
    }
  }
  return dp[len-1];
}
int main(){
  int len=11;
  vector<pair<int,int>> tasktime={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6, 10},{8,11},{8,12}, {2,13},{12,15}};
  // vector<int> endtime=  {4,5,6,7,8,9,10,11,12, 13,15};
  cout<<"res:"<<solve(tasktime)<<endl;

  return 0;
}