//program 9.2.4.cpp N皇后问题
#include <iostream>
#include <cmath>
using namespace std;
int N; //共N个皇后
int  queenPos[1000]; //用来存放算好的皇后位置
void NQueen( int n)  //摆放第n个皇后。皇后编号从0开始算
{
	int i;
	if( n == N ) { // N 个皇后已经摆好
		for( i = 0; i < n;++i ) //输出解
			cout << queenPos[i] << " ";
		cout << endl;
		return ;
	}
	for( i = 0;i < N; ++i) { //逐尝试第n个皇后的位置
		int j;
		for( j = 0; j < n; ++j ) { 
			//和已经摆好的 n 个皇后的位置比较，看是否冲突
			if( queenPos[j] == i || 
				abs(queenPos[j] - i) == abs(n-j)) {
				break; //冲突，则试下一个位置
			}
		}
		if( j == n ) { //当前选的位置 i 不冲突
			queenPos[n] = i; //将第n个皇后摆放在位置 i
			NQueen(n+1);     //摆放第n+1个皇后
		}
	}
}
int main()
{
	cin >> N;
	NQueen(0); //从第0个皇后开始摆放
	return 0;
}

