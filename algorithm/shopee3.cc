/*
 * @Date: 2022-03-13 19:07:54
 * @LastEditors: ChengWang
 * @LastEditTime: 2022-03-13 21:24:07
 * @FilePath: /undefined/Users/chengwang/shopee.cc
 */
#include<stdc++.h>
using namespace std;
1
2 3  
//构建堆：floy算法: 好像O(N)
/*
//void getTopM(int[] array, int m)
// output the top M frequency number from array
//for example:
// int[] array = {12, 34, 11, 10,9,12, 34, 78, 12}
// if m=4, then:
// top1:  [12, 3]

// top2:  [34, 2]

// top3:  [78, 1]

// top4:  [11, 1]


// void getTopM(int[] array, int M)
// output:  12, 3\n, 34, 2\n, 78, 1\n 11, 1
*/

// 100；50
//1 调整逻辑 是 下沉: step1: 
//2.  从最后一个父节点（left child or right child ), 往前前走，每次到达一个节点，执行一次下沉操作。
//space, O(N)
//time, O(N)+O(NlogN)+O(MlogN)=O(NlogN)
int main(){
    map<int,int> freq;//key, frequency
    //count
    vector<int> v={12, 34, 11, 10,9,12, 34, 78, 12};
    for(auto e: v){//O(N)
        freq[e]++;
    }
    
    //
    auto f=[](const pair<int,int>& p1, const pair<int,int>& p2)->bool{
        if( p1.second>p2.second){
            return true;
        }else if(p1.second<p2.second){
            return false;
        }else if(p1.first > p2.first){
            return true;
        }else{
            return false;
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,f> pq;
    for( aupt p: freq){
        pq.push(p);
    }

    //get 
    for(int i=0;i<M;++i){
        auto p=pq.top();
        pq.pop();
        cout<<"key:"<<p.first<<",frequency:"<<p.second<<endl;
    }
    return 0;
}