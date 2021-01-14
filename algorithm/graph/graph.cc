/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 14:22:16
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 06:40:37
 * @FilePath: /practice/algorithm/graph/graph.cc
 */
#include "graph.hpp"
Graph::Graph(int numofVertex, const vector<Edge>& inputArray)
:_vertexNum(numofVertex)
,_edgeNum(inputArray.size()){
  _vertexList=new VertexNode[numofVertex];
  for(int i=0;i<(int)inputArray.size();++i){
    insert(inputArray[i].u, inputArray[i].v, inputArray[i].w);
  }
}

 void Graph::insert(int u, int v, int w){
    EdgeNode* pnew=new EdgeNode(v, w);
    pnew->next=_vertexList[u].headOfNeighbours;//头插法
    _vertexList[u].headOfNeighbours=pnew;
    _vertexList[u].u=u;//mantain, but now it is useless
 }