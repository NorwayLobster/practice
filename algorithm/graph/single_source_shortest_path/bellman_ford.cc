/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-02 13:08:27
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-02 14:41:37
 * @FilePath: /practice/algorithm/graph/single_source_shortest_path/bellman_ford.cc
 */
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


//滚动数组优化:不能输出路径
void bellman_ford(const Graph& g, int s){

}

//要求：可以有负权，不能有负环
//time: O(n*n) 注意不是O(n^3) 江蕙如教授
void bellman_ford(const Graph& g, int s){
    vector<int> prevNode(g._vertexNum,0);
    vector<vector<int>> dp(g._vertexNum,vector<int>(g._vertexNum,0));
    for(int i=1;i<g._vertexNum;++i){//控制轮次，n-1轮即可
      for(int j=0;j<g._vertexNum;++j){//节点
        if(j==s) continue;
        EdgeNode* cur=g._vertexList[j].headOfNeighbours;
        while(nullptr!=cur){
          if(dp[i-1][cur->v]+cur->weight < dp[i-1][j]){
            dp[i][j]=dp[i-1][cur->v]+cur->weight;
            prevNode[j]=cur->v;
          }else{
            dp[i][j]=dp[i-1][j];
            //prevNode[j]
          }
          cur=cur->next;
        }
      }
    }
}

void printPath(const Graph& g, const vector<vector<int>>& dp){
    for(int i=0;i<g._vertexNum;++i){
      cout<<"cost"<<dp[g._vertexNum-1][i]<<endl;
      // prevNode[]
      // cout<<"cost"<<dp[g._vertexNum-1][i]<<endl;
    }
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
  bellman_ford(G,source);
  return 0;
}