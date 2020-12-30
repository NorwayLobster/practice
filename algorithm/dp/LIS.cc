/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-26 21:48:20
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-27 13:23:23
 * @FilePath: /practice/algorithm/dp/LIS.cc
 */
#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>& starttime, vector<int>& endtime, vector<int>& pretask){
  pretask[0]=0;
  int len=starttime.size();
  for(int i=1;i<len;++i){
    for(int j=i;j>=0;--j){
      if(endtime[j]<=starttime[i]){
        pretask[i]=j;
        break;
      }
    }
  }
  for(auto e:pretask){
    cout<<"i:"<<endl;
  }

}
int main(){
  int len=11;
  vector<int> starttime={1,3,0,5,3,5, 6, 8, 8,  2,12};
  vector<int> endtime=  {4,5,6,7,8,9,10,11,12, 13,15};
  vector<int> pretask(len,0);
  solve(starttime,endtime,pretask);

  return 0;
}