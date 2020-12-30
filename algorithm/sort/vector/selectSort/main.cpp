//
//  main.cpp
//  selectSort
//
//  Created by ChengWang on 11/24/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
//note: #include <limits> not   this one
#include <algorithm>
#include <iterator>
using namespace std;

void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);
int selectSort_v1(vector<int> & v);
int selectSort_v2(vector<int> & v);
int selectSort_v3(vector<int> & v);
void select_20200501(vector<int>&);
void select_20200501_v1(vector<int>&);
void selectionSort(vector<int>&v);
void selectionsort20201130(vector<int>&v);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, bubbleSorting!\n";
    int testTime = 5;
    int maxSize = 11;
    int maxValue = 1000;
    vector<int> v;
    v.reserve(maxSize);
    bool succeed = true;
    srand((unsigned)time(NULL));
    for (int i = 0; i < testTime; i++) {
        v.clear();//用完后每次都要清理
        generateRandomArray(v, maxSize, maxValue);
        vector<int> v1(v);
        vector<int> v2(v);
        print(v);
        //        print(v1);
        //        print(v2);
       sort(v2.begin(),v2.end());
        // sort(v2.begin(),v2.end(),[](int a,int b)->bool{return a>b; });//降序
//        sort(v2.begin(),v2.end(),greater<int>());
//        selectSort_v1(v1);
        //        selectSort_v2(v1);
//                selectSort_v3(v1);
        // select_20200501_v1(v1);
        // select_20200501_v1(v1);
        // selectionSort(v1);
        selectionsort20201130(v1);
//        select_20200501(v1);
                print(v2);
                print(v1);
        printf("\n");
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
    copy(v.begin(), v.end(), std::ostream_iterator<int> (cout," "));
    //    std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}





int selectSort_v1(vector<int> & v)
{
    for(int i=0;i<v.size();++i){
        int min=INT_MAX,min_idx=i;
        for(int j=i;j<v.size();++j){
            if(v[j]<min)
            {
                min_idx=j;
                min=v[j];
            }
        }
        swap(v[i],v[min_idx]);
    }
    return 0;
}

int selectSort_v2(vector<int> & v)
{
    for(int i=0;i<v.size();++i){
        int min_idx=i;//min_idx初始值
        for(int j=i;j<v.size();++j){
            if(v[j]<v[min_idx])
            {
                min_idx=j;
            }
        }
        swap(v[i],v[min_idx]);
    }
    return 0;
}



//large-----------small
void select_20200501_v1(vector<int>&v){
    int len=v.size();
    int maxNum=INT_MIN;
    for(int i=0;i<len;++i){
        maxNum=v[i];
        int index=i;
        for(int j=i;j<len;++j){
            if(maxNum<v[j]){
                maxNum=v[j];
                index=j;
            }
        }
        swap(v[i],v[index]);
    }
}

//2020 0501
//small-----------large
void select_20200501(vector<int>&v){
    int len=v.size();
//    int maxNum=INT_MIN;
		int minNum=INT_MAX;
    for(int i=0;i<len;++i){
//        maxNum=v[i];
        minNum=v[i];
        int index=i;
        for(int j=i;j<len;++j){
//            if(maxNum<v[j]){
            if(v[j]<minNum){
                minNum=v[j];
//                maxNum=v[j];
                index=j;
            }
        }
        swap(v[i],v[index]);
    }
}

//记忆版：精简版
int selectSort_v3(vector<int> & v){
    for(int i=0;i<(int)v.size();++i){
        for(int j=i+1;j<(int)v.size();++j){//单趟扫描时，v[i]的位置始终用来存在最小元素，扫描结束时，则v[i]则为被选出来的最小元素
            if(v[j]<v[i])
                swap(v[j],v[i]);
        }
    }
    return 0;
}

//直观，记忆版：精简版
void selectionSort(vector<int>&v){
    int len=v.size();
    for(int i=0;i<len;++i){
        int minIndex=i;
        for(int j=i;j<len;++j){
            if(v[j]<v[minIndex]){
                minIndex=j;
            }
        }
        swap(v[i],v[minIndex]);
    }
}






































//20201130 exercise
void selectionsort20201130(vector<int>&v){
    int len=v.size();
    for(int i=0;i<len;++i){
        int minIndex=i;
        for(int j=i+1;j<len;++j){
            if(v[j]<v[minIndex]){
                minIndex=j;
            }
        }
        swap(v[i],v[minIndex]);
    }
}