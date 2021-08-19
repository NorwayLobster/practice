#include<bits/stdc++.h>
using namespace std;
//[2,4,3,1,1,5,3,1,1,1,1]
//dp[i]: 表示到达第i个台阶，所使用的最小的步数
//dp[i]=1+min(dp[j])， 0<j<i, 其中要求第j个台阶可以到达第i个台阶
// j+A[j]>=i
//time, O(N*N)
//
void getMinstep(...){
    for(int i=0;i<len;){
        for(int j=i;j<i+A[i];++j){
            // if(remote<j+A[j]){
            //     remote=j+A[j];
            // }
            int remote=max(remote,j+A[j]);
        }
        i=remote;
    }
}
void getMinSteps(const vector<int>& A){
    int len=A.size();
    vector<int> dp(len+1,0);//
    dp[0]=0;
    for(int i=1;i<=len;++i){
        int minStep=INT_MAX;
        for(int j=1;j<i;j++){
            if(A[j]+j>=i){
                minStep=min(dp[j],minStep);
            }
        }
        dp[i]=minStep+1;
    }
}


//
int main(){
    cout<<"hello world"<<endl;
    return 0;
}