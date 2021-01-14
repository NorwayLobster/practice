/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-31 16:57:08
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 06:40:17
 * @FilePath: /practice/algorithm/graph/testGraph.cc
 */
#include "graph.hpp"
#include <utility>
#include <fstream>
#include <sstream>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  fstream fs("../input.txt");
  stringstream ss; 
  string line;
  getline(fs,line);//first line
  ss<<line;
  int numOfVertex; 
  ss>>numOfVertex; 
  cout<<"numOfVertex:"<<numOfVertex<<endl;
//   vector<pair<int,int>> inputArray(numOfVertex,pair<int,int>(0,0));//should be edges num.
  vector<Edge> inputArray;
  int u;
  int v;
  int w;
  while(getline(fs,line)){
    // cout<<line<<endl;
    ss.clear();
    ss<<line;
    ss>>u>>v>>w;
    cout<<"u:"<<u<<",v:"<<v<<",w:"<<w<<endl;
    inputArray.push_back(Edge(u,v,w));
  }
  cout<<"size:"<<inputArray.size()<<endl;
  Graph G(numOfVertex,inputArray);
  return 0;
}