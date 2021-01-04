//
//  main.cpp
//  leetcode
//
//  Created by ChengWang on 2/24/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> v={{1,2}};
    int findJudge(int N, vector<vector<int>>& t) ;
//    cout<<findJudge(2,v)<<endl;
    bool Find(int target, vector<vector<int> > array);
    Find(2,v);
    std::cout << "end!\n";
    return 0;
    
}

bool Find(int target, vector<vector<int> > array) {
    int len1=array.size();//row
    if(0==len1)
        return false;
    int len2=array[0].size();//column
    
    int row=0, column=len1-1;
    while(row<len1 && column>=0){
        if(array[row][column]==target){
            return true;
            else if(array[row][column]>target){
                --column;
            }
            else{
                ++row;
            }
        }
    }
}


int findJudge(int N, vector<vector<int>>& t) {
    // unordered_map<int> hash1,hash2;
    int h=t.size();
    if(0==h)
        return -1;
    int w=t[0].size();
    vector<vector<int>> v1(N,vector<int>(N,-1));
    vector<int> v2(N,0);
    vector<int> v3(N,-1);
    for(int i=0;i<t.size();++i){
        v1[t[i][0]-1][t[i][1]-1]=1;
        // v1[t[i][0]-1][t[i][0]-1]=v1[t[i][0]-1][t[i][0]-1]+1;
        v2[t[i][0]-1]=v2[t[i][0]-1]+1;
        v3[t[i][0]-1]=1;
//        v3[t[i][1]-1]=1;

        
        // v2[t[i][1]-1]=v2[t[i][0]-1]+1;
    }
    
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)
        {
            
            if(v1[i][j]==1 && i!=j)
            {
                v3[i]=0;
                break;
            }
        }
    }
    
    for(int i=0;i<N;++i){
        if(0!=v3[i]){
            bool flag=true;
            for(int j=0;j<N;++j)
            {
                if(i!=j && 1!=v1[i][j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                return i+1;
        }
    }
    return -1;
    }
