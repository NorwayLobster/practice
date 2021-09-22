#include<bits/stdc++.h>
/*
给定8x8二维矩阵（共64格）。其中入口坐标（0，0），出口坐标（7，7）。
矩阵中，1表示允许走的格子，0表示不能走，并规定只能上下左右行进。
*/
using namespace std;
vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>>& v, int i, int j, bool& flag){
    int width=v.size();
    int height=v.size();
    if(i>=height || i<0 || j<0 || j>=width) return ;
    if(j==width-1 && i==height-1){//exit
        if(v[i][j]==1){
            flag=true;//early stop
        }
        return ;
    }

//(0,7)-->(0,6)-->
//(0,7)-->(1,7)--> ture/false
    if(v[i][j]==1){
        v[i][j]=0;
        for( int k=0;k<4;k++){
            dfs(v,i+dir[k][0],j+dir[k][1],flag);
            if(flag) return ;
        }
        v[i][j]=1;
    }
    return ;
}
//dfs+pruning==backtraking

int  main(){
//    input
    dfs(intput,dir);
}