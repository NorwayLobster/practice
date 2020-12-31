/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 14:27:30
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-31 14:36:26
 * @FilePath: /practice/algorithm/graph/disjointSet.hpp
 */

#ifndef __Disjoint_Set_Hpp__
#define __Disjoint_Set_Hpp__
class DisjointSet{
public:
    DisjointSet(const DisjointSet&)=delete;
    DisjointSet(int n)
    :_size(n)
    {
        _arr= new int[_size];
        for(int i=0; i<_size; ++i){
            _arr[i]=-1;
        }
    }

    ~DisjointSet(){ delete [] _arr;}
    void Union(int root1, int root2);
    int Find(int x);
    int size(){return _size;}
private:
    int _size;
    int * _arr;
};

int DisjointSet::Find(int x){
    // while(_arr[x]!=-1){
    //   x = _arr[x];  
    // }
    // return x;
    if(_arr[x]<0) return x;
    _arr[x]=Find(_arr[x]);//path compression
    return _arr[x];
}

void DisjointSet::Union(int root1, int root2){
    if(root1==root2) 
        return ;
    else{//union by rank
        if(_arr[root1] < _arr[root2]){//root1 has more node
            _arr[root1]+=_arr[root2];
            _arr[root2]= root1;
        }
        else{
            _arr[root2]+=_arr[root1];
            _arr[root1]=root2;//该等价类的类名, i.e. 根节点的下标值
        }
    }
}
#endif