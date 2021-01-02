/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2019-12-17 15:31:39
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 09:59:10
 * @FilePath: /practice/algorithm/graph/mst/prim.cc
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
#include <climits>//INT_MAX
using namespace std;
//note: MST is just for undirected graph, not for directed graph
//图中的边节点会有一半的冗余
//greedy 

void prim(const Graph& g){// very similar to dijkstra
    cout<<"g._vertexNum:"<<g._vertexNum<<endl;
    vector<bool> MST(g._vertexNum,false);//节点是否在MST
    vector<int> lowCost(g._vertexNum, INT_MAX);//U 与 U-V集合的目前为止最短距离距离
    vector<int> prev(g._vertexNum,0);// 更新构成U与U-V集合最短距离的prev节点

    int mst=0;////mst's cost
    //init
    int cur=0;//mst中第一个节点
    lowCost[cur]=0;//set 0 cost to MST
    MST[cur]=true;//add 0 into mst
    mst+=lowCost[cur];//caculate mincost

    //init: update info of node connect to cur node
    EdgeNode* pcur=g._vertexList[cur].headOfNeighbours;
    while(nullptr!=pcur){
        int neighbour=pcur->v;
        if(false==MST[neighbour] && pcur->weight < lowCost[neighbour]){
            lowCost[neighbour]=pcur->weight;
            prev[neighbour]=cur;
        }
        pcur=pcur->next;
    }

    for(int i=1;i<g._vertexNum;++i){// 在找出g._vertexNum-1个节点
      //part1: select min cost node as cur 
        int mincost=INT_MAX;//
        for(int j=0;j<g._vertexNum;++j){
          if(false==MST[j] && lowCost[j] < mincost){
            mincost=lowCost[j];
            cur=j;
          }
        }

      //part2: store cur info
        mst+=lowCost[cur];//caculate mincost
        MST[cur]=true;//add cur into mst
        cout<<"cur:"<<cur<<endl;
        cout<<"mst:"<<mst<<endl;

      //part3: update info for next iteration
        EdgeNode* pcur=g._vertexList[cur].headOfNeighbours;
        while(nullptr!=pcur){
            int neighbour=pcur->v;
            if(false==MST[neighbour] && pcur->weight < lowCost[neighbour] ){//update info of node connect to cur node
                lowCost[neighbour]=pcur->weight;
                prev[neighbour]=cur;
            }
            pcur=pcur->next;
        }
    }
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
  prim(G);
  return 0;
}