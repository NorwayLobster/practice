/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 14:22:10
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-31 18:45:09
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
  VertexNode(){};
  VertexNode(int a, EdgeNode* p=nullptr)
  :u(a)
  ,headOfNeighbours(p)
  {}
};
class Graph{
  public:
    using Weight=int;
    using v=int;//u作为inputArray下标，构成u-->v, 权重w
    Graph(int numOfVertex, const vector<pair<int, int>>& inputArray);//<v,weight>
    Graph(const Graph&);
    void insert(int u, int v, int w);
    // void remove();
    ~Graph(){cout<<"dtor"<<endl;}
  private:
    // vector<VertexNode> _vertexList;
    VertexNode* _vertexList;
    int _edgeNum;
    int _vertexNum;
    void clone();
};
#endif