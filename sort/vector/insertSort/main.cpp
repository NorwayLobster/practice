//
//  main.cpp
//  insertSort
//
//  Created by ChengWang on 3/5/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);
int insertSort_v1(vector<int> & v);
int insertSort_v2(vector<int> & v);
void insertSort(vector<int> &v,int beginIndex,int endIndex);
void insertSort_1(vector<int> &v,int beginIndex,int endIndex);

void insertionSort(vector<int>&v);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, insertSorting!\n";
    int testTime = 5;
    int maxSize = 20;
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
        printf("v:");
        print(v);
        //        print(v1);
        //        print(v2);
        sort(v2.begin(),v2.end());
        printf("v2:");
        print(v2);
//        insertSort_v1(v1);
//        insertSort_v2(v1);
//        insertSort(v1,0,(int)v1.size()-1);
        // insertSort_1(v1,0,(int)v1.size()-1);
        insertionSort(v1);
        printf("v1:");
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
    copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
    //    std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}



int insertSort_v1(vector<int> & v)
{
    for(int i=1;i<v.size();++i)
        //error: for(int i=1;i<v.size()-1;++i) 应该是i<v.size() 或者 i<=v.size()-1
    {
        int tmp=v[i];
        int j=i;
#if 0
        for(;j>0;--j)//此处错误，应该找到插入点就退出，
        {
            if(tmp<v[j-1])
                v[j]=v[j-1];
        }
        v[j]=tmp;
#endif
        while(j>0 && tmp<v[j-1])//必须先检查j>0
        {
            v[j]=v[j-1];
            --j;
        }
        v[j]=tmp;
    }//for
    return 0;
    
}

int insertSort_v2(vector<int> & v)
{
    for(int i=1;i<v.size();++i)
    {
       int j=i;
       while(j>0 && v[j-1]>v[j])//优
        {
            swap(v[j],v[j-1]);
            --j;
        }
    }//for
    return 0;
    
}
//插入排序 记忆版
void insertSort(vector<int> &v,int beginIndex,int endIndex){
    for(int i=beginIndex+1;i<=endIndex;++i){//第一元素自然有序
        //v[j]为待插入元素，向前找可插入的地方，当v[j]>=v[j-1]，退出循环即可
        for(int j=i;j>beginIndex && v[j]<v[j-1];--j)
            swap(v[j],v[j-1]);
    }
}

void insertSort_1(vector<int> &v,int beginIndex,int endIndex){
    for(int i=beginIndex+1;i<=endIndex;++i){//第一元素自然有序
        //v[j]为待插入元素，向前找可插入的地方，当v[j]>=v[j-1]，退出循环即可
        int a=v[i];
        int j=i;
        for(;j>beginIndex && a<v[j-1];--j)
            v[j]=v[j-1];
        v[j]=a;
    }
}

//exercise
void insertionSort(vector<int>&v){
    int len=v.size();
    for(int i=1;i<len;++i){
        for(int j=i;j>0&&v[j]<v[j-1];--j){//负责把i个元素放到有序部分合适的位置
            swap(v[j],v[j-1]);
        }
    }
}