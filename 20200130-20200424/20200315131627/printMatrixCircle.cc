 ///
 /// @file    printMatrixCircle.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-15 17:20:42
 /// complete: Sun Mar 15 17:52:17 CST 2020
 //32min
#include <bits/stdc++.h>
using namespace std;
void printEdge(vector<vector<int>> &v, int leftTopX, int leftTopY, int rightBottomX, int rightBottomY){
	int i=leftTopX;
	int j=leftTopY;
	if(leftTopX==rightBottomX){
		while(j<=rightBottomY){
			cout<<v[i][j]<<" ";
			++j;
		}
	}else if(leftTopY==rightBottomY){
		while(i<=rightBottomX){
			cout<<v[i][j]<<" ";
			++i;
		}
	}else{
		while(i<rightBottomX){
			cout<<v[i][j]<<" ";
			++i;
		}
		while(j<rightBottomY){
			cout<<v[i][j]<<" ";
			++j;
		}
		while(i>leftTopX){
			cout<<v[i][j]<<" ";
			--i;
		}
		while(j>leftTopY){
			cout<<v[i][j]<<" ";
			--j;
		}
	}
}
void printMatrixCircle(vector<vector<int>> & v){
	int leftTopX=0;//行
	int leftTopY=0;//列
	int rightBottomX=v.size()-1;
	int rightBottomY=v[0].size()-1;
	while(leftTopX<=rightBottomX&&leftTopY<=rightBottomY){
		printEdge(v,leftTopX++,leftTopY++,rightBottomX--,rightBottomY--);
	}
}
int main(){
	vector<vector<int>> v(5,vector<int>(6,0));
	int len1=v.size();
	if(len1==0) return 0;
	int len2=v[0].size();
	int k=10;
	for(int i=0;i<len1;++i){
		for(int j=0;j<len2;++j){
			v[i][j]=k;
			cout<<v[i][j]<<" ";
			++k;
		}
		cout<<endl;
	}
	printMatrixCircle(v);
	return 0;

}
