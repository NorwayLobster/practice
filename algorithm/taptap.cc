#include<iostream>
#include<vector>
// 给定一个正整数 x, 可以对x做如下变换:
// x 为奇数时，x => x-1 or x => x+1
// x 为偶数时，x => x/2
// 则至少对x做多少次变换可以变换为1
//dp[x]=
//x is even: dp[x]=dp[x/2]+1
//x is odd: dp[x]=min(dp[(x+1)/2]+1,dp[x-1])+1
//x is odd: x+1 is even,  dp[x+1]=dp[(x+1)/2]+1
//(x+1)/2 < x, 
// func GetSteps(x int) int { }
using namespace std;
//time, O(N),  space, O(N)

int GetSteps(int x){
    vector<int> dp(x,0);
    //step0:
    dp[1]=0;
    dp[2]=1;
    dp[3]=2;
    if(x<=3){
        return dp[x];
    }
    for(int i=4;i<=x;++i){
        if(0==(i&1)){//x is even
            dp[i]=dp[i/2]+1;
        }else{
            dp[i]=min(dp[(i+1)/2]+1, dp[i-1])+1;
        }
    }
    return dp[x];
}

int main(){
    cout<<"steps:"<<GetSteps(15)<<endl;
    return 0;
}
