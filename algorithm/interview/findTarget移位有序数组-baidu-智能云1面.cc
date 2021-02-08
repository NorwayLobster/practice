/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-02-08 15:55:47
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-02-08 08:28:39
 * @FilePath: /practice/algorithm/interview/findTarget移位有序数组-baidu-智能云1面.cc
 */
/*
无重复
有序
循环移位
12345
45123
*/

#include<iostream>
#include<vector>
using namespace std;
int find_target(const vector<int>& v, int left, int right, int target){
  if(left>right){ return -1;}//exit
  int mid=left+(right-left)/2;
  cout<<"mid:"<<mid<<endl;
  int res;
  if(v[left]<=v[mid]){//left side
    if(target==v[mid]){
      return  mid;
    }else if(v[left]<=target && target<v[mid]){
      res=find_target(v, left, mid-1, target);
    }else{
      res=find_target(v, mid+1, right, target);
    }
  }else{//v[mid]<=v[right]
    if(target==v[mid]){
      return mid;
    }else if(v[right]>=target && target>v[mid]){
     res=find_target(v, mid+1, right, target);
    }else{
     res=find_target(v, left, mid-1, target);
    }
  }
  return res;
}

int main(){
  // vector<int> v={4,5,1,2,3};//
  // vector<int> v={4,5,6,7,1,2,3};//
  vector<int> v={4,5,6,7,8,9,1,2,3};//
  int len=v.size();
  int target=0;
  int index=find_target(v, 0,len-1, target);
  cout<<"index:"<<index<<endl;
  return 0;
}

