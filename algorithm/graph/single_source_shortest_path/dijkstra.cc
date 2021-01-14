/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2019-12-16 22:24:32
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 14:23:46
 * @FilePath: /practice/algorithm/graph/single_source_shortest_path/dijkstra.cc
 */
//
//  main.cpp
//  sssp单源最短路径
//
//  Created by ChengWang on 12/16/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>

#include "disjointSet.hpp"
#include "graph.hpp"
#include <cmath>
#include <algorithm>
#include <utility>
#include <fstream>
#include <sstream>
#include <climits>//INT_MAX
using namespace std;

//greedy
//无负权 
void dijkstra(const Graph& g,int s){// very similar to prim
    cout<<"g._vertexNum:"<<g._vertexNum<<endl;
    vector<bool> flag(g._vertexNum,false);//节点已经考虑过与否
    vector<int> pathCost(g._vertexNum, INT_MAX);//s源点到 node in U-V集合 的目前为止最短距离距离
    vector<int> prevNode(g._vertexNum,0);//更新构成U与U-V集合最短距离的prev节点

    //init
    int cur=s;//处理的第一个节点,即源点s
    pathCost[cur]=0;//from s to itself
    flag[cur]=true;//已处理cur节点

    //init: update info of node connect to cur node
    EdgeNode* pcur=g._vertexList[cur].headOfNeighbours;
    while(nullptr!=pcur){
        int neighbour=pcur->v;
        if(false==flag[neighbour] && pathCost[cur]+pcur->weight < pathCost[neighbour]){
            pathCost[neighbour]=pathCost[cur]+pcur->weight;
            prevNode[neighbour]=cur;
        }
        pcur=pcur->next;
    }

    for(int i=1;i<g._vertexNum;++i){// 在找出g._vertexNum-1个节点
      //part1: select a node as cur which there is min cost from source node to
        int mincost=INT_MAX;
        for(int j=0;j<g._vertexNum;++j){
          if(false==flag[j] && pathCost[j] < mincost){
            mincost=pathCost[j];
            cur=j;
          }
        }

      //part2: store cur info
        flag[cur]=true;//add cur into mst
        cout<<"cur:"<<cur<<endl;

      //part3: update info for next iteration
        EdgeNode* pcur=g._vertexList[cur].headOfNeighbours;
        while(nullptr!=pcur){
            int neighbour=pcur->v;
            if(false==flag[neighbour] && pathCost[cur] + pcur->weight < pathCost[neighbour] ){//update info of node connect to cur node
                pathCost[neighbour]=pathCost[cur]+pcur->weight;
                prevNode[neighbour]=cur;
            }
            pcur=pcur->next;
        }
    }
}

//greedy+PQ
//note: pq中已处理的点不直接略过
void dijkstra_pq(const Graph& g,int s){// very similar to prim
}
int main(){
  fstream fs("../input_directedgraph1.txt");
  // fstream fs("../input_directedgraph.txt");
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
  int source=1;
  cout<<"source node:"<<source<<endl;
  dijkstra(G,source);
  return 0;
}