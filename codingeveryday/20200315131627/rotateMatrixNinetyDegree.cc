///
/// @file    rotateMatrixNinetyDegree.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-15 17:55:08
///complete: Sun Mar 15 18:49:49 CST 2020

#include <bits/stdc++.h>
using namespace std;
void handleEdge(vector<vector<int>> &v, int leftTopX, int leftTopY, int rightBottomX, int rightBottomY){
	int i=0;
	while(leftTopX+i<rightBottomY){
		int tmp=v[leftTopX][leftTopY+i];//1st node
		v[leftTopX][leftTopY+i]= v[rightBottomX-i][leftTopY];//4--> 1
		v[rightBottomX-i][leftTopY]=v[rightBottomX][rightBottomY-i];//3-->4
		v[rightBottomX][rightBottomY-i]=v[leftTopX+i][rightBottomY];//2-->3
		v[leftTopX+i][rightBottomY]=tmp;//1-->2
		++i;
	}
}

void rotateMatrixNinetyDegree(vector<vector<int>> & v){
	int leftTopX=0;//行
	int leftTopY=0;//列
	int rightBottomX=v.size()-1;
	int rightBottomY=v[0].size()-1;
	while(leftTopX<=rightBottomX&&leftTopY<=rightBottomY){
		handleEdge(v,leftTopX++,leftTopY++,rightBottomX--,rightBottomY--);
	}
}




//to be test
void rotate(vector<vector<int>>& matrix) {
//			way1: 分圈处理，由外到里，O(N^2), O(1),见coding dir，左程云
		  //way2: 几何旋转：step1:先上下颠倒，step2:后以主对角线为对称轴翻转; or 先以副对称轴翻转，然后上下翻转
		  int len=matrix.size();
	  cout<<"len:"<<len<<endl;
	  if(!len) return ;
	  int len1=matrix[0].size();
	  cout<<"len1:"<<len1<<endl;


	  //step1: 
	  for(int i=0;i<len/2;++i){//若len为奇数，则中轴线不动
		  for(int j=0;j<(int) len1;++j){
			  swap(matrix[i][j],matrix[len-i-1][j]);
		  }
	  }

	  //step2
	  for(int i=0;i<len;++i){
		  for(int j=i+1;j<len1;++j){//i+1:表示主对角线上，不动
			  swap(matrix[i][j],matrix[j][i]);
		  }
	  }
}




int main(){
	vector<vector<int>> v(8,vector<int>(8,0));
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

	rotateMatrixNinetyDegree(v);
	cout<<endl;

	for(int i=0;i<len1;++i){
		for(int j=0;j<len2;++j){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;

}
