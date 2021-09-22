#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> getTarget(vector<int>& v, int target){
    int len=v.size();
    vector<pair<int,int>> res;
    if(len<=1) return res;
    //step0: prapre, sort
    sort(v.begin(),v.end());
    //step1:
    int left=0;
    int right=len-1;
    while(left<right){
        int sum=v[left]+v[right];
        if(sum<target){
            left++;
         }else if(sum>target){
             right--;
         }else{//sum==target
            res.push_back(make_pair(left,right));
            left++;
            right--;
         }
    }
    return res;
}
int main(){
     return 0;
}