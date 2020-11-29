//
//  main.cpp
//  vector
//
//  Created by ChengWang on 11/26/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
//vector: 5中经典constructor, 内置 sort 判空
//       1维
//       2维
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

//1维
    vector<int> v1{1,23,2};
    vector<int> v1_1={1,23,2};//Q:是否有临时对象的生成？？？
    
    vector<int>  v2(v1);
    vector<int>  v2_1=v1;
    
    vector<int>  v3_0;
    vector<int>  v3(4);
    vector<int>  v3_1(4,11);
    
    vector<int>  v4(v1.begin()+1,v1.end());
    for(auto a:v4)
        printf("%d ",a);
    printf("\n");
    for(auto a:v3_0)
        printf("%d ",a);
    printf("\n");
    
//2维
   //行数不确定
    vector<vector<int>> v(2,vector<int>(3,11));
    for(auto vtmp:v){
        for(auto a:vtmp)
            printf("%d_",a);
        
        printf("\n");
    }
    printf("\n");
   //行数列数都不确定
    return 0;
}
