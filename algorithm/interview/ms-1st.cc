#include<bits/stdc++.h>
//整数数组，连续和，等于target
using namespace std;
//time complexity, O(N), space, O(N)
bool findTarget(const vector<int>& a, int target){
    int len=a.size();
    unordered_map<int,bool> prefixSum;
    if(0==len) return false;
    //step1: init
    //prefixSum[0]=0;
    prefixSum[0]=true;
    int preSum=0;
    int curSum=0;
    for(int i=1;i<=len;i++){
        curSum=curSum+a[i-1];
        int diff=curSum-target;
        if(prefixSum.find(diff)!=prefixSum.end()){
            return true;
        }
        prefixSum[diff]=true;
    }
    return false;
}
int main(){
    vector<int> A{1,2,3,4,5};
    cout<<"hello world"<<endl;
    return 0;
}