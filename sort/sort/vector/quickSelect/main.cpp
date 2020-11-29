//
//  main.cpp
//  quickSelect
//
//  Created by ChengWang on 11/30/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

void quickSelect(vector<int>&v,int k);
int partition_iter(vector<int>&v,int left,int right);

void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void quickSelect(vector<int> & v,int k, int startIndex, int endIndex);
void quickSelect_iteration(vector<int> & v,int k, int startIndex, int endIndex);
int partition_1(vector<int> & v,int starIndex,int endIndex);
void print(vector<int> & v);

int select(vector<int>& v,int beginIndex,int endIndex,int k );
pair<int,int> partition(vector<int> & v,int beginIndex,int endIndex);
int medianOfmedians(vector<int> &v, int beginIndex,int endIndex);
int median(vector<int> & v,int beginIndex, int endIndex);
void insertSort(vector<int> &v,int beginIndex,int endIndex);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, quickSort!\n";
//    srand((unsigned int)time(NULL));
    srand((unsigned)time(NULL));
    int testTime = 100;
    int maxSize = 100;
    int maxValue = 1000;
//note:求下表为nth，即top nth+1 的元素
    int nth=34;//下表是5
    assert(nth<maxSize);
    vector<int> v;
    v.reserve(maxSize);
    bool succeed = true;
    for (int i = 0; i < testTime; i++) {
        v.clear();//用完后每次都要清理
        generateRandomArray(v, maxSize, maxValue);
        vector<int> v1(v);
        vector<int> v2(v);
//        print(v1);
//        print(v2);
//        sort(v1.begin(),v1.end());
        nth_element(v1.begin(),v1.begin()+nth,v1.end());
//
//        quickSelect(v2, nth, 0, (int)v2.size()-1);
//        quickSelect_iteration(v2,nth,0,(int)v2.size()-1);
//error:          int Nth=select(v2,0,(int)v2.size()-1,nth);
          quickSelect(v2,nth);
//        print(v1);
//        print(v2);
        printf("%dth:%d\n",nth,v1[nth]);
        printf("%dth:%d\n",nth,v2[nth]);
       // printf("%dth:%d\n",Nth,v2[Nth]);
        
//        printf("10th:%d\n",v2[nth]);
        printf("\n");
        //        print(v1);
        //        print(v2);
        if (v1[nth]!=v2[nth]){
            succeed = false;
            print(v1);
            print(v2);
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

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
    std::cout << '\n';
}


//基于随机元素进行partition
//下面的 迭代版和递归版 均属于randomized-select()

//基于partition的quickSelect()
//迭代版 #邓版 //自带partition功能
void quickSelect_iteration(vector<int> & v,int k, int startIndex, int endIndex){
    while(startIndex<endIndex){
        int leftIndex=startIndex,rightIndex=endIndex;
        int pivot=v[leftIndex];
        while(leftIndex<rightIndex){
            while(leftIndex<rightIndex && v[rightIndex]>=pivot) --rightIndex;
            v[leftIndex]=v[rightIndex];
            while(leftIndex<rightIndex && v[leftIndex]<=pivot) ++leftIndex;
            v[rightIndex]=v[leftIndex];
        }
        v[leftIndex]=pivot;
        if(k<=leftIndex) endIndex=leftIndex-1;
        if(k>=leftIndex) startIndex=leftIndex+1;
    }
}

//单边法
int partition_iter(vector<int>&v,int left,int right){
    srand(time(nullptr));
    int randIndex=left+rand()%(right-left+1);
    swap(v[left],v[randIndex]);
    int pivot=v[left];
    int boundary=left;
    for(int i=left+1;i<=right;++i){
        if(v[i]<pivot){
            boundary++;
            swap(v[i],v[boundary]);
        }
    }
    swap(v[left],v[boundary]);
    return boundary;
}

//迭代版
void quickSelect(vector<int>&v,int k){
    int len=v.size();
    if(k>len-1) return;
    int left=0;
    int right=len-1;
    while(left<right){
        int pivotIndex=partition_iter(v,left,right);
        if(pivotIndex<k)
            left=pivotIndex+1;
        else if(pivotIndex>k)
            right=pivotIndex-1;
        else
            return ;
    }
}

//递归版
void quickSelect(vector<int> & v,int k, int startIndex, int endIndex){
    if(startIndex>=endIndex)
        return ;
    int pivotIndex=partition_1(v,startIndex,endIndex);
    if(k==pivotIndex) return ;
    if(k<pivotIndex) quickSelect(v,k, startIndex,pivotIndex-1);
    if(k>pivotIndex) quickSelect(v,k, pivotIndex+1,endIndex);
    return ;
}
//双边法
int partition_1(vector<int> & v,int startIndex,int endIndex){
    int rndIndex=startIndex+rand()%(endIndex-startIndex+1);
    swap(v[rndIndex],v[startIndex]);
    int pivot=v[startIndex];
    int leftIndex=startIndex;
    int rightIndex=endIndex;
    while(leftIndex<rightIndex){
        while(leftIndex<rightIndex && v[rightIndex]>=pivot ) --rightIndex;
        v[leftIndex]=v[rightIndex];
        while(leftIndex<rightIndex && v[leftIndex]<=pivot ) ++leftIndex;
        v[rightIndex]=v[leftIndex];
    }
    v[leftIndex]=pivot;
    return leftIndex;
}





//note：每次破坏数组的划分， 必须另开空间存储临时中位数序列，

//区别：基于 中位数序列的中位数 进行partition的，可以保证每次partition淘汰的数据量
//基于BFPRT算法的quickSelect()
//原地移动元素
//https://blog.csdn.net/laojiu_/article/details/54986553
//select 返回第k大元素的下表index ，为什么不是用k直接去partition后的数组直接取数据，此时index是否等于k？？？

//note:返回第k大元素的索引
int select(vector<int>& v,int beginIndex,int endIndex,int k ){
    //返回 index 还是元素本身???
    if(beginIndex>=endIndex)
        return beginIndex;
    pair<int,int> pivotIndex=partition(v,beginIndex,endIndex);
    if(k<pivotIndex.first){
        return select(v,beginIndex,pivotIndex.first-1, k);
    }
    else if(pivotIndex.first<=k && k<=pivotIndex.second){
        return k;
    }
    else{
        return select(v,pivotIndex.second+1,endIndex,k);
    }
    
}

//双边循环partition法： 分三区
//荷兰国旗partitioin  less区， more区， equal区
pair<int,int>  partition(vector<int> & v, int left, int right){
    int pivotIndex=medianOfmedians(v,left,right);
//    int pivot=v[pivotIndex];
//    v[pivotIndex]=v[left];
    swap(v[pivotIndex],v[right]);
    int less = left-1;
    int cur= left;
    int pivot= right;//假设pivot元素大于自己，先放在more区
    
    int more= right;//
    while(cur<more){
        if(v[cur]<v[pivot])
            swap(v[cur++], v[++less]);//i.e. swap(v[cur++],v[less+1]); less++;//swap(v[cur++], v[less++]); //error: less初始位置是left-1
        else if(v[cur]>v[pivot])
            swap(v[cur], v[--more]);
        else
            cur++;
    }
    swap(v[cur], v[right]);
    return make_pair(less+1, cur);////less+1 即为等于区域的左边界， cur为等于区域的右边界
}

//三分区
/*
pair<int,int> partition(vector<int> & v,int beginIndex,int endIndex){
    int pivotIndex=medianOfmedians(v,beginIndex,endIndex);
    int pivot=v[pivotIndex];
    v[pivotIndex]=v[beginIndex];
    
    while(){
        
    }
    
    return make_pair(,);
}
*/

int medianOfmedians(vector<int> &v, int beginIndex,int endIndex){
    printf("beginIndex:%d\n",beginIndex);
    printf("endIndex:%d\n",endIndex);
    //note:endIndex能娶到该索引
    int cnt=(endIndex-beginIndex+1)/5+((endIndex-beginIndex+1)%5?1:0);
    printf("cnt:%d\n",cnt);
    vector<int> Medians(cnt,0);
    int MediansBoundryIndex=0;
    for(int iIndex=beginIndex,j=0;j<cnt;++j,iIndex=+5)
    {
        int MedianIndex=median(v,iIndex,min(iIndex+4,endIndex));//
        Medians[MediansBoundryIndex]=v[MedianIndex];
        ++MediansBoundryIndex;
    }
    //对该Medians数组的划分对原数组并无任务作用和影响。
    return select(Medians,0,(int)Medians.size()-1,(int)Medians.size()/2);
    //k是第k 还是下标为k？？？？
}
int median(vector<int> & v,int beginIndex, int endIndex){
    insertSort(v,beginIndex,endIndex);
    //返回中位数下标
    return beginIndex+(endIndex-beginIndex)/2;//奇数：5 6 7 8 9;9-5=4 ; 4/2=2;5+2=7
    //偶数：5 6 7 8  3/2=1 选上中位数
//    return v[beginIndex+(endIndex-beginIndex)/2];//返回中位数//5 6 7 8 9;9-5=4 ; 4/2=2;5+2=7
}

//插入排序
void insertSort(vector<int> &v,int beginIndex,int endIndex){
    for(int i=beginIndex+1;i<=endIndex;++i){//第一元素自然有序
        //v[j]为待插入元素，向前找可插入的地方，当v[j]>=v[j-1]，退出循环即可
        for(int j=i;j>beginIndex && v[j]<v[j-1];--j)
            swap(v[j],v[j-1]);
    }
}
