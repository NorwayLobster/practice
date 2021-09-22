/**
* 这是示例题目的代码
* 请使用console.log或者process.stdout.write函数输出运算结果
*/
//array: sorted, 旋转， 无重复元素
#include<bits/stdc++.h>
using namespace std;
int getTarget(const vector<int>& v, int target){
    int len=v.size();
    int left=0;
    int right=len-1;
    while(left<right){
        int mid=left+(right-left)/2;
        if(v[mid]>v[left]){
            if(target==v[mid]){
                return mid;
            }else if(target<v[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }else{
            if(target==v[mid]){
                return mid;
            }else if(target>v[mid]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    if(v[left]==target){
        return left;
    }
    return -1;
}
int main(){
    return 0;
}