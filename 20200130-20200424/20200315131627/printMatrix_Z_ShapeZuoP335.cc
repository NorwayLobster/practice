 ///
 /// @file    printMatrix_Z_ShapeZuoP335.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-15 18:53:30
 ///complete: Sun Mar 15 19:42:59 CST 2020
// 49min 
#include <bits/stdc++.h>
using namespace std;
void printDiagonalEdge(vector<vector<int>> &v, int x1, int y1, int x2, int y2,bool aboveFlag){
	int i=x2;
	int j=y2;
	if(aboveFlag){
		while(j<=y1&&i>=x1){
			cout<<v[i][j]<<" ";
			++j;
			--i;
		}
	}else{
		i=x1;
		j=y1;
		while(j>=y2&&i<=x2){
			cout<<v[i][j]<<" ";
			--j;
			++i;
		}
	}
}
void printMatrixZ(vector<vector<int>> & v){
	int leftTopX=0;//行
	int leftTopY=0;//列
	int rightBottomX=v.size()-1;
	int rightBottomY=v[0].size()-1;

	int a=leftTopX;
	int b=leftTopY;

	int x=leftTopX;
	int y=leftTopY;
	bool aboveFlag=true;
	while(a<=rightBottomX){
		printDiagonalEdge(v,a,b,x,y,aboveFlag);
		if(b!=rightBottomY){
			b++;
		}else{
			a++;
		}
//		a=b!=rightBottomY?a:a++;//wrong;
//		b=b!=rightBottomY?b++:b;//wrong;
		if(x!=rightBottomX){
			x++;
		}else{
			y++;
		}
//		x=x!=rightBottomX?x++:x;//wrong;
//		y=x!=rightBottomX?y:y++;//wrong;

//		if(aboveFlag) aboveFlag=false; else aboveFlag=true;
		aboveFlag=!aboveFlag;
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
	printMatrixZ(v);
	cout<<endl;
	return 0;
}
