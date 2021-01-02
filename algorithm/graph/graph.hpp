/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 14:22:10
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 07:17:58
 * @FilePath: /practice/algorithm/graph/graph.hpp
 */

#ifndef __graph_hpp__
#define __graph_hpp__
#include <vector>
#include <utility>
#include <iostream>
using std::vector;
using std::pair;
using std::cout;
using std::endl;
struct Edge{
  int u;
  int v;
  int w;
  Edge(int a,int b, int c)
  :u(a)
  ,v(b)
  ,w(c)
  {}
  bool operator<(const Edge& right){
    return  w<right.w;
  }
  bool operator>(const Edge& right){
    return  w>=right.w;
  }
};
struct EdgeNode{
  int v;
  int weight;
  EdgeNode* next;
  EdgeNode(int a, int b, EdgeNode* p=nullptr)
  :v(a)
  ,weight(b)
  ,next(p)
  {}
};
struct VertexNode{
  // vector<EdgeNode> _neighbours;
  int u;
  EdgeNode* headOfNeighbours;
  VertexNode(EdgeNode* p=nullptr)
  :headOfNeighbours(p)
  {}
  VertexNode(int a, EdgeNode* p=nullptr)
  :u(a)
  ,headOfNeighbours(p)
  {}
};
class Graph{
  public:
    using Weight=int;
    using v=int;//u作为inputArray下标，构成u-->v, 权重w
    Graph(int numOfVertex, const vector<Edge>& inputArray);//<v,weight>
    Graph(const Graph&);
    void insert(int u, int v, int w);
    // void remove();
    ~Graph(){cout<<"dtor"<<endl;}
    // vector<VertexNode> _vertexList;
    VertexNode* _vertexList;
    int _edgeNum;
    int _vertexNum;
  private:
    void clone();
};
#endif