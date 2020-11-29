//
//  main.cpp
//  quickSort()
//
//  Created by ChengWang on 3/6/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
//std::partition
int mypartition(vector<int>&v,int left,int right);
void quicksort(vector<int>&v, int left,int right);
void quicksort_v1(vector<int>&v, int left,int right);
void quickSort_v1(vector<int> & v, int left, int right);
void quickSort_v1_iteration(vector<int> & v, int left, int right);
void quickSort_v2(vector<int> & v, int left, int right);
void quickSort_v3(vector<int> &v, int left, int right );
void quickSort_v4(vector<int> &v, int left, int right );
void quickSort_A(vector<int> &v, int left, int right );

int partition_v1(vector<int> & v, int left, int right);
int partition_v1_1(vector<int> & v, int left, int right);
int partition_v2(vector<int> & v, int left, int right);
pair<int,int>  partition_v3(vector<int> & v, int left, int right);
int partition_v5(vector<int> & v, int left, int right);
int partition_A(vector<int> & v, int left, int right);
int partition_B(vector<int> & v, int left, int right);
    
void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, quickSort!\n";
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
        vector<int> v2(v);
//        print(v1);
//        print(v2);
        sort(v1.begin(),v1.end());
        // quicksort(v2, 0, (int)v.size()-1);
        quicksort_v1(v2, 0, (int)v.size()-1);
        // quickSort_v1_iteration(v2, 0, (int)v.size()-1);
