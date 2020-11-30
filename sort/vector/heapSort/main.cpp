//
//  main.cpp
//  heapSort
//
//  Created by ChengWang on 3/6/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//
void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);
void percolateDown(vector<int> & v, int index, int heapSize);
void percolateUp(vector<int> & v, int i);
void Insert(vector<int> & v, int index);
void delMax(vector<int> & v, int heapSize);
int heapSort_v1(vector<int> & v);
int heapSort_v2(vector<int> & v);
int heapSort_v3(vector<int> & v);
int heapSort_v4(vector<int> & v);
int heapSort_v5(vector<int> & v);
int heapSort_v6(vector<int> & v);

void percolateDown202021130(vector<int>&v,int partentIndex, int rightIndex);
void make_max_heap(vector<int>&v);
void sort_heap(vector<int>&v);
void heapsort(vector<int>&v);


void percolateDown(vector<int> & v, int index, int heapSize){
    int leftChild_idx=2*index+1;
    //error:    while(leftChild_idx<=heapSize){//note：heapSize-1 为最后一个节点的index
    while(leftChild_idx<heapSize){//note：heapSize-1 为最后一个节点的index
        int largest= leftChild_idx+1<heapSize && v[leftChild_idx]<v[leftChild_idx+1]? leftChild_idx+1 : leftChild_idx;//  <= 优先于 && 优先于？：
        largest = v[largest]>v[index]? largest:index; //        largest = v[largest]<v[index]? index: largest; 同上句
        if(largest==index) break;
        swap(v[largest],v[index]);
        
        index=largest;//更新index到新的位置
        leftChild_idx= 2*index+1;//计算新的index的左孩子，为下一循环做准备
    }
    return ;
}

//大根堆
void percolateUp(vector<int> & v, int i){
    //v[i]> v[(i-1)/2] 表示：v[i]大于其父亲节点
    while(v[i]>v[(i-1)/2]){//note：若i=0，(0-1)/2等于0，v[0]不大于自己，所以退出循环
        swap(v[i],v[(i-1)/2]);
        i=(i-1)/2;
    }
    return ;
}


void Insert(vector<int> & v, int index){
    percolateUp(v, index);
    return ;
}

void delMax(vector<int> & v, int heapSize){
    swap(v[0],v[heapSize-1]);
    percolateDown(v, 0, --heapSize);
    return ;
}


//蛮力建堆：自上而下上滤
int heapSort_v1(vector<int> & v)
{
//    cout<<"hello"<<endl;
    if(v.empty()) return 0; // error： 空，则，v.empty() 为true   if(!v.empty()) return 0;
//    cout<<"hello"<<endl;
    
//build_heap() // O(NlogN)
    for(int i =0; i< v.size();++i)
        Insert(v,i);
//    print(v);
//    cout<<"hello"<<endl;
    
    //sort_heap()
    int heapSize=v.size();
    while(0!=heapSize){
        swap(v[0],v[heapSize-1]);//出heap
        percolateDown(v, 0, --heapSize);
    }
    return 0;
}

//Floyd算法建堆：自下而上的下滤
int heapSort_v2(vector<int> & v)
{
    if(v.empty()) return 0;
    int heapSize=v.size();
    //build_heap()//O(logN) 证明见翁p168
    for(int i =(heapSize-1-1)/2;i>=0 ;--i)//lastParent(v, heapSize) 为 (heapSize-1-1)/2
        percolateDown(v, i, heapSize);//heapSize为整个堆的size，不是以i为root的子树的size；该heapSize判断i是否在heap中，
    
    //sort_heap()
    while(0!=heapSize){
        swap(v[0],v[heapSize-1]);
        percolateDown(v, 0, --heapSize);
    }
    return 0;
}

//stl: make_heap建堆， sort_heap使数组v变得的有序
int heapSort_v3(vector<int> & v)
{
    if(v.empty()) return 0;
    make_heap(v.begin(),v.end());
    sort_heap(v.begin(),v.end());
    return 0;
}

