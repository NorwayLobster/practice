/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 14:22:16
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-31 18:41:30
 * @FilePath: /practice/algorithm/graph/graph.cc
 */
#include "graph.hpp"
Graph::Graph(int numofVertex, const vector<pair<int,int>>& inputArray)
:_vertexNum(numofVertex)
,_edgeNum(inputArray.size()){
  _vertexList=new VertexNode[numofVertex];
  for(int u=0;u<(int)inputArray.size();++u){
    insert(u, inputArray[u].first, inputArray[u].second);
  }
}

 void Graph::insert(int u, int v, int w){
    EdgeNode* pnew=new EdgeNode(v, w);
    pnew->next=_vertexList[u].headOfNeighbours->next;//头插法
    _vertexList[u].headOfNeighbours=pnew;
    _vertexList[u].u=u;//mantain, but now it is useless
 }