//
//  main.cpp
//  mergeSort
//
//  Created by ChengWang on 3/6/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::merge;

void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);
//int mergeSort_v1(vector<int> & v);
int mergeSort_v1(vector<int> & v, int left, int right);
int merge(vector<int> &v, int left, int mid, int right);
void mergeSort(vector<int>&v,int leftIndex,int rightIndex);

int main(int argc, const char * argv[]){
    // insert code here...
    std::cout << "Hello, mergerSorting!\n";
    int testTime = 1000;
    int maxSize = 2010;
    int maxValue = 1000;
    vector<int> v;
    v.reserve(maxSize);
    bool succeed = true;
    srand((unsigned)time(NULL));
    for (int i = 0; i < testTime; i++){
        v.clear();//用完后每次都要清理
        generateRandomArray(v, maxSize, maxValue);
        vector<int> v1(v);
        vector<int> v2(v);
//        print(v1);
//        print(v2);
        sort(v2.begin(),v2.end());
        if(!v1.empty())//保证v1非空
//            mergeSort_v1(v1, 0, v1.size()-1);
            mergeSort(v1, 0, (int)v1.size()-1);
        
//        print(v1);
//        print(v2);
//        cout<<endl;
        if (!equal(v1.begin(), v1.end(), v2.begin())){
            //        if (v1!=v2){
            succeed = false;
            print(v1);
            print(v2);
            //            cout<<endl;
            break;
        }
        //            cout<<endl;
    }
    cout<<(succeed ? "Nice!" : "Fucking fucked!");
    cout<<endl;
    
    return 0;
}

void generateRandomArray(vector<int> &v, int maxSize, int maxValue){
    //    srand((unsigned)time(NULL));
    for(int i = 0; i < maxSize;i++ )
        v.push_back(rand()%(maxValue-10)+10);
}

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
    //    std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}


int mergeSort_v1(vector<int> & v, int left, int right)
{
//    if(left>right)//left 永远无法大于right，死循环，风扇起
    if(left==right)//相等时，一个数自然有序，退出递归。
        return 0;
    int mid= left + ((right-left)>>1);
    
    //先分区sort，后merge
    mergeSort_v1(v, left, mid);
    mergeSort_v1(v, mid+1, right);
    merge(v, left, mid, right);
    return 0;
}

int merge(vector<int> &v, int left, int mid, int right){
    vector<int> help(right-left+1);
    int i=0;
    int p=left;
    int p1=mid+1;
   
    //核心部分：
    while(p<=mid && p1<=right)
        help[i++]= v[p]<=v[p1]? v[p++]:v[p1++];
    
   //下面只有一个循环得到运行
    while(p<=mid)
        help[i++]=v[p++];
    while(p1<=right)
        help[i++]=v[p1++];
    copy(help.begin(), help.end(), v.begin()+left);
    
    return 0;
}


//使用std::merge()
//使用std::inplace_merge()
void mergeSort(vector<int>&v,int leftIndex,int rightIndex){
    if(leftIndex==rightIndex){
        return ;
    }
    int midIndex=leftIndex+((rightIndex-leftIndex)>>1);
    mergeSort(v,leftIndex,midIndex);
    mergeSort(v,midIndex+1,rightIndex);
#if 0
    vector<int> help(rightIndex-leftIndex+1,0);
    std::merge(v.begin()+leftIndex, v.begin()+midIndex+1,v.begin()+midIndex+1,v.begin()+rightIndex+1, help.begin());
    copy(help.begin(),help.end(),v.begin()+leftIndex);
#endif
    
    std::inplace_merge(v.begin()+leftIndex,v.begin()+midIndex+1,v.begin()+rightIndex+1);
//    std::inplace_merge(<#_BidirectionalIterator __first#>, <#_BidirectionalIterator __middle#>, <#_BidirectionalIterator __last#>, <#_Compare __comp#>)
}