//
//push_heap把新插入到vector尾部的一个元素，调整融入进heap里, 即插入位于位置 last-1 的元素到范围 [first, last-1) 所定义的最大堆中， [first, last-1) i.e.  [first, last-2]
//pop_heap把堆顶元素pop出，并放到vector末尾，并且，之前的元素一次往前更近一位，并恢复堆的性质
//即，交换在位置 first 的值和在位置 last-1 的值，并令子范围 [first, last-1) 变为最大堆
int heapSort_v4(vector<int> & v){
    if(v.empty()) return 0;
//    for(int i=0;i<(int)v.size();++i)
//       push_heap(v,v+i);
    
//迭代器失效问题
    for(auto ite=v.begin();ite!=v.end();++ite)
        push_heap(v.begin(),ite);
   
    
//迭代器失效问题
    for(auto ite=v.end()-1;ite>=v.begin();--ite)//error here,
//问题：pop_heap的时候，是否先make_heap?
//pop出去后，会自动make_heap来回复堆的有序特性
        pop_heap(v.begin(),ite);
    return 0;
}


//std::priority_queue: 大顶堆
int heapSort_v5(vector<int> & v)
{
    if(v.empty()) return 0;
    priority_queue<int> pq(v.begin(),v.end());//默认less，大顶堆
    vector<int> tmp;
    while(!pq.empty()){
        tmp.push_back(pq.top());
        pq.pop();
    }
    copy(tmp.begin(),tmp.end(),v.begin());
    reverse(v.begin(),v.end());
    //or
//    copy(tmp.rbegin(),tmp.rend(),v.begin());
    return 0;
}

//std::priority_queue：小顶堆
int heapSort_v6(vector<int> & v)
{
    if(v.empty()) return 0;
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(),v.end());
    vector<int> tmp;
    while(!pq.empty()){
        tmp.push_back(pq.top());
        pq.pop();
    }
    copy(tmp.begin(),tmp.end(),v.begin());
    return 0;
}






int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, heapSorting!\n";
    int testTime = 10;
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
        print(v1);
        print(v2);
        sort(v2.begin(),v2.end());
        //                heapSort_v6(v1);
        // heapSort_v5(v1);
        heapsort(v1);
//                heapSort_v4(v1);///still error, no time to debug, 20190306
//                heapSort_v3(v1);
//                heapSort_v2(v1);
//                heapSort_v1(v1);
        print(v1);
        print(v2);
        cout<<endl;
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
    for(int i = 0; i < maxSize;i++ )
        v.push_back(rand()%(maxValue-10)+10);
}

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
    std::cout << '\n';
}




//exercise 202021130

void percolateDown202021130(vector<int>&v,int partentIndex, int rightIndex){
    // int len=v.size();
    int childrenIndex=2*partentIndex+1;
    while(childrenIndex<=rightIndex){
        if(childrenIndex+1<=rightIndex&& v[childrenIndex]<v[childrenIndex+1]){
            childrenIndex++;
        }
        if(v[childrenIndex]>v[partentIndex]){
            swap(v[childrenIndex],v[partentIndex]);
        }

        partentIndex=childrenIndex;//do not miss this
        childrenIndex=2*partentIndex+1;
    }
}

void make_max_heap(vector<int>&v){
    int len=v.size();
    for(int i=len/2+1;i>=0;--i){
    // for(int i=len/2+1;i>0;--i){//bug
    // for(int i=len/2+1;i>0;++i){//fatal error:
        percolateDown202021130(v,i,len-1);
    }
}

void sort_heap(vector<int>&v){
    int len=v.size();
    // for(int i =len-1;i>1;--i){//error:
    for(int i =len-1;i>0;--i){
        swap(v[0],v[i]);
        percolateDown202021130(v,0,i-1);
    }
}

void heapsort(vector<int>&v){
    // make_heap(v.begin(),v.end());
    make_max_heap(v);//have bugs
    sort_heap(v);//correct
}
