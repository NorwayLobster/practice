/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2019-12-17 15:31:39
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 06:46:51
 * @FilePath: /practice/algorithm/graph/mst/kruskal.cc
 */
//
//  main.cpp
//  图算法经典1：MST最小支撑树
//
//  Created by ChengWang on 12/17/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include "disjointSet.hpp"
#include "graph.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//note: MST is just for undirected graph, not for directed graph
//图中的边节点会有一半的冗余
//greedy 
void prim(){// very similar to dijkstra

}
//v1: sort+
//v2: pq

//v1: sorted edges array
void kruskal(const Graph& g){
    DisjointSet ds(g._vertexNum);
    vector<Edge> v_edges;
    vector<Edge> MST;//MST由边组成
    int mincost=0;//MST's cost
    cout<<"g._vertexNum:"<<g._vertexNum<<endl;
    for(int u=0;u<g._vertexNum;++u){
        EdgeNode* cur=g._vertexList[u].headOfNeighbours;
        while(nullptr!=cur){
            if(u < cur->v){//无向图防止重复边进入
                v_edges.push_back(Edge(u,cur->v,cur->weight));
            }
            cur=cur->next;
        }
    }
    // for(auto edge:v_edges){ cout<<"edge:"<<edge.u<<","<<edge.v<<","<<edge.w<<endl; }
    sort(v_edges.begin(),v_edges.end(),[](const Edge& left, const Edge& right)->bool{return left.w<right.w;});
    // for(auto edge:v_edges){ cout<<"after edge:"<<edge.u<<","<<edge.v<<","<<edge.w<<endl; }
    for(int i=0;i<(int)v_edges.size();++i){
        cout<<"edges:"<<v_edges[i].u<<","<<v_edges[i].v<<","<<v_edges[i].w<<endl;
        int root1=ds.Find(v_edges[i].u);
        int root2=ds.Find(v_edges[i].v);
        if(root1==root2) continue;
        ds.Union(root1,root2);
        mincost+=v_edges[i].w;
        MST.push_back(v_edges[i]);
    }
    cout<<"mincost:"<<mincost<<endl;
}

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
  kruskal(G);
  return 0;
}