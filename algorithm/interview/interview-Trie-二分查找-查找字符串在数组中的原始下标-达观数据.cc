/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-06 13:50:17
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-18 12:10:28
 * @FilePath: /practice/algorithm/interview/interview-Trie-二分查找-查找字符串在数组中的原始下标-达观数据.cc
 */
 ///
 /// @file    interview达观数据.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2021-01-06 21:50:09
 ///
 
/*题目:
a = ["apple", "","dog", ..., "", "table", ..., "yes"]
index of "table",如果不存在，返回-1
node: pair<string,original_index>
[](const pair<string,original_index>& left, const pair<string,original_index>& right)-->bool{return left.first<right.first;}
"": ignore
create bbst: O(n)
target , node.first
search: log(n)
Trie:
256
    t->a>b>

1. hash:
2. 遍历
3. 排好序：二分
4. Trie O(m)
*/
#include <iostream>
using namespace std;
int find_index(const vector<string>& a, string target,int left, int right){
    if(left>right) return -1;
    int res=-1;
    int mid=left+(right-left)/2;
    if(a[mid]!=""){
        if(a[mid]==target){
            return mid;
        }else if(a[mid]<target){
            res=find_index(a,target, mid+1,right);
        }else{
            res=find_index(a,target,left,mid-1);
        }
    }else{
        //int left_mid=mid;
        while((left_mid>=left && a[left_mid]=="")){
            left_mid--;
        }
    if(left_mid>=left){
        if(a[left_mid]==target){
            return left_mid;
        }else if(a[left_mid]<target){
            res=find_index(a,target, left_mid+1,right);
        }else{
            res=find_index(a,target,left,left_mid-1);
        }
        }else{
int right_mid=mid;
     while((right_mid<=right && a[right_mid]=="")){
            right_mid++;
        }
    if(right_mid<=right){
        if(a[right_mid]==target){
            return right_mid;
        }else if(a[right_mid]<target){
            res=find_index(a,target, right_mid+1,right);
      }else{
        //res=find_index(a,target,left,right_mid-1);//可优化
    }
        }
        }
    return res;
}
