//
//  main.cpp
//  majority众数
//
//  Created by ChengWang on 11/30/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
//void print(vector<int> & v, string str);
void print(const vector<int> & v, const string  str);
int majorityFind(const vector<int> & v);
//特别注意：此处的众数必须超过元素个数的一半(严格）
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v={1,4,1,1,1,4,4};
//    vector<int> v={12,1,1,343,1,5334,1,1,4,4};
    printf("%d\n",(int)v.size());
    print(v,"$");
    int majorytyElement=majorityFind(v);
    printf("%d\n",majorytyElement);
    return 0;
}

void print(const vector<int> & v, const string  str){
//void print(vector<int> & v, string  str){
//    v[1]=10;
    for(auto a:v){
        printf("%d%s",a,str.c_str());
    }
    cout<<endl;
}

int majorityFind_1(const vector<int> & v){
    int num=0;
    int curElement;
    for(auto a:v){
        if(0==num)
            curElement=a;
        if(a==curElement){
            ++num;
        }else{
            --num;
        }
    }
    return  curElement;
}

int majorityFind_2(vector<int> & v){
    int pivotIndex=partition();
}

int partition(vector<int> &);