//        quickSort_v1(v2, 0, (int)v.size()-1);
//        quickSort_v2(v2, 0, (int)v.size()-1);
//        quickSort_v3(v2, 0, (int)v.size()-1);
//        quickSort_v4(v2, 0, (int)v2.size()-1);
//        quickSort_A(v2, 0, (int)v.size()-1);
//        print(v1);
//        print(v2);
        cout<<endl;
        cout<<endl;
        if (!equal(v1.begin(), v1.end(), v2.begin())){
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





void quickSort_v1(vector<int> & v, int left, int right){
    if(left>=right)//区间不存在； 区间有一个元素，自然有序，无序在partition
        return ;

    //先partition使得前后分区 区间有序，后sort使区内有序
//    int pivot = partition_v1(v, left, right);//有可能两个数做partition
    int pivot = partition_v1_1(v, left, right);//有可能两个数做partition
    quickSort_v1(v, left, pivot-1);
    quickSort_v1(v, pivot+1, right);

}

void quickSort_v1_iteration(vector<int> & v, int startIndex, int endIndex){
    stack<pair<int,int>> ps;
    ps.push(make_pair(startIndex,endIndex));
    while(!ps.empty()){
        pair<int,int> ptmp=ps.top();
        ps.pop();
        int pivotIndex=partition_v1_1(v,ptmp.first,ptmp.second);
        if(ptmp.first<pivotIndex-1){
            ps.push(make_pair(ptmp.first,pivotIndex-1));
        }
        if(ptmp.second>pivotIndex+1){
            ps.push(make_pair(pivotIndex+1,ptmp.second));
        }
    }
    return ;
}

//------------------------------------------partition两分区--------------------------------------------


//单边循环partitioin法:
//partitioin: less区和more区相邻，并往右边挤压
int partition_v1(vector<int> & v, int left, int right)
{
// note：   v[more]为pivot元素
    
    int less = left-1;//小于等于区域的右边界 //    int more= left-1;//大于区域的右边界, note: 右
    int cur= left;
    while(cur<right){//cur 走到 right-1位置，stop
        if(v[cur]<=v[right]){
                swap(v[cur++],v[less+1]);//与more区的左边 第一个元素交换，cur向前推进一个
                less++; }//当less=left-1时，且当cur=left时，此时是 cur元素自己和自己交换。
        else
                cur++;
    }
    swap(v[less+1],v[right]);//pivot元素 与 more区的左边第一个元素swap; more区元素个数不变，只是原来在more区左边第一，移到右边第一
    
    return less+1;
}

//单边循环partitioin法:容易记忆版
int partition_v1_1(vector<int> & v, int startIndex, int endIndex){
    int rndIndex=startIndex+rand()%(endIndex-startIndex+1);
    swap(v[startIndex],v[rndIndex]);
    int pivot=v[startIndex];
    int  boundryIndex=startIndex;
    for(int i=startIndex+1;i<=endIndex;++i){
        if(v[i]<pivot){
            ++boundryIndex;
            swap(v[boundryIndex],v[i]);
        }
    }
    swap(v[startIndex],v[boundryIndex]);
    return boundryIndex;
}






void quickSort_v2(vector<int> & v, int left, int right){
    if(left>=right)//区间不存在； 区间有一个元素，自然有序，无序在partition
        return ;
    
    //先partition使得前后分区 区间有序，后sort使区内有序
    //    int pivot = partition_v1(v, left, right);//有可能两个数做partition
    pair<int,int> pivot = partition_v3(v, left, right);
    quickSort_v2(v, left, pivot.first-1);
    quickSort_v2(v, pivot.second+1, right);
    
}




//------------------------------------------partition三分区--------------------------------------------
//双边循环partition法： 分三区
//荷兰国旗partitioin  less区， more区， equal区
pair<int,int>  partition_v3(vector<int> & v, int left, int right){
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


void quickSort_A(vector<int> & v, int left, int right){
    if(left>=right)//区间不存在； 区间有一个元素，自然有序，无序在partition
        return ;
    int pivotIndex = partition_B(v, left, right);
//    int pivotIndex = partition_A(v, left, right);
    quickSort_A(v, left, pivotIndex-1);
    quickSort_A(v, pivotIndex+1, right);
    
}

//最简单，最容易记忆
//双边循环法：分两区
//经典版，邓版本A 懒于交换，勤于拓展
int  partition_A(vector<int> & v, int startIndex, int endIndex){
    int rndIndex=startIndex+rand()%(endIndex-startIndex+1);
//    printf("\nstartIndex:%d\n",startIndex);
//    printf("endIndex:%d\n",endIndex);
//    printf("rndIndex:%d\n",rndIndex);
    swap(v[startIndex],v[rndIndex]);
    int leftIndex=startIndex,rightIndex=endIndex;
//    int pivot=v[startIndex];
    int pivot=v[leftIndex];//第一个位置空下来，所以从后面开始，....,空位被填上
    while(leftIndex<rightIndex){
        while(leftIndex<rightIndex && v[rightIndex]>=pivot)
            --rightIndex;
        v[leftIndex]=v[rightIndex];//
   //why is it wrong?     v[leftIndex++]=v[rightIndex];//because leftIndex等于rightIndex时，退出c循环，此时leftIndex后置++显然错误
        while(leftIndex<rightIndex && v[leftIndex]<=pivot)
            ++leftIndex;
        v[rightIndex]=v[leftIndex];
    }
    v[leftIndex]=pivot;
    return leftIndex;
}


//双边循环法：邓版本B 懒于拓展，勤于交换
int  partition_B(vector<int> & v, int startIndex, int endIndex){
    int rndIndex=startIndex+rand()%(endIndex-startIndex+1);
    swap(v[startIndex],v[rndIndex]);
    int leftIndex=startIndex,rightIndex=endIndex;
    int pivot=v[leftIndex];
//    int pivot=v[startIndex];
    while(leftIndex<rightIndex){
        while(leftIndex<rightIndex){
                if(v[rightIndex]>pivot)
                    --rightIndex;
                else{
// why is it wrong?                   v[leftIndex]=v[rightIndex];//因为如果不后置++，和等于pivot的元素，会出现从右y左移到的死循环
                    v[leftIndex++]=v[rightIndex];
                    break;
                }
        }
        while(leftIndex<rightIndex ){
            if(v[leftIndex]<pivot)
                ++leftIndex;
            else{
                v[rightIndex--]=v[leftIndex];
                break;
            }
        }
    }
    v[leftIndex]=pivot;
    return leftIndex;
}






//---------------------------------练习------------------------------------------//


//练习:less equal more 三区，less和more在两边往中间压，partition_v3
pair<int, int> partition_4(vector<int> &v, int left, int right){
    int less = left-1;
    int pivot = right;
    int more = right;
    int cur=left;
    while(cur < more){
        if(v[cur]<v[pivot]){ swap(v[++less], v[cur++]); }
        else if(v[cur]>v[pivot]){ swap(v[cur], v[--more]); }
        else
            ++cur;
    }
    swap(v[cur], v[pivot]);
    return make_pair(less+1, cur);
//    return make_pair(less+1, more-1);
}
//对练习的封装
void quickSort_v3(vector<int> &v, int left, int right ){
    if(left>=right) return ;
    pair<int, int > p = partition_4(v, left, right);
    quickSort_v3(v, left, p.first-1 );
    quickSort_v3(v, p.second+1, right);
    return;
}


void quickSort_v4(vector<int> &v, int left, int right ){
    if(left>=right){
        return ;
    }
    int pivotIndex=partition_v5(v,left,right);
    quickSort_v4(v,left,pivotIndex-1);
    quickSort_v4(v,pivotIndex+1,right);
    return ;
}


int partition_v5(vector<int> &v, int left, int right){
    int pivot=v[left];
    int less=left,more=right;
#if 1
    while(less!=more){
        //退出循环时，是more踏进less区，因为more每次先走
        //退出循环时，less和more指向less区的最右边的元素，该元素小于pivot
        while(less<more && v[more]>pivot) //此处应该严格大于
            --more;
        while(less<more && v[less]<=pivot)//相等的情况，只允许在左区，即此处的less区
            ++less;
        if(less<more){
            swap(v[less],v[more]);//因为相等的情况在less，所以必须保证和pivot交换的元素在less区。
        }
    }
    
    swap(v[left],v[less]);//
#endif
   
///fucking
#if 0///error:
    while(less!=more){
        //退出循环时，是less踏进more区，因为less每次先走
        while(less<more && v[less]<pivot)//相等的情况，只允许在左区，即此处的less区
            ++less;
        while(less<more && v[more]>=pivot) //此处应该严格大于
            --more;
        if(less<more){
            swap(v[less],v[more]);
        }
    }
    
    swap(v[left],v[less]);//退出循环时，less和more指向more区的最左边的元素，该元素大于pivot
    //因为相等的情况在less，所以必须保证和pivot交换的元素在less区。
//    if(v[less]<=pivot)
//    else
//        swap(v[left],v[less-1]);//退出循环时，less和more指向more区的最左边的元素，该元素大于pivot
        
#endif
    return less;
}

//exercise
int mypartition(vector<int>&v,int left,int right){
    int pivot=v[left];
    int boudaryIndex=left;
    for(int i=left+1;i<=right;++i){
        if(v[i]<pivot){
            swap(v[++boudaryIndex],v[i]);
        }
    }
    //fatal error: swap(v[left],v[++boudaryIndex]);//把大于pivot的element换过去了
    swap(v[left],v[boudaryIndex]);//
    return boudaryIndex;
}
void quicksort(vector<int>&v, int left,int right){
   //fatal error: if(left==right) return ; why
    if(left>=right) return ;//correct
    int pivotIndex=mypartition(v,left,right);
    quicksort(v,left,pivotIndex-1);////fatal error 的原因 
    quicksort(v,pivotIndex+1,right);
}

void quicksort_v1(vector<int>&v, int left,int right){
   //fatal error: //
    if(left==right) return ;// why
    int pivotIndex=mypartition(v,left,right);
    quicksort(v,left,pivotIndex);//fatal error 的原因 
    quicksort(v,pivotIndex+1,right);
}