/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 16:57:08
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-31 21:20:14
 * @FilePath: /practice/algorithm/graph/testGraph.cc
 */
#include <utility>
#include <iostream>
#include "graph.hpp"
using namespace std;
int main(){
  int numOfVertex; 
  cin>>numOfVertex; 
  cout<<"numOfVertex:"<<numOfVertex<<endl;
  vector<pair<int,int>> inputArray(numOfVertex);
  int u;
  int v;
  int w;
  for(int i=0;i<numOfVertex;++i){
    cin>>u>>v>>w;
    cout<<"u:"<<u<<",v:"<<v<<",w:"<<w<<endl;
    inputArray[u].first=v;
    inputArray[u].second=w;
    cout<<"inputArray[u]:"<<inputArray[u].first<<","<<inputArray[u].second<<endl;
  }
  Graph G(numOfVertex,inputArray);
  return 0;
}