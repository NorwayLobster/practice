//
//  main.cpp
//  lower_bound() upper_bound() equal_range()
//
//  Created by ChengWang on 12/17/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int myLowerBound(const vector<int>&,int );
int UpperBound(const vector<int>&v,int target,int left,int right){//[left,right) 
    left=0;
    right=v.size()-1;
    int mid;
    while(left<right){
        mid=left+(right-left)/2;
        if(target>v[mid])
            left=mid+1;
        else
            right=mid;
    }
    return left;
}

int LowerBound(const vector<int>&v, int target, int left, int right){
    int mid;
    left=0;
    right=v.size()-1;
    while(left<right){
        mid=left+(right-left)/2;
        if(target>=v[mid]){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}


int myUpperBound(const vector<int>&v,int target){
    int left=0;
    int right=v.size()-1;
    int mid;
    while(left<=right){
        mid=(left+right)>>1;
        if(target>=v[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int myLowerBound(const vector<int>&v,int k){
    int left=0;
    int right=v.size()-1;
    int mid=0;
    int i=0;
    while(left<=right){
        cout<<"i:"<<i++<<endl;
//        mid=left+((right-left)>>1);
        mid=(left+right)>>1;
        if(k>v[mid]){
            left=mid+1;
        }else{
            right=mid-1;//mid-1!!
        }
    }
    return left;
}
//to to debug
int myLowerBound_v2(const vector<int>&v,int k,int left,int right){
//    int left=0;
//    int right=v.size()-1;
    int mid=0;
    int i=0;
    while(left<=right){
        cout<<"i:"<<i++<<endl;
        mid=left+((right-left)>>1);
//        mid=(left+right)>>1;
        if(k>v[mid]){
            left=mid+1;
        }else{
            right=mid-1;//mid-1!!
        }
    }
    return left;
}

void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    srand((unsigned int)time(NULL));
    srand((unsigned)time(NULL));
    int testTime = 200;
    int maxSize = 51;
    int maxValue = 100;
    vector<int> v;
    v.reserve(maxSize);
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        v.clear();//用完后每次都要清理
        generateRandomArray(v, maxSize, maxValue);
        vector<int> v1(v);
 //       vector<int> v1={1,2,3,1,4,0,5,4,4,4,4,10,5};
        cout<<is_sorted(v1.begin(),v1.end())<<endl;
        //    bool is_sorted(<#_ForwardIterator __first#>, <#_ForwardIterator __last#>, <#_Compare __comp#>)
        //    upper_bound(<#_ForwardIterator __first#>, <#_ForwardIterator __last#>, <#const _Tp &__value_#>, <#_Compare __comp#>)
        sort(v1.begin(),v1.end());
        cout<<is_sorted(v1.begin(),v1.end())<<endl;
        auto iter1=upper_bound(v1.begin(), v1.end(), 4);
        auto iter2=lower_bound(v1.begin(), v1.end(), 4);
        int len=v1.size()-1;
        auto iter3=LowerBound(v1, 4,0,len);
        auto iter4=UpperBound(v1, 4,0,len);
        // auto iter3=myLowerBound(v1, 4);
        // auto iter4=myUpperBound(v1, 4);
        auto iterPair=equal_range(v1.begin(), v1.end(), 4);
        for(auto e:v1){
            printf("%d_",e);
        }
        printf("\n");
        cout<<*iter1<<endl;
        cout<<*iter2<<endl;
        cout<<*iterPair.first<<endl;
        cout<<*iterPair.second<<endl;
        //    sort(<#_RandomAccessIterator __first#>, <#_RandomAccessIterator __last#>, <#_Compare __comp#>)
//        print(v1);
//        print(v2);
//        quickSort_v1(v2, 0, (int)v.size()-1);
//        quickSort_v2(v2, 0, (int)v.size()-1);
//        quickSort_v3(v2, 0, (int)v.size()-1);
//        quickSort_v4(v2, 0, (int)v2.size()-1);
//        quickSort_A(v2, 0, (int)v.size()-1);
//        print(v1);
//        print(v2);
        cout<<endl;
        cout<<endl;
        // if(*iter1!=v1[iter4]){
       if(*iter2!=v1[iter3]){
        //if (!equal(v1.begin(), v1.end(), v2.begin())){
            succeed = false;
            break;
        }
    }
    cout<<(succeed ? "Nice!" : "Fucking fucked!");
    cout<<endl;
    
    return 0;
}

void generateRandomArray(vector<int> &v, int maxSize, int maxValue){
    for(int i = 0; i < maxSize;i++ )
        v.push_back(rand()%(maxValue-10)+10);//maxValue-10不能等于0
}
