/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-18 10:54:38
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-18 12:01:12
 * @FilePath: /practice/algorithm/leetcode/interview光鉴科技2-2.cc
 */
/*
题目二:
有一天，deptrum组织大家玩下面一个游戏：
有一个无重复数字的一串序列，谁能最快给出这串数组的全排列，谁就能够得到今天的奖品，那么如何用算法快速给出结果呢？请实现这样一个算法。

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

//在的
// 不用 嗯好的
//需要按字典序吗？
//好的， 我讲一下我的思路， 回溯法+递归， 音频吗
//在吗？
//好的
// 稍等啊 在会议室
*/
#include<iostream>
#include<vector>
#include<algorithm>
// std::next_permutation
using namespace std;
int generatePermutation(vector<int>& v, vector<vector<int>>& res){
  sort(v.begin(),v.end());
  do{
    res.push_back(v);
  }while(next_permutation(v.begin(),v.end()));
  return 0;
}
//time, O(n!), space, O(N!* N)=O(N!)
void mypermutation(vector<int>& v, vector<vector<int>>& res, int depth){
  // fatal error: if(depth==v.size()){//?
  if(depth==v.size()-1){//?
    res.push_back(v);
    return ;
  }
  //fatal error: for(int i=depth+1;i<(int)v.size();++i){
  for(int i=depth;i<(int)v.size();++i){
      swap(v[depth],v[i]);
      mypermutation(v, res, depth+1);
      swap(v[depth],v[i]);//backtrack
  }
}
int main(){
  //....
  vector<int> v={1,2,3};
  vector<vector<int>> res;
  generatePermutation(v, res);
  return 0;
}