/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-18 10:51:59
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-18 11:03:23
 * @FilePath: /practice/algorithm/leetcode/interview光鉴科技2-1.cc
 */


/*
题目1: 描述：给定一个字符串实现str，查找子字符串substr，返回查找到的子字符串个数及位置
输入输出样例:
输入:
str：“asjasklaskl”,
substr："ask"，
输出: 
number:2 
  position:3,7
*/
//时间复杂度有要求吗？
//没有音频吗？语音通话么
//在吗？？？
//面试官，您好，在吗？？？
//面试官， 开语音吧 可以么 
// 嗯嗯 在的
// 一会我有个会 不方便说话 
//抱歉啊asm
//没事，不过，我需要给您讲我的思路，以及自己对这题的思考
// 有第二题吗 先做题，然后您开完会一块讲我的思路
//一共需要写几题？三题算法？好的
//主要是，我写code之前一般和面试官确认我我的方法对与否，然后在写，在其他公司面试的的时候，因为如果我的算法思路不对，我写了也是错的。或者time/space complexity到不到要求
//ehun可以
//好的  那我先给你选下一题

//   2-3
//   2-3
  //e
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  string str="asjasklaskl";
  string substr="ask";
  // cin>>str;
  // cin>>substr;
  int len1=str.size();
  int len2=substr.size();
  int cnt=0;
  vector<int> res;
  //time, O(len1*len2), space, O(len1)
  for(int i=0;i<len1;++i){
      int left=i;
      int j=0;
      while(j<len2 && left<len1 && str[left]==substr[j]){
        left++;
        j++;
      }//while
      if(j==len2){
        cnt++;
        res.push_back(i);
      }
    }//for
    cout<<"numbers:"<<cnt<<endl;
    cout<<"position:";
    int i=0;
    for(auto e:res){
      if(i==0){
        cout<<e;
      }else{
        cout<<","<<e;
      }
      i++;
    }
    cout<<endl;
  return 0;
}