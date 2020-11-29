/*
 * @Author: your name
 * @Date: 2019-03-05 20:01:32
 * @LastEditTime: 2020-11-29 15:45:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/uniquify/main.cpp
 */
//
//  main.cpp
//  bubleSorting
//
//  Created by ChengWang on 3/5/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);

void uniquify(vector<int>&v){
    int left=0;
    int right=left+1;
    int len=v.size();
    while(right<len){
        if(v[left]!=v[right]){
            v[++left]=v[right++];
        }else{
            right++;
        }
    }
}

void print(vector<int>&v){
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, bubbleSorting!\n";
    int testTime = 1;
    // int testTime = 500;
    int maxSize = 500;
    int maxValue = 1000;
    vector<int> v;
    v.reserve(maxSize);
    bool succeed = true;
    srand((unsigned)time(NULL));
    for (int i = 0; i < testTime; i++) {
        v.clear();
        // generateRandomArray(v, maxSize, maxValue);
        vector<int> v={1,1,1,2,2,2,2,3,4,5,6,6,7,8,0,54,3,3,324443,24,32,42,42,42,23,32,23};
        sort(v.begin(),v.end());
       print(v);
        vector<int> v1(v);
        vector<int> v2(v);
//        print(v2);
        std::unique(v2.begin(),v2.end());
        uniquify(v1);
       print(v1);
       print(v2);
        if (!equal(v1.begin(), v1.end(), v2.begin())){
//        if (v1!=v2){
            succeed = false;
            print(v1);
            print(v2);
        //    cout<<endl;
            break;
        }
//            cout<<endl;
    }
    cout<<(succeed ? "Nice!" : "Fucking fucked!");
    cout<<endl;

    return 0;
}

