//
//  main.cpp
//  struct 结构体比较
//
//  Created by ChengWang on 3/13/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#if 0
struct Node1
{
    int x,y;
    bool operator <(Node a) const  {  return y < a.y; }
    bool operator >(Node a) const  {  return y > a.y; }
};
#endif

struct Node
{
    short f;
    short d;
    short fishs;
    short times;
    short i;
};

struct PCmp
{
    bool operator () (Node const *x, Node const *y)
    {
        if(x->f == y->f)
            return x->i > y->i;
        return x->f < y->f;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    priority_queue<float> q;    //默认的是大顶堆
    
    // insert three elements into the priority queue
    q.push(66.6);
    q.push(22.2);
    q.push(44.4);
    
    // read and print two elements
    cout << q.top() << ' ';         //queue当中是q.front();
    q.pop();
    cout << q.top() << endl;
    q.pop();
    
    // insert three more elements
    q.push(11.1);
    q.push(55.5);
    q.push(33.3);
    
    // skip one element
    q.pop();
    
    // pop and print remaining elements
    while (!q.empty())
    {
        cout << q.top() << ' ';
        q.pop();
    }

    priority_queue<Node*, vector<Node*>, PCmp > Q;
    
    cout << endl;
//2.下面是将节点存在优先队列中的两种方式

//最好的方式：这个简洁！


priority_queue<Node> A;                    //大根堆
priority_queue<Node, vector<Node>, greater<Node> > B;    //小根堆
    
//方式二：（cmp将结构体以val由大到小排列，组成大根堆）一般也用这个！

struct Node1
{
    int adj;
    int val;
};
    
struct cmp
{
    bool operator()(const Node1 & a, const Node1 & b) { return  a.val > b.val; }
};
priority_queue<Node1,vector<Node1>,cmp>pq;
//方式三：

#if 0
struct TMax
{
    TMax(int tx):x(tx){}
    int x;
};

struct TMin
{
    TMin(int tx):x(tx){}
    int x;
};

bool operator<(const TMax &a, const TMax &b)
{
    return a.x<b.x;
}

bool operator<(const TMin &a, const TMin &b)
{
    return a.x>b.x;
}

//priority_queue<TMax> hmax;    //大顶堆
//priority_queue<TMin> hmin;    //小顶堆
//3.下面是将指针存在优先队列中的方式


#endif
}
